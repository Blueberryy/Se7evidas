//-----------------------------------------------------------------------------
//
// Header for target library libacs.
//
// Defines from ZDoom's ACS.
//
// This file incorporates definitions from ZDoom's acc's zdefs.acs.
//
//-----------------------------------------------------------------------------

#ifndef __GDCC_Header__C__ACS_ZDoom__defs_h__
#define __GDCC_Header__C__ACS_ZDoom__defs_h__

#include <ACS_Hexen/defs.h>


//----------------------------------------------------------------------------|
// Macros                                                                     |
//

#undef T_DEMON
#undef T_GREENKEY

#define TEXFLAG_TOP       0x00000001
#define TEXFLAG_MIDDLE    0x00000002
#define TEXFLAG_BOTTOM    0x00000004
#define TEXFLAG_ADDOFFSET 0x00000008

#define GAME_TITLE_MAP 3

#define BLOCK_NOTHING    0
#define BLOCK_CREATURES  1
#define BLOCK_EVERYTHING 2
#define BLOCK_RAILING    3
#define BLOCK_PLAYERS    4

#define SCROLL           0
#define CARRY            1
#define SCROLL_AND_CARRY 2

#define MOD_UNKNOWN       0
#define MOD_ROCKET        5
#define MOD_R_SPLASH      6
#define MOD_PLASMARIFLE   7
#define MOD_BFG_BOOM      8
#define MOD_BFG_SPLASH    9
#define MOD_CHAINSAW     10
#define MOD_SSHOTGUN     11
#define MOD_WATER        12
#define MOD_SLIME        13
#define MOD_LAVA         14
#define MOD_CRUSH        15
#define MOD_TELEFRAG     16
#define MOD_FALLING      17
#define MOD_SUICIDE      18
#define MOD_BARREL       19
#define MOD_EXIT         20
#define MOD_SPLASH       21
#define MOD_HIT          22
#define MOD_RAILGUN      23
#define MOD_ICE          24
#define MOD_DISINTEGRATE 25
#define MOD_POISON       26
#define MOD_ELECTRIC     27

#define MOVIE_Played          0
#define MOVIE_Played_NoVideo  1
#define MOVIE_Played_Aborted  2
#define MOVIE_Failed         -1

#define PROP_FROZEN               0
#define PROP_NOTARGET             1
#define PROP_INSTANTWEAPONSWITCH  2
#define PROP_FLY                  3
#define PROP_TOTALLYFROZEN        4
#define PROP_INVULNERABILITY      5
#define PROP_STRENGTH             6
#define PROP_INVISIBILITY         7
#define PROP_RADIATIONSUIT        8
#define PROP_ALLMAP               9
#define PROP_INFRARED            10
#define PROP_WEAPONLEVEL2        11
#define PROP_FLIGHT              12
#define PROP_SPEED               15
#define PROP_BUDDHA              16

#define    INPUT_OLDBUTTONS   0
#define    INPUT_BUTTONS      1
#define    INPUT_PITCH        2
#define    INPUT_YAW          3
#define    INPUT_ROLL         4
#define    INPUT_FORWARDMOVE  5
#define    INPUT_SIDEMOVE     6
#define    INPUT_UPMOVE       7
#define MODINPUT_OLDBUTTONS   8
#define MODINPUT_BUTTONS      9
#define MODINPUT_PITCH       10
#define MODINPUT_YAW         11
#define MODINPUT_ROLL        12
#define MODINPUT_FORWARDMOVE 13
#define MODINPUT_SIDEMOVE    14
#define MODINPUT_UPMOVE      15

#define BT_ATTACK     0x00000001
#define BT_USE        0x00000002
#define BT_JUMP       0x00000004
#define BT_CROUCH     0x00000008
#define BT_TURN180    0x00000010
#define BT_ALTATTACK  0x00000020
#define BT_RELOAD     0x00000040
#define BT_ZOOM       0x00000080
#define BT_SPEED      0x00000100
#define BT_STRAFE     0x00000200
#define BT_MOVERIGHT  0x00000400
#define BT_MOVELEFT   0x00000800
#define BT_BACK       0x00001000
#define BT_FORWARD    0x00002000
#define BT_RIGHT      0x00004000
#define BT_LEFT       0x00008000
#define BT_LOOKUP     0x00010000
#define BT_LOOKDOWN   0x00020000
#define BT_MOVEUP     0x00040000
#define BT_MOVEDOWN   0x00080000
#define BT_SHOWSCORES 0x00100000
#define BT_USER1      0x00200000
#define BT_USER2      0x00400000
#define BT_USER3      0x00800000
#define BT_USER4      0x01000000

