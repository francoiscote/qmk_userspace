#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

enum layers {
  _BASE,
  _NAV,
  _WM,
  _NUM,
  _SYMB,
  _MEDIA,
  _FUN,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    LT_NAV_SPACE,

    SW_WIN,  // Switch to next window         (cmd-tab)
};

#define MAC_COPY   G(KC_C)
#define MAC_CUT    G(KC_X)
#define MAC_PASTE  G(KC_V)

#define MAC_QUIT   G(KC_Q)
#define MAC_PRVT   G(A(KC_LEFT))
#define MAC_NEXT   G(A(KC_RIGHT)) 
#define MAC_CLOSE  G(KC_W) 

#define MAC_UNDO   G(KC_Z)
#define MAC_REDO   G(S(KC_Z))

#define MO_NAV     MO(_NAV) 
#define MO_WM      MO(_WM)
#define MO_NUM     MO(_NUM) 
#define MO_SYMB    MO(_SYMB)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,           KC_J,   KC_L,   KC_U,       KC_Y,     KC_QUOT,
        KC_A,   KC_R,   KC_S,   KC_T,   KC_G,           KC_M,   KC_N,   KC_E,       KC_I,     KC_O,
        KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,           KC_K,   KC_H,   KC_COMMA,   KC_DOT,   KC_SLASH,
                       MO_WM, MO_NAV, MO_NUM,           OS_SHFT, KC_SPACE, MO_SYMB
    ),      
    [_NAV] = LAYOUT_split_3x5_3(
        MAC_QUIT,    MAC_CLOSE, MAC_PRVT,   MAC_NEXT,       XXXXXXX,             KC_PGUP,    KC_HOME,    KC_UP,      KC_END,    XXXXXXX,
        OS_CTRL,     OS_ALT,     OS_CMD,      OS_SHFT,      SW_WIN,            KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,
        MAC_UNDO,     MAC_CUT,    MAC_COPY,    MAC_PASTE,   MAC_REDO,           KC_ESC,     KC_BSPC,    KC_ENT,    KC_TAB,     KC_DEL,
                                          XXXXXXX, _______, XXXXXXX,            KC_BSPC, KC_ENT, _______
    ),
    [_WM] = LAYOUT_split_3x5_3(
        LCAG(KC_Q),              LCAG(KC_W),              LCAG(KC_E),              LCAG(KC_R),              LCAG(KC_T),              LCAG(KC_Y),              LCAG(KC_U),              LCAG(KC_I),              LCAG(KC_O),              LCAG(KC_P),          \
        LCAG(KC_A),              LCAG(KC_S),              LCAG(KC_D),              LCAG(KC_F),              LCAG(KC_G),              LCAG(KC_H),              LCAG(KC_J),              LCAG(KC_K),              LCAG(KC_L),              LCAG(KC_SEMICOLON),  \
        LCAG(KC_Z),              LCAG(KC_X),              LCAG(KC_C),              LCAG(KC_V),              LCAG(KC_B),              LCAG(KC_N),              LCAG(KC_M),              LCAG(KC_COMMA),           LCAG(KC_DOT),             LCAG(KC_SLSH),     \
        XXXXXXX, XXXXXXX, XXXXXXX,                                                                                                   _______,  _______, _______
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_TAB,     KC_LEFT,    KC_DOT,     KC_RGHT,        S(KC_MINS),          XXXXXXX,       KC_7,       KC_8,   KC_9,   S(KC_EQL),
        OS_CTRL ,   OS_ALT ,    OS_CMD,     OS_SHFT,        MO_NAV,              KC_SEMICOLON,  KC_4,       KC_5,   KC_6,   KC_MINS,
        MAC_UNDO,   _______,    KC_COMM,    KC_SEMICOLON,   MAC_REDO,            KC_MINS,       KC_1,       KC_2,   KC_3,   _______,
                                      _______,   _______,    _______,            KC_ENT,        KC_BSPC,    KC_0
  ),
    [_SYMB] = LAYOUT_split_3x5_3(
      LSFT(KC_LEFT_BRACKET),    LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     LSFT(KC_RIGHT_BRACKET),   KC_NO,  KC_NO,     KC_NO,    KC_NO,    KC_NO,   \
      LSFT(KC_SEMICOLON),        LSFT(KC_4),     LSFT(KC_5),     LSFT(KC_6),     LSFT(KC_EQUAL),           KC_NO,  KC_RSFT,   KC_RGUI,  KC_RALT,  KC_RCTL,        \
      LSFT(KC_GRAVE),           LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_BACKSLASH),       KC_NO,  KC_NO,     KC_NO,    KC_NO,    KC_NO,         \
      LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS),                                                            _______,  _______, _______
    ),
    [_MEDIA] = LAYOUT_split_3x5_3(
      KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO, KC_NO,     KC_NO,    KC_NO,  KC_NO,  KC_NO, \
       KC_NO,    KC_NO,    KC_VOLD,  KC_VOLU,    KC_NO, KC_NO,     KC_NO,    KC_NO,  KC_NO,  KC_NO, \
      KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO, KC_NO,     KC_NO,    KC_NO,  KC_NO,  KC_NO, \
      KC_MPRV,  KC_MPLY, KC_MNXT,                    _______,   _______,  _______
    ),
    [_FUN] = LAYOUT_split_3x5_3(
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,    KC_PRINT_SCREEN,   KC_F7,   KC_F8,  KC_F9,  KC_F12, \
      KC_LCTL,      KC_LALT,    KC_LGUI,    KC_LSFT,      KC_NO,    KC_NO,             KC_F4,   KC_F5,  KC_F6,  KC_F11, \
      KC_NO,        KC_NO,      KC_NO,      KC_NO,        KC_NO,    QK_BOOT,             KC_F1,   KC_F2,  KC_F3,  KC_F10, \
      XXXXXXX, XXXXXXX, XXXXXXX,                                    _______,   _______,  _______
    )
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case MO_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, SYM, NAV, NUM);
// }