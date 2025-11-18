/*
 * OSG60 keymap
 *
 * This is the keymap for my (ohshitgorillas) personal 60% keyboards,
 * the Tofu60 2.0 and the Luminkey LX60.
 *
 * Both use the same configuration:
 * - Split backspace
 * - Split right shift
 * - Tsangan bottom row/7U spacebar
 * - ANSI Enter
*/


#include QMK_KEYBOARD_H

#include "ohshitgorillas.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // macOS main layer
        KC_ESC,        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,   KC_6,   KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
        KC_TAB,        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC, KC_RBRC, KC_BSPC,
        LT(2,KC_CAPS), LCTL_T(KC_A), LALT_T(KC_S), LCMD_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RCMD_T(KC_K), ROPT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,          KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,                  KC_RSFT, MO(4),
        KC_LCTL,       KC_LOPT,      KC_LCMD,                                                  KC_SPC,                                                    KC_RCMD, KC_ROPT, KC_RCTL
    ),

    [1] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // Windows/Linux main layer
        KC_ESC,        KC_1,         KC_2,         KC_3,         KC_4,         KC_5,   KC_6,   KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
        KC_TAB,        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC, KC_RBRC, KC_BSPC,
        LT(3,KC_CAPS), LCTL_T(KC_A), LALT_T(KC_S), LWIN_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RWIN_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,          KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,                  KC_RSFT, MO(4),
        KC_LCTL,       KC_LWIN,      KC_LALT,                                                  KC_SPC,                                                    KC_RALT, KC_RWIN, KC_RCTL
    ),

    [2] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // macOS caps layer
        // notes:
        //     - KC_NUBS goes to Compose
        //     - LSG(3,4,5) allows screenshotting under macOS
        XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,  _______, _______,
        XXXXXXX,  KC_NUBS, KC_LCTL, KC_LSFT, KC_ENT,  XXXXXXX, KC_PGUP, KC_HOME, KC_UP,     KC_END,    KC_PSCR,   XXXXXXX,   XXXXXXX, _______,
        XXXXXXX,  KC_LOPT, KC_LCMD, KC_BSPC, KC_DEL,  XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN,   KC_RIGHT,  KC_UNDS,   KC_PLUS,            _______,
        _______,  QK_LEAD, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, LSG(KC_3), LSG(KC_4), LSG(KC_5),            _______, XXXXXXX,
        _______,  _______, _______,                                     _______,                                  _______,   _______, _______
    ),

     [3] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // Windows/Linux caps layer
        XXXXXXX,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,  _______, _______,
        XXXXXXX,  KC_NUBS, KC_LWIN, KC_LSFT, KC_ENT,  XXXXXXX, KC_PGUP, KC_HOME, KC_UP,   KC_END,    KC_PSCR,   XXXXXXX,   XXXXXXX, _______,
        XXXXXXX,  KC_LCTL, KC_LALT, KC_BSPC, KC_DEL,  XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_UNDS,   KC_PLUS,            _______,
        _______,  QK_LEAD, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,              _______, XXXXXXX,
        _______,  _______, _______,                                     _______,                                _______,   _______, _______
    ),

    [4] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // universal navigation layer (HHKB style w/ slight modifications)
        XXXXXXX,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,    KC_F12,  KC_INS,  KC_DEL,
        QK_LEAD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL,  KC_PAUS,   KC_UP,     XXXXXXX, _______,
        XXXXXXX,  OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, XXXXXXX, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP,  KC_LEFT,   KC_RIGHT,           _______,
        _______,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_PLUS, KC_MINS, KC_END,  KC_PGDN,  KC_DOWN,              _______, XXXXXXX,
        _______,  _______, _______,                                     _______,                               _______,   _______, _______
    ),
};
