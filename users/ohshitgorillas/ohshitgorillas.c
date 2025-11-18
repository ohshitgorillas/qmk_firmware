#include "ohshitgorillas.h"
#include "secrets.h"
#include "xcase.h"
#include "spongemock.h"

// OS Awareness
// macOS/iOS uses layer 0, everything else uses layer 1
bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_single_persistent_default_layer(0);
    } else {
        set_single_persistent_default_layer(1);
    }
    return true;
}


// Leader sequences
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
                delimiter = LSFT(leader_sequence[3]);  // Use shifted fourth key
                break;
        }
        enable_xcase_with(delimiter);
    }

    // Personal info macros
    else if (leader_sequence_two_keys(KC_M, KC_E)) { SEND_STRING("ohshitgorillas"); }
    else if (leader_sequence_four_keys(KC_A, KC_D, KC_D, KC_R)) { SEND_STRING(PERSONAL_ADDRESS); }
    else if (leader_sequence_three_keys(KC_P, KC_E, KC_M)) { SEND_STRING(PERSONAL_EMAIL); }
    else if (leader_sequence_three_keys(KC_W, KC_E, KC_M)) { SEND_STRING(WORK_EMAIL); }
    else if (leader_sequence_three_keys(KC_P, KC_P, KC_H)) { SEND_STRING(PERSONAL_PHONE); }
    else if (leader_sequence_three_keys(KC_W, KC_P, KC_H)) { SEND_STRING(WORK_PHONE); }
    else if (leader_sequence_three_keys(KC_O, KC_S, KC_G)) { SEND_STRING(PERSONAL_DOMAIN); }

    // Go-to app shortcuts (single key)
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

    // xcase toggles
    else if (leader_sequence_two_keys(KC_S, KC_C)) { enable_xcase_with(KC_UNDS); }
    else if (leader_sequence_two_keys(KC_K, KC_C)) { enable_xcase_with(KC_MINS); }
    else if (leader_sequence_two_keys(KC_C, KC_C)) { enable_xcase_with(KC_LSFT); }

    // autocorrect toggle
    else if (leader_sequence_two_keys(KC_A, KC_C)) { autocorrect_toggle(); }

    // sPOnGebob mOCkING tExt ToGGle
    else if (leader_sequence_two_keys(KC_S, KC_M)) { toggle_spongemock(); }
}


// Timing functions
bool get_hold_on_other_key_press_per_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_CAPS):  // 60s
        case LT(3, KC_CAPS):  // 60s
        case SC_SENT:         // Planck
            return true;
        default:              // Home Row Mods
            return false;
    }
}



uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_CAPS):  // 60s
        case LT(3, KC_CAPS):  // 60s
            return 50;
        case SC_SENT:         // Planck
            return 100;
        default:              // Home Row Mods
            return 200;
    }
}


bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2, KC_CAPS):  // 60s
        case LT(3, KC_CAPS):  // 60s
        case SC_SENT:         // Planck
            return true;
        default:              // Home Row Mods
            return false;
    }
}
