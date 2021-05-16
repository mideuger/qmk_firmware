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
    _EXTRA,
};

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    LOWER,
    GREATER,
    DELAY,
    HRM,
    CMD_TAB,
    ALT_TAB,
};

#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define CTLSCL LCTL_T(KC_SCLN)
#define CTLSLS LCTL_T(KC_SLSH)

#define NAV_BSPC LT(_NAV, KC_BSPC)
#define FN_DEL LT(_FN, KC_DELETE)
#define NUM_ENT LT(_NUM, KC_ENT)
#define NAV_SPC LT(_NAV, KC_SPC)

#define FN OSL(_FN)
#define TGEXT TG(_EXTRA)
#define TTEXT TT(_EXTRA)
#define OSM_SFT OSM(MOD_LSFT)

#define EURO LALT(LSFT(KC_2))
#define POUND LALT(KC_3)

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
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                              |  Y   |  U   |  I   |  O   |  P   | BSLS |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | GRV  |CTL_A |ALT_S |GUI_D |SFT_F |  G   |                              |  H   |SFT_J |GUI_K |ALT_L |CTLSCL| QUOT |
 * |------+------+------+------+------+------+------+------|  |------+------+------+------+------+------+------+------|
 * | LSPO |  Z   |  X   |  C   |  V   |  B   |      |      |  |      |      |  N   |  M   | COMM | DOT  | SLSH | RSPC |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 *                      | MPLY |ALT_TA|CMD_TA|NAV_BS|FN_DEL|  |NUM_EN|NAV_SP|OSM_SF|TTEXT | MUTE |
 *                      `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
    [_QWERTY_HRM] = LAYOUT(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
     KC_GRV,   CTL_A,   ALT_S,   GUI_D,   SFT_F,    KC_G,                                           KC_H,   SFT_J,   GUI_K,   ALT_L,  CTLSCL, KC_QUOT,
    KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
                               KC_MPLY, ALT_TAB, CMD_TAB,NAV_BSPC,  FN_DEL,    NUM_ENT, NAV_SPC, OSM_SFT,   TTEXT, KC_MUTE
    ),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                              |  Y   |  U   |  I   |  O   |  P   | BSLS |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | GRV  |  A   |  S   |  D   |  F   |  G   |                              |  H   |  J   |  K   |  L   | SCLN | QUOT |
 * |------+------+------+------+------+------+------+------|  |------+------+------+------+------+------+------+------|
 * | LSPO |  Z   |  X   |  C   |  V   |  B   |      |      |  |      |      |  N   |  M   | COMM | DOT  | SLSH | RSPC |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 *                      | MPLY |ALT_TA|CMD_TA|NAV_BS|FN_DEL|  |NUM_EN|NAV_SP|OSM_SF|TTEXT | MUTE |
 *                      `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
    [_QWERTY] = LAYOUT(
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
     KC_GRV,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
                               KC_MPLY, ALT_TAB, CMD_TAB,NAV_BSPC,  FN_DEL,    NUM_ENT, NAV_SPC, OSM_SFT,   TTEXT, KC_MUTE
    ),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  | CIRC |  AT  | HASH | AMPR | PERC |                              |      | HOME |  UP  | END  |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | ESC  | LCTL | LALT | LGUI | LSFT | MINS |                              |      | LEFT | DOWN | RGHT |ARROW | CAPS |
 * |------+------+------+------+------+------+------+------|  |------+------+------+------+------+------+------+------|
 * | LSPO | UNDO | CUT  | COPY |PASTE | UNDS |      |      |  |      |      |      |      |LOWER |GREATE| EXLM | RSPC |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 *                      |      |DM_REC|DM_PLY| BSPC | DEL  |  | ENT  | SPC  |DM_PLY|DM_REC|      |
 *                      `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
    [_NAV] = LAYOUT(
     KC_TAB, KC_CIRC,   KC_AT, KC_HASH, KC_AMPR, KC_PERC,                                        XXXXXXX, KC_HOME,   KC_UP,  KC_END, XXXXXXX, XXXXXXX,
     KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_MINS,                                        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,   ARROW, KC_CAPS,
    KC_LSPO,    UNDO,     CUT,    COPY,   PASTE, KC_UNDS, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   LOWER, GREATER, KC_EXLM, KC_RSPC,
                               XXXXXXX, DM_REC1, DM_PLY1, KC_BSPC,  KC_DEL,     KC_ENT,  KC_SPC, DM_PLY2, DM_REC2, XXXXXXX
    ),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * | TAB  |      |      | LCBR | RCBR | DLR  |                              | MINS |  7   |  8   |  9   | SLSH | PERC |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | ESC  | LCTL | LALT | LGUI | LSFT | EURO |                              | PLUS |  4   |  5   |  6   | ASTR |      |
 * |------+------+------+------+------+------+------+------|  |------+------+------+------+------+------+------+------|
 * | LSPO |      |      | LBRC | RBRC |POUND |      |      |  |      |      |  0   |  1   |  2   |  3   | EQL  | RSPC |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 *                      |      |      |      | BSPC | DEL  |  | ENT  | SPC  | DOT  | COMM |      |
 *                      `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
    [_NUM] = LAYOUT(
     KC_TAB, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,  KC_DLR,                                        KC_MINS,    KC_7,    KC_8,    KC_9, KC_SLSH, KC_PERC,
     KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,    EURO,                                        KC_PLUS,    KC_4,    KC_5,    KC_6, KC_ASTR, XXXXXXX,
    KC_LSPO, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,   POUND,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, KC_RSPC,
                               XXXXXXX, XXXXXXX, XXXXXXX,  KC_BSPC,  KC_DEL,     KC_ENT,  KC_SPC, KC_DOT, KC_COMM, XXXXXXX
    ),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |      |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * | ESC  | LCTL | LALT | LGUI | LSFT |      |                              |      |  F4  |  F5  |  F6  | F11  |      |
 * |------+------+------+------+------+------+------+------|  |------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      |      |  F1  |  F2  |  F3  | F12  |      |
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
    [_FN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
     KC_ESC, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                                        XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
/* ,-----------------------------------------.                              ,-----------------------------------------.
 * |LOCKSC|      |      | MS_U |      |RGB_HU|                              |RGB_HU|      | WH_D |      |      |PRTSCR|
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |FORCEQ|      | MS_L | MS_D | MS_R |RGB_SA|                              |RGB_SA| WH_L | WH_U | WH_R |      |PRTSCR|
 * |------+------+------+------+------+------+------+------|  |------+------+------+------+------+------+------+------|
 * |DELAY |      |      |      |      |RGB_VA|      |      |  |      |      |RGB_VA| ACL0 | ACL1 | ACL2 |      |PRTSCR|
 * `------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+------|
 *                      |RGB_TO|      | HRM  | BTN1 | BTN2 |  |      |      |      |TGEXT |      |
 *                      `----------------------------------'  `----------------------------------'
 *                                                                               generated by [keymapviz] */
    [_EXTRA] = LAYOUT(
    LOCKSCR, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, RGB_HUD,                                        RGB_HUI, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, PRTSCR1,
     FORCEQ, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, RGB_SAD,                                        RGB_SAI, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, PRTSCR2,
      DELAY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, RGB_VAI, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, PRTSCR3,
                               RGB_TOG, XXXXXXX,     HRM, KC_BTN1, KC_BTN2,    XXXXXXX, XXXXXXX, XXXXXXX,   TGEXT, XXXXXXX
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

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY_HRM:
        case _QWERTY:
            if (index == 0) {
                clockwise ? tap_code(KC_MEDIA_NEXT_TRACK) : tap_code(KC_MEDIA_PREV_TRACK);
            } else if (index == 1) {
                clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
            }
            break;
        case _NAV:
        case _NUM:
        case _FN:
            if (index == 0) {
                clockwise ? tap_code16(LSFT(LGUI(KC_Z))) : tap_code16(LGUI(KC_Z));
            } else if (index == 1) {
                clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            }
            break;
        case _EXTRA:
            if (index == 0) {
                clockwise ? rgblight_step() : rgblight_step_reverse();
            } else if (index == 1) {
                clockwise ? tap_code(KC_BRIU) : tap_code(KC_BRID);
            }
            break;
    }
}
#endif

