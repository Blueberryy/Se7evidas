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
#include "weapons/weapon_stuff.h"
#include "systems/stamina.h"
#include "systems/parkour.h"

#define DODGESTAMINA 30
void DodgeScriptP1 (PlayerData_t *player) {
    if (!player)
        return;

    if (player->parkourDef.dodgeInvulnTics > 0) {
        (player->parkourDef.dodgeInvulnTics)--;
        SetInventory (DODGEINVULITEM, 1);
        SetInventory (DODGETRAILITEM, 1);
    } else {
        SetInventory (DODGEINVULITEM, 0);
        SetInventory (DODGETRAILITEM, 0);
    }

    if (player->parkourDef.dodgeCooldown <= 0) { // If dodgeCooldown is less than or equal to 0...
        if (player->parkourDef.dodgeCooldown < 0) // If dodgeCooldown is less than 0...
            player->parkourDef.dodgeCooldown = 0; // Set dodgeCooldown to 0

        // If the player tapped user2, isn't sprinting, didn't have his Soul Lance beam grabbed and has at least DODGESTAMINA stamina...
        if (KeyPressed (BT_USER2) && !player->SprintDef.Sprinting && !player->scriptData.beamGrab && player->health.stamina >= DODGESTAMINA) {
            if ((GetPlayerInput (-1, INPUT_FORWARDMOVE) < 0 || GetPlayerInput (-1, INPUT_SIDEMOVE) != 0) &&
                !(GetPlayerInput (-1, INPUT_FORWARDMOVE) < 0 && GetPlayerInput (-1, INPUT_SIDEMOVE) != 0)) { // If the player is moving backwards or sideways...
                TakeInventory (STAMINATOKEN, DODGESTAMINA); // Take DODGESTAMINA stamina
                player->health.stamina = CheckInventory (STAMINATOKEN); // Update player data

                ActivatorSound (s"Player/Dodge", 127); // Play the dodge sound

                int byteAngle = (player->physics.angle << 16) >> 8; // For some reason I have to do this weird shit. I have no idea why. Go ask DavidPH.
                if (GetPlayerInput (-1, INPUT_FORWARDMOVE) < 0) { // If the player is trying to move backwards...
                    ThrustThing (byteAngle + 128, 18, 1, 0); // Thrust the player backwards
                    ThrustThingZ (0, 85, 1, 1);
                } else if (GetPlayerInput (-1, INPUT_SIDEMOVE) < 0) { // If the player is trying to move left...
                    ThrustThing (byteAngle + 64, 18, 1, 0); // Thrust the player left
                    ThrustThingZ (0, 85, 1, 1);
                } else if (GetPlayerInput (-1, INPUT_SIDEMOVE) > 0) { // If the player is trying to move right...
                    ThrustThing (byteAngle + 192, 18, 1, 0); // Thrust the player right
                    ThrustThingZ (0, 85, 1, 1);
                }

                player->parkourDef.dodgeCooldown = ServerData.dodgeCooldown; // Set dodgeCooldown to the server's dodge cooldown time
                player->parkourDef.dodgeInvulnTics = 24; // Set the invuln tics to 16
            }
        }
    }
}

void DodgeScriptP2 (PlayerData_t *player) {
    if (!player)
        return;

    if (player->parkourDef.dodgeCooldown > 0) { // If dodgeCooldown is greater than 0...
        player->parkourDef.dodgeCooldown--; // Decrement dodgeCooldown by 1
    }
}

#define MJUMPMINDIFF 15
void MultiJumpScript (PlayerData_t *player) {
    if (!player)
        return;

    int mJumpMax = player->scriptData.beamGrab ? player->parkourDef.mjumpMax / 2 : player->parkourDef.mjumpMax;
    if (mJumpMax < 1)
        mJumpMax = 1;

    accum force = 40.0k * ServerData.mjumpZMul;
    if (player->physics.relativeZ == 0) { // If the player is on the ground...
        player->parkourDef.mjumpOnGround = TRUE; // Set mjumpOnGround to TRUE
        if (player->parkourDef.mjumpCount > 0) // If the player has multijumped at least once...
            player->parkourDef.mjumpCount = 0; // Reset the counter to 0
    } else { // If not...
        player->parkourDef.mjumpOnGround = FALSE; // Set mjumpOnGround to FALSE
    }

    // If the player's floor-relative Z is greater than MJUMPMINDIFF, the player's Z velocity is lower than or equal to 32, the player is not on the ground, the player's multijump
    // counter isn't equal to mJumpMax, the player pressed jump and the sv_nojump CVAR isn't TRUE...
    if (!GetCVar (s"sv_nojump") && !player->parkourDef.wjumpJustJumped && !player->parkourDef.mjumpOnGround && KeyPressed (BT_JUMP) && abs (player->physics.relativeZ) >= MJUMPMINDIFF
        && player->physics.velZ <= 32 && player->parkourDef.mjumpCount < mJumpMax) {
        SpawnForced (s"S7_MultiJump_Marker", player->physics.x, player->physics.y, player->physics.z, 0, player->physics.angle); // Spawn a multijump marker
        ThrustThingZ (0, force, 0, FALSE); // Thrust the player up
        player->parkourDef.mjumpCount++; // Increment the jump counter by 1
    }
}
int sign (int x) {
    if (x < 0) { return -1; }
    return 1;
}

// Some code taken from Parkmore by Ijon Tichy
void WallJumpScript (PlayerData_t *player) {
    player->parkourDef.wjumpJustJumped = FALSE;

    if (GetPlayerInput (-1, INPUT_FORWARDMOVE) < 0 && KeyPressed (BT_JUMP) && player->physics.relativeZ > 24.0k) {
        bool canBounce;
        int j;
        accum x = 20 * CosA (player->physics.angle), y = 20 * SinA (player->physics.angle);
        accum x2 = 8 * CosA (player->physics.angle), y2 = 8 * SinA (player->physics.angle);
        accum x3, y3, z;

        if (AbsA (x) > AbsA (y)) {
            y = y * (20.0 / AbsA (x));
            x = 20.0 * sign (x);
        } else {
            x = x * (20.0 / AbsA (y));
            y = 20.0 * sign (y);
        }

        for (int i = 0; i < 10; i++) {
            x3 = GetActorX (0) + x + (x2 * i);
            y3 = GetActorY (0) + y + (y2 * i);
            z  = GetActorZ (0) + 16.0k;

            j = Spawn (s"S7_WalljumpChecker", x3, y3, z, -500);
            if (!j) { canBounce = TRUE; }
            Thing_Remove (-500);
            if (canBounce) { break; }
        }
        if (canBounce) {
            int byteAngle = (player->physics.angle << 16) >> 8;
            player->parkourDef.wjumpJustJumped = TRUE;
            ThrustThing (byteAngle + 128, 18, 1, 0);
            ThrustThingZ (0, 40.0k, 0, 0);
            ChangeActorAngle (0, player->physics.angle + 0.5, TRUE);
        }
    }
}