#include QMK_KEYBOARD_H

enum custom_keycodes {
  RESET_LAYERS = SAFE_RANGE
};

enum custom_layers {
  OVERWATCH,
  NUMPAD,
  RGB,
  MOUSE,
  NAV,
  MACRO,
  MACRO2,
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
  * |shift|  c  |  y  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  | ctrl|space|
  * |-----|-----|-----|-----|
  * (hold esc for layers)
  */
  [OVERWATCH] = LAYOUT_ortho_4x4(
    KC_TAB, KC_Q, KC_W, KC_E,
    KC_LCTRL, KC_A, KC_S, KC_D,
    KC_LSHIFT, KC_C, KC_Y, KC_F,
    LT(LAYER, KC_ESC), KC_H, KC_LCTRL, KC_SPACE
  ),

  /* numpad
  * |-----|-----|-----|-----|
  * |  7  |  8  |  9  |  *  |
  * |-----|-----|-----|-----|
  * |  4  |  5  |  6  |  /  |
  * |-----|-----|-----|-----|
  * |  1  |  2  |  3  |  -  |
  * |-----|-----|-----|-----|
  * | esc | ent |  .  |  =  |
  * |-----|-----|-----|-----|
  */
  [NUMPAD] = LAYOUT_ortho_4x4(
    KC_KP_7, KC_KP_8, KC_KP_9, KC_ASTR  ,
    KC_KP_4, KC_KP_5, KC_KP_6, KC_SLSH,
    KC_KP_1, KC_KP_2, KC_KP_3, KC_MINS,
    KC_TRNS, KC_ENT, KC_DOT, KC_EQL
  ),
  
  /* rgb controls
  * |------|------|------|------|
  * |toggle| hue+ | sat+ | val+ |
  * |------|------|------|------|
  * | ctrl | hue- | sat- | val- |
  * |------|------|------|------|
  * |lucio |      | mode-| mode+|
  * |------|------|------|------|
  * | esc  | grad |snake |swirl |
  * |------|------|------|------|
  */
  [RGB] = LAYOUT_ortho_4x4(
    RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI,
    KC_H,     RGB_HUD, RGB_SAD, RGB_VAD,
    KC_B, KC_N, RGB_RMOD, RGB_MOD,
    KC_TRNS, RGB_MODE_GRADIENT, RGB_MODE_BREATHE, RGB_MODE_SWIRL
  ),
  
  /* fake mouse
  * |-----|-----|-----|-----|
  * | tab |  q  |  w  |  e  |
  * |-----|-----|-----|-----|
  * |ctrl |  a  |  s  |  d  |
  * |-----|-----|-----|-----|
  * |shift|  c  |  y  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  | ctrl|space|
  * |-----|-----|-----|-----|
  */
  [MOUSE] = LAYOUT_ortho_4x4(
    KC_7, KC_8, KC_9, KC_TRNS,
    KC_4, KC_5, KC_6, KC_MINUS,
    KC_1, KC_2, KC_3, KC_EQUAL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  
  /* navigation
  * |-----|-----|-----|-----|
  * | tab |  q  |  w  |  e  |
  * |-----|-----|-----|-----|
  * |ctrl |  a  |  s  |  d  |
  * |-----|-----|-----|-----|
  * |shift|  c  |  y  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  | ctrl|space|
  * |-----|-----|-----|-----|
  */
  [NAV] = LAYOUT_ortho_4x4(
    KC_NO, KC_HOME, KC_NO, KC_VOLU,
    KC_NO, KC_PGUP, KC_NO, KC_VOLD,
    KC_NO, KC_PGDOWN, KC_NO, KC_MUTE,
    KC_TRNS, KC_END, KC_NO, KC_MEDIA_PLAY_PAUSE
  ),
  
  /* macros
  * |-----|-----|-----|-----|
  * | tab |  q  |  w  |  e  |
  * |-----|-----|-----|-----|
  * |ctrl |  a  |  s  |  d  |
  * |-----|-----|-----|-----|
  * |shift|  c  |  y  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  | ctrl|space|
  * |-----|-----|-----|-----|
  */
  [MACRO] = LAYOUT_ortho_4x4(
    KC_MS_BTN2, KC_MS_U, KC_MS_BTN1, KC_MS_WH_UP,
    KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_WH_DOWN,
    KC_MS_BTN3, KC_MS_BTN4, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
    KC_TRNS, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2
  ),
  
  /* macros 2
  * |-----|-----|-----|-----|
  * | tab |  q  |  w  |  e  |
  * |-----|-----|-----|-----|
  * |ctrl |  a  |  s  |  d  |
  * |-----|-----|-----|-----|
  * |shift|  c  |  y  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  | ctrl|space|
  * |-----|-----|-----|-----|
  */
  [MACRO2] = LAYOUT_ortho_4x4(
    KC_NO, KC_NO, KC_UP, KC_NO,
    KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT,
    KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_NO, KC_NO, KC_SPACE
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
  * | nav |macro| mac2| pwd |
  * |-----|-----|-----|-----|
  * |shift|  c  |  y  |  f  |
  * |-----|-----|-----|-----|
  * | esc |  h  |a-tab|rgbOn|
  * |-----|-----|-----|-----|
  */
  [LAYER] = LAYOUT_ortho_4x4(
    RESET_LAYERS, TG(NUMPAD), TG(RGB), TG(MOUSE),
    TG(NAV), TG(MACRO), TG(MACRO2), TG(PWD),
    KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_NO, A(KC_TAB), RGB_TOG
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