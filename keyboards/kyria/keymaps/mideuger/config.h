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

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 60000
#endif

#ifdef RGBLIGHT_ENABLE
  // #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_TWINKLE
  #define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs to a circle around both halves
  // #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs for a left half-right half columnar progression
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 150
  #define RGBLIGHT_SLEEP true  // turn off leds on sleep
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
// #define EE_HANDS

// https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk
#define TAPPING_TERM 170
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

// Disable macro nesting to avoid recursive loops
#define DYNAMIC_MACRO_NO_NESTING
