/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <config.h>
#include <stdio.h>
#include <string.h>
#define SHRT_MAX 32767

#define OLED_SHOW_ACTIVE_LAYER
#define OLED_SHOW_ACTIVE_LAYER_MINI_OFFHAND

#define OLED_SHOW_LOGO

#define OLED_SHOW_KEYLOG
// #define OLED_SHOW_KEYLOG_OG // the original keylogger with additional info instead of my simpler one
#define OLED_SHOW_KEYPRESSCOUNT
#define OLED_SHOW_KEYPRESSCOUNT_LEVEL
#define OLED_SHOW_KEYPRESSCOUNT_HIDEAT0
// #define OLED_SHOW_KEYPRESSCOUNT_SHOW_GLITCH_AT0 // shows a cool looking character glitch caused by trying to draw undefined memory space
// #define OLED_SHOW_KEYPRESSCOUNT_ONLY_REALKEYS // only "real keys", (<60) so modifiers dont count, idk unfinished

#define OLED_SHOW_ACTIVE_MODS_MASTER
#define OLED_SHOW_ACTIVE_MODS_OFFHAND

/// MAIN ///
enum layers{
    _BASE,
    _FIRST,
    _SECOND,
    _GAMING,
    _GAMING_NUM,
    _FUNC,
    _SPECIAL
};

// attempts at custom Backspace where Shift+Bspc = Del
enum custom_keycodes {
    SFT_BSPC = SAFE_RANGE,
    USER_RST_CTR,
    USER_RST_CTRLVL,
};

#define MOD1KC MOD_LCTL
#define MOD2KC MOD_LSFT
#define MOD3KC MOD_LALT
#define MOD4KC MOD_LGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /// Bottom row mods, Colemak-DH
  [_BASE] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                                                 ,-----------------------------------------------------.
      LT(_FUNC, KC_ESC),    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                       KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+--------|
      MT(MOD_LSFT, KC_TAB),    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                            KC_M,    KC_N,    KC_E,    KC_I, KC_O, KC_DEL,
