/*
 *  Se7evidas - A GZDoom mod
 *  Copyright (C) 2018-2019 Chronos "phantombeta" Ouroboros
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//-------------------------------------------------------------------------------------------
//
// DemonDog
//
//-------------------------------------------------------------------------------------------
class S7_DemonDog : S7_DemonBase {
    default {
        //$Category "Se7evidas/Monsters"
        //$Color 12
        //$Title "Hellhound"
        //$Angled

        Health 80;
        GibHealth -40;
        PainChance 180;

        Radius 20;
        Height 32;
        Speed 13;

        SeeSound "Monsters/DemonDog/Sight";
        ActiveSound "Monsters/DemonDog/Active";
        PainSound "Monsters/DemonDog/Pain";
        DeathSound "Monsters/DemonDog/Death";

        Obituary "$OBDEMONDOG";
        Species 'DemonDog';
        Tag "$DEMONDOGTAG";

        // Quick-melee weakness
        DamageFactor "QuickMelee", 1.5;
    }

    override void InitializeXPSystem () {
        let serverData = S7_ServerData.Get ();
        xpSys.level = int (max (1.0, (double (serverData.avgLevel) / 3.25) + random [monsterStats] (-2, 2)));
        int attrPts = xpSys.level * 4;

        while (attrPts > 0) {
            int rnd = random [monsterStats] (0, 3);

            switch (rnd) {
            case 0: xpSys.SetStat (S7Stat_Strength, 1); break;
            case 1: xpSys.SetStat (S7Stat_Defense, 1); break;
            case 2: xpSys.SetStat (S7Stat_Vitality, 1); break;
            case 3: xpSys.SetStat (S7Stat_Agility, 1); break;
            }

            attrPts--;
        }

        // Vitality
        startHealth = int (health * (1.0 + (.065 * xpSys.GetStat (S7Stat_Vitality))));
        health = startHealth;
    }

    override void UpdateStats () {
        // Strength
        damageMultiply = 1.0 + (0.025 * xpSys.GetStat (S7Stat_Strength));
        // Defense
        damageFactor = clamp (1.0 - (0.02 * xpSys.GetStat (S7Stat_Defense)), 0.1, 1.0);
        // Agility
        speed = default.Speed + clamp (xpSys.GetStat (S7Stat_Agility) * 0.075, -default.Speed * .75, default.Speed);
    }

    override void OnDeath (Actor source, Actor inflictor, int dmgflags) {
        if (source) {
            let xpSys = GetXPSystem ();
            double level = xpSys ? xpSys.level : 1;
            GiveXP (source, int (140 * max (1, level / 3.)));
            GiveCash (source, int (clamp (120 * (level / 15.), 120, 120 * 3.5)));
        }
    }

    double GetDamageBonus () {
        if (!xpSys)
            return 0.;

        return xpSys.GetStat (S7Stat_Strength, false) * 0.065;
    }

    states {
    Spawn:
        DDOG A 10 A_S7Look;
        loop;
    See:
        DDOG AABBCCDD 2 A_S7ChaseDef;
        loop;

    Melee:
        TNT1 A      0 A_StartSound ("Monsters/DemonDog/Attack", slot: CHAN_Voice);
        DDOG EEEFFF 2 A_FaceTarget ();
        TNT1 A      0 A_CustomMeleeAttack (int ((24. + fRandom [monsterDMG] (-2., 2.)) * (1. + GetDamageBonus ())), "", "", 'Bite');
        DDOG GGGG   2 A_FaceTarget ();
        DDOG FFFEEE 2 A_FaceTarget ();
        goto See;

    Pain:
        DDOG G 2;
        DDOG G 2 A_Pain;
        goto See;

    Death.Massacre:
    Death:
        DDOG H  5 A_Scream;
        DDOG I  5;
        DDOG J  5 A_NoBlocking;
        DDOG K -1;
        stop;

    /*Death.Fire:
        TNT1 A 0 A_JumpIfHealthLower (-15, "RealDeath.Fire");
        goto Death;
    Death.Fire2:
    RealDeath.Fire:
        BURN ABC        5 bright A_Pain;
        BURN D          5 bright A_Pain;
        TNT1 A          0 A_NoBlocking;
        BURN EFGHIJKLMN 5 bright;
        BURN O          5 bright;
        BURN PQRSTU     5 bright;
        BURN V          1;
        wait;*/

    XDeath:
        DDOG H 1 { bDontGib = true; }
        DDOG H 2 {
            A_XScream ();
            A_NoBlocking ();
        }
        TNT1 A 0 S7_SpawnGibs ();
        CRSH A 1 { translation = bloodTranslation; }
        wait;

    Raise:
        DDOG K   5 { bDontGib = false; }
        DDOG JIH 5;
        goto See;
    }
}