#define CR_UNTRANSLATED -1
#define CR_BRICK         0
#define CR_TAN           1
#define CR_GRAY          2
#define CR_GREY          2
#define CR_GREEN         3
#define CR_BROWN         4
#define CR_GOLD          5
#define CR_RED           6
#define CR_BLUE          7
#define CR_ORANGE        8
#define CR_WHITE         9
#define CR_YELLOW       10
#define CR_BLACK        12
#define CR_LIGHTBLUE    13
#define CR_CREAM        14
#define CR_OLIVE        15
#define CR_DARKGREEN    16
#define CR_DARKRED      17
#define CR_DARKBROWN    18
#define CR_PURPLE       19
#define CR_DARKGRAY     20
#define CR_DARKGREY     20
#define CR_CYAN         21

#define HUDMSG_PLAIN             0x00000000
#define HUDMSG_FADEOUT           0x00000001
#define HUDMSG_TYPEON            0x00000002
#define HUDMSG_FADEINOUT         0x00000003
#define HUDMSG_LAYER_OVERHUD     0x00000000
#define HUDMSG_LAYER_UNDERHUD    0x00001000
#define HUDMSG_LAYER_OVERMAP     0x00002000
#define HUDMSG_NOTWITH3DVIEW     0x00010000
#define HUDMSG_NOTWITHFULLMAP    0x00020000
#define HUDMSG_NOTWITHOVERLAYMAP 0x00040000
#define HUDMSG_NOWRAP            0x08000000
#define HUDMSG_ALPHA             0x10000000
#define HUDMSG_ADDBLEND          0x20000000
#define HUDMSG_COLORSTRING       0x40000000
#define HUDMSG_LOG               0x80000000

#define MARINEWEAPON_Dummy           0
#define MARINEWEAPON_Fist            1
#define MARINEWEAPON_BerserkFist     2
#define MARINEWEAPON_Chainsaw        3
#define MARINEWEAPON_Pistol          4
#define MARINEWEAPON_Shotgun         5
#define MARINEWEAPON_SuperShotgun    6
#define MARINEWEAPON_Chaingun        7
#define MARINEWEAPON_RocketLauncher  8
#define MARINEWEAPON_PlasmaRifle     9
#define MARINEWEAPON_Railgun        10
#define MARINEWEAPON_BFG            11

#define APROP_Health            0
#define APROP_Speed             1
#define APROP_Damage            2
#define APROP_Alpha             3
#define APROP_RenderStyle       4
#define APROP_SeeSound          5
#define APROP_AttackSound       6
#define APROP_PainSound         7
#define APROP_DeathSound        8
#define APROP_ActiveSound       9
#define APROP_Ambush           10
#define APROP_Invulnerable     11
#define APROP_JumpZ            12
#define APROP_ChaseGoal        13
#define APROP_Frightened       14
#define APROP_Gravity          15
#define APROP_Friendly         16
#define APROP_SpawnHealth      17
#define APROP_Dropped          18
#define APROP_Notarget         19
#define APROP_Species          20
#define APROP_Nametag          21
#define APROP_Score            22
#define APROP_Notrigger        23
#define APROP_DamageFactor     24
#define APROP_MasterTID        25
#define APROP_TargetTID        26
#define APROP_TracerTID        27
#define APROP_Waterlevel       28
#define APROP_ScaleX           29
#define APROP_ScaleY           30
#define APROP_Dormant          31
#define APROP_Mass             32
#define APROP_Accuracy         33
#define APROP_Stamina          34
#define APROP_Height           35
#define APROP_Radius           36
#define APROP_Reactiontime     37
#define APROP_MeleeRange       38
#define APROP_ViewHeight       39
#define APROP_AttackZOffset    40
#define APROP_StencilColor     41
#define APROP_Friction         42
#define APROP_DamageMultiplier 43

