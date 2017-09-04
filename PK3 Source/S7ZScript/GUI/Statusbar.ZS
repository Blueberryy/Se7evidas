class Se7evidasStatusBar : BaseStatusBar {
    // Fonts
    HUDFont mNormalHUDFont;
    HUDFont mFscreenHUDFont;
    // Interpolators
    DynamicValueInterpolator mHealthInterpolator;
    DynamicValueInterpolator mArmorInterpolator;
    DynamicValueInterpolator mStaminInterpolator;
    DynamicValueInterpolator mCashInterpolator;
    DynamicValueInterpolator mLsrRfInterpolator;
    DynamicValueInterpolator mLPPInterpolator1;
    DynamicValueInterpolator mLPPInterpolator2;
    // Misc
    InventoryBarState diparms;
    Array<S7_FScreenSBarAmmoBar> FScreenAmmoBars;

    override void Init () {
        // Initialize the statusbar
        Super.Init ();
        SetSize (0, 320, 200);
        fullscreenOffsets = true;

        // Initialize the fonts
        Font fnt = "S7HUDFONT";
        mNormalHUDFont = HUDFont.Create (fnt, fnt.GetCharWidth ("0"), true, 1, 1);
        fnt = "S7FSHUDFNT.lmp";
        mFscreenHUDFont = HUDFont.Create (fnt, 0, false, 1, 1);
        // Initialize the interpolators
        mHealthInterpolator = DynamicValueInterpolator.Create (0, 0.25, 1, 8);
        mArmorInterpolator  = DynamicValueInterpolator.Create (0, 0.25, 1, 8);
        mStaminInterpolator = DynamicValueInterpolator.Create (0, 0.25, 1, 8);
        mCashInterpolator   = DynamicValueInterpolator.Create (0, 0.25, 1, 65536);
        mLsrRfInterpolator = DynamicValueInterpolator.Create (0, 0.25, 1, 25);
        mLPPInterpolator1  = DynamicValueInterpolator.Create (0, 0.25, 1, 25);
        mLPPInterpolator2  = DynamicValueInterpolator.Create (0, 0.25, 1, 25);
        // Initialize the inventory bar
        diparms = InventoryBarState.Create ();
        // Populate the fullscreen statusbar ammo bars list
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_Raptor", "S7_RaptorClip", "Inventory", 16, "graphics/HUD/Cartridges/S7H9MM.png", -10, -5, -20, -18));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_TEC9", "S7_TEC9Clip", "Inventory", 32, "graphics/HUD/Cartridges/S7H9MM.png", -10, -4, -20, -18));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_Revolver", "S7_RevolverClip", "Inventory", 6, "graphics/HUD/Cartridges/S7H44M.png", -11, -7, -23));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_AMG", "S7_AMGMag", "Inventory", 35, "graphics/HUD/Cartridges/S7H762MM.png", -11, -4, -27, -26, -25));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_ManxCarbine", "S7_ManxCarbineClip", "Inventory", 23, "graphics/HUD/Cartridges/S7H9MM.png", -10, -4, -20, -18));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_Shotgun", "S7_ShotgunMag", "Inventory", 10, "graphics/HUD/Cartridges/S7H20GA.png", -16, -8, -32, -31));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_HitterSMG", "S7_HitterSMGClip", "Inventory", 62, "graphics/HUD/Cartridges/S7H45ACP.png", -10, -2, -20, -19, -18));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_GrenadeWeap", "S7_GrenadeCount", "Inventory", 15, "graphics/HUD/Throwables/S7TGRICN.png", -15, -8, -22, -24));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_ConquerorRifle", "S7_ConquerorRifleClip", "Inventory", 15, "graphics/HUD/Cartridges/S7H45WW.png", -14, -7, -43, -41));
        FScreenAmmoBars.Push (S7_FScreenSBarAmmoBar.GenerateBar ("S7_AK47", "S7_AK47Clip", "Inventory", 30, "graphics/HUD/Cartridges/S7H762MM.png", -11, -4, -27, -26));
    }

    override void NewGame () {
        Super.NewGame();

        mHealthInterpolator.Reset (0);
        mArmorInterpolator.Reset  (0);
        mStaminInterpolator.Reset (0);
        mCashInterpolator.Reset   (0);
        mLsrRfInterpolator.Reset (0);
        mLPPInterpolator1.Reset  (0);
        mLPPInterpolator2.Reset  (0);
    }

    override void Tick () {
        super.Tick ();

        mHealthInterpolator.Update (CPlayer.health);
        mArmorInterpolator.Update  (GetArmorAmount ());
        mStaminInterpolator.Update (GetAmount ("S7_Stamina"));
        mCashInterpolator.Update   (GetAmount ("S7_CashCounter"));
        mLsrRfInterpolator.Update (GetAmount ("S7_FauchardMag"));
        mLPPInterpolator1.Update  (GetAmount ("S7_LaserPewPewClip"));
        mLPPInterpolator2.Update  (GetAmount ("S7_LaserPewPewClipSecond"));
    }

    override void Draw (int state, double TicFrac) {
        Super.Draw (state, TicFrac);

        if (CPlayer == null)
            return;

        if (state == HUD_StatusBar) {
            BeginHUD (1.0, true, 320, 200);
            DrawMainBar (TicFrac);
        } else if (state == HUD_Fullscreen) {
            BeginHUD (1.0, false, 320, 200);
            DrawFullScreenBar (TicFrac);
        }
    }

    protected void DrawMainBar (double TicFrac) {
        DrawImage ("HELMTOP", (0, 0), DI_ITEM_TOP | DI_SCREEN_HCENTER);
        DrawImage ("HELMBTML", (0, 0), DI_ITEM_LEFT_BOTTOM | DI_SCREEN_LEFT_BOTTOM);
        DrawImage ("HELMBTMR", (0, 0), DI_ITEM_RIGHT_BOTTOM | DI_SCREEN_RIGHT_BOTTOM);
        if (!CheckInventory ("S7_DisableHud", 1)) {
            alpha = 0.75;

            DrawImage ("graphics/HUD/Normal/HOLOBARSNONE.png", (0, 27), DI_ITEM_TOP | DI_SCREEN_HCENTER);

            string energyImg;
            if (CheckHealth (75, true))
                energyImg = "graphics/HUD/Normal/HOLOBARSGREEN.png";
            else if (CheckHealth (50, true))
                energyImg = "graphics/HUD/Normal/HOLOBARSYELLOW.png";
            else if (CheckHealth (25, true))
                energyImg = "graphics/HUD/Normal/HOLOBARSORANGE.png";
            else
                energyImg = "graphics/HUD/Normal/HOLOBARSRED.png";
            DrawImage (energyImg, (0, 29), DI_ITEM_TOP | DI_SCREEN_HCENTER);

            // Draw health/armor bars
            DrawBar ("HOLOBR00", "HOLOBR01", mHealthInterpolator.GetValue (), CPlayer.mo.GetMaxHealth (true), (0, 36), 0, 0, DI_ITEM_TOP | DI_SCREEN_HCENTER);
            DrawBar ("HOLOBR10", "HOLOBR01", mArmorInterpolator.GetValue (), GetMaxAmount ("BasicArmor"), (0, 41), 0, 0, DI_ITEM_TOP | DI_SCREEN_HCENTER);
            // Draw health/armor numbers
            DrawString (mNormalHUDFont, FormatNumber (mHealthInterpolator.GetValue (), 1, 3), (-33, 50), DI_SCREEN_HCENTER | DI_NOSHADOW, Font.FindFontColor ("HUD_Health"));
            DrawString (mNormalHUDFont, FormatNumber (mArmorInterpolator.GetValue (), 1, 3), (33, 50), DI_TEXT_ALIGN_RIGHT | DI_SCREEN_HCENTER | DI_NOSHADOW, Font.FindFontColor ("HUD_Armour"));
        }
    }

    protected void DrawFullScreenBar (double TicFrac) {
        // Icons
        DrawImage ("graphics/HUD/Fullscreen/S7HLTH.png", (11,  -7), DI_ITEM_LEFT_BOTTOM);
        DrawImage ("graphics/HUD/Fullscreen/S7ARMR.png", (11, -25), DI_ITEM_LEFT_BOTTOM);
        DrawImage ("graphics/HUD/Fullscreen/S7STMN.png", (11, -42), DI_ITEM_LEFT_BOTTOM);
        // Bar frames
        DrawImage ("graphics/HUD/Fullscreen/S7BARFR0.png", (28, -12), DI_ITEM_LEFT_BOTTOM);
        DrawImage ("graphics/HUD/Fullscreen/S7BARFR0.png", (28, -30), DI_ITEM_LEFT_BOTTOM);
        DrawImage ("graphics/HUD/Fullscreen/S7BARFR0.png", (28, -47), DI_ITEM_LEFT_BOTTOM);
        // Bars
        DrawBar ("graphics/HUD/Fullscreen/S7HLTHBR.png", "S7BARBK0", mHealthInterpolator.GetValue (), CPlayer.mo.GetMaxHealth (true), (29, -13), 0, 0, DI_ITEM_LEFT_BOTTOM);
        DrawBar ("graphics/HUD/Fullscreen/S7ARMRBR.png", "S7BARBK0", mArmorInterpolator.GetValue  (), GetMaxAmount ("BasicArmor"),    (29, -31), 0, 0, DI_ITEM_LEFT_BOTTOM);
        DrawBar ("graphics/HUD/Fullscreen/S7STMNBR.png", "S7BARBK0", mStaminInterpolator.GetValue (), GetMaxAmount ("S7_Stamina"),    (29, -48), 0, 0, DI_ITEM_LEFT_BOTTOM);
        // Strings
        DrawString (mFScreenHUDFont, "Cash: ", (11, -66), DI_TEXT_ALIGN_LEFT | DI_NOSHADOW, Font.CR_WHITE);
        // Numbers
        DrawString (mFScreenHUDFont, FormatNumber (mHealthInterpolator.GetValue (), 1,  5), (81, -18), DI_TEXT_ALIGN_LEFT  | DI_NOSHADOW, Font.CR_WHITE);
        DrawString (mFScreenHUDFont, FormatNumber (mArmorInterpolator.GetValue  (), 1,  5), (81, -36), DI_TEXT_ALIGN_LEFT  | DI_NOSHADOW, Font.CR_WHITE);
        DrawString (mFScreenHUDFont, FormatNumber (mStaminInterpolator.GetValue (), 1,  5), (81, -53), DI_TEXT_ALIGN_LEFT  | DI_NOSHADOW, Font.CR_WHITE);
        DrawString (mFScreenHUDFont, FormatNumber (mCashInterpolator.GetValue   (), 1, 10), (77, -66), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
        // Selected inv
        if (CPlayer.mo.InvSel != null) {
            DrawInventoryIcon (CPlayer.mo.InvSel, (24, -70));
            DrawString (mFscreenHUDFont, FormatNumber (CPlayer.mo.InvSel.Amount), (37, -76), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
        }

        // Ammo bars
        if (CPlayer.ReadyWeapon != null) {
            if (CheckWeaponSelected ("S7_SSG")) {
                // Draw ammo pool count
                DrawString (mFScreenHUDFont, "Pool:      ", (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                DrawString (mFScreenHUDFont, FormatNumber (GetAmount (CPlayer.ReadyWeapon.AmmoType2), 1, 5), (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                // Draw shells
                if (CheckInventory ("S7_SSGRightLoadedToken", 1)) DrawImage ("graphics/HUD/Cartridges/S7H12GA.png", (-17, -29), DI_ITEM_LEFT_TOP);
                if (CheckInventory ("S7_SSGLeftLoadedToken",  1)) DrawImage ("graphics/HUD/Cartridges/S7H12GA.png", (-31, -29), DI_ITEM_LEFT_TOP);
            } else if (CheckWeaponSelected ("S7_Fauchard")) {
                // Draw ammo pool count
                DrawString (mFScreenHUDFont, "Pool:      ", (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                DrawString (mFScreenHUDFont, FormatNumber (GetAmount (CPlayer.ReadyWeapon.AmmoType2), 1, 5), (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                // Draw ammo bar
                DrawBar ("graphics/HUD/Fullscreen/S7LRABFG.png", "graphics/HUD/Fullscreen/S7LRABBG.png",
                    mLsrRfInterpolator.GetValue (), GetMaxAmount ("S7_FauchardMag"), (-5, -5), 0, SHADER_REVERSE, DI_ITEM_RIGHT_BOTTOM);
            } else if (CheckWeaponSelected ("S7_LaserPewPew")) {
                // Draw ammo pool count
                DrawString (mFScreenHUDFont, "Pool:      ", (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                DrawString (mFScreenHUDFont, FormatNumber (GetAmount (CPlayer.ReadyWeapon.AmmoType2), 1, 5), (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                // Draw ammo bar(s)
                let lppWeap = S7_LaserPewPew (CPlayer.ReadyWeapon);
                if (CheckInventory ("S7_LaserPewPewSecond", 1) && lppWeap.akimbo) {
                    DrawBar ("S7LPPDFG", "S7LPPDBG", mLPPInterpolator1.GetValue (), GetMaxAmount ("S7_LaserPewPewClip"), (-5, -5), 0, SHADER_REVERSE, DI_ITEM_RIGHT_BOTTOM);
                    DrawBar ("S7LPPDFG", "S7LPPDBG", mLPPInterpolator2.GetValue (), GetMaxAmount ("S7_LaserPewPewClipSecond"), (-5, -23), 0, SHADER_REVERSE, DI_ITEM_RIGHT_BOTTOM);
                } else {
                    DrawBar ("graphics/HUD/Fullscreen/S7LRABFG.png", "graphics/HUD/Fullscreen/S7LRABBG.png",
                        mLPPInterpolator1.GetValue (), GetMaxAmount ("S7_LaserPewPewClip"), (-5, -5), 0, SHADER_REVERSE, DI_ITEM_RIGHT_BOTTOM);
                }
            } else if (CheckWeaponSelected ("S7_Thumper")) {
                static const string ThumperGrenNames [] = { "", "Explosive", "Fragmentation", "Incendiary", "Flare", "Clusterbomb", "Nailbomb", "Nerve Gas" };
                static const int ThumperGrenColors [] = { Font.CR_WHITE, Font.CR_ORANGE, Font.CR_GREEN, Font.CR_DARKRED, Font.CR_WHITE, Font.CR_BLUE, Font.CR_YELLOW, Font.CR_BLACK };
                // Draw ammo pools count
                DrawString (mFScreenHUDFont, "Pool:      ", (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                DrawString (mFScreenHUDFont, FormatNumber (GetAmount ("S7_Thumper_PUnified"), 1, 5), (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);

                for (int i = 1; i < ThumperGrenNames.Size (); i++) {
                    bool selected = GetAmount ("S7_ThumperSelectedPool") == (i - 1);
                    string poolText = String.Format (selected ? ">%s:      " : "%s:      ", ThumperGrenNames [i]);
                    int colour = (selected ? Font.CR_RED : ThumperGrenColors [i]);
                    DrawString (mFScreenHUDFont, poolText, (-6, -50 - (7 * (8-i))), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, colour);
                    DrawString (mFScreenHUDFont, FormatNumber (GetAmount (S7_Thumper.PoolNames [i]), 1, 5), (-6, -50 - (7 * (8-i))), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, colour);
                }
                for (int i = 0; i < 5; i++) {
                    int grenType = GetAmount (String.Format ("S7_ThumperMag%d", i + 1));
                    if (grenType == S7_TH_None)
                        continue;

                    DrawImage ("graphics/HUD/Cartridges/S7H50M0.png", (-26 - 22 * i, -43), DI_ITEM_LEFT_TOP);
                    DrawImage (String.Format ("graphics/HUD/Cartridges/S7H50M%d.png", grenType), (-26 - 22 * i, -17), DI_ITEM_LEFT_TOP);
                }
            } else {
                for (int i = 0; i < FScreenAmmoBars.Size (); i++) {
                    if (CheckWeaponSelected (FScreenAmmoBars [i].weap)) {
                        let bar = FScreenAmmoBars [i];

                        // Draw ammo pool count
                        int poolAmount = -1;
                        if (bar.poolType == "Inventory" && CPlayer.ReadyWeapon.AmmoType2 != null)
                            poolAmount = GetAmount (CPlayer.ReadyWeapon.AmmoType2);
                        else if (bar.poolType != "Inventory" && bar.poolType != null)
                            GetAmount (bar.poolType);

                        if (poolAmount >= 0) {
                            DrawString (mFScreenHUDFont, "Pool:      ", (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                            DrawString (mFScreenHUDFont, FormatNumber (poolAmount, 1, 5), (-6, -50), DI_TEXT_ALIGN_RIGHT | DI_NOSHADOW, Font.CR_WHITE);
                        }

                        // Draw in-mag count
                        int maxX = min (bar.xPositions.Size (), GetAmount (bar.magType));
                        for (int x = 0; x < maxX; x++)
                            DrawImage (bar.sprite, (bar.xPositions [x], bar.yPositions [x]), DI_ITEM_LEFT_TOP);

                        break;
                    }
                }
            }
        }
    }
}