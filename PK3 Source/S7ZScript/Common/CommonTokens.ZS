class S7_EvadeNow        : S7_Boolean { } // Usage: A_RadiusGive ("S7_EvadeNow", <distance>, RGF_Monsters, 1)
class S7_IsDead          : S7_Boolean { }
class S7_NotRealMonster  : S7_Boolean { }
class S7_MFireMode       : S7_Counter { default { inventory.maxAmount 3; } }
class S7_Weap_ReadyFrame : S7_Counter { }