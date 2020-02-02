#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _NAV 1
#define _SYM 2
#define _GAME 3
#define _MOUSE 4
#define _SPECIAL 5

// Fillers to make layering more clear

#define ____ KC_TRNS

// #define SFT_ESC  SFT_T(KC_ESC)
// #define CTL_BSPC CTL_T(KC_BSPC)
// #define ALT_SPC  ALT_T(KC_SPC)
// #define SFT_ENT  SFT_T(KC_ENT)

#define NAV_TAB LT(_NAV, KC_TAB)
#define SFT_SPC LSFT_T(KC_SPACE)
#define CTL_RTN LCTL_T(KC_ENTER)
#define SYM_BKSP LT(_SYM, KC_BSPC)

//Tap Dance Declarations
enum {
  TD_GR_TILD = 0,
  TD_BSLSH_PIPE,
  TD_CLNS
};

enum custom_keycodes {
  M_MS_DOWN = SAFE_RANGE,
  M_MS_UP
};

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define NAV MO(_NAV)
#define SYM MO(_SYM)

// command:
// sudo make handwired/dactyl_manuform/4x5:hogdog:avrdude

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   '  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  (   |   )  |                                                         |   [  |   ]  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | Tab  |Space |                             | Enter| BkSp |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | NAV  |Shift |                             | Ctl  | SYM  |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |  Esc | LEAD | | LEAD | del |
 *                                    |   +  |      | |      |  +  |
 *                                    |  GUI |      | |      | GUI |
 *                                    '------+------' '------+------'
 *                                    |      |  Ins | |      |     |
 *                                    |      |   +  | |      |     |
 *                                    |  alt |  ctl | |MOUSE | alt |
 *                                    '------+------' '------+------'
 */
[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,     \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_QUOTE, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH,  \
           KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
                        NAV_TAB, SFT_SPC,                           CTL_RTN, SYM_BKSP,                                \
                             LGUI_T(KC_ESC), KC_LALT,          KC_RALT,  RGUI_T(KC_DEL),                             \
                             KC_LEAD, LCTL_T(KC_INS),         TG(_MOUSE), KC_LEAD                                \
),

/* NAV
 * ,----------------------------------,                             ,----------------------------------,
 * |  `~  |  M2  |  mup | ScLt | ScRt |                             | Home | PgDn | PgUp |  End |   |  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   :  | mleft|   _  |  -   |  _   |                             | left | down |  up  |right |  ;   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   ~  |      |   +  |  =   |  >   |                             |  -   |  :   |  _   |  \   |  :   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | ScLt | ScRt |                                                         | ScDn | ScUp |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | | dflt |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */
[_NAV] = LAYOUT( \
  TD(TD_GR_TILD), KC_MB2, KC_MU, KC_WH_L, KC_WH_R,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, \
  KC_COLON, KC_ML, KC_UNDS, KC_MINUS, KC_UNDS,                          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN,    \
  KC_TILDE, ____,  KC_PLUS,  KC_EQL, KC_GT,                             KC_MINUS, KC_COLON, KC_UNDS, KC_BSLS, KC_COLON,    \
        KC_WH_L, KC_WH_R,                                                          KC_WH_D,  KC_WH_U,               \
                                   ____, ____,  ____, ____,                                                       \
                                   ____, ____,  ____, ____,                                                       \
                                   ____, ____,  ____, TG(_NAV)                                                        \
),
/* SYM
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |   ;  |   :  |                                                         | F11  | F12  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | | dflt |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_SYM] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
           KC_SCLN, KC_COLON,                                                               KC_VOLD, KC_VOLU,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, TG(_SYM)                                                \
),
/* GAME
 * ,----------------------------------,                             ,----------------------------------,
 * |  tab |  q   |  w   |  e   |  r   |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  sft |  a   |  s   |  d   |  f   |                             |   h  |   j  |   k  |   l  |   '  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | ctl  |  z   |  x   |  c   |  v   |                             |   n  |   m  |   ,  |   .  |   /  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [   |   ]  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |  `   | spc  |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |  esc | rtn  | | dflt |      |
 *                                    '------+------' '------+------'
 *                                    |   h  |  n   | |      |      |
 *                                    '------+------' '------+------'
 */

