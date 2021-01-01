#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 7
#define _NAV 1
#define _SYM 2
#define _GAME 3
#define _MOUSE 4
#define _SPECIAL 5
#define _COLEMAK 6
#define _COLEMAK_DH 0

// Fillers to make layering more clear

enum combos {
  UY_QUOTE,
};

#define ____ KC_TRNS

// #define SFT_ESC  SFT_T(KC_ESC)
// #define CTL_BSPC CTL_T(KC_BSPC)
// #define ALT_SPC  ALT_T(KC_SPC)
// #define SFT_ENT  SFT_T(KC_ENT)

#define NAV_TAB LT(_NAV, KC_TAB)
#define NAV_SPC LT(_NAV, KC_SPACE)
#define NAV_ESC LT(_NAV, KC_ESC)
#define SYM_RTN LT(_SYM, KC_ENTER)
#define SYM_SPACE LT(_SYM, KC_SPACE)
#define SYM_BKSP LT(_SYM, KC_BSPC)
#define SYM_DEL LT(_SYM, KC_DEL)

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
 *                                    | mouse| LEAD | | LEAD | del |
 *                                    |      |      | |      |  +  |
 *                                    |      |      | |      | GUI |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |     |
 *                                    |      |      | |      | prnt|
 *                                    |  ins |  esc | | caps | scrn|
 *                                    '------+------' '------+------'
 */
/* [_BASE] = LAYOUT( \
//   KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,     \
//   KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_QUOTE, \
//   KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH,  \
//            KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
//                         NAV_TAB, SFT_SPC,                           CTL_RTN, SYM_BKSP,                                \
//                              LGUI_T(KC_ESC), KC_LALT,          KC_PSCR,  RGUI_T(KC_DEL),                             \
//                              KC_LEAD, LCTL_T(KC_INS),         TG(_MOUSE), KC_LEAD                                \
// ),
// alternate for thumbs - gui-sym-sft going in-out

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,     \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_QUOTE, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH,  \
           KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
                        LGUI_T(KC_ESC), NAV_TAB,                           SYM_BKSP, RGUI_T(KC_DEL),                                \
                                SFT_SPC, KC_LALT,                KC_PSCR, CTL_RTN,                             \
                             KC_LEAD, LCTL_T(KC_INS),         TG(_MOUSE), KC_LEAD                                \
),
*/
[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, 
    LALT_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,      KC_H, RCTL_T(KC_J), RSFT_T(KC_K), RGUI_T(KC_L), RALT_T(KC_QUOTE),
    KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, 
           KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
                        LGUI_T(KC_ESC), NAV_SPC,                          SYM_RTN, RGUI_T(KC_DEL),                                \
                             NAV_TAB, KC_LALT,          KC_PSCR, SYM_BKSP,                             \
                             KC_LEAD, LCTL_T(KC_INS),         TG(_MOUSE), KC_LEAD                                \
),
[_COLEMAK] = LAYOUT( \
  KC_Q, KC_W, KC_F, KC_P, KC_G,                                   KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
  LALT_T(KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D,   KC_H, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
  KC_Z, KC_X, KC_C, KC_V, KC_B,                                   KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLSH,
           KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
                        LGUI_T(KC_ESC), NAV_SPC,                           SYM_RTN, RGUI_T(KC_DEL),                                \
                             NAV_TAB, KC_LALT,          KC_PSCR, SYM_BKSP,                             \
                             KC_LEAD, LCTL_T(KC_INS),         TG(_MOUSE), KC_LEAD                                \
),
[_COLEMAK_DH] = LAYOUT( \
  KC_Q, KC_W, KC_F, KC_P, KC_B,                                   KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
  LALT_T(KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,   KC_K, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
  KC_Z, KC_X, KC_C, KC_D, KC_V,                                   KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLSH,
           KC_LPRN, KC_RPRN,                                                   KC_LBRC, KC_RBRC,                      \
                        NAV_TAB, NAV_SPC,                         SYM_RTN, SYM_BKSP,                                \
                             TG(_MOUSE), KC_INS,          KC_PSCR, SYM_DEL,                             \
                             KC_LEAD, KC_ESC,         KC_CAPS, KC_LEAD                                \
),

/* NAV
 * ,----------------------------------,                             ,----------------------------------,
 * |   ~  |  +   |   :  |  _   | ScUp |                             | Home | PgDn | PgUp |  End |   |  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   `  |  =   |   ;  |  -   | ScDn |                             | left | down |  up  |right | esc  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | caps |   }  |   ]  |  )   | click|                             |  >   |   (  |  [   |  {   |  \   |
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
  KC_TILDE, KC_PLUS, KC_COLON, KC_UNDS, KC_WH_U,                                   KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, 
  LALT_T(KC_GRAVE), LGUI_T(KC_EQL), LSFT_T(KC_SCLN), LCTL_T(KC_MINUS), KC_WH_D,    KC_LEFT, RCTL_T(KC_DOWN), RSFT_T(KC_UP), RGUI_T(KC_RIGHT), RALT_T(KC_ESC), 
  KC_CAPS, KC_RCBR, KC_RBRC, KC_RPRN, KC_MS_BTN1,                                    KC_GT, KC_LPRN, KC_LBRC, KC_LCBR, KC_BSLS,
        KC_WH_L, KC_WH_R,                                                          KC_WH_D,  KC_WH_U,               \
                                   ____, ____,  SYM_SPACE, ____,                                                       \
                                   ____, ____,  ____, ____,                                                       \
                                   ____, ____,  ____, TG(_NAV)                                                        \
),
/* SYM
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   | F11  |  F12 |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |   ;  |   :  |                                                         | F11  | F12  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      | cole | | dflt |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_SYM] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  LALT_T(KC_1), LGUI_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5,       KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RGUI_T(KC_9), RALT_T(KC_0),    \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_F11, KC_F12, \
           KC_SCLN, KC_COLON,                                                               KC_VOLD, KC_VOLU,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             DF(_COLEMAK_DH), ____,  ____, TG(_SYM)                                                \
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
  M_MS_DOWN, KC_MB2, KC_MU, KC_MB1, KC_WH_U,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, \
  M_MS_UP, KC_ML, KC_MD, KC_MR, KC_WH_D,                          KC_LEFT, RCTL_T(KC_DOWN), RSFT_T(KC_UP), RGUI_T(KC_RIGHT), RALT_T(KC_SCLN),    \
  KC_WH_L, KC_WH_R,  KC_C,  KC_V, KC_PLUS,                             KC_ACL0, KC_ACL1, KC_ACL2, KC_BSLS, KC_COLON,    \
        KC_WH_L, KC_WH_R,                                                          KC_WH_D,  KC_WH_U,               \
                                   ____, ____,  ____, ____,                                                       \
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

    SEQ_ONE_KEY(KC_V) {
      register_code(KC_LCTRL);
      register_code(KC_LSFT);
      tap_code(KC_INS);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTRL);
    }

    SEQ_THREE_KEYS(KC_Q, KC_M, KC_K) {
      SEND_STRING("sudo make handwired/dactyl_manuform/4x5:hogdog:avrdude\n");
    }

    // SEQ_THREE_KEYS(KC_C, KC_O, KC_L) {
    //   register_code(DF(_COLEMAK_DH));
    // }

    // toggle ctl / alt / shift / gui on 
    // (not sure if it can be smart enough to toggle for real)
    // it should be okay though, just hold the layer down and it will unregister on release
  }
}

const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [UY_QUOTE] = COMBO(uy_combo, KC_DQUO)
};

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

