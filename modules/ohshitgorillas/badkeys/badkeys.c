/* Simple badkeys implementation
 * Plays a sound when designated "bad" keys are pressed for training purposes
 */

#include "badkeys.h"
#include "audio.h"


// Private types
typedef struct {
    uint8_t row;
    uint8_t col;
} matrix_pos_t;


// Private variables
static bool badkeys_active = false;

#define MAX_BAD_KEYCODES 16
#define MAX_BAD_POSITIONS 16

static uint16_t bad_keycodes[MAX_BAD_KEYCODES];
static uint8_t bad_keycode_count = 0;

static matrix_pos_t bad_positions[MAX_BAD_POSITIONS];
static uint8_t bad_position_count = 0;

static float bad_sound[][2] = SONG(TERMINAL_SOUND);

// Track number of bad keys currently pressed
static uint8_t bad_keys_pressed = 0;


// Public functions
void enable_badkeys(void) {
    badkeys_active = true;
}


void disable_badkeys(void) {
    badkeys_active = false;
    bad_keys_pressed = 0;
}


bool is_badkeys_active(void) {
    return badkeys_active;
}


bool is_badkey_by_keycode(uint16_t keycode) {
    for (uint8_t i = 0; i < bad_keycode_count; i++) {
        if (bad_keycodes[i] == keycode) {
            return true;
        }
    }
    return false;
}


bool is_badkey_by_position(uint8_t row, uint8_t col) {
    for (uint8_t i = 0; i < bad_position_count; i++) {
        if (bad_positions[i].row == row && bad_positions[i].col == col) {
            return true;
        }
    }
    return false;
}


void add_badkey_by_keycode(uint16_t keycode) {
    if (bad_keycode_count >= MAX_BAD_KEYCODES) {
        return; // List is full
    }

    // Check if already exists
    if (is_badkey_by_keycode(keycode)) {
        return; // Already in list
    }

    bad_keycodes[bad_keycode_count] = keycode;
    bad_keycode_count++;
}


void remove_badkey_by_keycode(uint16_t keycode) {
    for (uint8_t i = 0; i < bad_keycode_count; i++) {
        if (bad_keycodes[i] == keycode) {
            for (uint8_t j = i; j < bad_keycode_count - 1; j++) {
                bad_keycodes[j] = bad_keycodes[j + 1];
            }
            bad_keycode_count--;
            return;
        }
    }
}


void add_badkey_by_position(uint8_t row, uint8_t col) {
    if (bad_position_count >= MAX_BAD_POSITIONS) {
        return; // List is full
    }

    // Check if already exists
    if (is_badkey_by_position(row, col)) {
        return; // Already in list
    }

    bad_positions[bad_position_count].row = row;
    bad_positions[bad_position_count].col = col;
    bad_position_count++;
}


void remove_badkey_by_position(uint8_t row, uint8_t col) {
    for (uint8_t i = 0; i < bad_position_count; i++) {
        if (bad_positions[i].row == row && bad_positions[i].col == col) {
            for (uint8_t j = i; j < bad_position_count - 1; j++) {
                bad_positions[j] = bad_positions[j + 1];
            }
            bad_position_count--;
            return;
        }
    }
}


// main function
bool process_record_badkeys(uint16_t keycode, keyrecord_t *record) {
    // Handle toggle/enable/disable keycodes first
    if (record->event.pressed) {
        switch (keycode) {
            case BADKEY_TOGGLE:
                badkeys_active = !badkeys_active;
                return false; // Keycode handled
            case BADKEY_ENABLE:
                enable_badkeys();
                return false; // Keycode handled
            case BADKEY_DISABLE:
                disable_badkeys();
                return false; // Keycode handled
        }
    }

    // If not active, pass all keys through
    if (!badkeys_active) {
        return true;
    }

    // Check if keycode is in bad list
    if (
        is_badkey_by_keycode(keycode) ||
        is_badkey_by_position(record->event.key.row, record->event.key.col)
    ) {
        if (record->event.pressed) {
            // Key down - start tone if this is the first bad key
            if (bad_keys_pressed == 0) {
                PLAY_LOOP(bad_sound);
            }
            bad_keys_pressed++;
        } else {
            // Key up - stop tone if no bad keys remain pressed
            if (bad_keys_pressed > 0) {
                bad_keys_pressed--;
                if (bad_keys_pressed == 0) {
                    stop_all_notes();
                }
            }
        }
    }
    return true; // Pass through all keys
}
