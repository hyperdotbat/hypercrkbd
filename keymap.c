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
#include <stdio.h>
#include <string.h>

enum layers{
    _BASE,
    _FIRST,
    _SECOND,
    _GAMING,
    _GAMING_NUM,
    _FUNC,
    _SPECIAL
};

// enum custom_keycodes {
//     SHIFT_T = KC_T,
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case SHIFT_T:
//             if (record->event.pressed) {
//                 register_mods(MOD_BIT(KC_LSFT));
//             } else {
//                 unregister_mods(MOD_BIT(KC_LSFT));
//             }
//             return false;
//     }
//     return true;
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [_BASE] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_TAB,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LSFT,    MT(MOD_LGUI, KC_A),    MT(MOD_LALT, KC_R),    MT(MOD_LSFT, KC_S),    MT(MOD_LCTL, KC_T),    KC_G,                         KC_M,    MT(MOD_RCTL, KC_N),    MT(MOD_RSFT, KC_E),    MT(MOD_RALT, KC_I), MT(MOD_RGUI, KC_O), KC_QUOT,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  MO(_FUNC),
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           KC_LGUI,   KC_SPC,  MO(_FIRST),     KC_ENT,   KC_BSPC, KC_RALT
//                                       //`--------------------------'  `--------------------------'

//   ),

    ///Bottom row mods
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I, KC_O, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    MT(MOD_LGUI, KC_Z),    MT(MOD_LALT, KC_X),    MT(MOD_LSFT, KC_C),    MT(MOD_LCTL, KC_D),    KC_V,                         KC_K,    MT(MOD_LCTL, KC_H), MT(MOD_LSFT, KC_COMM),  MT(MOD_LALT, KC_DOT), MT(MOD_LGUI, KC_SLSH),  MO(_FUNC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT(MOD_LSFT, KC_LGUI),   KC_SPC,  MO(_FIRST),     MT(MO(_SECOND), KC_ENT),   KC_BSPC, MT(MOD_RALT, KC_TAB)
                                      //`--------------------------'  `--------------------------'
  ),

    /// Old NumPad design
//   [_FIRST] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_ESC,    XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_COMM,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LSFT,    KC_0,      KC_4,    KC_5,   KC_6,     KC_DOT,                      KC_HOME, KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LCTL, XXXXXXX, KC_7,    KC_8,     KC_9,  XXXXXXX,                      XXXXXXX, KC_END, KC_LALT, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           MT(MOD_LSFT, KC_LGUI), KC_SPC,  _______,     KC_ENT,   KC_BSPC, MO(_SECOND)  
//                                       //`--------------------------'  `--------------------------'
//   ),

    /// Revamped NumPad design
