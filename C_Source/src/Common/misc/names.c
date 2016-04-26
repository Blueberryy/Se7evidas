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
#include "misc/names.h"

string NL_GenMaleNameEng () {
    int fore = Random (0, NL_Eng_Fore_Length - 1);
    int sur  = Random (0, NL_Eng_Sur_Length  - 1);

    for (int i = 0; i < 255; i++) {
        if (StrICmp (NL_Eng_Fore [fore], NL_Eng_Sur [sur]) == 0)
            sur = Random (0, NL_Eng_Sur_Length - 1);
        else
            break;
    }

    string ret = StrParam ("%S %S", NL_Eng_Fore [fore], NL_Eng_Sur [sur]);
    return ret;
}