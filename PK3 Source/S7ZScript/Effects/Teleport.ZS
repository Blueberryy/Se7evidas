//-------------------------------------------------------------------------------------------
//
// Telefog
//
//-------------------------------------------------------------------------------------------
class S7_TeleportFog : actor {
    default {
        renderStyle "add";

        +noInteraction +noTeleport +noGravity +noBlockmap
    }

    states {
    Spawn:
        TFOG A 36 bright;
    Fade:
        TFOG A 1 bright A_FadeOut (0.1);
        loop;
    }
}

//-------------------------------------------------------------------------------------------
//
// Telefog spawner
//
//-------------------------------------------------------------------------------------------
class S7_TeleportFogSpawner : teleportFog replaces teleportFog {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnItemEx ("S7_TeleportFog", 0.0, 0.0);
        stop;
    }
}