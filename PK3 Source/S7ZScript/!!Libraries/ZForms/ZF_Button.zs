class S7_ZF_Button : S7_ZF_Element {
	enum ButtonState {
		ButtonState_Inactive,
		ButtonState_Hover,
		ButtonState_Click,
		ButtonState_Disabled
	}

	Font fnt;
	string text;
	int textColor;
	double textScale;

	S7_ZF_BoxTextures textures[4];
	string btnTextures [4];
	bool singleTex;

	int holdTicInterval;
	int currentHoldTicsRemaining;

	ButtonState curButtonState;

	Vector2 mousePos;

	void setTexture(string inactive, string hover, string click, string disabled) {
		self.btnTextures[ButtonState_Inactive] = inactive;
		self.btnTextures[ButtonState_Hover] = hover;
		self.btnTextures[ButtonState_Click] = click;
		self.btnTextures[ButtonState_Disabled] = disabled;
		self.singleTex = true;
	}

	void config(string text = "", S7_ZF_Handler cmdHandler = NULL, string command = "",
	            S7_ZF_BoxTextures inactive = NULL, S7_ZF_BoxTextures hover = NULL,
	            S7_ZF_BoxTextures click = NULL, S7_ZF_BoxTextures disabled = NULL,
	            Font fnt = NULL, double textScale = 1, int textColor = Font.CR_WHITE, int holdInterval = -1) {
		if (fnt == NULL) {
			self.fnt = smallfont;
		}
		else {
			self.fnt = fnt;
		}
		self.cmdHandler = cmdHandler;
		self.command = command;
		self.holdTicInterval = holdInterval;
		self.text = text;
		self.textScale = textScale;
		self.textures[ButtonState_Inactive] = inactive;
		self.textures[ButtonState_Hover] = hover;
		self.textures[ButtonState_Click] = click;
		self.textures[ButtonState_Disabled] = disabled;
		self.singleTex = false;
		self.textColor = textColor;
	}

	S7_ZF_Button init(Vector2 pos, Vector2 size, string text = "", S7_ZF_Handler cmdHandler = NULL, string command = "",
	               S7_ZF_BoxTextures inactive = NULL, S7_ZF_BoxTextures hover = NULL, S7_ZF_BoxTextures click = NULL,
	               S7_ZF_BoxTextures disabled = NULL, Font fnt = NULL, double textScale = 1, int textColor = Font.CR_WHITE, int holdInterval = -1) {
		self.config(text, cmdHandler, command, inactive, hover, click, disabled, fnt, textScale, textColor, holdInterval);
		self.setBox(pos, size);

		return self;
	}

	override void ticker() {
		if (!isEnabled() || holdTicInterval == -1) {
			currentHoldTicsRemaining = 0;
			return;
		}

		if (curButtonState == ButtonState_Click && currentHoldTicsRemaining <= 0) {
			if (cmdHandler) {
				cmdHandler.buttonHeldCommand(self, command);
			}
			currentHoldTicsRemaining = holdTicInterval;
		}
		else if (curButtonState == ButtonState_Click && currentHoldTicsRemaining > 0) {
			currentHoldTicsRemaining--;
		}
		else if (curButtonState != ButtonState_Click && currentHoldTicsRemaining != 0) {
			currentHoldTicsRemaining = 0;
		}
	}

	override void drawer() {
		if (!isShown()) {
			return;
		}

		if (singleTex) {
			string texture = btnTextures[curButtonState];
			drawTiledImage((0, 0), box.size, texture);
		}
		else {
			S7_ZF_BoxTextures textures = textures[curButtonState];
			drawBox((0, 0), box.size, textures);
		}

		// draw the text in the middle of the button
		Vector2 textSize = (fnt.stringWidth(text), fnt.getHeight()) * textScale;
		Vector2 textPos = (box.size - textSize) / 2;
		drawText(textPos, fnt, text, textColor, textScale);
	}

	override void onUIEvent(UIEvent ev) {
		// if the player's clicked, and their mouse is in the right place, set the state accordingly
		if (ev.type == UIEvent.Type_LButtonDown) {
			if (isEnabled() && boxToScreen().pointCollides(mousePos)) {
				if (cmdHandler && holdTicInterval >= 0) {
					cmdHandler.buttonClickCommand(self, command);
					currentHoldTicsRemaining = holdTicInterval;
				}
				curButtonState = ButtonState_Click;
			}
		}
		// if the player's releasing, check if their mouse is still in the correct range and trigger method if it was
		else if (ev.type == UIEvent.Type_LButtonUp) {
			if (!isEnabled()) {
				curButtonState = ButtonState_Disabled;
			}
			else if (boxToScreen().pointCollides(mousePos) && curButtonState == ButtonState_Click) {
				if (cmdHandler && holdTicInterval == -1) {
					cmdHandler.buttonClickCommand(self, command);
				}

				curButtonState = ButtonState_Hover;
			}
			else {
				curButtonState = ButtonState_Inactive;
			}
		}
		// if the player's mouse has moved, update the tracked position and do a quick hover check
		else if (ev.type == UIEvent.Type_MouseMove) {
			mousePos = (ev.mouseX, ev.mouseY);
			if (!isEnabled()) {
				curButtonState = ButtonState_Disabled;
			}
			else if (curButtonState != ButtonState_Click) {
				if (boxToScreen().pointCollides(mousePos)) {
					curButtonState = ButtonState_Hover;
				}
				else {
					curButtonState = ButtonState_Inactive;
				}
			}
			doHover(mousePos);
		}
	}
}