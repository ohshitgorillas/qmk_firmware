#include QMK_KEYBOARD_H


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