#define STYLE_None                0
#define STYLE_Normal              1
#define STYLE_Fuzzy               2
#define STYLE_SoulTrans           3
#define STYLE_OptFuzzy            4
#define STYLE_Stencil             5
#define STYLE_AddStencil          6
#define STYLE_AddShaded           7
#define STYLE_Translucent        64
#define STYLE_Add                65
#define STYLE_Shaded             66
#define STYLE_TranslucentStencil 67
#define STYLE_Shadow             68
#define STYLE_Subtract           69

#define LEVELINFO_PAR_TIME         0
#define LEVELINFO_CLUSTERNUM       1
#define LEVELINFO_LEVELNUM         2
#define LEVELINFO_TOTAL_SECRETS    3
#define LEVELINFO_FOUND_SECRETS    4
#define LEVELINFO_TOTAL_ITEMS      5
#define LEVELINFO_FOUND_ITEMS      6
#define LEVELINFO_TOTAL_MONSTERS   7
#define LEVELINFO_KILLED_MONSTERS  8
#define LEVELINFO_SUCK_TIME        9

#define PLAYERINFO_TEAM        0
#define PLAYERINFO_AIMDIST     1
#define PLAYERINFO_COLOR       2
#define PLAYERINFO_GENDER      3
#define PLAYERINFO_NEVERSWITCH 4
#define PLAYERINFO_MOVEBOB     5
#define PLAYERINFO_STILLBOB    6
#define PLAYERINFO_PLAYERCLASS 7
#define PLAYERINFO_FOV         8
#define PLAYERINFO_DESIREDFOV  9

#define NOT_BOTTOM  0x00000001
#define NOT_MIDDLE  0x00000002
#define NOT_TOP     0x00000004
#define NOT_FLOOR   0x00000008
#define NOT_CEILING 0x00000010

#define DAMAGE_PLAYERS            0x00000001
#define DAMAGE_NONPLAYERS         0x00000002
#define DAMAGE_IN_AIR             0x00000004
#define DAMAGE_SUBCLASSES_PROTECT 0x00000008

#define MRF_OLDEFFECTS        0x00000000
#define MRF_ADDSTAMINA        0x00000001
#define MRF_FULLHEALTH        0x00000002
#define MRF_UNDOBYTOMEOFPOWER 0x00000004
#define MRF_UNDOBYCHAOSDEVICE 0x00000008
#define MRF_FAILNOTELEFRAG    0x00000010
#define MRF_FAILNOLAUGH       0x00000020
#define MRF_WHENINVULNERABLE  0x00000040
#define MRF_LOSEACTUALWEAPON  0x00000080
#define MRF_NEWTIDBEHAVIOUR   0x00000100
#define MRF_UNDOBYDEATH       0x00000200
#define MRF_UNDOBYDEATHFORCED 0x00000400
#define MRF_UNDOBYDEATHSAVES  0x00000800