[_GAME] = LAYOUT( \
  KC_TAB,  KC_Q,  KC_W,   KC_E,  KC_R,                        KC_Y, KC_U,    KC_I,    KC_O,   KC_P,  \
  KC_LSFT,  KC_A,   KC_S,   KC_D,   KC_F,                     KC_H, KC_J,    KC_K,    KC_L,   KC_QUOTE,    \
  KC_LCTL, KC_Z,  KC_X, KC_C, KC_V,                          KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
           KC_LBRC, KC_RBRC,                                                               ____,    ____,             \
                                    KC_GRAVE, KC_SPACE, ____, ____,                                               \
                                             KC_ESC, KC_H,  ____, ____,                                               \
                                             KC_ENTER, KC_N,    ____, TG(_GAME)                                                \
),
/* MOUSE
 * ,----------------------------------,                             ,----------------------------------,
 * |  `~  |  M2  |  mup |  M1  | 1 dn |                             | Home | PgDn | PgUp |  End |  |   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   :  | mleft| mdown|mright| 1 up |                             | left | down |  up  |right |  ;   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   ~  |   x  |   c  |  v   |  +   |                             | sp 0 | sp 1 | sp 2 |   \  |  :   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | ScLt | ScRt |                                                         | ScDn | ScUp |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | | dflt |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */
[_MOUSE] = LAYOUT( \
  TD(TD_GR_TILD), KC_MB2, KC_MU, KC_MB1, M_MS_DOWN,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, \
  KC_COLON, KC_ML, KC_MD, KC_MR, M_MS_UP,                          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN,    \
  KC_TILDE, KC_X,  KC_C,  KC_V, KC_PLUS,                             KC_ACL0, KC_ACL1, KC_ACL2, KC_BSLS, KC_COLON,    \
        KC_WH_L, KC_WH_R,                                                          KC_WH_D,  KC_WH_U,               \
                                   KC_WH_D, KC_WH_U,  ____, ____,                                                       \
                                   ____, ____,  ____, ____,                                                       \
                                   ____, ____,  ____, TG(_MOUSE)                                                        \
)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_GR_TILD] =    ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
  [TD_BSLSH_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLASH, S(KC_BSLASH)),
  [TD_CLNS] =       ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      tap_code(KC_MS_BTN1);
    }

    SEQ_ONE_KEY(KC_E) {
      tap_code16(MEH(KC_E));
    }

    SEQ_ONE_KEY(KC_SPACE) {
      tap_code(KC_CAPS);
    }

    SEQ_ONE_KEY(KC_ENTER) {
      register_code(KC_LCTRL);
    }

    SEQ_ONE_KEY(KC_ESC) {
      register_code(KC_LGUI);
    }

    SEQ_ONE_KEY(KC_DEL) {
      register_code(KC_LGUI);
    }

    SEQ_ONE_KEY(KC_LALT) {
      register_code(KC_LALT);
    }

    SEQ_ONE_KEY(KC_TAB) {
      layer_on(_NAV);
    }

    SEQ_ONE_KEY(KC_BSPC) {
      layer_on(_SYM);
    }

    SEQ_TWO_KEYS(KC_O, KC_W) {
      layer_on(_GAME);
    }

    SEQ_TWO_KEYS(KC_M, KC_S) {
      layer_on(_MOUSE);
    }

    SEQ_THREE_KEYS(KC_Q, KC_M, KC_K) {
      SEND_STRING("sudo make handwired/dactyl_manuform/4x5:hogdog:avrdude\n");;
    }

    // toggle ctl / alt / shift / gui on 
    // (not sure if it can be smart enough to toggle for real)
    // it should be okay though, just hold the layer down and it will unregister on release
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_MS_DOWN:
      if (record->event.pressed) {
        register_code(KC_MS_BTN1);
      }
      break;
    case M_MS_UP:
      if (record->event.pressed) {
        unregister_code(KC_MS_BTN1);
      }
      break;
  }
  return true;
}
