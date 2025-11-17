#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif


#include "secrets.h"


extern uint16_t leader_sequence[];


void leader_end_user(void) {
    // xcase dynamic delimiters
    if (leader_sequence[0] == KC_X && leader_sequence[1] == KC_C) {
        uint16_t delimiter = leader_sequence[2];
        switch (delimiter) {
            case KC_LSFT:
            case KC_RSFT:

            case OS_LSFT:
            case OS_RSFT:
            case SC_SENT:
                delimiter = LSFT(leader_sequence[3]);  // Use shifted fourth key
                break;
        }
        enable_xcase_with(delimiter);
    }

    // Personal info macros
    else if (leader_sequence_three_keys(KC_P, KC_E, KC_M)) { SEND_STRING(PERSONAL_EMAIL); }
    else if (leader_sequence_three_keys(KC_W, KC_E, KC_M)) { SEND_STRING(WORK_EMAIL); }
    else if (leader_sequence_three_keys(KC_P, KC_P, KC_H)) { SEND_STRING(PERSONAL_PHONE); }
    else if (leader_sequence_three_keys(KC_W, KC_P, KC_H)) { SEND_STRING(WORK_PHONE); }
    else if (leader_sequence_four_keys(KC_A, KC_D, KC_D, KC_R)) { SEND_STRING(PERSONAL_ADDRESS); }
    else if (leader_sequence_three_keys(KC_O, KC_S, KC_G)) { SEND_STRING(PERSONAL_DOMAIN); }

    // Go-to app shortcuts
    else if (leader_sequence_one_key(KC_Q)) { tap_code16(LCG(KC_F23)); }   // WeChat
    else if (leader_sequence_one_key(KC_W)) { tap_code16(LALT(KC_F23)); }  // WhatsApp
    else if (leader_sequence_one_key(KC_T)) { tap_code16(LSFT(KC_F23)); }  // Teams
    else if (leader_sequence_one_key(KC_A)) { tap_code16(LCS(KC_F23)); }   // Safari (Android msgs)
    else if (leader_sequence_one_key(KC_S)) { tap_code16(LGUI(KC_F23)); }  // Signal
    else if (leader_sequence_one_key(KC_D)) { tap_code16(LCA(KC_F23)); }   // Discord
    else if (leader_sequence_one_key(KC_F)) { tap_code(KC_F22); }          // Finder
    else if (leader_sequence_one_key(KC_Z)) { tap_code16(LGUI(KC_F24)); }  // Outlook
    else if (leader_sequence_one_key(KC_X)) { tap_code16(LSFT(KC_F24)); }  // Terminal
    else if (leader_sequence_one_key(KC_C)) { tap_code16(LCTL(KC_F24)); }  // Cursor
    else if (leader_sequence_one_key(KC_B)) { tap_code(KC_F14); }          // Browser
    else if (leader_sequence_one_key(KC_N)) { tap_code(KC_F15); }          // Calculator
    else if (leader_sequence_one_key(KC_M)) { tap_code(KC_F16); }          // Music

    // Two-key sequences
    else if (leader_sequence_two_keys(KC_S, KC_M)) { toggle_spongemock(); }
    else if (leader_sequence_two_keys(KC_A, KC_C)) { tap_code16(QK_AUTOCORRECT_TOGGLE); }
    else if (leader_sequence_two_keys(KC_S, KC_C)) { tap_code16(XCASE_SNAKE); }
    else if (leader_sequence_two_keys(KC_K, KC_C)) { tap_code16(XCASE_KEBAB); }
    else if (leader_sequence_two_keys(KC_C, KC_C)) { tap_code16(XCASE_CAMEL); }
}


// space cadet shift/enter hold on other key press per key
bool get_hold_on_other_key_press_per_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SC_SENT:
            return true;
        default:
            return false;
    }
}