//   [_FIRST] = LAYOUT_split_3x6_3(
//   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//        KC_ESC,    XXXXXXX,    KC_4,    KC_5,    KC_6,    KC_COMM,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LSFT,    KC_0,      KC_1,    KC_2,   KC_3,     KC_DOT,                      KC_HOME, KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, XXXXXXX,
//   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//       KC_LCTL, XXXXXXX, KC_7,    KC_8,     KC_9,  XXXXXXX,                      XXXXXXX, KC_END, KC_LALT, XXXXXXX, XXXXXXX, _______,
//   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                           MT(MOD_LSFT, KC_LGUI), KC_SPC,  _______,     KC_ENT,   KC_BSPC, MO(_SECOND)  
//                                       //`--------------------------'  `--------------------------'
//   ),

  [_FIRST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_8,    KC_7,    KC_6,    KC_5,    KC_MINS,                         KC_MUTE,    KC_PGDN,    KC_INS,    KC_PGUP,    KC_RSFT, KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_4,      KC_3,    KC_2,   KC_1,     KC_EQL,                      KC_HOME, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_UP, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LALT, KC_TAB,    KC_9,     KC_0,  KC_DOT,                      KC_LALT, KC_END, KC_COMM, KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT(MOD_LSFT, KC_LGUI), KC_SPC,  _______,     KC_ENT,   KC_BSPC, MO(_SECOND)  
                                      //`--------------------------'  `--------------------------'
  ),

  [_SECOND] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_GRV,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,                      KC_PERC, KC_CIRC, KC_ASTR, KC_MINS, KC_EQL, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_BSLS, KC_AMPR, KC_LPRN, KC_RPRN, KC_TILD,                      KC_HOME, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_UP, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_SCLN,                      KC_LALT, KC_END, KC_COMM, KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MT(MOD_LSFT, KC_LGUI),   MO(_FUNC),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_B,       KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_O, TG(_GAMING),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  MO(_FUNC),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_SPC,  MO(_GAMING_NUM),     KC_ENT,   KC_BSPC, TO(_GAMING_NUM)
                                      //`--------------------------'  `--------------------------'

  ),

  [_GAMING_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_LGUI,    KC_5,    KC_1,    KC_W,    KC_2,    KC_3,                         KC_MUTE,    KC_PGDN,    KC_INS,    KC_PGUP,   KC_RSFT,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,       KC_6,    KC_A,    KC_S,    KC_D,    KC_4,                         KC_HOME, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_UP, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_LSFT,    KC_8,    KC_0,    KC_9,    KC_7,                         KC_F16,  KC_END, KC_COMM,  KC_DOT, KC_SLSH,  TG(_GAMING_NUM),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   KC_SPC,  _______,     KC_ENT,   KC_BSPC, KC_LGUI
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
                                          KC_LALT, KC_SPC,  MO(_SPECIAL),     KC_ENT, KC_BSPC, KC_LGUI
                                      //`--------------------------'  `--------------------------'
  ),

  [_SPECIAL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN2, KC_WH_U, KC_MYCM, KC_SLEP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_BRIU,                      KC_WH_L, KC_MS_L, KC_MS_D,  KC_MS_U,  KC_MS_R, TG(_SPECIAL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BRID,                      KC_WH_R, KC_BTN4, KC_BTN3, KC_WH_D, KC_BTN5, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_SPC,  _______,     KC_ENT, KC_BSPC, KC_LGUI
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

// #define L_BASE 0
// #define L_LOWER 2
// #define L_RAISE 4
// #define L_ADJUST 8

void oled_render_layerstate(void) {
    oled_clear();
    // oled_write_P(PSTR("Layer: "), false);
    // switch (layer_state) {
    //     case L_BASE:
    //         oled_write_ln_P(PSTR("Default"), false);
    //         break;
    //     case L_LOWER:
    //         oled_write_ln_P(PSTR("Lower"), false);
    //         break;
    //     case L_RAISE:
    //         oled_write_ln_P(PSTR("Raise"), false);
    //         break;
    //     case L_ADJUST:
    //     case L_ADJUST|L_LOWER:
    //     case L_ADJUST|L_RAISE:
    //     case L_ADJUST|L_LOWER|L_RAISE:
    //         oled_write_ln_P(PSTR("Adjust"), false);
    //         break;
    // }

    // oled_set_cursor(oled_max_chars()/2, 1);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("B\na\ns\ne"), false);
            // oled_write_ln_P(PSTR("B  A\na\ns\ne"), false);
            // oled_write_ln_P(PSTR("D  A\ne\nf\na\nu\nl\nt"), false);
            break;
        case _FIRST:
            oled_write_ln_P(PSTR("N  1\nu\nm\nb\ne\nr\ns"), false);
            break;
        case _SECOND:
            oled_write_ln_P(PSTR("S  #\ny\nm\nb\no\nl\ns"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("G\na\nm\ne"), false);
            break;
        case _GAMING_NUM:
            oled_write_ln_P(PSTR("G\na\nm\ne\n|\nN\nU\nM"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("F Fn\nu\nn\nc\nt\ni\no\nn"), false);
            break;
        case _SPECIAL:
            oled_write_ln_P(PSTR("S !!\nP\nE\nC\nI\nA\nL"), false);
            break;
    }
}

void oled_render_simplified_layerstate_bot(void) {
    oled_set_cursor(oled_max_chars()/2, oled_max_lines()-1);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            // oled_write_ln_P(PSTR("A"), false);
            break;
        case _FIRST:
            oled_write_ln_P(PSTR("1"), false);
            break;
        case _SECOND:
            oled_write_ln_P(PSTR("#"), false);
            break;
        // case _GAMING:
        //     oled_write_ln_P(PSTR("G"), false);
        //     break;
        case _GAMING_NUM:
            oled_write_ln_P(PSTR("1"), false);
            break;
        case _FUNC:
            oled_write_ln_P(PSTR("Fn"), false);
            break;
        case _SPECIAL:
            oled_write_ln_P(PSTR("!!"), false);
            break;
    }
}


// char keylog_str[24] = {"H"};
char keylog_char[2];

// const char code_to_name[60] = {
//     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
//     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
//     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
//     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
//     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'W', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    ' ', ' ', ' ', ' ', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

// void set_keylog(uint16_t keycode, keyrecord_t *record) {
//   char name = ' ';
//     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
//         (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
//   if (keycode < 60) {
//     name = code_to_name[keycode];
//   }

//   update keylog
//   snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
//            record->event.key.row, record->event.key.col,
//            keycode, name);
// }
// void oled_render_keylog(void) {
//     oled_set_cursor(oled_max_chars()/2, oled_max_lines()-1);
//     oled_write(keylog_str, false);
// }


void set_keylogchar(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }
    keylog_char[0] = name;
    keylog_char[1] = '\0'; // Null-terminate the string
}
void oled_render_keylogchar_top(void) {
    oled_set_cursor(oled_max_chars()/2, 1);
    oled_write(keylog_char, false);
}
void oled_render_keylogchar_bot(void) {
    oled_set_cursor(oled_max_chars()/2, oled_max_lines()-1);
    oled_write(keylog_char, false);
}

char modstate_str[32] = {};
static uint8_t active_mods;
void update_modstate(void) {
    char temp_str[32];
    temp_str[0] = '\0';
    strcat(temp_str, "\n");
    // strlcat(temp_str, "\n", sizeof(temp_str));

    if ((active_mods & MOD_BIT(KC_LCTL)) || (active_mods & MOD_BIT(KC_RALT))) {
        strlcat(temp_str, "\nCtrl", sizeof(temp_str));
    }
    if ((active_mods & MOD_BIT(KC_LALT)) || (active_mods & MOD_BIT(KC_RALT))) {
        strlcat(temp_str, "\nAlt", sizeof(temp_str));
    }
    if (active_mods & MOD_BIT(KC_LSFT)) {
        strlcat(temp_str, "\nShft", sizeof(temp_str));
    }
    if (active_mods & MOD_BIT(KC_LGUI)) {
        strlcat(temp_str, "\nMod", sizeof(temp_str));
    }

    modstate_str[0] = '\0';

    strlcat(modstate_str, temp_str, sizeof(modstate_str));
}
void matrix_scan_user(void) {
    active_mods = get_mods(); // Update the state of active modifier keys
    update_modstate(); // Update the keylog string based on active modifier keys
}

void oled_render_modstate(void) {
    oled_write(modstate_str, false);
}

// void oled_render_modstate_offhand(void) {
//     oled_set_cursor(1, (oled_max_lines()/2));
//     oled_write(modstate_str, true);
// }

// void render_bootmagic_status(bool status) {
//     /* Show Ctrl-Gui Swap options */
//     static const char PROGMEM logo[][2][3] = {
//         {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
//         {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
//     };
//     if (status) {
//         oled_write_ln_P(logo[0][0], false);
//         oled_write_ln_P(logo[0][1], false);
//     } else {
//         oled_write_ln_P(logo[1][0], false);
//         oled_write_ln_P(logo[1][1], false);
//     }
// }

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

    // oled_write_P(epd_bitmap_archLogo, false);
    oled_clear();
    switch(get_highest_layer(layer_state)){
        case _GAMING:
        case _GAMING_NUM:
            oled_write_raw_P(epd_bitmap_oledSteamLogo, sizeof(epd_bitmap_oledSteamLogo));
            break;
        default:
            oled_write_raw_P(epd_bitmap_oledArchLogo, sizeof(epd_bitmap_oledArchLogo));
            break;
    }
    // if(get_highest_layer(layer_state)==_GAMING || get_highest_layer(layer_state)==_GAMING_NUM){
    //    oled_clear();
    //    oled_write_raw_P(epd_bitmap_oledSteamLogo, sizeof(epd_bitmap_oledSteamLogo));
    // }else{
    //     oled_clear();
    //     oled_write_raw_P(epd_bitmap_oledArchLogo, sizeof(epd_bitmap_oledArchLogo));
    // }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layerstate();
        oled_render_modstate();
    } else {
        oled_render_logo();
        oled_render_keylogchar_top();
        // oled_render_keylogchar_bot();
        // oled_render_modstate();
        // oled_render_modstate_offhand();
        oled_render_simplified_layerstate_bot();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    // set_keylog(keycode, record);
    set_keylogchar(keycode, record);
  }
  return true;
}

bool should_process_keypress(void) { return true; }

#endif // OLED_ENABLE
