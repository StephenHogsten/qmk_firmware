#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 10
#define _BASE2 0
#define _NAV 1
#define _SYM 2
#define _GAME 3
#define _SPECIAL 4

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
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [   |   ]  |                                                         |   (  |   )  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | Tab  |Space |                             | Enter| BkSp |
 *                      |  +   |   +  |                             |  +   |      |
 *                      | NAV  |Shift |                             | Ctl  | SYM  |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |  GUI |  Esc | | Del | GUI / Esc|
 *                                    |  GUI |  Esc | | Del | GUI / Esc|
 *                                    '------+------' '------+------'
 *                                    |  alt |  ctl | |  f  | alt |
 *                                    '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
              KC_LPRN, KC_RPRN,                                       KC_LBRC, KC_RBRC,                              \
              NAV_TAB, SFT_SPC,                                       CTL_RTN, SYM_BKSP,                             \
                                    KC_LGUI, KC_LALT,     KC_RALT,  RGUI_T(KC_ESC),                                  \
                                    KC_ESC,   KC_LCTRL,    KC_F, KC_DEL                                              \
),

/* Base2 (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   '  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [   |   ]  |                                                         |   (  |   )  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | Tab  |Space |                             | Enter| BkSp |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | NAV  |Shift |                             | Ctl  | SYM  |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |  Esc | LOCK | |  del |  ;  |
 *                                    |   +  |      | |   +  |  +  |
 *                                    |  GUI |      | |  meh | GUI |
 *                                    '------+------' '------+------'
 *                                    |      |  Ins | |      |     |
 *                                    |      |   +  | |      |     |
 *                                    |  alt |  ctl | | GAME | alt |
 *                                    '------+------' '------+------'
 */
[_BASE2] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,     \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_QUOTE, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH,  \
           KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
                        NAV_TAB, SFT_SPC,                           CTL_RTN, SYM_BKSP,                                \
                             LGUI_T(KC_ESC), KC_LALT,          KC_RALT,  RGUI_T(KC_SCLN),                             \
                             KC_LOCK, LCTL_T(KC_INS),         TG(_GAME), MEH_T(KC_DEL)                               \
),

/* NAV
 * ,----------------------------------,                             ,----------------------------------,
 * |  `~  |  M2  |  mup | ScLt | ScRt |                             | Home | PgDn | PgUp |  End |  \|   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   :  | mleft| mdown|  -   |  _   |                             | left | down |  up  |right |  ;:   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   ~  |      |   >  |  =   |  +   |                             |  +   |  =   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | ScDn | ScUp |                                                         | Vol-| Vol+ |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */
[_NAV] = LAYOUT( \
  TD(TD_GR_TILD), KC_MB2, KC_MU, KC_WH_L, KC_WH_R,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, TD(TD_BSLSH_PIPE), \
  KC_COLON, KC_ML, KC_MD, KC_MINUS, KC_UNDS,                          KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TD(TD_CLNS),    \
  KC_TILDE, ____,  KC_GT,  KC_EQL, KC_PLUS,                             KC_PLUS, KC_EQL, KC_BSLS, KC_QUES,  KC_PIPE,    \
        KC_WH_D,  KC_WH_U,                                                          KC_VOLD,  KC_VOLU,               \
                                   ____, ____,  ____, ____,                                                       \
                                   ____, ____,  ____, ____,                                                       \
                                   ____, ____,  ____, ____                                                        \
),
/* SYM
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_SYM] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
           KC_F11, KC_F12,                                                               ____,    ____,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____                                                \
),
/* GAME
 * ,----------------------------------,                             ,----------------------------------,
 * |  tab |  q   |  w   |  e   |  r   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  sft |  a   |  s   |  d   |  f   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   `  |  z   |  x   |  c   |  v   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  [   |   ]  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |  ctl | spc  |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |  esc |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |  rtn |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_GAME] = LAYOUT( \
  KC_TAB,  KC_Q,  KC_W,   KC_E,  KC_R,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_LSFT,  KC_A,   KC_S,   KC_D,   KC_F,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_GRAVE, KC_Z,  KC_X, KC_C, KC_V,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
           KC_LBRC, KC_RBRC,                                                               ____,    ____,             \
                                    KC_LCTRL, KC_SPACE, ____, ____,                                               \
                                             KC_ESC, ____,  ____, ____,                                               \
                                             KC_ENTER, ____,  ____, ____                                                \
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
