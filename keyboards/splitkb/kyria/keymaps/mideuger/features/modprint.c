/* Copyright 2021 Jérémy Quilleré jeremy.quillere@smthng.io
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

#include "modprint.h"

static bool is_modprint_enabled = false;

void enable_mod_print() {
    is_modprint_enabled = true;
}

void tap_translated_keycode(uint16_t keycode) {
    switch (keycode) {
    case KC_A...KC_Z:
        tap_code16(LSFT(keycode));
        break;
    case KC_F1...KC_F9:
        SEND_STRING("F");
        keycode = KC_1 + (keycode - KC_F1);
        tap_code(keycode);
        break;
    case KC_F10:
        SEND_STRING("F10");
        break;
    case KC_F11:
        SEND_STRING("F11");
        break;
    case KC_F12:
        SEND_STRING("F12");
        break;
    case KC_ESC:
        SEND_STRING(";;esc");
        break;
    case KC_ENTER:
        SEND_STRING(";;return");
        break;
    case KC_SPACE:
        SEND_STRING(";;space");
        break;
    case KC_BSPC:
        SEND_STRING(";;bs");
        break;
    case KC_DEL:
        SEND_STRING(";;del");
        break;
    case KC_UP:
        SEND_STRING(";;up");
        break;
    case KC_DOWN:
        SEND_STRING(";;down");
        break;
    case KC_LEFT:
        SEND_STRING(";;left");
        break;
    case KC_RIGHT:
        SEND_STRING(";;right");
        break;
    case KC_HOME:
        SEND_STRING(";;home");
        break;
    case KC_END:
        SEND_STRING(";;end");
        break;
    case KC_PGUP:
        SEND_STRING(";;pgup");
        break;
    case KC_PGDN:
        SEND_STRING(";;pgdown");
        break;
    case KC_TAB:
        SEND_STRING(";;tab");
        break;
    case KC_CAPS:
        SEND_STRING(";;capslock");
        break;
    case KC_LSPO:
        SEND_STRING("(");
        break;
    case KC_RSPC:
        SEND_STRING(")");
        break;
    default:
        tap_code(keycode);
        break;
    }
}

bool process_mod_print(uint16_t keycode, const keyrecord_t *record) {
    if (is_modprint_enabled) {
        if ((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX)
            || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX)) {
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
        }

        if (keycode >= QK_LAYER_TAP && keycode <= QK_ONE_SHOT_LAYER_MAX) {
            return true;
        }

        uint8_t mods = get_mods() | get_weak_mods();
        clear_mods();

        if (!mods) {
            if (keycode == KC_ESC) {
                is_modprint_enabled = false;
            }
            return false;
        }

        if (mods & MOD_MASK_CTRL) {
            SEND_STRING(";;ctrl");
            _delay_ms(100);
        }
        if (mods & MOD_MASK_SHIFT) {
            SEND_STRING(";;shift");
            _delay_ms(100);
        }
        if (mods & MOD_MASK_ALT) {
            SEND_STRING(";;alt");
            _delay_ms(100);
        }
        if (mods & MOD_MASK_GUI) {
            SEND_STRING(";;cmd");
            _delay_ms(100);
        }
        tap_translated_keycode(keycode);

        is_modprint_enabled = false;
        return false;
    }

    return true;
}
