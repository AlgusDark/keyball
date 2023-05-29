/*
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

#include "quantum.h"

#include "lib/oledkit/oledkit.h"

// Move to next/previous tab
#define NEXT_TAB LCTL(KC_PGDN)
#define PREV_TAB LCTL(KC_PGUP)

// Thumb layer switch
#define SYM_ENTER LT(SYMBOL, KC_ENTER)
#define NAV_SPACE LT(NAV, KC_SPACE)
#define MS_BSPACE LT(MOUSE, KC_BSPC)
#define DIG_SPACE LT(DIGITS, KC_SPACE)

// Move to buffers in code
#define CODE_BCK LCTL(KC_O)
#define CODE_FWD LCTL(KC_I)

// Used for Move to left/right space
#define MV_LSPC LGUI(LCTL(KC_LEFT))
#define MV_RSPC LGUI(LCTL(KC_RIGHT))

// Useful for changing to # space
#define SP_1 LALT(KC_1)
#define SP_2 LALT(KC_2)
#define SP_3 LALT(KC_3)
#define SP_4 LALT(KC_4)
#define SP_5 LALT(KC_5)
#define SP_6 LALT(KC_6)
#define SP_7 LALT(KC_7)
#define SP_8 LALT(KC_8)
#define SP_9 LALT(KC_9)
#define SP_0 LALT(KC_0)

// :::::: QWERTY ::::::
// ==> Left HYPER and MEH
#define ME_W MEH_T(KC_W)  // MT(MOD_LCTL | MOD_LSFT | MOD_LALT, kc)
#define HY_E HYPR_T(KC_E) // MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, kc)
// ==> Right HYPER and MEH
#define HY_I HYPR_T(KC_I)
#define ME_O MEH_T(KC_O)

// ==> Left homerows
#define HR_A MT(MOD_LCTL, KC_A)
#define HR_S MT(MOD_LALT, KC_S)
#define HR_D MT(MOD_LSFT, KC_D)
#define HR_F MT(MOD_LGUI, KC_F)
// ==> Right homerows
#define HR_J MT(MOD_LGUI, KC_J)
#define HR_K MT(MOD_RSFT, KC_K)
#define HR_L MT(MOD_LALT, KC_L)
#define HR_SCLN MT(MOD_LCTL, KC_SCLN)

// ==> Left Spanish layer
#define SPA_G LT(SPANISH, KC_G)
// ==> Right Spanish layer
#define SPA_H LT(SPANISH, KC_H)

// :::::: COLEMAK ::::::
// ==> Left HYPER and MEH
#define ME_W MEH_T(KC_W)
#define HY_F HYPR_T(KC_F)
// ==> Right HYPER and MEH
#define HY_U HYPR_T(KC_U)
#define ME_Y MEH_T(KC_Y)

// ==> Left homerows
#define CM_A MT(MOD_LCTL, KC_A)
#define CM_R MT(MOD_LALT, KC_R)
#define CM_S MT(MOD_LSFT, KC_S)
#define CM_T MT(MOD_LGUI, KC_T)
// ==> Right homerows
#define CM_N MT(MOD_LGUI, KC_N)
#define CM_E MT(MOD_RSFT, KC_E)
#define CM_I MT(MOD_LALT, KC_I)
#define CM_O MT(MOD_LCTL, KC_O)

// ==> Left Spanish layer
#define SPC_G LT(SPANISH_DH, KC_G)
// ==> Right Spanish layer
#define SPC_M LT(SPANISH_DH, KC_M)

enum custom_keycodes {
    KC_RESTORE_TAB = SAFE_RANGE,
    UMLAU_U        = LT(0, KC_U),
    ACUTE_A        = LT(0, KC_A),
    ACUTE_E        = LT(0, KC_E),
    ACUTE_I        = LT(0, KC_I),
    ACUTE_O        = LT(0, KC_O),
    ACUTE_U        = LT(8, KC_U),
    TILDE_N        = LT(0, KC_N),
    SW_LANG,
};

#define BASE 0
#define NAV 1
#define SYMBOL 2
#define DIGITS 3
#define SPANISH 4
#define CONFIG 5
#define MOUSE 6

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* [0] = LAYOUT_universal( */
  /*   _______ , _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,  */
  /*   _______ , _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,  */
  /*   _______ , _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,  */
  /*                      _______, _______, _______, _______, _______,                      _______, _______, _______, _______,          _______,   */
  /* ), */

  /* [0] = LAYOUT_universal( */
  /*   _______ , _______ , _______ , _______ , _______ , _______ , */
  /*   _______ , _______ , _______ , _______ , _______ , _______ , */
  /*   _______ , _______ , _______ , _______ , _______ , _______ , */
  /*                       _______ , _______ , _______ , _______ , _______ , */
  /**/
  /*             _______ , _______ , _______ , _______ , _______ , _______ , */
  /*             _______ , _______ , _______ , _______ , _______ , _______ , */
  /*             _______ , _______ , _______ , _______ , _______ , _______ , */
  /*   _______ , _______ , _______ , _______           , _______  */
  /* ), */

