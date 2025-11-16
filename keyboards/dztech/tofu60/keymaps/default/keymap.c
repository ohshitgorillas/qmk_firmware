/* Copyright 2022 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "secrets.h"

extern uint16_t leader_sequence[];


void leader_end_user(void) {
  // personal info macros
  if (leader_sequence_three_keys(KC_P, KC_E, KC_M)) {
      // personal email
      SEND_STRING(PERSONAL_EMAIL);
  }
  else if (leader_sequence_three_keys(KC_W, KC_E, KC_M)) {
      // work email
      SEND_STRING(WORK_EMAIL);
  }
  else if (leader_sequence_three_keys(KC_P, KC_P, KC_H)) {
      // personal phone number
      SEND_STRING(PERSONAL_PHONE);
  }
  else if (leader_sequence_three_keys(KC_W, KC_P, KC_H)) {
      // work phone number
      SEND_STRING(WORK_PHONE);
  }
  else if (leader_sequence_four_keys(KC_A, KC_D, KC_D, KC_R)) {
      // personal address
      SEND_STRING(PERSONAL_ADDRESS);
  }
  else if (leader_sequence_three_keys(KC_O, KC_S, KC_G)) {
      // personal use domain
      SEND_STRING(PERSONAL_DOMAIN);
  }

  // go to app shortcuts
  else if (leader_sequence_one_key(KC_Q)) {
    // WeChat
    tap_code16(LCG(KC_F23));
  }
  else if (leader_sequence_one_key(KC_W)) {
    // WhatsApp
    tap_code16(LALT(KC_F23));
  }
  else if (leader_sequence_one_key(KC_T)) {
    // Microsoft Teams
    tap_code16(LSFT(KC_F23));
  }
  else if (leader_sequence_one_key(KC_A)) {
    // Safari (Android messaging webapp)
    tap_code16(LCS(KC_F23));
  }
  else if (leader_sequence_one_key(KC_S)) {
    // Signal
    tap_code16(LGUI(KC_F23));
  }
  else if (leader_sequence_one_key(KC_D)) {
    // Discord
    tap_code16(LCA(KC_F23));
  }
  else if (leader_sequence_one_key(KC_F)) {
    // Finder
    tap_code(KC_F22);
  }
  else if (leader_sequence_one_key(KC_Z)) {
    // Outlook
    tap_code16(LGUI(KC_F24));
  }
  else if (leader_sequence_one_key(KC_X)) {
    // Terminal
    tap_code16(LSFT(KC_F24));
  }
  else if (leader_sequence_one_key(KC_C)) {
    // Cursor
    tap_code16(LCTL(KC_F24));
  }
  else if (leader_sequence_one_key(KC_B)) {
    // Browser
    tap_code(KC_F14);
  }
  else if (leader_sequence_one_key(KC_N)) {
    // Calculator
    tap_code(KC_F15);
  }
  else if (leader_sequence_one_key(KC_M)) {
    // Music
    tap_code(KC_F16);
  }

  // sPoNgEmock Mode shorTCUT
  else if (leader_sequence_two_keys(KC_S, KC_M)) {
    toggle_spongemock();
  }

  // xcase static modes
  else if (leader_sequence_two_keys(KC_S, KC_C)) {
    enable_xcase_with(KC_UNDS);  // snake_case
  }
  else if (leader_sequence_two_keys(KC_K, KC_C)) {
    enable_xcase_with(KC_MINS);  // kebab-case
  }
  else if (leader_sequence_two_keys(KC_C, KC_C)) {
    enable_xcase_with(OS_LSFT);  // camelCase
  }
  // dynamic delimiters
  else if (
    leader_sequence[0] == KC_X &&
    leader_sequence[1] == KC_C) {

        // Get the third key (the dynamic delimiter)
        uint16_t third_key = leader_sequence[2];
        switch (third_key) {
            case KC_LSFT:  // if shift is the third key,
            case KC_RSFT:  // use the shifted fourth key as the delimiter
            case OS_LSFT:
            case OS_RSFT:
            case SC_SENT:
                third_key = LSFT(leader_sequence[3]);  // the shifted fourth key is the intended third key
                break;
        }
        enable_xcase_with(third_key);  // use the third key as the delimiter
    }
}


// disable flow tap term for caps lock layer key
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        switch (keycode) {
            case LT(2, KC_CAPS):
            case LT(3, KC_CAPS):
                return 0;
            default:
                return FLOW_TAP_TERM;
        }
    }
    return FLOW_TAP_TERM;
}


// caps lock layer hold on other key press per key
bool get_hold_on_other_key_press_per_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LT(2,KC_CAPS):
      case LT(3,KC_CAPS):
          return true;
      default:
          return false;
  }
}


// default tapping term for caps lock layer key (mod taps 300ms)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LT(2,KC_CAPS):
      case LT(3,KC_CAPS):
          return 60;
      default:
          return 300;
  }
}


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
        LT(3,KC_CAPS),  LCTL_T(KC_A), LALT_T(KC_S), LWIN_T(KC_D), LSFT_T(KC_F), KC_G,   KC_H,   RSFT_T(KC_J), RWIN_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,          KC_ENT,
        KC_LSFT,       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,   KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,                  KC_RSFT, MO(4),
        KC_LCTL,       KC_LWIN,      KC_LALT,                                                  KC_SPC,                                                    KC_RALT, KC_RWIN, KC_RCTL
    ),
    [2] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // macOS caps layer
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
        XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,    KC_F12,  KC_INS,  KC_DEL,
        QK_LEAD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL,  KC_PAUS,   KC_UP,     XXXXXXX, _______,
        XXXXXXX,  OS_LCTL, OS_LALT, OS_LGUI, OS_LSFT, XXXXXXX, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP,  KC_LEFT,   KC_RIGHT,           _______,
        _______,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_PLUS, KC_MINS, KC_END,  KC_PGDN,  KC_DOWN,              _______, XXXXXXX,
        _______,  _______, _______,                                     _______,                               _______,   _______, _______
    ),
};


// OS Awareness
bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_single_persistent_default_layer(0);  // macOS/iOS uses layer 0
    } else {
        set_single_persistent_default_layer(1);  // Everything else uses layer 1
    }
    return true;
}
