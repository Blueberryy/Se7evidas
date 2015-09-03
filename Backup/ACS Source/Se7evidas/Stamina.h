#LIBDEFINE MAXSTAMINA 150

global int 3:S7_SR_StaminaEmpty [];

script "S7_StaminaRegeneration" ENTER {
    // Not needed or desired in TitleMaps.
    if (gameType () == game_Title_Map)
        terminate;
    
    int staminaTics = 0;
    int staminaAmount, health;
    
    while (TRUE) {
        staminaAmount = checkInventory ("S7_Stamina");
        health = getActorProperty (0, APROP_HEALTH);
        
        if (!CheckInventory ("S7_Dying") && staminaTics >= 1 && !checkWeapon ("S7_SprintWeapon")) {
            staminaTics = 0;
            giveInventory ("S7_Stamina", 1);
        }
        if (CheckInventory ("S7_Dying") && staminaTics >= 3 && !checkWeapon ("S7_SprintWeapon")) {
            staminaTics = 0;
            giveInventory ("S7_Stamina", 1);
        }
        if (staminaTics > 0 && staminaAmount == MAXSTAMINA || staminaTics > 0 && checkWeapon ("S7_SprintWeapon"))
            staminaTics = 0;            
        if (S7_SR_StaminaEmpty [PLN] == 1 && staminaAmount >= 50)
            S7_SR_StaminaEmpty [PLN] = 0;
        
        delay(1);
        if (staminaAmount != MAXSTAMINA)
            if (!checkWeapon ("S7_SprintWeapon"))
                staminaTics++;
    }
}