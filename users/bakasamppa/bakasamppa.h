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

#pragma once

// DEFINE MACROS
//#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

#define SWAP_L SGUI(KC_LEFT)                 // Swap application to left display
#define SWAP_R SGUI(KC_RGHT)                 // Swap application to right display

// KEYCODES
enum custom_user_keycodes {
    KC_00 = SAFE_RANGE,
        RGB_NITE,      // Disables RGB backlighting effects but allows RGB indicators to still work

        TG_CAPS,       // Toggles RGB highlighting of alphas during capslock

        YAHOO,         // yahoo.com
        OUTLOOK,       // outlook.com
        GMAIL,         // gmail.com
        HOTMAIL,       // hotmail.com
        DOTCOM,        // .com

        EMO_SHRUG,     // `\_("/)_/`
        EMO_CONFUSE,   // (*_*)
        EMO_SAD,       // :'-(
        EMO_NERVOUS,   // (~_~;)
        EMO_JOY,       // (^o^)
        EMO_TEARS,     // (T_T)

        NEW_SAFE_RANGE // New safe range for keymap level custom keycodes
};

// Set up boolean variables to track user customizable configuration options
typedef union {
  uint32_t raw;
  struct {
    bool     rgb_hilite_caps :1;
  };
} user_config_t;

user_config_t user_config;

#ifdef RGB_MATRIX_ENABLE
void activate_rgb_nightmode(bool turn_on);
bool get_rgb_nightmode(void);
#endif
