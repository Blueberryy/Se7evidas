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
#include "save_system/save_invdata.h"

SaveInv_InvInfo importantInvInfo [] = {
    { .name = s"S7_BackpackToken", .callback = &InvUpdAmmoMax,  },
};

SaveInv_InvDef importantInv = {
    .cvarName = SD_IMPINV,
    .maxCVars = 5,
    .cvarMaxLen = (MAXCVARSIZ) - 24,
    .invArrSize = ArraySize (importantInvInfo),
    .invInfoArr = &importantInvInfo [0],
};

SaveInv_InvInfo normalInvInfo [] = {
    /* Ammo */
    { .name = s"S7_9mmCartridges",                              },
    { .name = s"S7_45ACPCartridges",                            },
    { .name = s"S7_44MCartridges",                              },
    { .name = s"S7_762x39Cartridges",                           },
    { .name = s"S7_12gaShells",                                 },
    { .name = s"S7_20gaShells",                                 },
    { .name = s"S7_Cells",                                      },
    { .name = s"S7_FBSysCells",                                 },
    // Thumper ammo
    { .name = s"S7_Thumper_PExp",                               },
    { .name = s"S7_Thumper_PFrag",                              },
    { .name = s"S7_Thumper_PTherm",                             },
    { .name = s"S7_Thumper_PFlare",                             },
    { .name = s"S7_Thumper_PCluster",                           },
    { .name = s"S7_Thumper_PNail",                              },
    { .name = s"S7_Thumper_PNGas",                              },

    /* Weapons and etc weapon info */
    // Mars Assault Rifle
    { .name = s"S7_AMG",                                        },
    { .name = s"S7_AMGMag",                                     },
    // Hitter SMG
    { .name = s"S7_HitterSMG",                                  },
    { .name = s"S7_HitterSMGClip",                              },
    { .name = s"S7_HitterSMGUpperJammed",                       },
    { .name = s"S7_HitterSMGLowerJammed",                       },
    // Manx Carbine
    { .name = s"S7_ManxCarbine",                                },
    { .name = s"S7_ManxCarbineClip",                            },
    // Plasma MG
    { .name = s"S7_PlasmaGun",                                  },
    { .name = s"S7_PlasmaGunMag",                               },
    { .name = s"S7_PlasmaGun_Charge",                           },
    // Fauchard Laser Rifle
    { .name = s"S7_Fauchard",                                   },
    { .name = s"S7_FauchardMag",                                },
    // Mjolnir Ion Cannon
    { .name = s"S7_PrettyShootyIonCannonGun",                   },
    // Lucifer Combat Shotgun
    { .name = s"S7_Shotgun",                                    },
    { .name = s"S7_ShotgunMag",                                 },
    { .name = s"S7_ShotgunLoaded",                              },
    // 12ga Super Shotgun
    { .name = s"S7_SSG",                                        },
    { .name = s"S7_SSGLeftLoaded",                              },
    { .name = s"S7_SSGRightLoaded",                             },
    // Thumper 50mm GL
    { .name = s"S7_Thumper",                                    },
    { .name = s"S7_ThumperSelectedPool",                        },
    { .name = s"S7_ThumperChambered",                           },
    // Raptor Pistol
    { .name = s"S7_Raptor",                                     },
    { .name = s"S7_RaptorClip",                                 },
    // Deathbringer Revolver
    { .name = s"S7_Revolver",                                   },
    { .name = s"S7_RevolverClip",                               },
    // Kronos SMG
    { .name = s"S7_TEC9",                                       },
    { .name = s"S7_TEC9Clip",                                   },
    // Grenades
    { .name = s"S7_GrenadeWeap",                                },
    { .name = s"S7_GrenadeCount",                               },
    // Hellwarrior Blade
    { .name = s"S7_HellwarriorBladeForm1",                      },

    /* Health */
    { .name = s"S7_Medikit",                                    },
    { .name = s"S7_Stimpack",                                   },
    { .name = s"S7_Canteen",                                    },

    /* Powerups */
    { .name = s"S7_Berserk",                                    },

    /* Loot */
    { .name = s"S7_Thumper_Used",                               },
};

SaveInv_InvDef normalInv = {
    .cvarName = SD_INV,
    .maxCVars = 25,
    .cvarMaxLen = (MAXCVARSIZ) - 18,
    .invArrSize = ArraySize (normalInvInfo),
    .invInfoArr = &normalInvInfo [0],
};