#define T_SHOTGUY              1
#define T_CHAINGUY             2
#define T_BARON                3
#define T_ZOMBIE               4
#define T_IMP                  5
#define T_ARACHNOTRON          6
#define T_SPIDERMASTERMIND     7
#define T_DEMON                8
#define T_SPECTRE              9
#define T_IMPFIREBALL         10
#define T_CLIP                11
#define T_SHELLS              12
#define T_CACODEMON           19
#define T_REVENANT            20
#define T_BRIDGE              21
#define T_ARMORBONUS          22
#define T_STIMPACK            23
#define T_MEDKIT              24
#define T_SOULSPHERE          25
#define T_SHOTGUN             27
#define T_CHAINGUN            28
#define T_ROCKETLAUNCHER      29
#define T_PLASMAGUN           30
#define T_BFG                 31
#define T_CHAINSAW            32
#define T_SUPERSHOTGUN        33
#define T_PLASMABOLT          51
#define T_TRACER              53
#define T_GREENARMOR          68
#define T_BLUEARMOR           69
#define T_CELL                75
#define T_BLUEKEYCARD         85
#define T_REDKEYCARD          86
#define T_YELLOWKEYCARD       87
#define T_YELLOWSKULLKEY      88
#define T_REDSKULLKEY         89
#define T_BLUESKULLKEY        90
#define T_TEMPLARGEFLAME      98
#define T_STEALTHBARON       100
#define T_STEALTHKNIGHT      101
#define T_STEALTHZOMBIE      102
#define T_STEALTHSHOTGUY     103
#define T_LOSTSOUL           110
#define T_VILE               111
#define T_MANCUBUS           112
#define T_HELLKNIGHT         113
#define T_CYBERDEMON         114
#define T_PAINELEMENTAL      115
#define T_WOLFSS             116
#define T_STEALTHARACHNOTRON 117
#define T_STEALTHVILE        118
#define T_STEALTHCACODEMON   119
#define T_STEALTHCHAINGUY    120
#define T_STEALTHSERGEANT    121
#define T_STEALTHIMP         122
#define T_STEALTHMANCUBUS    123
#define T_STEALTHREVENANT    124
#define T_BARREL             125
#define T_CACODEMONSHOT      126
#define T_ROCKET             127
#define T_BFGSHOT            128
#define T_ARACHNOTRONPLASMA  129
#define T_BLOOD              130
#define T_PUFF               131
#define T_MEGASPHERE         132
#define T_INVULNERABILITY    133
#define T_BERSERK            134
#define T_INVISIBILITY       135
#define T_IRONFEET           136
#define T_COMPUTERMAP        137
#define T_LIGHTAMP           138
#define T_AMMOBOX            139
#define T_ROCKETAMMO         140
#define T_ROCKETBOX          141
#define T_BATTERY            142
#define T_SHELLBOX           143
#define T_BACKPACK           144
#define T_GUTS               145
#define T_BLOODPOOL          146
#define T_BLOODPOOL1         147
#define T_BLOODPOOL2         148
#define T_FLAMINGBARREL      149
#define T_BRAINS             150
#define T_SCRIPTEDMARINE     151
#define T_HEALTHBONUS        152
#define T_MANCUBUSSHOT       153
#define T_BARONBALL          154

