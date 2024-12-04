/* Copyright 2021 Jonavin Eng @Jonavin
   Copyright 2022 gourdo1 <gourdo1@outlook.com>
   Copyright 2024 bakasamppa

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "bakasamppa.h"

// RGB NIGHT MODE
#ifdef RGB_MATRIX_ENABLE
static bool rgb_nightmode = false;

// Turn on/off NUM LOCK if current state is different
void activate_rgb_nightmode(bool turn_on) {
    if (rgb_nightmode != turn_on) {
        rgb_nightmode = !rgb_nightmode;
    }
}

bool get_rgb_nightmode(void) {
    return rgb_nightmode;
}
#endif // RGB_MATRIX_ENABLE

// Initialize variable holding the binary representation of active modifiers.
uint8_t mod_state;

// ============================================= PROCESS KEY CODES =============================================

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t * record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t * record) {
    mod_state = get_mods();
    if (!process_record_keymap(keycode, record)) { return false; }

    // Key macros ...
    switch (keycode) {

    case TG_CAPS:  // Toggle RGB highlighting of Capslock state
        if (record->event.pressed) {
            user_config.rgb_hilite_caps ^= 1; // Toggles the status
            eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
        }
        break;

        #ifdef RGB_MATRIX_ENABLE
    case RGB_NITE:
        if (record -> event.pressed) {
            rgb_nightmode = !rgb_nightmode;
        } else unregister_code16(keycode);
        break;
        #endif // RGB_MATRIX_ENABLE

    default:
        if (record -> event.pressed) {
            #ifdef RGB_MATRIX_ENABLE
            rgb_matrix_enable();
            #endif
        }
        break;

    case GUI_L:
        if (record->event.pressed) {
            KC_LGUI,KC_LEFT
            KC_LGUI,KC_RGHT
        }
        break;

    case GUI_R:
        if (record->event.pressed) {
            KC_LGUI,KC_RGHT
        }
        break;
    }
    return true;
};

// INITIAL STARTUP
__attribute__((weak)) void keyboard_post_init_keymap(void) {
}

void keyboard_post_init_user(void) {
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
    keyboard_post_init_keymap();
}

/* Set defaults for EEPROM user configuration variables */
void eeconfig_init_user(void) {
    user_config.raw                           = 0;
    user_config.rgb_hilite_caps               = true;

    eeconfig_update_user(user_config.raw);
}
