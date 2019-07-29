#include QMK_KEYBOARD_H

enum custom_keycodes {
  RESET_LAYERS = SAFE_RANGE,
  M_WIN_D,
  M_GG,
  M_LOL,
  M_OOPS
};

enum custom_layers {
  OVERWATCH,
  NUMPAD,
  RGB,
  MOUSE,
  NAV,
  MACRO,
  LEFT,
  PWD,
  LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* overwatch standard
  * |-----|-----|-----|-----|
  * | tab |  q  |  w  |  e  |
  * |-----|-----|-----|-----|
  * |ctrl |  a  |  s  |  d  |
  * |-----|-----|-----|-----|
  * |shift|  c  |  n  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  |  `  |space|
  * |-----|-----|-----|-----|
  * (hold esc for layers)
  */
  [OVERWATCH] = LAYOUT_ortho_4x4(
    KC_TAB, KC_Q, KC_W, KC_E,
    KC_LCTRL, KC_A, KC_S, KC_D,
    KC_LSHIFT, KC_C, KC_N, KC_F,
    LT(LAYER, KC_ESC), KC_H, KC_GRAVE, KC_SPACE
  ),

  /* numpad
  * |-----|-----|-----|-----|
  * |  7  |  8  |  9  |  *  |
  * |-----|-----|-----|-----
  * |  4  |  5  |  6  |  /  |
  * |-----|-----|-----|-----|
  * |  1  |  2  |  3  |  -  |
  * |-----|-----|-----|-----|
  * | esc | ent |  .  |  =  |
  * |-----|-----|-----|-----|
  */
  [NUMPAD] = LAYOUT_ortho_4x4(
    KC_KP_7, KC_KP_8, KC_KP_9, KC_ASTR,
    KC_KP_4, KC_KP_5, KC_KP_6, KC_SLSH,
    KC_KP_1, KC_KP_2, KC_KP_3, KC_MINS,
    KC_TRNS, KC_ENT, KC_DOT, KC_EQL
  ),
  
  /* rgb controls
  * |------|------|------|------|
  * |toggle| hue+ | sat+ | val+ |
  * |------|------|------|------|
  * |      | hue- | sat- | val- |
  * |------|------|------|------|
  * |*lucio |      | mode-| mode+|
  * |------|------|------|------|
  * | esc  | grad |snake |swirl |
  * |------|------|------|------|
  */
  [RGB] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI,
    KC_TRNS,     RGB_HUD, RGB_SAD, RGB_VAD,
    KC_TRNS, KC_TRNS, RGB_RMOD, RGB_MOD,
    KC_TRNS, RGB_MODE_GRADIENT, RGB_MODE_BREATHE, RGB_MODE_SWIRL
  ),
  
  /* fake mouse
  * |-----|-----|-----|-----|
  * | btn2|  up | btn1| s up|
  * |-----|-----|-----|-----|
  * | left| down|right| s dn|
  * |-----|-----|-----|-----|
  * | btn3| btn4| s lt| s rt|
  * |-----|-----|-----|-----|
  * | esc |acc 0|acc 1|acc 2|
  * |-----|-----|-----|-----|
  */
  [MOUSE] = LAYOUT_ortho_4x4(
    KC_MS_BTN2, KC_MS_U, KC_MS_BTN1, KC_MS_WH_UP,
    KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_WH_DOWN,
    KC_MS_BTN3, KC_MS_BTN4, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
    KC_TRNS, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2
  ),
  
  /* navigation
  * |-----|-----|-----|-----|
  * |PgUp |home | up  | end |
  * |-----|-----|-----|-----|
  * |PgDn |left |down |right|
  * |-----|-----|-----|-----|
  * |     |mute |vol- |vol+ |
  * |-----|-----|-----|-----|
  * | esc |winD |     |     |
  * |-----|-----|-----|-----|
  */
  [NAV] = LAYOUT_ortho_4x4(
    KC_PGUP, KC_HOME, KC_UP, KC_END,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,
    KC_TRNS, KC_MUTE, KC_VOLU, KC_VOLD,
    KC_TRNS, KC_END, KC_TRNS, KC_TRNS
  ),
  
  /* macros
  * |-----|-----|-----|-----|
  * |  gg | lol |oops |  -  |
  * |-----|-----|-----|-----|
  * |  -  |  -  |  -  |  -  |
  * |-----|-----|-----|-----|
  * |  -  |  -  |  -  |  -  |
  * |-----|-----|-----|-----|
  * | esc |sleep|  -  |  -  |
  * |-----|-----|-----|-----|
  */
  [MACRO] = LAYOUT_ortho_4x4(
    M_GG, M_LOL, M_OOPS, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_SYSTEM_SLEEP, KC_NO, KC_NO
  ),
  
  /* left / baba
  * |-----|-----|-----|-----|
  * | tab |  q  |  w  |  e  |
  * |-----|-----|-----|-----|
  * | caps|  a  |  s  |  d  |
  * |-----|-----|-----|-----|
  * |shift|  z  |  x  |  c  |
  * |-----|-----|-----|-----|
  * | esc |  r  |enter|space|
  * |-----|-----|-----|-----|
  */
  [LEFT] = LAYOUT_ortho_4x4(
    KC_TAB, KC_Q, KC_W, KC_E,
    KC_CAPS, KC_A, KC_S, KC_D,
    KC_LSHIFT, KC_Z, KC_X, KC_C,
    KC_TRNS, KC_R, KC_ENTER, KC_SPACE
  ),
  
  /* password
  * |-----|-----|-----|-----|
  * |  S  |  L  |  3  |  !  |
  * |-----|-----|-----|-----|
  * |  b  |  e  |  s  |  t  |
  * |-----|-----|-----|-----|
  * | tab |  x  |  c  |  f  |
  * |-----|-----|-----|-----|
  * |layer| alt |bkspc|enter|
  * |-----|-----|-----|-----|
  */
  [PWD] = LAYOUT_ortho_4x4(
    S(KC_S), S(KC_L), KC_3, S(KC_1),
    KC_B, KC_E, KC_S, KC_T,
    KC_TAB, KC_X, KC_C, KC_F,
    KC_TRNS, KC_LALT, KC_BSPC, KC_ENTER
  ),

  /* layer switch
  * |-----|-----|-----|-----|
  * | ow  | num | rgb |mouse|
  * |-----|-----|-----|-----|
  * | nav |macro| left| pwd |
  * |-----|-----|-----|-----|
  * |shift|  c  |  y  | winD|
  * |-----|-----|-----|-----|
  * | esc |sleep|a-tab|rgbOn|
  * |-----|-----|-----|-----|
  */
  [LAYER] = LAYOUT_ortho_4x4(
    RESET_LAYERS, TG(NUMPAD), TG(RGB), TG(MOUSE),
    TG(NAV), TG(MACRO), TG(LEFT), TG(PWD),
    KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_SYSTEM_SLEEP, A(KC_TAB), RGB_TOG
  )
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_YELLOW);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RESET_LAYERS:
      if (record->event.pressed) {
        layer_state_set(1);
      }
      break;
    case M_WIN_D:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("D"));
      }
      break;
    case M_GG:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER) "gg" SS_TAP(X_ENTER));
      }
      break;
    case M_LOL:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER) "lol" SS_TAP(X_ENTER));
      }
      break;
    case M_OOPS:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ENTER) "oops" SS_TAP(X_ENTER));
      }
      break;
    case KC_LSHIFT:
      if (record->event.pressed) {
        rgblight_sethsv_noeeprom(HSV_GREEN);
      } else {
        rgblight_sethsv_noeeprom(HSV_YELLOW);
      }
      break;
  }
  return true;
}