#define T_CLINK                  1
#define T_MUMMYLEADER            2
#define T_BEAST                  3
#define T_MUMMY                  4
#define T_IMP                    5
#define T_KNIGHT                 6
#define T_IMPLEADER              7
#define T_MUMMYGHOST             8
#define T_MUMMYLEADERGHOST       9
#define T_IMPFIREBALL           10
#define T_WIMPYWANDAMMO         11
#define T_HEFTYWANDAMMO         12
#define T_ITEMEGG               14
#define T_ITEMFLIGHT            15
#define T_ITEMTELEPORT          18
#define T_WIZARD                19
#define T_IRONLICH              20
#define T_ITEMHEALTHPOTION      23
#define T_ITEMHEALTHFLASK       24
#define T_ITEMHEALTHFULL        25
#define T_CROSSBOW              27
#define T_BLASTER               28
#define T_PHOENIXROD            29
#define T_SKULLROD              30
#define T_MACE                  31
#define T_GAUNTLETS             32
#define T_WIMPYCROSSBOWAMMO     33
#define T_HEFTYCROSSBOWAMMO     34
#define T_WIMPYMACEAMMO         35
#define T_HEFTYMACEAMMO         36
#define T_WIMPYBLASTERAMMO      37
#define T_HEFTYBLASTERAMMO      38
#define T_MORPHBLAST            40
#define T_SHIELD1               68
#define T_SHIELD2               69
#define T_ITEMTIMEBOMB          72
#define T_ITEMTORCH             73
#define T_BLUEKEY               85
#define T_GREENKEY              86
#define T_YELLOWKEY             87
#define T_SOUND_WIND           110
#define T_SOUND_WATERFALL      111
#define T_BEASTBALL            120
#define T_FEATHER              121
#define T_CHICKEN              122
#define T_VOLCANOBALL          123
#define T_TINYVOLCANOBALL      124
#define T_POD                  125
#define T_PODGENERATOR         126
#define T_KNIGHTAXE            127
#define T_KNIGHTBLOODAXE       128
#define T_KNIGHTGHOST          129
#define T_MUMMYHEAD            131
#define T_SNAKE                132
#define T_ITEMINVULNERABILITY  133
#define T_ITEMTOME             134
#define T_ITEMINVISIBILITY     135
#define T_ITEMBAGOFHOLDING     136
#define T_ITEMALLMAP           137
#define T_SNAKEPROJECTILE      138
#define T_SNAKEPROJECTILEBIG   139
#define T_WIZARDSHOT           140
#define T_DSPARILTELEPORTDEST  141
#define T_DSPARILONSERPENT     142
#define T_DSPARILALONE         143
#define T_SERPENTFIREBALL      144
#define T_DSPARILBLUESHOT      145
#define T_DSPARILWIZARDSPAWNER 146
#define T_CROSSBOWMAINBLAST    147
#define T_CROSSBOWMINIBLAST    148
#define T_CROSSBOWPOWERBLAST   149
#define T_VOLCANO              150
#define T_POWERWANDMINIBLAST   151
#define T_POWERWANDBIGGERBLAST 152
#define T_DEATHBALL            153
#define T_NOGRAVITYMACEBALL    154
#define T_BOUNCYMACEBALL       155
#define T_HEAVYMACEBALL        156
#define T_RIPPER               157
#define T_WIMPYSKULLRODAMMO    158
#define T_HEFTYSKULLRODAMMO    159
#define T_SKULLRODBLAST        160
#define T_WIMPYPHOENIXRODAMMO  161
#define T_HEFTYPHOENIXRODAMMO  162
#define T_PHOENIXSHOT          163
#define T_IRONLICHBLUESHOT     164
#define T_WHIRLWIND            165
#define T_REDTELEGLITTER       166
#define T_BLUETELEGLITTER      167

#define T_DEMON1         3
#define T_SMALLMETALKEY 86

#define ACTOR_NONE       0x00000000
#define ACTOR_WORLD      0x00000001
#define ACTOR_PLAYER     0x00000002
#define ACTOR_BOT        0x00000004
#define ACTOR_VOODOODOLL 0x00000008
#define ACTOR_MONSTER    0x00000010
#define ACTOR_ALIVE      0x00000020
#define ACTOR_DEAD       0x00000040
#define ACTOR_MISSILE    0x00000080
#define ACTOR_GENERIC    0x00000100

#define SECSEQ_FLOOR      1
#define SECSEQ_CEILING    2
#define SECSEQ_FULLHEIGHT 3
#define SECSEQ_INTERIOR   4

#define CHAN_AUTO        0x00000000
#define CHAN_WEAPON      0x00000001
#define CHAN_VOICE       0x00000002
#define CHAN_ITEM        0x00000003
#define CHAN_BODY        0x00000004
#define CHAN_LISTENERZ   0x00000008
#define CHAN_MAYBE_LOCAL 0x00000010
#define CHAN_UI          0x00000020
#define CHAN_NOPAUSE     0x00000040

#define ATTN_NONE   0.0k
#define ATTN_NORM   1.0k
#define ATTN_IDLE   1.001k
#define ATTN_STATIC 3.0k

#define SOUND_See        0
#define SOUND_Attack     1
#define SOUND_Pain       2
#define SOUND_Death      3
#define SOUND_Active     4
#define SOUND_Use        5
#define SOUND_Bounce     6
#define SOUND_WallBounce 7
#define SOUND_CrushPain  8
#define SOUND_Howl       9

#define SDF_ABSANGLE  1
#define SDF_PERMANENT 2

