#ifndef KEY_EVENT_HPP
#define KEY_EVENT_HPP

#include "string.hpp"
#include <SDL2/SDL.h>

enum VirtKey {
    VirtKeyReturn = SDLK_RETURN,
    VirtKeyEscape = SDLK_ESCAPE,
    VirtKeyBackspace = SDLK_BACKSPACE,
    VirtKeyTab = SDLK_TAB,
    VirtKeySpace = SDLK_SPACE,
    VirtKeyExclaim = SDLK_EXCLAIM,
    VirtKeyQuoteDbl = SDLK_QUOTEDBL,
    VirtKeyHash = SDLK_HASH,
    VirtKeyPercent = SDLK_PERCENT,
    VirtKeyDollar = SDLK_DOLLAR,
    VirtKeyAmpersand = SDLK_AMPERSAND,
    VirtKeyQuote = SDLK_QUOTE,
    VirtKeyLeftParen = SDLK_LEFTPAREN,
    VirtKeyRightParen = SDLK_RIGHTPAREN,
    VirtKeyAsterisk = SDLK_ASTERISK,
    VirtKeyPlus = SDLK_PLUS,
    VirtKeyComma = SDLK_COMMA,
    VirtKeyMinus = SDLK_MINUS,
    VirtKeyPeriod = SDLK_PERIOD,
    VirtKeySlash = SDLK_SLASH,
    VirtKey0 = SDLK_0,
    VirtKey1 = SDLK_1,
    VirtKey2 = SDLK_2,
    VirtKey3 = SDLK_3,
    VirtKey4 = SDLK_4,
    VirtKey5 = SDLK_5,
    VirtKey6 = SDLK_6,
    VirtKey7 = SDLK_7,
    VirtKey8 = SDLK_8,
    VirtKey9 = SDLK_9,
    VirtKeyColon = SDLK_COLON,
    VirtKeySemicolon = SDLK_SEMICOLON,
    VirtKeyLess = SDLK_LESS,
    VirtKeyEquals = SDLK_EQUALS,
    VirtKeyGreater = SDLK_GREATER,
    VirtKeyQuestion = SDLK_QUESTION,
    VirtKeyAt = SDLK_AT,
    VirtKeyLeftBracket = SDLK_LEFTBRACKET,
    VirtKeyBackslash = SDLK_BACKSLASH,
    VirtKeyRightBracket = SDLK_RIGHTBRACKET,
    VirtKeyCaret = SDLK_CARET,
    VirtKeyUnderscore = SDLK_UNDERSCORE,
    VirtKeyBackquote = SDLK_BACKQUOTE,
    VirtKeyA = SDLK_a,
    VirtKeyB = SDLK_b,
    VirtKeyC = SDLK_c,
    VirtKeyD = SDLK_d,
    VirtKeyE = SDLK_e,
    VirtKeyF = SDLK_f,
    VirtKeyG = SDLK_g,
    VirtKeyH = SDLK_h,
    VirtKeyI = SDLK_i,
    VirtKeyJ = SDLK_j,
    VirtKeyK = SDLK_k,
    VirtKeyL = SDLK_l,
    VirtKeyM = SDLK_m,
    VirtKeyN = SDLK_n,
    VirtKeyO = SDLK_o,
    VirtKeyP = SDLK_p,
    VirtKeyQ = SDLK_q,
    VirtKeyR = SDLK_r,
    VirtKeyS = SDLK_s,
    VirtKeyT = SDLK_t,
    VirtKeyU = SDLK_u,
    VirtKeyV = SDLK_v,
    VirtKeyW = SDLK_w,
    VirtKeyX = SDLK_x,
    VirtKeyY = SDLK_y,
    VirtKeyZ = SDLK_z,
    VirtKeyCapsLock = SDLK_CAPSLOCK,
    VirtKeyF1 = SDLK_F1,
    VirtKeyF2 = SDLK_F2,
    VirtKeyF3 = SDLK_F3,
    VirtKeyF4 = SDLK_F4,
    VirtKeyF5 = SDLK_F5,
    VirtKeyF6 = SDLK_F6,
    VirtKeyF7 = SDLK_F7,
    VirtKeyF8 = SDLK_F8,
    VirtKeyF9 = SDLK_F9,
    VirtKeyF10 = SDLK_F10,
    VirtKeyF11 = SDLK_F11,
    VirtKeyF12 = SDLK_F12,
    VirtKeyPrintScreen = SDLK_PRINTSCREEN,
    VirtKeyScrollLock = SDLK_SCROLLLOCK,
    VirtKeyPause = SDLK_PAUSE,
    VirtKeyInsert = SDLK_INSERT,
    VirtKeyHome = SDLK_HOME,
    VirtKeyPageUp = SDLK_PAGEUP,
    VirtKeyDelete = SDLK_DELETE,
    VirtKeyEnd = SDLK_END,
    VirtKeyPageDown = SDLK_PAGEDOWN,
    VirtKeyRight = SDLK_RIGHT,
    VirtKeyLeft = SDLK_LEFT,
    VirtKeyDown = SDLK_DOWN,
    VirtKeyUp = SDLK_UP,
    VirtKeyNumLockClear = SDLK_NUMLOCKCLEAR,
    VirtKeyKp_Divide = SDLK_KP_DIVIDE,
    VirtKeyKp_Multiply = SDLK_KP_MULTIPLY,
    VirtKeyKp_Minus = SDLK_KP_MINUS,
    VirtKeyKp_Plus = SDLK_KP_PLUS,
    VirtKeyKp_Enter = SDLK_KP_ENTER,
    VirtKeyKp_1 = SDLK_KP_1,
    VirtKeyKp_2 = SDLK_KP_2,
    VirtKeyKp_3 = SDLK_KP_3,
    VirtKeyKp_4 = SDLK_KP_4,
    VirtKeyKp_5 = SDLK_KP_5,
    VirtKeyKp_6 = SDLK_KP_6,
    VirtKeyKp_7 = SDLK_KP_7,
    VirtKeyKp_8 = SDLK_KP_8,
    VirtKeyKp_9 = SDLK_KP_9,
    VirtKeyKp_0 = SDLK_KP_0,
    VirtKeyKp_Period = SDLK_KP_PERIOD,
    VirtKeyApplication = SDLK_APPLICATION,
    VirtKeyPower = SDLK_POWER,
    VirtKeyKp_Equals = SDLK_KP_EQUALS,
    VirtKeyF13 = SDLK_F13,
    VirtKeyF14 = SDLK_F14,
    VirtKeyF15 = SDLK_F15,
    VirtKeyF16 = SDLK_F16,
    VirtKeyF17 = SDLK_F17,
    VirtKeyF18 = SDLK_F18,
    VirtKeyF19 = SDLK_F19,
    VirtKeyF20 = SDLK_F20,
    VirtKeyF21 = SDLK_F21,
    VirtKeyF22 = SDLK_F22,
    VirtKeyF23 = SDLK_F23,
    VirtKeyF24 = SDLK_F24,
    VirtKeyExecute = SDLK_EXECUTE,
    VirtKeyHelp = SDLK_HELP,
    VirtKeyMenu = SDLK_MENU,
    VirtKeySelect = SDLK_SELECT,
    VirtKeyStop = SDLK_STOP,
    VirtKeyAgain = SDLK_AGAIN,
    VirtKeyUndo = SDLK_UNDO,
    VirtKeyCut = SDLK_CUT,
    VirtKeyCopy = SDLK_COPY,
    VirtKeyPaste = SDLK_PASTE,
    VirtKeyFind = SDLK_FIND,
    VirtKeyMute = SDLK_MUTE,
    VirtKeyVolumeUp = SDLK_VOLUMEUP,
    VirtKeyVolumeDown = SDLK_VOLUMEDOWN,
    VirtKeyKp_Comma = SDLK_KP_COMMA,
    VirtKeyKp_EqualsAs400 = SDLK_KP_EQUALSAS400,
    VirtKeyAltErase = SDLK_ALTERASE,
    VirtKeySysReq = SDLK_SYSREQ,
    VirtKeyCancel = SDLK_CANCEL,
    VirtKeyClear = SDLK_CLEAR,
    VirtKeyPrior = SDLK_PRIOR,
    VirtKeyReturn2 = SDLK_RETURN2,
    VirtKeySeparator = SDLK_SEPARATOR,
    VirtKeyOut = SDLK_OUT,
    VirtKeyOper = SDLK_OPER,
    VirtKeyClearAgain = SDLK_CLEARAGAIN,
    VirtKeyCrsel = SDLK_CRSEL,
    VirtKeyExsel = SDLK_EXSEL,
    VirtKeyKp_00 = SDLK_KP_00,
    VirtKeyKp_000 = SDLK_KP_000,
    VirtKeyThousandsSeparator = SDLK_THOUSANDSSEPARATOR,
    VirtKeyDecimalSeparator = SDLK_DECIMALSEPARATOR,
    VirtKeyCurrencyUnit = SDLK_CURRENCYUNIT,
    VirtKeyCurrencySubunit = SDLK_CURRENCYSUBUNIT,
    VirtKeyKp_LeftParen = SDLK_KP_LEFTPAREN,
    VirtKeyKp_RightParen = SDLK_KP_RIGHTPAREN,
    VirtKeyKp_LeftBrace = SDLK_KP_LEFTBRACE,
    VirtKeyKp_RightBrace = SDLK_KP_RIGHTBRACE,
    VirtKeyKp_Tab = SDLK_KP_TAB,
    VirtKeyKp_Backspace = SDLK_KP_BACKSPACE,
    VirtKeyKp_A = SDLK_KP_A,
    VirtKeyKp_B = SDLK_KP_B,
    VirtKeyKp_C = SDLK_KP_C,
    VirtKeyKp_D = SDLK_KP_D,
    VirtKeyKp_E = SDLK_KP_E,
    VirtKeyKp_F = SDLK_KP_F,
    VirtKeyKp_Xor = SDLK_KP_XOR,
    VirtKeyKp_Power = SDLK_KP_POWER,
    VirtKeyKp_Percent = SDLK_KP_PERCENT,
    VirtKeyKp_Less = SDLK_KP_LESS,
    VirtKeyKp_Greater = SDLK_KP_GREATER,
    VirtKeyKp_Ampersand = SDLK_KP_AMPERSAND,
    VirtKeyKp_DblAmpersand = SDLK_KP_DBLAMPERSAND,
    VirtKeyKp_VerticalBar = SDLK_KP_VERTICALBAR,
    VirtKeyKp_DblVerticalBar = SDLK_KP_DBLVERTICALBAR,
    VirtKeyKp_Colon = SDLK_KP_COLON,
    VirtKeyKp_Hash = SDLK_KP_HASH,
    VirtKeyKp_Space = SDLK_KP_SPACE,
    VirtKeyKp_At = SDLK_KP_AT,
    VirtKeyKp_Exclam = SDLK_KP_EXCLAM,
    VirtKeyKp_MemStore = SDLK_KP_MEMSTORE,
    VirtKeyKp_MemRecall = SDLK_KP_MEMRECALL,
    VirtKeyKp_MemClear = SDLK_KP_MEMCLEAR,
    VirtKeyKp_MemAdd = SDLK_KP_MEMADD,
    VirtKeyKp_MemSubtract = SDLK_KP_MEMSUBTRACT,
    VirtKeyKp_MemMultiply = SDLK_KP_MEMMULTIPLY,
    VirtKeyKp_MemDivide = SDLK_KP_MEMDIVIDE,
    VirtKeyKp_PlusMinus = SDLK_KP_PLUSMINUS,
    VirtKeyKp_Clear = SDLK_KP_CLEAR,
    VirtKeyKp_ClearEntry = SDLK_KP_CLEARENTRY,
    VirtKeyKp_Binary = SDLK_KP_BINARY,
    VirtKeyKp_Octal = SDLK_KP_OCTAL,
    VirtKeyKp_Decimal = SDLK_KP_DECIMAL,
    VirtKeyKp_Hexadecimal = SDLK_KP_HEXADECIMAL,
    VirtKeyLCtrl = SDLK_LCTRL,
    VirtKeyLShift = SDLK_LSHIFT,
    VirtKeyLAlt = SDLK_LALT,
    VirtKeyLGui = SDLK_LGUI,
    VirtKeyRCtrl = SDLK_RCTRL,
    VirtKeyRShift = SDLK_RSHIFT,
    VirtKeyRAlt = SDLK_RALT,
    VirtKeyRGui = SDLK_RGUI,
    VirtKeyMode = SDLK_MODE,
    VirtKeyAudioNext = SDLK_AUDIONEXT,
    VirtKeyAudioPrev = SDLK_AUDIOPREV,
    VirtKeyAudioStop = SDLK_AUDIOSTOP,
    VirtKeyAudioPlay = SDLK_AUDIOPLAY,
    VirtKeyAudioMute = SDLK_AUDIOMUTE,
    VirtKeyMediaSelect = SDLK_MEDIASELECT,
    VirtKeyWww = SDLK_WWW,
    VirtKeyMail = SDLK_MAIL,
    VirtKeyCalculator = SDLK_CALCULATOR,
    VirtKeyComputer = SDLK_COMPUTER,
    VirtKeyAc_Search = SDLK_AC_SEARCH,
    VirtKeyAc_Home = SDLK_AC_HOME,
    VirtKeyAc_Back = SDLK_AC_BACK,
    VirtKeyAc_Forward = SDLK_AC_FORWARD,
    VirtKeyAc_Stop = SDLK_AC_STOP,
    VirtKeyAc_Refresh = SDLK_AC_REFRESH,
    VirtKeyAc_Bookmarks = SDLK_AC_BOOKMARKS,
    VirtKeyBrightnessDown = SDLK_BRIGHTNESSDOWN,
    VirtKeyBrightnessUp = SDLK_BRIGHTNESSUP,
    VirtKeyDisplaySwitch = SDLK_DISPLAYSWITCH,
    VirtKeyKbdIllumToggle = SDLK_KBDILLUMTOGGLE,
    VirtKeyKbdIllumDown = SDLK_KBDILLUMDOWN,
    VirtKeyKbdIllumUp = SDLK_KBDILLUMUP,
    VirtKeyEject = SDLK_EJECT,
    VirtKeySleep = SDLK_SLEEP,
};

