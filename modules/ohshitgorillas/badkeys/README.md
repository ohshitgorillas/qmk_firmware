# qmk-badkeys: Audio Feedback on Keypresses
Does your keyboard make noise? Do you wish it made even more noise? Today is your lucky day!

BadKeys is a QMK community module which allows users to "train" themselves against using certain keys by providing audio feedback from the keyboard's speaker for the duration of certain keypresses.

One example of usage is for users with 65% keyboards or larger trying to get used to using layered arrow keys to move down to 60% or smaller keyboards: when the actual arrow keys are pressed, the keyboard will beep to indicate that the user has made a mistake (by not using the layered arrow keys).

Another example is users trying to get used to Home Row Mods: the dedicated modifier keys can beep upon use, indicating that the user should instead be using the HRMs.

## Usage

Obviously, you need a keyboard with a speaker for this to work.

1.  Ensure you have `AUDIO_ENABLE = yes` in your `rules.mk` file. 
2.  Add the BadKeys module to your QMK directory.

    **Option A: Git Submodule (Recommended)**
    ```bash
    cd <qmk directory>
    git submodule add https://github.com/ohshitgorillas/qmk-badkeys.git modules/ohshitgorillas/badkeys
    ```

    **Option B: Manual Download**
    
    Create a new folder at the following path inside your QMK firmware directory:
    ```
    <qmk directory>/modules/ohshitgorillas/badkeys/
    ```
    Place `badkeys.c`, `badkeys.h`, `qmk_module.json`, `introspection.h`, and `readme.md` inside this folder.

3.  Add the following to your `keymap.json` file:

```json
{
    "modules": [
        "ohshitgorillas/badkeys"
    ]
}
```

4. In your `keymap.c`, add the following to `keyboard_post_init_user`:

```c
void keyboard_post_init_user(void) {
    enable_badkeys();
    add_badkey_by_position(0, 0);  // example: beep upon use of the top left-most key on the board
    add_badkey_by_keycode(KC_LSFT);  // example: beep upon use of the left shift key, e.g., to use LSFT_T() instead
}
```

For a cleaner implementation, define a separate function `set_badkeys` and call it from `keyboard_post_init_user`:

```c
void set_badkeys(void) {
    enable_badkeys();
    // beep on use of dedicated mod keys; use HRMs instead
    add_badkey_by_position(3, 0);  // ctrl
    add_badkey_by_position(3, 1);  // opt
    add_badkey_by_position(3, 2);  // cmd
    add_badkey_by_position(3, 5);  // right cmd
}

void keyboard_post_init_user(void) {
    set_badkeys();  // enable and set badkeys
}
```

You may add up to 16 keycodes and 16 matrix positions to BadKeys.


## Custom Keycodes
BadKeys provides the following custom keycodes:
- `BADKEYS_TOGGLE` [alias `BK_TOGG`]: Toggles BadKeys on/off.
- `BADKEYS_ENABLE` [alias `BK_ON`]: Turns BadKeys on.
- `BADKEYS_DISABLE` [alias `BK_OFF`]: Turns BadKeys off.

## Functions
The following functions are made available to your `keymap.c`.

### enable_badkeys
```c
void enable_badkeys(void);
```
Enables BadKeys.

### disable_badkeys
```c
void disable_badkeys(void);
```
Disables BadKeys.

### is_badkeys_active
```c
bool is_badkeys_active(void);
```
Returns true when BadKeys is active.

### add_badkey_by_keycode
```c
void add_badkey_by_keycode(uint16_t keycode);
```
Add a given keycode to BadKeys. BadKeys will accept up to 16 keycodes.

### remove_badkey_by_keycode
```c
void remove_badkey_by_keycode(uint16_t keycode);
```
Remove a given keycode from BadKeys.

### is_badkey_by_keycode
```c
void is_badkey_by_keycode(uint16_t keycode);
```
Returns true if the keycode is a badkey.

### add_badkey_by_position
```c
void add_badkey_by_position(uint8_t row, uint8_t col);
```
Add a physical key to BadKeys based on its matrix position on the board. BadKeys will accept up to 16 positions.

You may need to refer to the `layouts` section of `keyboard.json` to find the correct matrix position for a given key.

### remove_badkey_by_position
```c
void remove_badkey_by_position(uint8_t row, uint8_t col);
```
Remove a physical key from BadKeys.

### is_badkey_by_position
```c
bool is_badkey_by_position(uint8_t row, uint8_t col);
```
Returns true if the given physical key position is a badkey.