//|--------+--------+--------+--------+--------+--------|                                                             |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    MT(MOD4KC, KC_Z),    MT(MOD3KC, KC_X),    MT(MOD2KC, KC_C),    MT(MOD1KC, KC_D),    KC_V,                         KC_K,    MT(MOD1KC, KC_H), MT(MOD2KC, KC_COMM),  MT(MOD3KC, KC_DOT), MT(MOD4KC, KC_SLSH),  MO(_FUNC),
  //|--------+--------+--------+--------+--------+--------+--------|                                    |--------+--------+--------+--------+--------+--------+--------|
                                          MT(MOD_LSFT, KC_LGUI),   KC_SPC,  LT(_FIRST, KC_TAB),             LT(_SECOND, KC_ENT),    SFT_BSPC,    MT(MOD_RALT, KC_TAB)
                                      //`--------------------------'                                    `--------------------------'
  ),

  [_FIRST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                               ,-----------------------------------------------------.
        LT(_SECOND, KC_ESC),    KC_8,    KC_7,    KC_6,    KC_5,    KC_TILD,                                  KC_MUTE,    KC_PGDN,    KC_INS,    KC_PGUP,    KC_RSFT, KC_TAB,
    //|--------+--------+--------+--------+--------+--------|                               |--------+--------+--------+--------+--------+--------|
        MT(MOD_LSFT, KC_TAB),    KC_4,      KC_3,    KC_2,   KC_1,     KC_COLN,                                  KC_HOME, KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                                   |--------+--------+--------+--------+--------+--------|
      KC_LCTL, MT(MOD4KC, KC_MINS), MT(MOD3KC, KC_EQL),   MT(MOD2KC, KC_0),   MT(MOD1KC, KC_9),  KC_DOT,                    KC_SCLN, MT(MOD1KC, KC_END), MT(MOD2KC, KC_COMM), MT(MOD3KC, KC_DOT), MT(MOD4KC, KC_SLSH), _______,
  //|--------+--------+--------+--------+--------+--------+--------|                                                |--------+--------+--------+--------+--------+--------+--------|
                                          MT(MOD_LSFT, KC_LGUI), LT(_SECOND, KC_SPC),  _______,                     KC_ENT,   SFT_BSPC, MO(_SECOND)  
                                      //`--------------------------'                                                `--------------------------'
  ),

  [_SECOND] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                 ,-----------------------------------------------------.
       KC_TAB, KC_TILD,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,                                           KC_PERC, KC_CIRC, KC_ASTR, KC_MINS, KC_EQL, SFT_BSPC,
  //|--------+--------+--------+--------+--------+--------|                                 |--------+--------+--------+--------+--------+--------|
      MT(MOD_LSFT, KC_TAB), KC_BSLS, KC_AMPR, KC_LPRN, KC_RPRN, KC_LBRC,                                    KC_HOME, KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                                             |--------+--------+--------+--------+--------+--------|
      KC_LCTL, MT(MOD4KC, KC_TILD), MT(MOD3KC, KC_LCBR), MT(MOD2KC, KC_RCBR), MT(MOD1KC, KC_RBRC), KC_SCLN,                      KC_LALT, MT(MOD1KC, KC_END), MT(MOD2KC, KC_COMM), MT(MOD3KC, KC_DOT), MT(MOD4KC, KC_SLSH), _______,
  //|--------+--------+--------+--------+--------+--------+--------|                                                |--------+--------+--------+--------+--------+--------+--------|
                                          MT(MOD_LSFT, KC_LGUI),   MO(_FUNC),  KC_SPC,                                      KC_ENT, _______, KC_RALT
                                      //`--------------------------'                                                `--------------------------'
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  LT(_FUNC, KC_ESC),    KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  TO(_GAMING_NUM),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,       KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SLSH, TG(_GAMING),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,                         KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  MO(_FUNC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        //   KC_LALT,   LT(_GAMING_NUM, KC_SPC),  MO(_GAMING_NUM),     KC_ENT,   SFT_BSPC, TO(_GAMING_NUM)
                                        //   KC_LALT,   KC_SPC,  MO(_GAMING_NUM),     KC_ENT,   SFT_BSPC, TO(_GAMING_NUM)
                                          KC_LALT,   KC_SPC,  LT(_GAMING_NUM, KC_LGUI),     KC_ENT,   SFT_BSPC, KC_TAB
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_LGUI,    KC_9,    KC_3,    KC_W,    KC_2,    KC_6,                         KC_MUTE,    KC_PGDN,    KC_INS,    KC_PGUP,   KC_RSFT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,       KC_1,    KC_A,    KC_S,    KC_D,    KC_7,                         KC_HOME, KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, TO(_GAMING),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_LSFT,    KC_5,    KC_0,    KC_4,    KC_8,                         KC_F16,  KC_END, KC_COMM,  KC_DOT, KC_SLSH,  MO(_FUNC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_SPC,  _______,     KC_ENT,   SFT_BSPC, KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

  [_FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TO(_SPECIAL), KC_F8, KC_F7, KC_F6, KC_F5, KC_F13,                      KC_MPLY, KC_MUTE, KC_F15, KC_F14, TO(_GAMING), KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F4, KC_F3, KC_F2, KC_F1, KC_MNXT,                      KC_HOME, KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_F12, KC_F11, KC_F9, KC_F10, KC_MPRV,                      KC_F16, KC_END, KC_SCRL, KC_PAUS, KC_PSCR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_SPC,  MO(_SPECIAL),     KC_ENT, SFT_BSPC, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_SPECIAL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, RGB_TOG, USER_RST_CTR, USER_RST_CTRLVL, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN2, KC_WH_U, KC_MYCM, KC_SLEP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_BRIU,                      KC_WH_L, KC_MS_L, KC_MS_D,  KC_MS_U,  KC_MS_R, TG(_SPECIAL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BRID,                      KC_WH_R, KC_BTN4, KC_BTN3, KC_WH_D, KC_BTN5, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_SPC,  _______,     KC_ENT, SFT_BSPC, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//   if (!is_keyboard_master()) {
//     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
//     // return OLED_ROTATION_90;
//   }
//   return rotation;
    // if (!is_keyboard_master()){return OLED_ROTATION_0;}
    return OLED_ROTATION_270;
}


/// LAYER DISPLAY ///
#ifdef OLED_SHOW_ACTIVE_LAYER
void oled_render_layerstate(void) {
    oled_clear();
    const char *layer_str;
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            layer_str = ">_";
            break;
        case _FIRST:
            layer_str = "N 7\nu\nm";
            break;
        case _SECOND:
            layer_str = "S @\ny\nm\nb\no\nl\ns";
            break;
        case _GAMING:
            layer_str = "G\na\nm\ne";
            break;
        case _GAMING_NUM:
            layer_str = "G 7\na\nm\ne\n|\nN\nU\nM";
            break;
        case _FUNC:
            layer_str = "F Fn\nu\nn\nc\nt\ni\no\nn";
            break;
        case _SPECIAL:
            layer_str = "S !!\nP\nE\nC\nI\nA\nL";
            break;
        default:
            layer_str = "";
            break;
    }
    oled_write_ln(layer_str, false);
}
#endif

#ifdef OLED_SHOW_ACTIVE_LAYER_MINI_OFFHAND
void oled_render_simplified_layerstate_bot(void) {
    oled_set_cursor(oled_max_chars()/2, oled_max_lines()-1);
    const char *simple_layer_str;
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            simple_layer_str = "";
            break;
        case _FIRST:
            simple_layer_str = "7";
            break;
        case _SECOND:
            simple_layer_str = "@";
            break;
        case _GAMING_NUM:
            simple_layer_str = "7";
            break;
        case _FUNC:
            simple_layer_str = "Fn";
            break;
        case _SPECIAL:
            simple_layer_str = "!!";
            break;
        default:
            simple_layer_str = "";
            break;
    }
    oled_write_ln(simple_layer_str, false);
}
#endif


/// KEYLOGGER ///
// #ifdef OLED_SHOW_KEYLOG
#if defined(OLED_SHOW_KEYLOG) || defined(OLED_SHOW_KEYLOG_OG)
static const char code_to_name[60] = {
// static const char code_to_name[60] PROGMEM = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    // 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    ' ', ' ', ' ', ' ', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};
#endif
// the og keylogger is too heavy?
#ifdef OLED_SHOW_KEYLOG_OG
char keylog_str[24];
void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}
void oled_render_keylog(void) {
    oled_set_cursor(oled_max_chars()/2, oled_max_lines()-1);
    oled_write(keylog_str, false);
}
#endif

#ifdef OLED_SHOW_KEYLOG
#ifndef OLED_SHOW_KEYLOG_OG
char keylog_char[2];
void set_keylogchar(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }
    keylog_char[0] = name;
    keylog_char[1] = '\0';
}
void oled_render_keylogchar(void) {
    oled_set_cursor(oled_max_chars()/2, 0);
    oled_write(keylog_char, false);
}
void oled_render_keylogchar_bot(void) {
    oled_set_cursor(oled_max_chars()/2, oled_max_lines()-1);
    oled_write(keylog_char, false);
}
#endif
#endif