enum KeyAction {
    KeyActionDown,
    KeyActionUp,
};

struct KeyEvent {
    KeyAction action;
    VirtKey virt_key;
    uint16_t modifiers;

    bool left_shift() const {
        return modifiers & KMOD_LSHIFT;
    }
    bool right_shift() const {
        return modifiers & KMOD_RSHIFT;
    }
    bool left_ctrl() const {
        return modifiers & KMOD_LCTRL;
    }
    bool right_ctrl() const {
        return modifiers & KMOD_RCTRL;
    }
    bool left_alt() const {
        return modifiers & KMOD_LALT;
    }
    bool right_alt() const {
        return modifiers & KMOD_RALT;
    }
    bool left_super() const {
        return modifiers & KMOD_LGUI;
    }
    bool right_super() const {
        return modifiers & KMOD_RGUI;
    }
    bool num_lock() const {
        return modifiers & KMOD_NUM;
    }
    bool caps_lock() const {
        return modifiers & KMOD_CAPS;
    }
    bool alt_gr() const {
        return modifiers & KMOD_MODE;
    }
    bool ctrl() const {
        return modifiers & KMOD_CTRL;
    }
    bool shift() const {
        return modifiers & KMOD_SHIFT;
    }
    bool alt() const {
        return modifiers & KMOD_ALT;
    }
    bool super() const {
        return modifiers & KMOD_GUI;
    }
};

enum TextInputAction {
    TextInputActionCandidate,
    TextInputActionCommit,
};

struct TextInputEvent {
    TextInputAction action;
    String text;
};



#endif
