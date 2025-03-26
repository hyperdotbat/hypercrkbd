/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define EE_HANDS

#define TAPPING_TERM 140
// #define QUICK_TAP_TERM 250
// #define HOLD_ON_OTHER_KEY_PRESS
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS
// #define PERMISSIVE_HOLD_PER_KEY
// #define RETRO_TAPPING

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_SPLIT
    
    #define RGBLIGHT_EFFECT_STATIC
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #undef RGBLIGHT_EFFECT_ALTERNATING
    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_KNIGHT
    #undef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_RGB_TEST
    #undef RGBLIGHT_EFFECT_TWINKLE

    #define RGBLIGHT_DEFAULT_HUE 162
    #define RGBLIGHT_DEFAULT_SAT 84

    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_SLEEP
#endif

#undef SLEEP_LED_ENABLE

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define SPLIT_TRANSPORT_MIRROR