uint8_t get_xoffset_based_on_length(char *buf){
    uint8_t len = strlen(buf);
    uint8_t offset = (oled_max_chars() - len) / 2;
    if(len%2==0){offset+=1;}
    // Offset by 1 for even number length
    if(len>5){offset=0;}
    return offset;
}

#ifdef OLED_SHOW_KEYPRESSCOUNT
    short keypress_counter = 0; // MAX IS 32167
    #ifdef OLED_SHOW_KEYPRESSCOUNT_LEVEL
        uint8_t keypress_counter_level = 0; // +1 for reaching the max each time, (5 overflows)
        char keypress_counter_level_char = '+';
    #endif
    void oled_render_keypress_counter(void) {
        uint8_t y_pos = 0;
        #ifdef OLED_SHOW_KEYLOG
            y_pos += 2;
        #endif
        char buf[10];

        bool should_show = true;
        #ifdef OLED_SHOW_KEYPRESSCOUNT_HIDEAT0
            if(keypress_counter == 0){
                should_show = false;
            }
        #endif
        if(should_show){
            itoa(keypress_counter, buf, sizeof(buf));
        }
        else{
            #ifndef OLED_SHOW_KEYPRESSCOUNT_SHOW_GLITCH_AT0
                buf[0] = '\0';
            #endif
        }

        oled_set_cursor(get_xoffset_based_on_length(buf), y_pos);
        oled_write(buf, false);
        
        #ifdef OLED_SHOW_KEYPRESSCOUNT_LEVEL
            buf[0] = '\0';
            for(uint8_t i = 0; i < keypress_counter_level; i++){
                strlcat(buf, &keypress_counter_level_char, sizeof(buf));
            }

            oled_set_cursor(get_xoffset_based_on_length(buf), y_pos+2);
            oled_write(buf, false);
        #endif
    }