// default tapping term for space cadet shift/enter (mod taps 300ms)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SC_SENT:
            return 100;
        default:
            return 300;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_1x2uR(
        /* macOS main layer
        accesses:
          - layer 2: lower / numbers and symbols
          - layer 3: macOS raise / navigation
          - layer 5: function key layer
        */
        KC_ESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_GRAVE,
        KC_TAB,  LCTL_T(KC_A), LOPT_T(KC_S), LCMD_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RCMD_T(KC_K), ROPT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         SC_SENT,
        KC_LCTL, KC_LOPT,      KC_LCMD,      MO(2),        KC_BSPC,      KC_DEL, KC_SPC,               MO(3),        MO(5),        QK_LEAD,         KC_RCMD
    ),

    [1] = LAYOUT_planck_1x2uR(
        /* Windows main layer
        accesses:
          - layer 2: lower / numbers and symbols
          - layer 4: Windows raise / navigation
          - layer 5: function key layer
        */
        KC_ESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_GRAVE,
        KC_TAB,  LCTL_T(KC_A), LALT_T(KC_S), LWIN_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RWIN_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         SC_SENT,
        KC_LCTL, KC_LALT,      KC_LWIN,      MO(2),        KC_BSPC,      KC_DEL, KC_SPC,               MO(4),        MO(5),        QK_LEAD,         KC_RCTL
    ),

    [2] = LAYOUT_planck_1x2uR(
        // lower: numbers and symbols
        _______, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_CIRC, KC_HASH, KC_7,    KC_8, KC_9,    KC_PLUS, KC_BSLS,
        KC_CAPS, KC_UNDS, KC_EQL,  KC_LPRN, KC_RPRN, KC_COLN, KC_DLR,  KC_4,    KC_5, KC_6,    KC_MINS, _______,
        _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_PERC, KC_1,    KC_2, KC_3,    KC_ASTR, _______,
        _______, _______, _______, _______, _______, _______, _______,          KC_0, KC_PDOT, KC_SLSH, _______
    ),

    [3] = LAYOUT_planck_1x2uR(
        /* macOS raise: navigation
        accesses:
          - layer 6: lighting and misc
        note: NUBS goes to Compose
        */
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,      KC_PGUP,   KC_HOME,   KC_UP,         KC_END,        KC_PSCR,      LSFT(KC_BSLS),
        XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT,       XXXXXXX,      KC_PGDN,   KC_LEFT,   KC_DOWN,       KC_RGHT,       LSA(KC_MINS), LOPT(KC_MINS),
        _______, KC_NUBS, KC_MUTE, KC_VOLD, KC_VOLU,       LSG(KC_3),    LSG(KC_4), LSG(KC_5), LCMD(KC_LBRC), LCMD(KC_RBRC), XXXXXXX,      _______,
        _______, _______, _______, MO(6),   LOPT(KC_BSPC), LOPT(KC_DEL), _______,              _______,       _______,       _______,      _______
    ),

    [4] = LAYOUT_planck_1x2uR(
        /* Windows raise: navigation
        accesses:
          - layer 6: lighting and misc
        */
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,      KC_PGUP, KC_HOME, KC_UP,         KC_END,        KC_PSCR, LSFT(KC_BSLS),
        XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT,       XXXXXXX,      KC_PGDN, KC_LEFT, KC_DOWN,       KC_RGHT,       XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,       XXXXXXX,      XXXXXXX, XXXXXXX, LCTL(KC_LBRC), LCTL(KC_RBRC), XXXXXXX, _______,
        _______, _______, _______, MO(6),   LCTL(KC_BSPC), LCTL(KC_DEL), _______,          _______,       _______,       _______, _______
    ),

    [5] = LAYOUT_planck_1x2uR(
        // function key layer
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F1, KC_F2,   KC_F3,   KC_F4,   XXXXXXX,
        XXXXXXX, OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, XXXXXXX, XXXXXXX, KC_F5, KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9, KC_F10,  KC_F11,  KC_F12,  _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______
    ),

    [6] = LAYOUT_planck_1x2uR(
        // lighting and misc
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, UG_TOGG, UG_NEXT, UG_PREV, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, UG_SPDU, UG_SPDD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,          _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};


// set badkeys function
void set_badkeys(void) {
    enable_badkeys();
    add_badkey_by_position(3, 0);  // ctrl
    add_badkey_by_position(3, 1);  // opt
    add_badkey_by_position(3, 2);  // cmd
    add_badkey_by_position(3, 5);  // right cmd
}


// post init user function
void keyboard_post_init_user(void) {
    set_badkeys();
}


// OS Awareness
bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_single_persistent_default_layer(0);  // macOS/iOS uses layer 0
    } else {
        set_single_persistent_default_layer(1);  // Everything else uses layer 1
    }
    return true;
}
