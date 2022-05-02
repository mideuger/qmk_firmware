/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY_HRM = 0,
    _QWERTY,
    _NAV,
    _NUM,
    _FN,
};

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    LOWER,
    GREATER,
    DELAY,
    HRM,
    KLAYER,
    CMD_TAB,
    ALT_TAB,
};

/*
* HRM
*/
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define CTLSCL LCTL_T(KC_SCLN)
#define CTLSLS LCTL_T(KC_SLSH)

/*
* Layers and shift
*/
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define FN_DEL LT(_FN, KC_DELETE)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NAV_SPC LT(_NAV, KC_SPC)
#define OSM_SFT OSM(MOD_LSFT)

/*
* OSX symbols shortcuts
*/
#define EURO RALT(LSFT(KC_2))
#define POUND RALT(KC_3)
#define OCQUOTE RALT(KC_RBRC)
#define ODCQUOTE RALT(KC_LBRC)
#define CCQUOTE RALT(LSFT(KC_RBRC))
#define CDCQUOTE RALT(LSFT(KC_LBRC))

/*
* OSX action shortcuts
*/
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define FORCEQ LALT(LGUI(KC_ESCAPE))
#define LOCKSCR LCTL(LGUI(KC_Q))
#define PRTSCR1 LCTL(LGUI(LSFT(KC_3)))
#define PRTSCR2 LCTL(LGUI(LSFT(KC_4)))
#define PRTSCR3 LGUI(LSFT(KC_5))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY_HRM] = LAYOUT(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
     KC_GRV,   CTL_A,   ALT_S,   GUI_D,   SFT_F,    KC_G,                                           KC_H,   SFT_J,   GUI_K,   ALT_L,  CTLSCL, KC_QUOT,
    KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
                      KC_MPRV, KC_MNXT, KC_MPLY, CMD_TAB,NAV_BSPC,  FN_DEL,    NUM_ENT, NAV_SPC, OSM_SFT, KC_MUTE, KC_VOLD, KC_VOLU
    ),
    [_QWERTY] = LAYOUT(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
     KC_GRV,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
                      XXXXXXX, XXXXXXX, ALT_TAB, CMD_TAB, KC_BSPC,  KC_DEL,    NUM_ENT, NAV_SPC, OSM_SFT,     HRM, XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT(
     KC_TAB, KC_CIRC,   KC_AT, KC_HASH, KC_AMPR, KC_PERC,                                        KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
     KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_MINS,                                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,   ARROW, KC_CAPS,
    KC_LSPO,    UNDO,     CUT,    COPY,   PASTE, KC_UNDS,                                        XXXXXXX, XXXXXXX,   LOWER, GREATER, KC_EXLM, KC_RSPC,
                      XXXXXXX, XXXXXXX, ALT_TAB, CMD_TAB, KC_BSPC,  KC_DEL,     KC_ENT,  KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT(
     KC_TAB, OCQUOTE, CCQUOTE, KC_LCBR, KC_RCBR,  KC_DLR,                                        KC_MINS,    KC_7,    KC_8,    KC_9, KC_SLSH, KC_PERC,
     KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,    EURO,                                        KC_PLUS,    KC_4,    KC_5,    KC_6, KC_ASTR, XXXXXXX,
    KC_LSPO, OCDQUOTE,CDCQUOTE,KC_LBRC, KC_RBRC,   POUND,                                           KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, KC_RSPC,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_BSPC,  KC_DEL,     KC_ENT,  KC_SPC, KC_DOT, KC_COMM, XXXXXXX, XXXXXXX
    ),
    [_FN] = LAYOUT(
    LOCKSCR, XXXXXXX, XXXXXXX, DM_REC1, DM_PLY1, RGB_VAD,                                         RGB_VAI,   KC_F7,   KC_F8,   KC_F9,  KC_F10, PRTSCR1,
     FORCEQ, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, RGB_HUD,                                         RGB_HUI,   KC_F4,   KC_F5,   KC_F6,  KC_F11, PRTSCR2,
      DELAY, XXXXXXX, XXXXXXX, DM_REC2, DM_PLY2,RGB_RMOD,                                         RGB_MOD,   KC_F1,   KC_F2,   KC_F3,  KC_F12, PRTSCR3,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, RGB_TOG,     HRM, KC_BRMD, KC_BRMU
    ),
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_BSPC:
        case FN_DEL:
        case NUM_ENT:
        case NAV_SPC:
        case ALT_S:
        case ALT_L:
            return true;
        default:
            return false;
    }
}

bool is_hrm_enabled = true;
bool is_cmd_tab_active = false;
bool is_alt_tab_active = false;
uint16_t cmd_tab_timer = 0;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        if (record->event.pressed) {
            uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
                keycode,
                record->event.key.row,
                record->event.key.col,
                get_highest_layer(layer_state),
                record->event.pressed,
                get_mods(),
                get_oneshot_mods(),
                record->tap.count
            );
        }
    #endif
    switch (keycode) {
        case ARROW:
            if (record->event.pressed) {
                tap_code(KC_MINS);
                tap_code16(KC_GT);
            }
            break;
        case LOWER:
            if (record->event.pressed) {
                tap_code16(KC_LT);
                tap_code(KC_EQL);
            }
            break;
        case GREATER:
            if (record->event.pressed) {
                tap_code16(KC_GT);
                tap_code(KC_EQL);
            }
            break;
        case DELAY:
            if (record->event.pressed) {
                _delay_ms(500);
            }
            break;
        case HRM:
            if (record->event.pressed) {
                layer_clear();
                is_hrm_enabled = !is_hrm_enabled;
                is_hrm_enabled ? default_layer_set(1UL << _QWERTY_HRM) : default_layer_set(1UL << _QWERTY);
            }
            return false;
        case CMD_TAB:
            if (record->event.pressed) {
                if (!is_cmd_tab_active) {
                    is_cmd_tab_active = true;
                    register_code(KC_LGUI);
                }
                cmd_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
};

void matrix_scan_user(void) {
    if (is_cmd_tab_active) {
        if (timer_elapsed(cmd_tab_timer) > 350 && get_highest_layer(layer_state) != _NAV) {
            unregister_code(KC_LGUI);
            is_cmd_tab_active = false;
        }
    }
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 350 && get_highest_layer(layer_state) != _NAV) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