#define AAPTR_DEFAULT                0x00000000
#define AAPTR_NULL                   0x00000001
#define AAPTR_TARGET                 0x00000002
#define AAPTR_MASTER                 0x00000004
#define AAPTR_TRACER                 0x00000008
#define AAPTR_PLAYER_GETTARGET       0x00000010
#define AAPTR_PLAYER_GETCONVERSATION 0x00000020
#define AAPTR_PLAYER1                0x00000040
#define AAPTR_PLAYER2                0x00000080
#define AAPTR_PLAYER3                0x00000100
#define AAPTR_PLAYER4                0x00000200
#define AAPTR_PLAYER5                0x00000400
#define AAPTR_PLAYER6                0x00000800
#define AAPTR_PLAYER7                0x00001000
#define AAPTR_PLAYER8                0x00002000
#define AAPTR_FRIENDPLAYER           0x00004000
#define AAPTR_GET_LINETARGET         0x00008000

#define PTROP_UNSAFETARGET 0x00000001
#define PTROP_UNSAFEMASTER 0x00000002
#define PTROP_NOSAFEGUARDS (PTROP_UNSAFETARGET | PTROP_UNSAFEMASTER)

#define SPAC_None       0x00000000
#define SPAC_Cross      0x00000001
#define SPAC_Use        0x00000002
#define SPAC_MCross     0x00000004
#define SPAC_Impact     0x00000008
#define SPAC_Push       0x00000010
#define SPAC_PCross     0x00000020
#define SPAC_UseThrough 0x00000040
#define SPAC_AnyCross   0x00000080
#define SPAC_MUse       0x00000100
#define SPAC_MPush      0x00000200
#define SPAC_UseBack    0x00000400

#define ARMORINFO_CLASSNAME        0
#define ARMORINFO_SAVEAMOUNT       1
#define ARMORINFO_SAVEPERCENT      2
#define ARMORINFO_MAXABSORB        3
#define ARMORINFO_MAXFULLABSORB    4
#define ARMORINFO_ACTUALSAVEAMOUNT 5

#define EV_KeyDown          1
#define EV_KeyRepeat        2
#define EV_KeyUp            3
#define EV_Char             4
#define EV_MouseMove        5
#define EV_LButtonDown      6
#define EV_LButtonUp        7
#define EV_LButtonDblClick  8
#define EV_MButtonDown      9
#define EV_MButtonUp       10
#define EV_MButtonDblClick 11
#define EV_RButtonDown     12
#define EV_RButtonUp       13
#define EV_RButtonDblClick 14
#define EV_WheelDown       15
#define EV_WheelUp         16

#define GKM_SHIFT    0x00000100
#define GKM_CTRL     0x00000200
#define GKM_ALT      0x00000400
#define GKM_LBUTTON  0x00000800
#define GKM_MBUTTON  0x00001000
#define GKM_RBUTTON  0x00002000

#define GK_PGDN       1
#define GK_PGUP       2
#define GK_HOME       3
#define GK_END        4
#define GK_LEFT       5
#define GK_RIGHT      6
#define GK_ALERT      7
#define GK_BACKSPACE  8
#define GK_TAB        9
#define GK_LINEFEED  10
#define GK_DOWN      10
#define GK_VTAB      11
#define GK_UP        11
#define GK_FORMFEED  12
#define GK_RETURN    13
#define GK_F1        14
#define GK_F2        15
#define GK_F3        16
#define GK_F4        17
#define GK_F5        18
#define GK_F6        19
#define GK_F7        20
#define GK_F8        21
#define GK_F9        22
#define GK_F10       23
#define GK_F11       24
#define GK_F12       25
#define GK_DEL       26
#define GK_ESCAPE    27
#define GK_FREE1     28
#define GK_FREE2     29
#define GK_FREE3     30
#define GK_CESCAPE   31

#define CHANGELEVEL_KEEPFACING     0x00000001
#define CHANGELEVEL_RESETINVENTORY 0x00000002
#define CHANGELEVEL_NOMONSTERS     0x00000004
#define CHANGELEVEL_CHANGESKILL    0x00000008
#define CHANGELEVEL_NOINTERMISSION 0x00000010
#define CHANGELEVEL_RESETHEALTH    0x00000020
#define CHANGELEVEL_PRERAISEWEAPON 0x00000040

#define NO_CHANGE 32767.0k

#define SECF_SILENT          0x00000001
#define SECF_NOFALLINGDAMAGE 0x00000002
#define SECF_FLOORDROP       0x00000004
#define SECF_NORESPAWN       0x00000008