#ifdef DYNAMIC_MACRO_ENABLE
bool is_recording_dynamic_macro = false;

void dynamic_macro_record_start_user(void) {
    is_recording_dynamic_macro = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    is_recording_dynamic_macro = false;
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

#ifdef WPM_ENABLE
uint16_t wpm_graph_timer = 0;

static void render_wpm_graph(void) {
    static uint8_t zero_bar_count = 0;
    static uint8_t bar_count = 0;
    uint8_t bar_height = 0;
    uint8_t bar_segment = 0;

    if (wpm_graph_timer == 0) {
        wpm_graph_timer = timer_read();
        return;
    }
    if (timer_elapsed(wpm_graph_timer) > 500) {
        wpm_graph_timer = timer_read();

        if (OLED_DISPLAY_HEIGHT == 64)
            bar_height = get_current_wpm() / 2;
        if (OLED_DISPLAY_HEIGHT == 32)
            bar_height = get_current_wpm() / 4;
        if (bar_height > OLED_DISPLAY_HEIGHT)
            bar_height = OLED_DISPLAY_HEIGHT;

        if (bar_height == 0) {
            // keep track of how many zero bars we have drawn.  If
            // there is a whole screen worth, turn the display off and
            // wait until there is something to do
            if (zero_bar_count > OLED_DISPLAY_WIDTH) {
                oled_off();
                return;
            }
            zero_bar_count++;
        } else
            zero_bar_count = 0;

        oled_pan(false);
        bar_count++;
        for (uint8_t i = (OLED_DISPLAY_HEIGHT / 8); i > 0; i--) {
            if (bar_height > 7) {
                if (i % 2 == 1 && bar_count % 3 == 0)
                    bar_segment = 254;
                else
                    bar_segment = 255;
                bar_height -= 8;
            } else {
                switch (bar_height) {
                    case 0:
                        bar_segment = 0;
                        break;
                    case 1:
                        bar_segment = 128;
                        break;
                    case 2:
                        bar_segment = 192;
                        break;
                    case 3:
                        bar_segment = 224;
                        break;
                    case 4:
                        bar_segment = 240;
                        break;
                    case 5:
                        bar_segment = 248;
                        break;
                    case 6:
                        bar_segment = 252;
                        break;
                    case 7:
                        bar_segment = 254;
                        break;
                }
                bar_height = 0;

                if (i % 2 == 1 && bar_count % 3 == 0)
                    bar_segment++;
            }
            oled_write_raw_byte(bar_segment, (i - 1) * OLED_DISPLAY_WIDTH);
        }
    }
}
#else
static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}
#endif

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY_HRM:
        case _QWERTY:
            oled_write_P(PSTR("qwerty\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("navigation\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("numpad\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("fn\n"), false);
            break;
        case _EXTRA:
            oled_write_P(PSTR("quantum\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }

    oled_write_P(PSTR("HRM: "), false);
    oled_write_P(is_hrm_enabled ? PSTR("on\n") : PSTR("off\n"), false);

    #ifdef WPM_ENABLE
    static char wpm_str[5];
    itoa(get_current_wpm(), wpm_str, 10);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(wpm_str, false);
    oled_write_P(PSTR("\n"), false);
    #endif

    if (is_recording_dynamic_macro) {
        oled_write_P(PSTR("                  REC"), false);
    } else {
        oled_write_P(PSTR("                     "), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        #ifdef WPM_ENABLE
        render_wpm_graph();
        #else
        render_kyria_logo();
        #endif
    }
}
#endif
