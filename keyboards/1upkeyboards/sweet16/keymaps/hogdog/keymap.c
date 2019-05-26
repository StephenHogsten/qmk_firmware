#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_4x4(
    KC_TAB, KC_Q, KC_W, KC_R,
    KC_ESC, KC_A, KC_S, KC_D,
    KC_LSHIFT, KC_C, KC_Y, KC_E,
    TG(1), KC_ENTER, KC_LCTRL, KC_SPACE
  ),
  [1] = LAYOUT_ortho_4x4(
    TG(1), TG(2), TG(3), TG(4),
    TG(5), TG(6), TG(7), TG(8),
    KC_NO, KC_NO, KC_NO, KC_NO,
    TO(0), KC_NO, KC_NO, KC_NO
  ),
  [2] = LAYOUT_ortho_4x4(
    KC_Q, KC_W, KC_E, KC_R,
    KC_A, KC_S, KC_D, KC_F,
    KC_Z, KC_X, KC_C, KC_Y,
    TG(2), KC_T, KC_G, KC_RSHIFT
  ),
  [3] = LAYOUT_ortho_4x4(
    KC_U, KC_I, KC_O, KC_P,
    KC_H, KC_J, KC_K, KC_L,
    KC_B, KC_N, KC_M, KC_COMMA,
    TG(3), KC_LSHIFT, KC_RSHIFT, KC_ENTER
  ),
  [4] = LAYOUT_ortho_4x4(
    KC_7, KC_8, KC_9, KC_TRNS,
    KC_4, KC_5, KC_6, KC_MINUS,
    KC_1, KC_2, KC_3, KC_EQUAL,
    TG(4), KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [5] = LAYOUT_ortho_4x4(
    KC_NO, KC_HOME, KC_NO, KC_VOLU,
    KC_NO, KC_PGUP, KC_NO, KC_VOLD,
    KC_NO, KC_PGDOWN, KC_NO, KC_MUTE,
    TG(5), KC_END, KC_NO, KC_MEDIA_PLAY_PAUSE
  ),
  [6] = LAYOUT_ortho_4x4(
    KC_MS_BTN2, KC_MS_U, KC_MS_BTN1, KC_MS_WH_UP,
    KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_WH_DOWN,
    KC_MS_BTN3, KC_MS_BTN4, KC_MS_WH_LEFT, KC_MS_WH_RIGHT,
    TG(6), KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2
  ),
  [7] = LAYOUT_ortho_4x4(
    KC_NO, KC_NO, KC_UP, KC_NO,
    KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT,
    KC_NO, KC_NO, KC_NO, KC_NO,
    TG(7), KC_NO, KC_NO, KC_SPACE
  ),
  [8] = LAYOUT_ortho_4x4(
    KC_TAB, KC_Q, KC_W, KC_E,
    KC_R, KC_A, KC_S, KC_D,
    KC_LSHIFT, KC_X, KC_C, KC_F,
    TG(8), KC_Y, KC_SPACE, KC_SPACE
  )
};