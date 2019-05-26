#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _NAV 3
#define _FN 4
#define _ADJUST 16

#define TAPPING_TOGGLE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  FN3,
  FN4,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ortho_4x4(
    KC ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,                            KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KS_S, KC_D, KC_F, KC_G,           KC_H, KC_J, KC_K, KC_L, RSFT_T(KC_SCLN), RSFT_T(KC_QUOTE),
    LCTL_T(KC_MINUS), LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMMA, RALT_T(KC_DOT), RGUI_T(KC_SLSH), RCTL_T(KC_EQUAL),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, TT(_NAV), KC_SPACE,            KC_ENTER, TT(_FN), KC_BSPACE, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_DVORAK] = LAYOUT_ortho_4x4(
    KC ESC, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                      KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KC_O, KC_E, KC_U, KC_I,            KC_D, KC_H, KC_T, KC_N, RSFT_T(KC_S), RSFT_T(KC_SLSH),
    LCTL_T(KC_MINUS), LGUI_T(KC_SCLN), LALT_T(KC_Q), KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, RALT_T(KC_V), RGUI_T(KC_Z), RCTL_T(KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, TT(_NAV), KC_SPACE,            KC_ENTER, TT(_FN), KC_BSPACE, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_COLEMAK] = LAYOUT_ortho_4x4(
    KC ESC, KC_Q, KC_W, KC_F, KC_P, KC_G,                             KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
    LSFT_T(KC_GRAVE), LSFT_T(KC_A), KC_R, KC_S, KC_T, KC_D,           KC_H, KC_N, KC_E, KC_I, RSFT_T(KC_O), RSFT_T(KC_QUOT),
    LCTL_T(KC_MINUS), LGUI_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B,   KC_K, KC_M, RALT_T(KC_COMMA), RGUI_T(KC_DOT), RCTL_T(KC_ENTER),
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, TT(_NAV), KC_SPACE,            KC_ENTER, TT(_FN), KC_BSPACE, KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCAP, NO ,HOME,PGDN,PGUP, END,     LEFT,DOWN, UP ,RGHT, INS, DEL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     CTB , F1 , F2 , F3 , F4 , F5 ,      F6,  F7 , F8 , F9 , F10, F11,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      X3 ,LCTL,LALT,LGUI, LOW, ENT,      SPC,RAIS,RALT,    ,    , F12
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TAB, EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN, DEL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCAP,    ,    ,    ,    ,    ,     MINS, EQL,    ,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      CTB,    ,    ,    ,    ,    ,     UNDS,PLUS,VOLD,VOLU,MUTE,SENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      X3 ,LCTL,LALT,LGUI, LOW, ENT,      SPC,RAIS,RALT,    ,    , NO
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     GESC, Q  , W  , F  , P  , G  ,      J  , L  , U  , Y  ,SCLN,MINS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCAP, A  , R  , S  , T  , D  ,      H  , N  , E  , I  , O  ,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      CTB, Z  , X  , C  , V  , B  ,      K  , M  ,COMM,DOT ,SLSH,SENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      X3 ,LCTL,LALT,LGUI, LOW, ENT,      SPC,RAIS,RALT,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_DVORAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.  
     TAB ,QUOT,COMM,DOT , P  , Y  ,      F  , G  , C  , R  , L  ,MINS, 
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      X0 , A  , O  , E  , U  , I  ,      D  , H  , T  , N  , S  ,SLSH,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,SCLN, Q  , J  , K  , X  ,      B  , M  , W  , V  , Z  ,SENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      X3 ,LCTL,LALT,LGUI, LOW, ENT,      SPC,RAIS,RALT,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_FN3] = LAYOUT_kc(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     MS_L,MS_D,MS_U,MS_R,WH_L,WH_R,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     BTN1,WH_D,WH_U,BTN2,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT( \
      RESET,  QWERTY, COLEMAK,  DVORAK, _______, EEP_RST,   KC_MNXT, KC_MPRV, KC_MFFD, KC_MRWD,  DVORAK, KC_EJCT, \
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_PGUP, KC_HOME,   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,   CK_UP, CK_DOWN, \
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_PGDN,  KC_END,   KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, \
    BL_TOGG,  BL_INC,  BL_DEC, BL_BRTG, _______, _______,    CK_RST, _______, CK_TOGG,  MU_MOD,  MU_TOG,  AU_TOG \
  )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
         set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