/* LAYOUT_universal */

  [BASE] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,             KC_Y     , KC_U     , HY_I     , ME_O     , KC_P     , KC_EQL   ,
    KC_ESC   , HR_A     , HR_S     , HR_D     , HR_F     , SPA_G    ,             SPA_H    , HR_J     , HR_K     , HR_L     , HR_SCLN  , KC_QUOTE ,
    KC_GRAVE , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,             KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_MINUS ,
                          KC_LCTL  , KC_LALT  , KC_LSFT  , NAV_SPACE,             MS_BSPACE, DIG_SPACE, SYM_ENTER, _______  , _______             , MO(CONFIG) 

  ),

  [NAV] = LAYOUT_universal(
    _______ , MV_LSPC, PREV_TAB, NEXT_TAB, MV_RSPC, _______, KC_SPACE, KC_HOME , KC_UP  , KC_END  , _______  , _______, 
    _______ , KC_LCTL, KC_LALT , KC_LSFT , KC_LGUI, _______, KC_BSPC , KC_LEFT , KC_DOWN, KC_RIGHT, KC_DELETE, _______, 
    _______ , SP_1   , SP_2    , SP_3    , SP_4   , SP_5   , KC_ENTER, CODE_BCK, KC_PGDN, KC_PGUP , CODE_FWD , _______,
                       _______ , _______ , _______, _______, _______, _______,  _______ , _______ , _______          , _______

  ),

  [SYMBOL] = LAYOUT_universal(
    _______ , KC_TILD, KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE, KC_PERC, KC_ASTR, KC_PLUS, KC_MINUS, KC_SLASH, _______, 
    KC_DQUO , KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , KC_AT, KC_PIPE, _______, _______, _______ , _______ , _______, 
    _______ , KC_QUES, KC_LBRC, KC_RBRC, KC_HASH, KC_GRAVE, KC_BSLS, KC_EXLM, KC_LT  , KC_GT   , KC_EQL  , _______, 
                       _______ , _______ , _______, _______, _______, _______,  _______, _______, _______          , _______

  ),

  [DIGITS] = LAYOUT_universal(
    _______ , _______, KC_7    , KC_8    , KC_9   , _______, _______, _______, _______, _______, _______, _______, 
    _______ , _______, KC_4    , KC_5    , KC_6   , _______, _______, _______, _______, _______, _______, _______, 
    _______ , _______, KC_1    , KC_2    , KC_3   , KC_0   , _______, _______, _______, _______, _______, _______, 
                       _______ , _______ , _______, _______, _______, _______,  _______, _______, _______         , _______
  ),

  [SPANISH] = LAYOUT_universal(
    _______ , _______, _______, ACUTE_E, _______, _______, _______, UMLAU_U, ACUTE_U, ACUTE_I, ACUTE_O, _______, 
    _______ , ACUTE_A, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______, _______ , _______, _______, _______, _______, _______, TILDE_N, _______, _______, _______, _______, 
                       _______, _______, _______, _______, _______, _______,  _______, _______, _______         , _______
  ),

  [CONFIG] = LAYOUT_universal(
    _______ , QK_BOOT , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                        _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______ 
  ),

  [MOUSE] = LAYOUT_universal(
    _______ , _______, _______ , _______ , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______, SCRL_TO , KC_BTN2 , KC_BTN1 , _______, _______ , KC_BTN1 , KC_BTN2 , _______ , _______ , _______ ,
    _______ , _______, _______ , _______ , _______ , _______, _______ , SCRL_MO , _______ , _______ , _______ , _______ ,
              _______, _______ , _______ , _______ , _______, _______ , _______ , _______ , _______           , _______ 
  ),

};

