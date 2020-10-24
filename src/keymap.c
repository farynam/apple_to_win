/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

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
#include "private.c"


enum combo_events {
  CMD_COPY,
  CMD_PASTE,
  CMD_CLOSE_TAB,
  CMD_SELECT_ALL,
  CMD_FIND,
  CMD_NEW_TAB,
  CMD_MIN_WIN,
  CMD_QUIT,
  CMD_UNDO,
  CMD_HOME,
  CMD_END,
  CMD_BOLD,

  PRIV_KEYS
};

const uint16_t PROGMEM copy_combo[] = {KC_LGUI, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_LGUI, KC_V, COMBO_END};
const uint16_t PROGMEM close_tab_combo[] = {KC_LGUI, KC_W, COMBO_END};
const uint16_t PROGMEM select_all_combo[] = {KC_LGUI, KC_A, COMBO_END};
const uint16_t PROGMEM find_combo[] = {KC_LGUI, KC_F, COMBO_END};
const uint16_t PROGMEM new_tab_combo[] = {KC_LGUI, KC_T, COMBO_END};
const uint16_t PROGMEM min_win_combo[] = {KC_LGUI, KC_M, COMBO_END};
const uint16_t PROGMEM quit_app_combo[] = {KC_LGUI, KC_Q, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_LGUI, KC_Z, COMBO_END};
const uint16_t PROGMEM home_combo[] = {KC_LGUI, KC_LEFT, COMBO_END};
const uint16_t PROGMEM end_combo[] = {KC_LGUI, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM bold_combo[] = {KC_LGUI, KC_B, COMBO_END};
PRIV_COMBO

combo_t key_combos[COMBO_COUNT] = {
  [CMD_COPY] = COMBO_ACTION(copy_combo),
  [CMD_PASTE] = COMBO_ACTION(paste_combo),
  [CMD_CLOSE_TAB] = COMBO_ACTION(close_tab_combo),
  [CMD_SELECT_ALL] = COMBO_ACTION(select_all_combo),
  [CMD_FIND] = COMBO_ACTION(find_combo),
  [CMD_NEW_TAB] = COMBO_ACTION(new_tab_combo),
  [CMD_MIN_WIN] = COMBO_ACTION(min_win_combo),
  [CMD_QUIT] = COMBO_ACTION(quit_app_combo),
  [CMD_UNDO] = COMBO_ACTION(undo_combo),
  [CMD_HOME] = COMBO_ACTION(home_combo),
  [CMD_END] = COMBO_ACTION(end_combo),
  [CMD_BOLD] = COMBO_ACTION(bold_combo),

  PRIV_KEY_COMBO_REL
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMD_COPY:
      if (pressed) {
        tap_code16(LCTL(KC_C));
      }
      break;
    case CMD_PASTE:
      if (pressed) {
        tap_code16(LCTL(KC_V));
      }
      break;
    case CMD_CLOSE_TAB:
      if (pressed) {
        tap_code16(LCTL(KC_W));
      }
      break;
    case CMD_SELECT_ALL:
      if (pressed) {
        tap_code16(LCTL(KC_A));
      }
      break;
    case CMD_FIND:
      if (pressed) {
        tap_code16(LCTL(KC_F));
      }
      break; 
    case CMD_NEW_TAB:
      if (pressed) {
        tap_code16(LCTL(KC_T));
      }
      break;
    case CMD_MIN_WIN:
      if (pressed) {
        tap_code16(LALT(KC_SPC));
        tap_code16(KC_M);
        tap_code16(KC_ENT);
      }
      break;
    case CMD_QUIT:
      if (pressed) {
        tap_code16(LALT(KC_F4));
      }
      break;
    case CMD_UNDO:
      if (pressed) {
        tap_code16(LCTL(KC_Z));
      }
      break;
    case CMD_HOME:
      if (pressed) {
        tap_code16(KC_HOME);
      }
      break;
    case CMD_END:
      if (pressed) {
        tap_code16(KC_END);
      }
      break;
    case CMD_BOLD:
      if (pressed) {
        tap_code16(LCTL(KC_B));
      }
      break;
PRIV_CASE
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [0] = LAYOUT_all(
                      KC_F13,  KC_F14,  KC_F15,  KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_PSCR, KC_SLCK, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_JYEN, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,     KC_RCTL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_NUHS, KC_ENT,                                    KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RO,   KC_RSFT,              KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    KC_LCTL, KC_LGUI, KC_LALT, KC_MHEN, KC_HANJ,         KC_SPC,         KC_HAEN, KC_HENK, KC_KANA, KC_RALT, KC_DEL, KC_APP,  KC_RGUI,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),
    [1] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
};
