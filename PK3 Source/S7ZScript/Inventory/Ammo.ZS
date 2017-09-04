//-------------------------------------------------------------------------------------------
//
// Backpack
//
//-------------------------------------------------------------------------------------------
class S7_BackpackToken : ammo { default { inventory.maxAmount 1; +inventory.undroppable -inventory.invBar } }
class S7_Backpack      : customInventory replaces backpack {
    default {
        height 26;
        tag "$BACKPACK";
        inventory.pickupMessage "$BACKPACK";
        inventory.amount 1;
        inventory.maxAmount 0;
    }

    states {
    Spawn:
        BPAK A -1;
        stop;
    Pickup:
        TNT1 A 0 A_JumpIfInventory ("S7_BackpackToken", 1, "GotOne");
        TNT1 A 0 GiveInventory ("S7_BackpackToken", 1);
        goto GiveAmmo;
    GotOne:
        TNT1 A 0 A_DropItem ("S7_BackpackNoAmmo");
        goto GiveAmmo;

    GiveAmmo:
        TNT1 A 1 A_Jump (256, "Give9mm", "Give45ACP");
        wait;
    Give9mm:
        TNT1 A 0 A_JumpIfInventory ("S7_9mmCartridges", 0, "No9mm");
        TNT1 A 0 GiveInventory ("S7_9mmCartridges", 15 * 2);
        goto GiveAmmoP2;
    No9mm:
        TNT1 AA 0 A_DropItem ("S7_9mmCartridges");
        goto GiveAmmoP2;
    Give45ACP:
        TNT1 A 0 A_JumpIfInventory ("S7_45ACPCartridges", 0, "No45ACP");
        TNT1 A 0 GiveInventory ("S7_45ACPCartridges", 62 * 2);
        goto GiveAmmoP2;
    No45ACP:
        TNT1 AA 0 A_DropItem ("S7_45ACPCartridges");
        goto GiveAmmoP2;

    GiveAmmoP2:
        TNT1 A 1 A_Jump (256, "Give44M", "GiveShells");
        wait;
    Give44M:
        TNT1 A 0 A_JumpIfInventory ("S7_44MCartridges", 0, "No44M");
        TNT1 A 0 GiveInventory ("S7_44MCartridges", 6 * 2);
        goto GiveAmmoP3;
    No44M:
        TNT1 AA 0 A_DropItem ("S7_44MCartridges");
        goto GiveAmmoP3;
    GiveShells:
        TNT1 A 0 A_JumpIfInventory ("S7_20gaShells", 0, "NoShells");
        TNT1 A 0 GiveInventory ("S7_20gaShells", 10 * 2);
        goto GiveAmmoP3;
    NoShells:
        TNT1 AA 0 A_DropItem ("S7_20gaShells");
        goto GiveAmmoP3;

    GiveAmmoP3:
        TNT1 A 1 A_Jump (256, "Give762x39", "GiveCells");
        wait;
    Give762x39:
        TNT1 A 0 A_JumpIfInventory ("S7_762x39Cartridges", 0, "No762x39");
        TNT1 A 0 GiveInventory ("S7_762x39Cartridges", 35 * 2);
        goto EndSuccess;
    No762x39:
        TNT1 AA 0 A_DropItem ("S7_762x39Cartridges");
        goto EndSuccess;
    GiveCells:
        TNT1 A 0 A_JumpIfInventory ("S7_Cells", 0, "NoCells");
        TNT1 A 0 GiveInventory ("S7_Cells", (18 * 2) * 2);
        goto EndSuccess;
    NoCells:
        TNT1 AA 0 A_DropItem ("S7_Cells");
        goto EndSuccess;


    EndSuccess:
        TNT1 A 0 A_RailWait;
        stop;
    EndFail:
        TNT1 A 0 A_RailWait;
        fail;
    }
}

class S7_BackpackNoAmmo : S7_Backpack {
    default {
        tag "$EMPTBACKPACK";
        inventory.pickupMessage "$EMPTBACKPACK";
        inventory.amount 1;
        inventory.maxAmount 0;

        +inventory.alwaysPickup
    }

    states {
    Spawn:
        BPAK A -1;
        stop;
    Pickup:
        TNT1 A 0 A_JumpIfInventory ("S7_BackpackToken", 1, "EndFail");
        TNT1 A 0 GiveInventory ("S7_BackpackToken", 1);
        goto EndSuccess;
    }
}

