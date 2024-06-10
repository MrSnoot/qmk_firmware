/* Copyright 2021 Simon S.
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
#include <stdio.h>

#include "keymap_german.h"
#include "sendstring_german.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names
{
	_one = 0,
	_two,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
[_one] = LAYOUT(
        KC_TRNS, KC_TRNS, TO(1),
        KC_F1, KC_F2, KC_F3,
        KC_F4, KC_F5, KC_F6),
		
[_two] = LAYOUT(
        KC_TRNS, KC_TRNS, TO(0),
        KC_F7, KC_F8, KC_F9,
        KC_F10, KC_F11, KC_F12),
};

bool encoder_update_user(uint8_t index, bool clockwise)
{
    if (clockwise) {
        tap_code(KC_AUDIO_VOL_UP);
    } else {
        tap_code(KC_AUDIO_VOL_DOWN);
    }
	
    return true;
}

void keyboard_post_init_user(void) {
	rgblight_mode(6);
}

bool led_update_user(led_t led_state) {
    rgblight_mode(6);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_mode(6);
    return state;
}

#ifdef OLED_ENABLE
bool oled_task_user(void)
{
	
	switch (get_highest_layer(layer_state))
    {
    case _one:
        oled_write_ln_P(PSTR("     Premium Pad     "
                             "F1       F2        F3"
                             "F4       F5        F6"),
                        false);
        break;
    case _two:
        oled_write_ln_P(PSTR("     Premium Pad     "
                             "F7       F8        F9"
                             "F10      F11      F12"),
                        false);
        break;
    }
	return true;
}
#endif