#endif


void oled_render_top_candy(void) {
    #ifdef OLED_SHOW_KEYLOG
        #ifdef OLED_SHOW_KEYLOG_OG
            oled_render_keylog();
        #else
            oled_render_keylogchar();
        #endif
    #endif
    #ifdef OLED_SHOW_KEYPRESSCOUNT
        oled_render_keypress_counter();
    #endif
}

/// MODSTATE ///
#if defined(OLED_SHOW_ACTIVE_MODS_MASTER) || defined(OLED_SHOW_ACTIVE_MODS_OFFHAND)
char modstate_str[32];
static uint8_t active_mods;
void update_modstate(void) {
    modstate_str[0] = '\0';

    if ((active_mods & MOD_BIT(KC_LCTL)) || (active_mods & MOD_BIT(KC_RALT))) {
        strlcat(modstate_str, "\nCtrl", sizeof(modstate_str));
    }
    if ((active_mods & MOD_BIT(KC_LALT)) || (active_mods & MOD_BIT(KC_RALT))) {
        strlcat(modstate_str, "\nAlt", sizeof(modstate_str));
    }
    if (active_mods & MOD_BIT(KC_LSFT)) {
        strlcat(modstate_str, "\nShft", sizeof(modstate_str));
    }
    if (active_mods & MOD_BIT(KC_LGUI)) {
        strlcat(modstate_str, "\nMod", sizeof(modstate_str));
    }
}
void oled_render_modstate_bottom(void) {
    oled_set_cursor(1, (oled_max_lines()/2)+2);
    oled_write(modstate_str, false);
}
#endif


