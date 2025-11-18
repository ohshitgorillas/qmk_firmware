/*
 * OSGPlanck keymap
 *
 * This is the keymap for my (ohshitgorillas) personal Planck keyboard.
 *
 * It's a 4x12 layout with a 2U spacebar on the right side.
 */


#include QMK_KEYBOARD_H

#include "ohshitgorillas.h"


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
