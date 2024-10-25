/*
* Copyright 2018 Wooting Technologies B.V.
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/
#pragma once

// Enum that can be used to easily get the scan code from a key. 
// TODO: Add array indexing to/from scan codes helpers

typedef enum SCAN_CODES {
	SCAN_Escape,
	SCAN_F1,
	SCAN_F2,
	SCAN_F3,
	SCAN_F4,
	SCAN_F5,
	SCAN_F6,
	SCAN_F7,
	SCAN_F8,
	SCAN_F9,
	SCAN_F10,
	SCAN_F11,
	SCAN_F12,
	SCAN_Printscreen,
	SCAN_Pause,
	SCAN_Mode,
	SCAN_Tilde,
	SCAN_Number1,
	SCAN_Number2,
	SCAN_Number3,
	SCAN_Number4,
	SCAN_Number5,
	SCAN_Number6,
	SCAN_Number7,
	SCAN_Number8,
	SCAN_Number9,
	SCAN_Number0,
	SCAN_Underscore,
	SCAN_Plus,
	SCAN_Backspace,
	SCAN_Insert,
	SCAN_Home,
	SCAN_Tab,
	SCAN_Q,
	SCAN_W,
	SCAN_E,
	SCAN_R,
	SCAN_T,
	SCAN_Y,
	SCAN_U,
	SCAN_I,
	SCAN_O,
	SCAN_P,
	SCAN_OpenBracket,
	SCAN_CloseBracket,
	SCAN_Backslash,
	SCAN_Delete,
	SCAN_End,
	SCAN_CapsLock,
	SCAN_A,
	SCAN_S,
	SCAN_D,
	SCAN_F,
	SCAN_G,
	SCAN_H,
	SCAN_J,
	SCAN_K,
	SCAN_L,
	SCAN_Colon,
	SCAN_Quote,
	SCAN_Enter,
	SCAN_PageUp,
	SCAN_PageDown,
	SCAN_Up,
	SCAN_ModifierLeftShift,
	SCAN_Z,
	SCAN_X,
	SCAN_C,
	SCAN_V,
	SCAN_B,
	SCAN_N,
	SCAN_M,
	SCAN_Comma,
	SCAN_Dot,
	SCAN_Slash,
	SCAN_ModifierRightShift,
	SCAN_Left,
	SCAN_Down,
	SCAN_Right,
	SCAN_ModifierRightCtrl,
	SCAN_ModifierLeftCtrl,
	SCAN_ModifierLeftUi,
	SCAN_ModifierLeftAlt,
	SCAN_Spacebar,
	SCAN_ModifierRightAlt,
	SCAN_ModifierRightUi,
	SCAN_FnKey,
	SCAN_ExtraIso,
	SCAN_Numpad1 = 90,
	SCAN_Numpad2,
	SCAN_Numpad3,
	SCAN_NumpadEnter,
	SCAN_NumpadDot,
	SCAN_Numpad0,
	SCAN_Numpad6,
	SCAN_Numpad5,
	SCAN_Numpad4,
	SCAN_NumpadPlus,
	SCAN_Numpad9,
	SCAN_Numpad8,
	SCAN_Numpad7,
	SCAN_NumpadMinus,
	SCAN_NumpadMultiply,
	SCAN_NumpadDivide,
	SCAN_NumLock,
	SCAN_A1,
	SCAN_A2,
	SCAN_A3,
	SCAN_FullsizeMode
} SCAN_CODES;