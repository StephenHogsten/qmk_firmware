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
  M_S_ALT_GRAVE
};

#define _QWERTY 0
#define _QWERTY_ALT 1
#define _COLEMAK 2
#define _DVORAK 3
#define _OW 4
#define _NAV 5
#define _NAVALT 6
#define _SYM 7
#define _ADJUST 15

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |   `  |  Q   |  W   |  E   |  R   |  T   |    |  Y   |  U   |  I   |  O   |  P   |  \   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Esc  |  A   |  S   |  D   |  F   |  G   |    |  H   |  J   |  K   |  L   |  ;   |  '   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |  -   |  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   |  =   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Ctrl | Gui  |  Alt |  Alt | Tab  | Space|    | Enter| BkSp | Alt  | Alt  | Gui  | Ctrl |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  /* QWERTY - hold
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |      |      |      |      |      |      |    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Shift|      |      |      |      |      |    |      |      |      |      |      | Shift|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Ctrl | Gui  |  Alt |      |      |      |    |      |      |      | Alt  | Gui  | Ctrl |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |      | _NAV | shift|    | ctrl | _SYM |      |      |      |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_QWERTY] = LAYOUT_ortho_4x12(
    LSFT_T(KC_GRAVE),  KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                             KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_QUOTE),
    LCTL_T(KC_MINUS), LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,             KC_N, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_EQUAL),
    KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, LT(_NAVALT, KC_TAB), LSFT_T(KC_SPACE),  LCTL_T(KC_ENTER), LT(_SYM, KC_BSPC), KC_RALT, KC_RALT, KC_RGUI, KC_RCTL
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
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAVALT, KC_DEL), LSFT_T(KC_SPACE),   LCTL_T(KC_RSFT), LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_DVORAK] = LAYOUT_ortho_4x12(
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                       KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KC_O, KC_E, KC_U, KC_I,             KC_D, KC_H, KC_T, KC_N, RSFT_T(KC_S), RSFT_T(KC_SLSH),
    LCTL_T(KC_MINUS), LGUI_T(KC_SCLN), LALT_T(KC_Q), KC_J, KC_K, KC_X,  KC_B, KC_M, KC_W, RALT_T(KC_V), RGUI_T(KC_Z), RCTL_T(KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAVALT, KC_DEL), LSFT_T(KC_SPACE),   LCTL_T(KC_RSFT), LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_COLEMAK] = LAYOUT_ortho_4x12(
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G,                               KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KC_R, KC_S, KC_T, KC_D,             KC_H, KC_N, KC_E, KC_I, RSFT_T(KC_O), RSFT_T(KC_QUOT),
    LCTL_T(KC_MINUS), LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,     KC_K, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_EQUAL),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAVALT, KC_DEL), LSFT_T(KC_SPACE),   LCTL_T(KC_RSFT), LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_OW] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    RSFT_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,                       KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_QUOTE),
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                              KC_N, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_ENTER),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LT(_NAVALT, KC_DEL), KC_SPACE,   KC_RSFT, LT(_SYM, KC_BSPC), KC_BSPC, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_NAV] = LAYOUT_ortho_4x12(
    KC_ESC, KC_TAB, KC_HOME, KC_UP, KC_END, KC_PGUP,             KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_DEL, KC_BSPC,
    KC_VOLU, KC_LSFT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,       KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_RSFT, KC_ENT,
    KC_VOLD, KC_MUTE, C(KC_LEFT), KC_TRNS, C(KC_RIGHT), KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, S(KC_RALT), S(KC_RGUI), S(KC_RCTL),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, TT(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),


  /* NAVALT (left thumb) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | Esc  | menu |  M2  | M up |  M1  | ScUp |    | Home | PgDn | PgUp |  End | BrUp | PtSc |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | Mute | VolU |  M l | M d  |  mRt | ScDn |    | Left | Down |  Up  | Right| BrDn | Insrt|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      | VolD |      | s alt| s ctl|      |    | alt` |alttab|saltab|salt` | acc2 | acc0 |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |      |(this)|  Del |    | BkSp | _ADJ |      |      |      |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_NAVALT] = LAYOUT_ortho_4x12(/*  */
    KC_TRNS, KC_APP, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BRIGHTNESS_UP, KC_PSCREEN,
    KC_MUTE, KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                         KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BRIGHTNESS_DOWN, KC_INS,
    KC_TRNS, LGUI_T(KC_VOLD), KC_TRNS, S(KC_LALT), S(KC_LCTRL), KC_TRNS,          M_ALT_GRAVE, M_ALT_TAB, M_S_ALT_TAB, M_S_ALT_GRAVE, KC_ACL2, KC_ACL0,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT_T(KC_DEL),                  LCTL_T(KC_BSPC), LT(_ADJUST, KC_DEL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* SYM (right thumb) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |    |  F6  |  F7  |  F8  |  F9  |  F0  |  F11 |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans|  1   |  2   |  3   |  4   |  5   |    |  6   |  7   |  8   |  9   |   0  |   \  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans|      |  {   |  (   |   [  |    |  ]   |  )   |  }   |      | trans| trans|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans| trans|      | Esc  |  Del |    | Bk`Sp |(this)| trans| trans| trans| trans|
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_SYM] = LAYOUT_ortho_4x12(
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,                                      KC_6, KC_7, KC_8, KC_9, KC_0, RSFT_T(KC_BSLASH),
    KC_TRNS, KC_TRNS, KC_TRNS, S(KC_LBRC), S(KC_9), KC_LBRC,                    KC_RBRC, S(KC_0), S(KC_RBRC), KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(_ADJUST, KC_ESC), LSFT_T(KC_DEL),  LCTL_T(KC_BSPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* ADJUST (both thumbs) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | trans| QWERT|QWERT2|DVORAK|COLEMA|OVERWA|    | trans| trans| trans| trans| trans| trans|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans| trans| trans|c a E | trans|    | trans| trans| trans|ls ahl| trans| trans|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans| trans|railsc| trans| trans|    | trans| trans| trans| trans| trans| trans|
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | trans| trans| trans| trans| trans| trans|    | trans| trans| trans| trans| trans| trans|
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_ADJUST] = LAYOUT_ortho_4x12(
    KC_TRNS, DF(_QWERTY), DF(_QWERTY_ALT), DF(_DVORAK), DF(_COLEMAK), DF(_OW),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MEH(KC_E), KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS, M_LSAHL, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, M_RAILSC, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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

void matrix_scan_user(void) {     // The very important timer. 
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 2500) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
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