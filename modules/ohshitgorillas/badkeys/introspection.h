#include "quantum.h"

// state management
void enable_badkeys(void);
void disable_badkeys(void);
bool is_badkeys_active(void);

// add/remove badkeys by keycode
void add_badkey_by_keycode(uint16_t keycode);
void remove_badkey_by_keycode(uint16_t keycode);
bool is_badkey_by_keycode(uint16_t keycode);

// add/remove badkeys by position
void add_badkey_by_position(uint8_t row, uint8_t col);
void remove_badkey_by_position(uint8_t row, uint8_t col);
bool is_badkey_by_position(uint8_t row, uint8_t col);
