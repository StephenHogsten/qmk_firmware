#include QMK_KEYBOARD_H
// bool is_sym_locked = false;
// bool is_nav_locked = false;
extern keymap_config_t keymap_config;

enum custom_keycodes {
  M_LSAHL = SAFE_RANGE,
  M_RAILSC,
  M_RELOAD,
  M_REBUILD,
  M_MS_DOWN,
  M_MS_UP,
  M_RESET
};

#define _COLEMAK_DH 0
#define _MOUSE 1
#define _GAME 2
#define _NAV 3
#define _SYM 4
#define _ADJUST 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_ortho_4x12(
    KC_Q, KC_W, KC_F, KC_P, KC_B, TG(_MOUSE),                                            TG(_GAME), KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
    LALT_T(KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G, TG(_MOUSE),            TG(_GAME), KC_K, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
    KC_Z, KC_X, KC_C, KC_D, KC_V, TG(_MOUSE),                                            TG(_GAME), KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLSH,
    M_RESET, KC_LPRN, KC_RPRN, KC_ESC, LT(_NAV, KC_TAB), LT(_NAV, KC_SPACE),          LT(_SYM, KC_ENTER), LT(_SYM, KC_BSPC), KC_DEL, KC_LBRC, KC_RBRC, KC_PSCR
  ),

    /* NAV (left thumb) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * |  ~   |  +   |  :   |   _  | ScUp |      |    |      | Home | PgDn | PgUp |  End |   |  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  `   |  =   |  ;   |   -  | ScDn |      |    |      | Left | Down |  Up  | Right|  ESC |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * | caps |   }  |   ]  |   )  | click|      |    |      |   >  |   (  |   [  |  {   |   \  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | LEAD | ScLt | ScRt |      |(this)|      |    | spc  | _ADJ |      | ScDn | ScUp |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_NAV] = LAYOUT_ortho_4x12(
    KC_TILDE, KC_PLUS, KC_COLON, KC_UNDS, KC_WH_U, _______,                                 _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, 
    LALT_T(KC_GRAVE), LGUI_T(KC_EQL), LSFT_T(KC_SCLN), LCTL_T(KC_MINUS), KC_WH_D, _______,  _______, KC_LEFT, RCTL_T(KC_DOWN), RSFT_T(KC_UP), RGUI_T(KC_RIGHT), RALT_T(KC_ESC), 
    KC_CAPS, KC_RCBR, KC_RBRC, KC_RPRN, KC_MS_BTN1, _______,                                     _______, KC_GT, KC_LPRN, KC_LBRC, KC_LCBR, KC_BSLS,
    KC_LEAD, KC_WH_L, KC_WH_R, _______, _______, _______,                                   LT(_ADJUST, KC_SPACE), LT(_ADJUST, KC_BSPC), _______, KC_WH_D, KC_WH_U, _______
  ),
  [_SYM] = LAYOUT_ortho_4x12(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,                                        _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
    LALT_T(KC_1), LGUI_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5, _______,             _______, KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RGUI_T(KC_9), RALT_T(KC_0), 
    KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC, _______,                                _______, KC_CIRC, KC_AMPR,  KC_ASTR, KC_F11, KC_F12,
    KC_LEAD, KC_SCLN, KC_F11, _______, LT(_ADJUST, KC_TAB), LT(_ADJUST, KC_SPACE),   _______, _______, _______, KC_F12, _______, _______
  ),

  /* ADJUST (both thumbs) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | qwer | qwe2 |      |      |reload|      |    |      |      |      |      |      | SYM  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | caps | prsc |coledh| caps |      |      |    |      |      | caps |ls ahl|      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      | cole |railsc|      | fold |    |unfold|      |      |      |      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |    |      |      |      |      |      |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_ADJUST] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, TO(_SYM),
    KC_CAPS, KC_PSCR, _______, KC_CAPS, _______, _______,                       _______, _______, KC_CAPS, M_LSAHL, _______, _______,
    _______, _______, _______, M_RAILSC, _______, C(S(KC_LBRC)),                  C(S(KC_RBRC)), _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______
  ),
  /* MOUSE
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | m1 dn|  M2  | M up |  M1  | scup |      |    |      | Home | PgDn | PgUp |  End |   \  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * | m1 up|  M l | M up | M rt | scdn |      |    |      | Left | Down |  Up  | Right|   ;  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  ~   |   x  |  c   |   v  |   >  |      |    |      | sp 0 | sp 1 | sp 2 |  ?   |  |   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      | ScLt | ScRt |      |normal|      |    | BkSp | _ADJ |      | ScUp | ScUp |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_MOUSE] = LAYOUT_ortho_4x12(
    M_MS_DOWN, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, TG(_MOUSE),               TG(_MOUSE), KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS, 
    M_MS_UP, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, TG(_MOUSE),              TG(_MOUSE), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, 
    KC_TILDE, KC_X, KC_C, KC_V, KC_GT, TG(_MOUSE),                  TG(_MOUSE), KC_ACL0, KC_ACL1, KC_ACL2, KC_QUES, KC_PIPE, 
    _______, KC_WH_L, KC_WH_R, _______, TG(_MOUSE), _______,               _______, TG(_MOUSE), _______, KC_WH_D, KC_WH_U, _______
  ),
  /* GAME
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | tab  |  Q   |  W   |  E   |  R   |      |    |      |  Y   |  U   |  I   |  O   |  P   |
  * +------|------+------+------+------+      |    |      |------+------+------+------+------+
  * | sft  |  A   |  S   |  D   |  F   |      |    |      |  H   |  J   |  K   |  L   |   '  |
  * +------|------+------+------+------+      |    |      |------+------+------+------+------+
  * | ctl  |  Z   |  X   |  C   |  V   |      |    |      |  N   |  M   |  ,   |  .   |  /   |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | esc  |   N  |   Y  |  H   |   `  | Space|    | Enter| BkSp |  del |   [  |   ]  | alt  |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_GAME] = LAYOUT_ortho_4x12(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, _______,           TG(_GAME), KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, _______,          TG(_GAME), KC_K, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, _______,          TG(_GAME), KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLSH,
    KC_LEAD, KC_N, KC_Y, KC_H, KC_GRAVE, KC_SPACE,         LT(_SYM, KC_ENTER), LT(_SYM, KC_BSPC), KC_DEL, KC_LBRC, KC_RBRC, KC_LALT
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_RESET: 
      if (record->event.pressed) {
        eeconfig_init();
      }
      break;
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
    case M_REBUILD:
      if (record->event.pressed) {
        SEND_STRING("sudo make keebio/levinson/rev2:hogdog:avrdude" SS_TAP(X_ENTER));
      }
      break;
  }
  return true;
}

LEADER_EXTERNS();

// void toggle_sym_lock(void) {
//   if (is_sym_locked) {
//     layer_on(_SYMALT);
//   } else {
//     layer_off(_SYMALT);
//   }
//   is_sym_locked = !is_sym_locked;
// }

// void toggle_nav_lock(void) {
//   if (is_nav_locked) {
//     layer_on(_NAV);
//   } else {
//     layer_off(_NAV);
//   }
//   is_nav_locked = !is_nav_locked;
// }

void matrix_scan_user(void) {     // The very important timer. 
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_LSFT) {
      SEND_STRING("1");
    }

    SEQ_ONE_KEY(KC_A) {
      SEND_STRING("2");
    }
    
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("3");
    }

    SEQ_ONE_KEY(KC_D) {
      SEND_STRING("4");
    }

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("5");
    }

    // SEQ_ONE_KEY(KC_TAB) {
    //   toggle_nav_lock();
    // }

    // SEQ_ONE_KEY(KC_SPACE) {
    //   toggle_nav_lock();
    // }

    // SEQ_ONE_KEY(KC_BSPC) {
    //   toggle_sym_lock();
    // }

    // SEQ_ONE_KEY(KC_ENTER) {
    //   toggle_sym_lock();
    // }

    SEQ_ONE_KEY(KC_V) {
      register_code(KC_LCTRL);
      register_code(KC_LSFT);
      tap_code(KC_INS);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTRL);
    }

    SEQ_ONE_KEY(KC_LCTL) {
      tap_code(KC_ESC);
    }

    SEQ_TWO_KEYS(KC_M, KC_S) {
      layer_off(_NAV);
      layer_on(_MOUSE);
    }

    SEQ_TWO_KEYS(KC_P, KC_S) {
      SEND_STRING(SS_LGUI(" ")"gnome-screenshot -ac\n");
    }

    SEQ_THREE_KEYS(KC_P, KC_S, KC_S) {
      SEND_STRING(SS_LGUI(" ")"gnome-screenshot -a\n");
    }

    // 
    SEQ_THREE_KEYS(KC_C, KC_B, KC_M) {
      SEND_STRING("clipit &; jobs | disown\n");
    }

    SEQ_TWO_KEYS(KC_G, KC_M) {
      layer_off(_NAV);
      layer_on(_GAME);
    }
   
    SEQ_THREE_KEYS(KC_Q, KC_M, KC_K) {
      SEND_STRING("sudo make keebio/levinson/rev2:hogdog:avrdude\n");
    }

    SEQ_THREE_KEYS(KC_E, KC_E, KC_P) {
      eeconfig_init();
    }
  }
}

// uint32_t layer_state_set_user(uint32_t state) {
//   switch (biton32(state)) {
//     case _QWERTY:
//       unregister_code(KC_LALT);
//       is_alt_tab_active = false;
//       break;
//   }
//   return state;
// }

// uint16_t get_tapping_term(uint16_t keycode) {
//   switch (keycode) {
//     case LALT_T(KC_A):
//     case RALT_T(KC_QUOT):
//     case RALT_T(KC_O):
//       return TAPPING_TERM + 500;
//     default:
//       return TAPPING_TERM;
//   }
// }

