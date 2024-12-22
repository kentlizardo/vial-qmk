 /* Copyright 2020 Naoki Katahira
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

enum layer_number {
  _ALPHA = 0,
  _SYMBOL,
  _NAV,
  _FUNC
};

// #define RAISE MO(_NAV)
// #define LOWER MO(_SYMBOL)

// Generated from QMK Configurator and `qmk json2c`
// Must set up QMK TT for Copy, and Vial tap dance for Paste since Windows does not recognize.
// Must set up key override for swapping ( and ) to match bracket keys
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_GRV, KC_LCTL, KC_A, KC_R, KC_S, LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), KC_E, KC_I, KC_O, RCTL_T(KC_QUOT), LSFT_T(KC_ESC), KC_Z, KC_X, KC_C, KC_D, KC_V, OSM(MOD_LCTL|MOD_LSFT), OSM(MOD_RCTL|MOD_RALT), KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_BSLS), KC_LGUI, KC_LALT, QK_TRI_LAYER_UPPER, KC_SPC, KC_ENT, QK_TRI_LAYER_LOWER, KC_BSPC, OSM(MOD_LCTL|MOD_LSFT|MOD_LGUI)),
    [_SYMBOL] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_TRNS, KC_1, KC_2, KC_3, LSFT_T(KC_4), KC_5, KC_6, RSFT_T(KC_7), KC_8, KC_9, KC_0, KC_RCTL, KC_TRNS, KC_BSLS, KC_SLSH, KC_MINS, KC_EQL, KC_QUOT, KC_TRNS, KC_TRNS, KC_SCLN, KC_DOT, KC_COMM, KC_RBRC, KC_LBRC, KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_NAV] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_A, KC_S, KC_W, KC_D, KC_BTN3, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BTN1, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_RCTL, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BTN2, KC_TRNS, KC_TRNS, KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_FUNC] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_NO, KC_TRNS, KC_DEL, KC_CUT, LCTL(KC_C), LCTL(KC_V), KC_UNDO, KC_AGIN, KC_CAPS, KC_NUM, KC_SCRL, CW_TOGG, KC_RCTL, KC_TRNS, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_MUTE, KC_MPLY, KC_PSCR, KC_NO, KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYMBOL, _FUNC);
    return state;
}

static void render_logo(void) {
	
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

// char wpm[4];
char layer_misc[7];

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

static void render_status(void) {
    oled_write_P(PSTR("layer "), false);

    switch (get_highest_layer(layer_state)) {
        case _ALPHA:
            oled_write_P(PSTR("<alpha>"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("<sym>"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("<nav>"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("<func>"), false);
            break;
        default:
            sprintf(layer_misc, "MO(%01d) ", get_highest_layer(layer_state));
	    oled_write(layer_misc, false);
            break;
    }
    oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);
    // oled_write_P(PSTR("  "), false);
    // sprintf(wpm, "%03d", get_current_wpm());
    // oled_write(wpm, false);
    // oled_write_P(PSTR(" wpm\n"), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
  }
  return true;
}
