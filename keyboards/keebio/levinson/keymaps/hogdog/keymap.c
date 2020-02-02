#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

extern keymap_config_t keymap_config;

enum custom_keycodes {
  M_LSAHL = SAFE_RANGE,
  M_RAILSC,
  M_ALT_TAB,
  M_S_ALT_TAB,
  M_ALT_GRAVE,
  M_S_ALT_GRAVE,
  M_RELOAD,
  M_REBUILD,
  M_MS_DOWN,
  M_MS_UP
};

#define _QWERTY 0
#define _QWERTY_ALT 1
#define _COLEMAK 2
#define _DVORAK 3
#define _OW 4
#define _NAV_OLD 5
#define _NAV 6
#define _SYM 7
#define _MOUSE 8
#define _GAME 9
#define _ADJUST 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |  Q   |  W   |  E   |  R   |  T   |      |    |      |  Y   |  U   |  I   |  O   |  P   |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  A   |  S   |  D   |  F   |  G   |      |    |      |  H   |  J   |  K   |  L   |   '  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  Z   |  X   |  C   |  V   |  B   |      |    |      |  N   |  M   |  ,   |  .   |  /   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Ctrl |   (  |   )  |  esc | Tab  | Space|    | Enter| BkSp |  del |   [  |   ]  | alt  |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  /* QWERTY - hold
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |      |      |      |      |      |      |    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |  GUI | _NAV | shft |    | ctrl | _SYM | GUI  |      |      |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_Q, KC_W, KC_E, KC_R, KC_T, TO(_MOUSE),                TO(_MOUSE), KC_Y, KC_U, KC_I, KC_O, KC_P, 
    KC_A, KC_S, KC_D, KC_F, KC_G, TO(_MOUSE),                TO(_MOUSE), KC_H, KC_J, KC_K, KC_L, KC_QUOTE, 
    KC_Z, KC_X, KC_C, KC_V, KC_B, TO(_MOUSE),                TO(_MOUSE), KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, 
    KC_LCTL, KC_LPRN, KC_RPRN, LGUI_T(KC_ESC), LT(_NAV, KC_TAB), LSFT_T(KC_SPACE),          LCTL_T(KC_ENTER), LT(_SYM, KC_BSPC), RGUI_T(KC_DEL), KC_LBRC, KC_RBRC, KC_LALT
  ),

  /* QWERTY ALT - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | Tab  |  Q   |  W   |  E   |  R   |  T   |    |  Y   |  U   |  I   |  O   |  P   | Bksp |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |  `   |  A   |  S   |  D   |  F   |  G   |    |  H   |  J   |  K   |  L   |  ;   |  '   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |  -   |  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   | Enter|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Ctrl | Gui  |  Alt |  Del | _NAV | Space|    | Shift| _SYM | Bksp | Alt  | Gui  | Ctrl |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_QWERTY_ALT] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    RSFT_T(KC_GRAVE), KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_QUOTE),
    LCTL_T(KC_ESC), LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_ENTER),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAV, KC_DEL), LSFT_T(KC_SPACE),   LCTL_T(KC_RSFT), LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_DVORAK] = LAYOUT_ortho_4x12(
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                       KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KC_O, KC_E, KC_U, KC_I,             KC_D, KC_H, KC_T, KC_N, RSFT_T(KC_S), RSFT_T(KC_SLSH),
    LCTL_T(KC_MINUS), LGUI_T(KC_SCLN), LALT_T(KC_Q), KC_J, KC_K, KC_X,  KC_B, KC_M, KC_W, RALT_T(KC_V), RGUI_T(KC_Z), RCTL_T(KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAV, KC_DEL), LSFT_T(KC_SPACE),   LCTL_T(KC_RSFT), LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_COLEMAK] = LAYOUT_ortho_4x12(
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G,                               KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KC_R, KC_S, KC_T, KC_D,             KC_H, KC_N, KC_E, KC_I, RSFT_T(KC_O), RSFT_T(KC_QUOT),
    LCTL_T(KC_MINUS), LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,     KC_K, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_EQUAL),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAV, KC_DEL), LSFT_T(KC_SPACE),   LCTL_T(KC_RSFT), LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_OW] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    RSFT_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_QUOTE),
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                              KC_N, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_ENTER),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAV, KC_DEL), KC_SPACE,   KC_RSFT, LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_NAV_OLD] = LAYOUT_ortho_4x12(
    KC_ESC, KC_TAB, KC_HOME, KC_UP, KC_END, KC_PGUP,             KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_DEL, KC_BSPC,
    KC_VOLU, KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,       KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_RSFT, KC_ENT,
    KC_VOLD, KC_MUTE, C(KC_LEFT), _______, C(KC_RIGHT), _______, KC_ACL0, KC_ACL1, KC_ACL2, S(KC_RALT), S(KC_RGUI), S(KC_RCTL),
    _______, _______, _______, _______, _______, _______,        _______, TT(_ADJUST), _______, _______, _______, _______
  ),


  /* NAV (left thumb) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |  `   |  M2  | M up |  M1  | ScUp |      |    |      | Home | PgDn | PgUp |  End |   |  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  :   |  M l |  _   |   -  |   _  |      |    |      | Left | Down |  Up  | Right|   ;  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  ~   |      |   >  |   =  |  +   |      |    |      |  -   |  :   |  _   |  \   |   :  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | LEAD | ScLt | ScRt |      |(this)|      |    | BkSp | _ADJ |      |      |      |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_NAV] = LAYOUT_ortho_4x12(
    KC_GRAVE, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, _______,               _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, 
    KC_COLON, KC_MS_L, KC_UNDS, KC_MINUS, KC_UNDS, _______,              _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, 
    KC_TILDE, _______, KC_PLUS, KC_EQL, KC_GT, _______,                  _______, KC_MINUS, KC_COLON, KC_UNDS, KC_BSLS, KC_COLON,
    KC_LEAD, KC_WH_L, KC_WH_R, _______, _______, _______,               _______, LT(_ADJUST, KC_BSPC), _______, KC_WH_D, KC_WH_U, _______
  ),

  /* SYM (right thumb) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |  F1  |  F2  |  F3  |  F4  |  F5  |      |    |      |  F6  |  F7  |  F8  |  F9  |  F0  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  1   |  2   |  3   |  4   |  5   |      |    |      |  6   |  7   |  8   |  9   |   0  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  !   |  @   |  #   |  $   |  %   |      |    |      |  ^   |  &   |  *   |  (   |  )   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans|   ;  |   :  |      | Esc  |  Del |    | BkSp |(this)| trans| trans| trans| trans|
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_SYM] = LAYOUT_ortho_4x12(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,                   _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
    KC_1, KC_2, KC_3, KC_4, KC_5, _______,                        _______, KC_6, KC_7, KC_8, KC_9, KC_0, 
    KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC, _______,           _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,
    _______, KC_SCLN, KC_COLON, _______, LT(_ADJUST, KC_TAB), _______,   _______, _______, _______, _______, _______, _______
  ),

  /* ADJUST (both thumbs) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | NAV  | build| trans| trans|reload| trans|    | trans| trans| trans| trans| trans| SYM  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | caps | trans| trans| trans|c a E | trans|    | trans| trans| trans|ls ahl| trans| trans|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans| trans|railsc| trans| fold |    |unfold| trans| trans| trans| trans| trans|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans| trans| trans| trans| trans|    | trans| trans| trans| trans| trans| trans|
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_ADJUST] = LAYOUT_ortho_4x12(
    TO(_NAV), _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, TO(_SYM),
    KC_CAPS, _______, _______, _______, MEH(KC_E), _______,                       _______, _______, _______, M_LSAHL, _______, _______,
    _______, _______, _______, M_RAILSC, _______, C(S(KC_LBRC)),                  C(S(KC_RBRC)), _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______
  ),
  /* MOUSE
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |  `   |  M2  | M up |  M1  | m1 dn|      |    |      | Home | PgDn | PgUp |  End |   \  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  :   |  M l | M up | M rt | m1 up|      |    |      | Left | Down |  Up  | Right|   ;  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  ~   |   x  |  c   |   v  |  +   |      |    |      | sp 0 | sp 1 | sp 2 |  ?   |  |   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      | ScLt | ScRt |      |normal|      |    | BkSp | _ADJ |      | ScUp | ScUp |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_MOUSE] = LAYOUT_ortho_4x12(
    KC_GRAVE, KC_BTN2, KC_MS_U, KC_BTN1, M_MS_DOWN, TG(_MOUSE),               TG(_MOUSE), KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS, 
    KC_COLON, KC_MS_L, KC_MS_D, KC_MS_R, M_MS_UP, TG(_MOUSE),              TG(_MOUSE), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, 
    KC_TILDE, KC_X, KC_C, KC_V, KC_GT, TG(_MOUSE),                  TG(_MOUSE), KC_ACL0, KC_ACL1, KC_ACL2, KC_QUES, KC_PIPE, 
    _______, KC_WH_L, KC_WH_R, _______, TG(_MOUSE), _______,               _______, _______, _______, KC_WH_D, KC_WH_U, _______
  ),
  /* GAME
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | tab  |  Q   |  W   |  E   |  R   |      |    |      |  Y   |  U   |  I   |  O   |  P   |
  * +------|------+------+------+------+      |    |      |------+------+------+------+------+
  * | sft  |  A   |  S   |  D   |  F   |      |    |      |  H   |  J   |  K   |  L   |   '  |
  * +------|------+------+------+------+      |    |      |------+------+------+------+------+
  * | ctl  |  Z   |  X   |  C   |  V   |      |    |      |  N   |  M   |  ,   |  .   |  /   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | esc  |   [  |   ]  |  h   |   `  | Space|    | Enter| BkSp |  del |   [  |   ]  | alt  |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_GAME] = LAYOUT_ortho_4x12(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, TO(_MOUSE),                TG(_GAME), KC_Y, KC_U, KC_I, KC_O, KC_P, 
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, TO(_MOUSE),                TG(_GAME), KC_H, KC_J, KC_K, KC_L, KC_QUOTE, 
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, TO(_MOUSE),                TG(_GAME), KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, 
    KC_ESC, KC_LBRC, KC_RBRC, KC_H, KC_GRAVE, KC_SPACE,          LCTL_T(KC_ENTER), LT(_SYM, KC_BSPC), RGUI_T(KC_DEL), KC_LBRC, KC_RBRC, TG(_GAME)
  ),
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
    case M_LSAHL:
      if (record->event.pressed) {
        SEND_STRING("ls -ahl" SS_TAP(X_ENTER));
      } 
      break;
    case M_RAILSC: 
      if (record->event.pressed) {
        SEND_STRING("rails c" SS_TAP(X_ENTER));
      }
      break;
    case M_RELOAD:
      if (record->event.pressed) {
        SEND_STRING("reload!" SS_TAP(X_ENTER));
      }
      break;
    case M_REBUILD:
      if (record->event.pressed) {
        SEND_STRING("sudo make keebio/levinson/rev2:hogdog:avrdude" SS_TAP(X_ENTER));
      }
      break;
    case M_ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case M_S_ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        alt_tab_timer = timer_read();
        register_code(KC_LSHIFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
        unregister_code(KC_LSHIFT);
      }
      break;
    case M_ALT_GRAVE:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        alt_tab_timer = timer_read();
        register_code(KC_GRAVE);
      } else {
        unregister_code(KC_GRAVE);
      }
      break;
    case M_S_ALT_GRAVE:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        } 
        alt_tab_timer = timer_read();
        register_code(KC_LSHIFT);
        register_code(KC_GRAVE);
      } else {
        unregister_code(KC_GRAVE);
        unregister_code(KC_LSHIFT);
      }
      break;
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {     // The very important timer. 
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_M, KC_S) {
      layer_off(_NAV);
      layer_on(_MOUSE);
    }

    SEQ_TWO_KEYS(KC_G, KC_M) {
      layer_on(_GAME);
    }
  }
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _QWERTY:
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
      break;
  }
  return state;
}
