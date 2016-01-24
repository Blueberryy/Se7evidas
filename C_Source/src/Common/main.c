/*
**  Se7evidas - A GZDoom mod
**  Copyright (C) 2015  Chronos Ouroboros
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
#include "health.h"
#include "HUD.h"
#include "misc.h"
#include "sprint_system.h"
#include "stamina.h"
#include "weapon_stuff.h"

Script_C void S7_ServersideEnter ENTER () {
    // Not needed or desired in TitleMaps.
    if (GameType () == GAME_TITLE_MAP)
        return;

    PlayerData_t *player = &PlayerData [PLN];

    while (TRUE) {
        UpdatePlayerData (player);
        StaminaRegenerationPart1 (player);
        SpeedScript (player);
        WaterScript (player);
        KeysScript ();

        Delay (1);

        StaminaRegenerationPart2 (player);
    }

}

Script_C void S7_ClientsideEnter ENTER CLIENTSIDE () {
    // Not needed or desired in TitleMaps.
    if (GameType () == GAME_TITLE_MAP)
        return;

    PlayerData_t *player = &PlayerData [PLN];
    int heartbeatTics = 0;

    while (TRUE) {
        HudWeapons ();
        HeartbeatScript (player, &heartbeatTics);

        Delay (1);
    }
}