/// LOGO ///
#ifdef OLED_SHOW_LOGO
void oled_render_logo(void) {
    // static const char PROGMEM crkbd_logo[] = {
    //     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    //     0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
    //     0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    //     0};
    // oled_write_P(crkbd_logo, false);
    
    /// 'oledArchLogo', 32x128px
    static const char epd_bitmap_oledArchLogo [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xff, 
        0xff, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfe, 0xff, 0xfe, 0xfd, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x4f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xd8, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x04, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x04, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    
    /// 'oledSteamLogo', 32x128px
    static const char epd_bitmap_oledSteamLogo [] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 
        0xfc, 0xfc, 0x7c, 0x7c, 0x7c, 0x78, 0x78, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x78, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x07, 
        0x01, 0x38, 0x46, 0x82, 0x82, 0x82, 0x42, 0x7c, 0x00, 0x83, 0xff, 0xff, 0xfe, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x10, 0x70, 0xe0, 0xe0, 0xc1, 0xc1, 0x03, 0x83, 0x83, 0x05, 0x85, 0xc8, 0x70, 0x80, 
        0xe0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x1e, 0x1e, 0x3e, 0x3e, 0x3e, 0x3f, 0x3f, 
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    if (get_highest_layer(layer_state) == _GAMING || get_highest_layer(layer_state) == _GAMING_NUM) {
        oled_write_raw_P(epd_bitmap_oledSteamLogo, sizeof(epd_bitmap_oledSteamLogo));
    } else {
        oled_write_raw_P(epd_bitmap_oledArchLogo, sizeof(epd_bitmap_oledArchLogo));
    }
}
#endif


bool oled_task_user(void) {
    active_mods = get_mods();
    update_modstate();

    if (is_keyboard_master()) {
        #ifdef OLED_SHOW_ACTIVE_LAYER
            oled_render_layerstate();
        #endif
        #ifdef OLED_SHOW_ACTIVE_MODS_MASTER
            oled_render_modstate_bottom();
        #endif
    } else {
        #ifdef OLED_SHOW_LOGO
            oled_render_logo();
        #endif
        // Always draw other stuff after logo
        oled_render_top_candy();
        #ifdef OLED_SHOW_ACTIVE_MODS_OFFHAND
            oled_render_modstate_bottom();
        #endif
        #ifdef OLED_SHOW_ACTIVE_LAYER_MINI_OFFHAND
            oled_render_simplified_layerstate_bot();
        #endif
    }
    return false;
}

// #endif // OLED_ENABLE

// static bool sft_bspc_was_del = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef OLED_ENABLED
            #ifdef OLED_SHOW_KEYLOG
                #ifdef OLED_SHOW_KEYLOG_OG
                    set_keylog(keycode, record);
                #else
                    set_keylogchar(keycode, record);
                #endif
            #endif
            #ifdef OLED_SHOW_KEYPRESSCOUNT
                bool should_count_keypress = true;
                #ifdef OLED_SHOW_KEYPRESSCOUNT_ONLY_REALKEYS
                    if(keycode < 60){
                        should_count_keypress = false;
                    }
                #endif
                
                if(should_count_keypress){
                    keypress_counter += 1;
                    if (keypress_counter >= SHRT_MAX){
                        keypress_counter = 0;
                        #ifdef OLED_SHOW_KEYPRESSCOUNT_LEVEL
                            keypress_counter_level += 1;
                        #endif
                    }
                }
            #endif
        #endif
    }
    switch (keycode) {
        // Shift+Backspace = Delete
        // case SFT_BSPC:
        //     if (record->event.pressed) {
        //         if (get_mods() & MOD_MASK_SHIFT) {
        //             del_mods(MOD_MASK_SHIFT);
        //             clear_oneshot_mods();
        //             register_code(KC_DEL);
        //             sft_bspc_was_del = true;
        //         } else {
        //             register_code(KC_BSPC);
        //         }
        //     } else {
        //         if (sft_bspc_was_del) {
        //             unregister_code(KC_DEL);
        //             sft_bspc_was_del = false;
        //         } else {
        //             unregister_code(KC_BSPC);
        //         }
        //         if (get_mods() & MOD_MASK_SHIFT) {
        //             add_mods(MOD_MASK_SHIFT);
        //         }
        //     }
        //     return false;
        case SFT_BSPC:
            if (record->event.pressed) {
                register_code(KC_BSPC);
            } else {
                unregister_code(KC_BSPC);
            }
            return false;
        case USER_RST_CTR:
            if (record->event.pressed) {
                #ifdef OLED_SHOW_KEYPRESSCOUNT
                    keypress_counter = 0;
                #endif
            }
            return false;
        case USER_RST_CTRLVL:
            if (record->event.pressed) {
                #ifdef OLED_SHOW_KEYPRESSCOUNT_LEVEL
                    keypress_counter_level = 0;
                #endif
            }
            return false;
    }
    return true;
}

bool should_process_keypress(void) { return true; }

#endif // OLED_ENABLE | THIS AT THE END SPECIFICALLY MAKES LIKE 15 INTELLISENSE ERRORS DISAPPEAR