/* enum combos { */
/*   DK_CAPSWORD, */
/*   COMBO_LENGTH, */
/* }; */
/**/
/* uint16_t COMBO_LEN = COMBO_LENGTH; */
/* const uint16_t PROGMEM dk_combo[] = {HOME_D, HOME_K, COMBO_END}; */
/**/
/* combo_t key_combos[] = { */
/*   [DK_CAPSWORD] = COMBO_ACTION(dk_combo), */
/* }; */
/**/
/* void process_combo_event(uint16_t combo_index, bool pressed) { */
/*   switch(combo_index) { */
/*     case DK_CAPSWORD: */
/*       if (pressed) { */
/*         caps_word_toggle(); */
/*       } */
/*       break; */
/*   } */
/* } */
/**/

// For this to work:
// - Windows needs to have wincompose: https://github.com/samhocevar/wincompose)
// - Linux has to set the compose key to RALT (A.K.A. AltGr): https://en.wikipedia.org/wiki/Compose_key
void send_letter_with_accent(uint16_t lalt, uint16_t letter, uint16_t ralt_combo, uint16_t keycode, keyrecord_t *record) {
  uint8_t mod_state = get_mods();
  uint16_t combo = (!keymap_config.swap_lctl_lgui) ? RALT(lalt) : ralt_combo;
  del_mods(mod_state);

  if (record->tap.count && record->event.pressed){
    tap_code16(combo);
    tap_code(letter);
  } else if (record->event.pressed) {
    tap_code16(combo);
    add_mods(MOD_LSFT);
    tap_code(letter);
  }

  set_mods(mod_state);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Letter with accute (´)
    case ACUTE_A:
      send_letter_with_accent(KC_E, KC_A, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_E:
      send_letter_with_accent(KC_E, KC_E, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_I:
      send_letter_with_accent(KC_E, KC_I, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_O:
      send_letter_with_accent(KC_E, KC_O, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_U:
      send_letter_with_accent(KC_E, KC_U, RALT(KC_QUOTE), keycode, record);
      return false;
    // letter with umlaut (¨)
    case UMLAU_U:
      send_letter_with_accent(KC_U, KC_U, LSFT(RALT(KC_QUOTE)), keycode, record);
      return false;
    // letter with tilde (˜)
    case TILDE_N:
      send_letter_with_accent(KC_N, KC_N, LSFT(RALT(KC_GRAVE)), keycode, record);
      return false;

    case KC_RESTORE_TAB:
      if(record->event.pressed){
        register_mods(MOD_LSFT | mod_config(MOD_LGUI));
        tap_code(KC_T);
      }else {
        unregister_mods(MOD_LSFT | mod_config(MOD_LGUI));
      }
      break;
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  /* autoshift_enable(); */

  // Auto enable scroll mode when the highest layer is 3
  /* keyball_set_scroll_mode(get_highest_layer(state) == 3); */

  switch (get_highest_layer(state)) {
    case DIGITS:
      /* autoshift_disable(); */
      break;
    default:
      break;
  }

  return state;
}

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
