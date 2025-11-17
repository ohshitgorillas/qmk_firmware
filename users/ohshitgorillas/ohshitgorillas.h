#pragma once
#include QMK_KEYBOARD_H

// Declare weak keymap functions that keyboards can override
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
__attribute__((weak)) uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record);
__attribute__((weak)) bool get_hold_on_other_key_press_keymap(uint16_t keycode, keyrecord_t *record);
__attribute__((weak)) bool process_detected_host_os_keymap(os_variant_t detected_os);
