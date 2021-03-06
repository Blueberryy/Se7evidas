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

// Casing sprites by Captain J. Edited by Chronos "phantombeta" Ouroboros

// Explosive/Normal
class S7_50mmCasingSpawn : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasing', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasing : S7_CasingBase {
    default {
        SeeSound "Weapons/shell";
        Scale .2;
    }

    states {
    Spawn:
        C501 HABCDEFG 2;
        loop;
    }
}

// Fragmentation
class S7_50mmCasingSpawnFrag : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasingFrag', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasingFrag : S7_50mmCasing {
    states {
    Spawn:
        C502 HABCDEFG 2;
        loop;
    }
}

// Thermite
class S7_50mmCasingSpawnTherm : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasingTherm', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasingTherm : S7_50mmCasing {
    states {
    Spawn:
        C503 HABCDEFG 2;
        loop;
    }
}

// Flare
class S7_50mmCasingSpawnFlare : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasingFlare', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasingFlare : S7_50mmCasing {
    states {
    Spawn:
        C504 HABCDEFG 2;
        loop;
    }
}

// Clusterbomb
class S7_50mmCasingSpawnCluster : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasingCluster', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasingCluster : S7_50mmCasing {
    states {
    Spawn:
        C505 HABCDEFG 2;
        loop;
    }
}

// Nailbomb
class S7_50mmCasingSpawnNail : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasingNail', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasingNail : S7_50mmCasing {
    states {
    Spawn:
        C506 HABCDEFG 2;
        loop;
    }
}

// Nerve Gas
class S7_50mmCasingSpawnNGas : S7_CasingSpawnerBase {
    states {
    Spawn:
        TNT1 A 0 noDelay A_SpawnProjectile ('S7_50mmCasingNGas', 0, 0, random [CasingsRNG] (-80, -100), 2, random [CasingsRNG] (-20, 0));
        stop;
    }
}

class S7_50mmCasingNGas : S7_50mmCasing {
    states {
    Spawn:
        C507 HABCDEFG 2;
        loop;
    }
}