#define BLOCKF_CREATURES   0x00000001
#define BLOCKF_MONSTERS    0x00000002
#define BLOCKF_PLAYERS     0x00000004
#define BLOCKF_FLOATERS    0x00000008
#define BLOCKF_PROJECTILES 0x00000010
#define BLOCKF_EVERYTHING  0x00000020
#define BLOCKF_RAILING     0x00000040
#define BLOCKF_USE         0x00000080
#define BLOCKF_SIGHT       0x00000100
#define BLOCKF_HITSCAN     0x00000200

#define FOGP_DENSITY        0
#define FOGP_OUTSIDEDENSITY 1
#define FOGP_SKYFOG         2

#define PRINTNAME_LEVELNAME -1
#define PRINTNAME_LEVEL     -2
#define PRINTNAME_SKILL     -3

#define CSF_NOFAKEFLOORS 1
#define CSF_NOBLOCKALL   2

#define FHF_NORANDOMPUFFZ 1

#define MF_SPECIAL          0x00000001
#define MF_SOLID            0x00000002
#define MF_SHOOTABLE        0x00000004
#define MF_NOSECTOR         0x00000008
#define MF_NOBLOCKMAP       0x00000010
#define MF_AMBUSH           0x00000020
#define MF_JUSTHIT          0x00000040
#define MF_JUSTATTACKED     0x00000080
#define MF_SPAWNCEILING     0x00000100
#define MF_NOGRAVITY        0x00000200
#define MF_DROPOFF          0x00000400
#define MF_PICKUP           0x00000800
#define MF_NOCLIP           0x00001000
#define MF_INCHASE          0x00002000
#define MF_FLOAT            0x00004000
#define MF_TELEPORT         0x00008000
#define MF_MISSILE          0x00010000
#define MF_DROPPED          0x00020000
#define MF_SHADOW           0x00040000
#define MF_NOBLOOD          0x00080000
#define MF_CORPSE           0x00100000
#define MF_INFLOAT          0x00200000
#define MF_INBOUNCE         0x00200000
#define MF_COUNTKILL        0x00400000
#define MF_COUNTITEM        0x00800000
#define MF_SKULLFLY         0x01000000
#define MF_NOTDMATCH        0x02000000
#define MF_SPAWNSOUNDSOURCE 0x04000000
#define MF_FRIENDLY         0x08000000
#define MF_UNMORPHED        0x10000000
#define MF_NOLIFTDROP       0x20000000
#define MF_STEALTH          0x40000000
#define MF_ICECORPSE        0x80000000

#define ML_BLOCKING            0x00000001
#define ML_BLOCKMONSTERS       0x00000002
#define ML_TWOSIDED            0x00000004
#define ML_DONTPEGTOP          0x00000008
#define ML_DONTPEGBOTTOM       0x00000010
#define ML_SECRET              0x00000020
#define ML_SOUNDBLOCK          0x00000040
#define ML_DONTDRAW            0x00000080
#define ML_MAPPED              0x00000100
#define ML_REPEAT_SPECIAL      0x00000200
#define ML_ADDTRANS            0x00000400
#define ML_MONSTERSCANACTIVATE 0x00002000
#define ML_BLOCK_PLAYERS       0x00004000
#define ML_BLOCKEVERYTHING     0x00008000
#define ML_ZONEBOUNDARY        0x00010000
#define ML_RAILING             0x00020000
#define ML_BLOCK_FLOATERS      0x00040000
#define ML_CLIP_MIDTEX         0x00080000
#define ML_WRAP_MIDTEX         0x00100000
#define ML_3DMIDTEX            0x00200000
#define ML_CHECKSWITCHRANGE    0x00400000
#define ML_FIRSTSIDEONLY       0x00800000
#define ML_BLOCKPROJECTILE     0x01000000
#define ML_BLOCKUSE            0x02000000
#define ML_BLOCKSIGHT          0x04000000
#define ML_BLOCKHITSCAN        0x08000000

#endif//__GDCC_Header__C__ACS_ZDoom__defs_h__