//-------------------------------------------------------------------------------------------
//
// 9x19mm
//
//-------------------------------------------------------------------------------------------
class S7_9mmCartridges : ammo {
    default {
        tag "$9MM";
        inventory.pickupMessage "$9MM";
        inventory.amount 15;
        inventory.maxAmount 90;
        // ammo.backpackMaxAmount 120;
        inventory.icon "CLIPA0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        CLIP A -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// .45 ACP
//
//-------------------------------------------------------------------------------------------
class S7_45ACPCartridges : ammo {
    default {
        tag "$45ACP";
        inventory.pickupMessage "$45ACP";
        inventory.amount 62;
        inventory.maxAmount 372;
        // ammo.backpackMaxAmount 496;
        //inventory.icon "CLIPC0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        CLIP C -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// .44 Magnum
//
//-------------------------------------------------------------------------------------------
class S7_44MCartridges : ammo {
    default {
        tag "$44M";
        inventory.pickupMessage "$44M";
        inventory.amount 6;
        inventory.maxAmount 36;
        // ammo.backpackMaxAmount 48;
        //inventory.icon "44MP0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        44MP A -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// 7.62x39mm
//
//-------------------------------------------------------------------------------------------
class S7_762x39Cartridges : ammo {
    default {
        tag "$762X39";
        inventory.pickupMessage "$762X39";
        inventory.amount 35;
        inventory.maxAmount 210;
        // ammo.backpackMaxAmount 280;
        //inventory.icon "CLIPE0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        CLIP E -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// .45 WW
//
//-------------------------------------------------------------------------------------------
class S7_45WWCartridges : ammo {
    default {
        tag "$44WW";
        inventory.pickupMessage "$44WW";
        inventory.amount 15;
        inventory.maxAmount 450;
        //inventory.icon "CLIPG0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        CLIP G -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// 20 gauge buckshot
//
//-------------------------------------------------------------------------------------------
class S7_20gaShells : ammo {
    default {
        tag "$20GA";
        inventory.pickupMessage "$20GA";
        inventory.amount 10;
        inventory.maxAmount 60;
        // ammo.backpackMaxAmount 80;
        inventory.icon "SHELA0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        SHEL A -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// 12 gauge buckshot
//
//-------------------------------------------------------------------------------------------
class S7_12gaShells : ammo {
    default {
        tag "$12GA";
        inventory.pickupMessage "$12GA";
        inventory.amount 4;
        inventory.maxAmount 72;
        // ammo.backpackMaxAmount 96;
        //inventory.icon "SHELB0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        SHEL B -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// Type A Energy Cells
//
//-------------------------------------------------------------------------------------------
class S7_Cells : ammo {
    default {
        tag "$CELLS";
        inventory.pickupMessage "$CELLS";
        inventory.amount 18;
        inventory.maxAmount 216;
        // ammo.backpackMaxAmount 288;
        //inventory.icon "CELLA0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        CELL A -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// Firebrand Systems Energy Cells
//
//-------------------------------------------------------------------------------------------
class S7_FBSysCells : ammo {
    default {
        tag "$FBSYSCELLS";
        inventory.pickupMessage "$FBSYSCELLS";
        inventory.amount 32;
        inventory.maxAmount 192;
        // ammo.backpackMaxAmount 184;
        inventory.icon "CELLC0";
        inventory.pickupSound "misc/ammopickup";
    }

    states {
    Spawn:
        CELL C -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// Antimatter shells
//
//-------------------------------------------------------------------------------------------
class S7_AntimatterShells : ammo {
    default {
        tag "$ANTISHELLS";
        inventory.pickupMessage "$ANTISHELLS";
        inventory.amount 1;
        inventory.maxAmount 4;
        //inventory.icon "ANSHA0";
        inventory.pickupSound "misc/ammopickup";
    }
    states {
    Spawn:
        ANSH A -1;
        stop;
    }
}

//-------------------------------------------------------------------------------------------
//
// Thumper. AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
//
//-------------------------------------------------------------------------------------------
class S7_Thumper_PExp     : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PFrag    : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PTherm   : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PFlare   : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PCluster : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PNail    : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PNGas    : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }
class S7_Thumper_PUnified : ammo { default { inventory.amount 0; inventory.maxAmount 40; +inventory.ignoreSkill } }