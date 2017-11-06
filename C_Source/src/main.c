/*
**  Se7evidas - A GZDoom mod
**  Copyright (C) 2015-???  Chronos Ouroboros
**
**  This program is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation; either version 2 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License along
**  with this program; if not, write to the Free Software Foundation, Inc.,
**  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "includes.h"
#include "gui/HUD.h"
#include "gui/playerMenu.h"
#include "systems/health.h"
#include "systems/misc.h"
#include "systems/monster_stuff.h"
#include "systems/parkour.h"
#include "systems/stamina.h"

void ShopSystem_Script (PlayerData_t *player);
void ResetStuff (PlayerData_t *player);

Script_C void S7_ServersideOpen OPEN () {
    #ifdef DEBUG
    Log_Str (s"Se7evidas version %s\nSe7evidas ACSVM Library compiled at %s %s.", MOD_VERSION_CSTR, __DATE__, __TIME__);
    #endif

    if (GetCVar (s"S7_DebugMode"))
        Log_Str (s"\CgSe7evidas: Debug mode is active (S7_DebugMode)");

    SetAirControl (0.1k);
    SetupMapEvents ();
    if (MapData.mapEvent > 0)
        Log ("%d", MapData.mapEvent);

    if (MapData.name == NULL) {
        MapData.name = StrParam ("%tS", PRINTNAME_LEVELNAME);
        MapData.author = s"";
    }

    while (TRUE) {
        UpdateServerData (); // Update server data
        UpdateMapData    (); // Update map data

        Delay (1);
    }
}

Script_C void S7_ServersideUnloading UNLOADING () {
    ServerData.mapCount++;

    if (ServerData.mapCount > 0 && Random (0, 255) < 32) {
        for (int i = 0; i < 50; i++)
            ServerData.queuedMapEvent = Random (i > 25 ? MEVNT_None : MEVNT_None + 1, MEVNT_LastToken - 1);
    } else
        ServerData.queuedMapEvent = MEVNT_None;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        PlayerData_t *player = &PlayerData [i];
        if (player)
            ResetStuff (player);
    }
}

Script_C void S7_ShowMapInfo () {
    SetHudSize (640, 480, FALSE);
    Delay (20);
    SetFont (s"BIGFONT");
    HudMessage (HUDMSG_FADEINOUT, 0, CR_RED, 320.0k, 300.0k, 4.0k, 1.0k, 1.0k, 0.0k, "%S", MapData.name);
    if (StrCmp (MapData.author, s"") != 0) {
        SetFont (s"SMALLFNT");
        HudMessage (HUDMSG_FADEINOUT, 0, CR_WHITE, 320.0k, 315.0k, 4.0k, 1.0k, 1.0k, 0.0k, "By %S", MapData.author);
    }
}

// General stuff
Script_C void S7_ServersideEnter2 (PlayerData_t *player);
Script_C void S7_ServersideEnter ENTER () {
    // Not needed or desired in TitleMaps.
    if (GameType () == GAME_TITLE_MAP || !PlayerInGame (PLN))
        return;

    PlayerData_t *player = &PlayerData [PLN]; // Get the player's PlayerData_t struct

    if (!player) {
        PlayerData_t tmp;
        PlayerData [PLN] = tmp;
        player = &PlayerData [PLN];
    }

    if (!player->initialized) {
        InitializePlayer (player);
    } else {
        FadeRange (0, 0, 0, 1.0k, 0, 0, 0, 0.0k, TicsToSecs (9));
        SetPlayerProperty (FALSE, OFF, PROP_TOTALLYFROZEN);
        TakeInventory (DISABLEHUDTOKEN, 0x7FFFFFFF);
    }

    SetActorPropertyFixed (0, APROP_Speed, 1.0k);

    S7_ServersideEnter2 (player); // This has to be done like this to make sure this script runs first.

    S7_ShowMapInfo ();

    while (TRUE) { // Loop forever
        if (!PlayerInGame (PLN))
            return;

        UpdatePlayerData (player); // Update the player's data
        UpdateAmmoMax    (player); // Update the max ammo
        StaminaRegenerationPart1 (player); // Regenerate stamina (Part 1)
        WallHoldScript           (player);
        UpdatePlayerData      (player); // Update the player's data again because of the parkour stuff
        ShopSystem_Script     (player); // Run the shop system
        SpeedScript           (player);
        PlayerMenuScript      (player);

        UpdatePlayerAlpha  (player); // Update the alpha

        Delay (1); // Wait for a tic

        StaminaRegenerationPart2 (player); // Regenerate stamina (Part 2)
    }
}

// Clientside-ish (HUD, popups, etc.) stuff
Script_C void S7_ServersideEnter2 (PlayerData_t *player) {
    if (!player) {
        DebugLog ("\CgScript S7_ServersideEnter2: Fatal error: Invalid or NULL player struct.");
        return;
    }

    SP_Data_t  sp_data;

    while (TRUE) { // Loop forever
        if (!PlayerInGame (PLN))
            return;

        ShowPop                  (player, &sp_data);
        ScreenOverlays           (player);

        Delay (1); // Wait for a tic
    }
}

Script_C void S7_MapStart ENTER () {
    if (!MapData.mapEventSet)
        while (!MapData.mapEventSet)
            Delay (1);

    SetHudSize (640, 480, FALSE);
    switch (MapData.mapEvent) {
        case MEVNT_GhostTown:
        break;

        case MEVNT_PowerOutage:
        break;

        case MEVNT_NuclearMeltdown:
        break;

        case MEVNT_PerfectHatred:
            SetFont (s"GARGWING");
            cstr s = CorruptText ((cstr) "Perfect Hatred");
            HudMessage (HUDMSG_FADEINOUT, 10000, CR_UNTRANSLATED, 250.1k, 320, 2.5k, 0.8k, 0.0k, 0.0k, s);
            Delay (2.5k * 35);
            for (int i = strlen (s) - 1; i >= 0; --i) {
                s [i] = 0;
                HudMessage (HUDMSG_PLAIN, 10000, CR_UNTRANSLATED, 250.1k, 320, 0.5k, 0.0k, 0.0k, 0.0k, "%s", s);
                Delay (3);
            }
        break;

        default:
        break;
    }
}

// Truly clientside stuff
Script_C void S7_ClientsideEnter ENTER CLIENTSIDE () {
    // Not needed or desired in TitleMaps.
    if (GameType () == GAME_TITLE_MAP || !PlayerInGame (PLN))
        return;

    while (TRUE) { // Loop forever
        if (!PlayerInGame (PLN))
            return;

        UpdateClientsideCVars ();

        Delay (1); // Wait for a tic
    }
}

void ResetStuff (PlayerData_t *player) {
    if (!player) {
        DebugLog ("\CgFunction ResetStuff: Fatal error: Invalid or NULL player struct");
        return;
    }

    player->misc.waterlevel = 0;
    player->misc.dying = FALSE;
    player->scriptData.staminaTics = 0;
    player->scriptData.beamGrab = FALSE;
    player->parkourDef.mjumpCount = 0;
    SetInventory (DISABLEHUDTOKEN, 0);

    SetPlayerProperty (FALSE, OFF, PROP_TOTALLYFROZEN);
}

Script_C void S7_ServersideRespawn RESPAWN () {
    // Not needed or desired in TitleMaps.
    if (ServerData.gameType == GAME_TITLE_MAP || !PlayerInGame (PLN))
        return;

    PlayerData_t *player = &PlayerData [PLN]; // Get the player's PlayerData_t struct

    if (!player) {
        DebugLog ("\CgScript S7_ServersideRespawn: Fatal error: Invalid or NULL player struct for player %d.", PLN);
        return;
    }

    ResetStuff (player);

    SetActorPropertyFixed (0, APROP_Speed, 1.0k);
}

Script_C void S7_ServersideDisconnect DISCONNECT (int num) {
    // Not needed or desired in TitleMaps.
    if (ServerData.gameType == GAME_TITLE_MAP)
        return;

    PlayerData_t *player = &PlayerData [num]; // Get the player's PlayerData_t struct

    if (!player) {
        DebugLog ("\CgScript S7_ServersideDisconnect: Fatal error: Invalid or NULL player struct for player %d.", num);
        return;
    }

    DisconnectPlayer (player);
}