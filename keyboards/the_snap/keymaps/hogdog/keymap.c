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

enum combos {
  // WF_ESC,
  // FP_SFT,
  UY_QUOTE,
  // LU_SFT
};

#define _COLEMAK_DH 0
#define _MOUSE 1
#define _GAME 2
#define _NAV 3
#define _SYM 4
#define _ADJUST 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT(
    KC_Q, KC_W, LSFT_T(KC_F), KC_P, KC_B,                                           KC_J, KC_L, RSFT_T(KC_U), KC_Y, KC_QUOTE,
    LALT_T(KC_A), LGUI_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,           KC_K, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
    KC_Z, KC_X, KC_C, KC_D, KC_V,                                           KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLSH,
    // RGB_MODE_FORWARD, LT(_NAV, KC_ESC), LT(_NAV, KC_TAB), LT(_NAV, KC_SPACE),        LT(_SYM, KC_ENTER), LT(_SYM, KC_BSPC), LT(_SYM, KC_DEL), KC_PSCR
    M_RESET, LT(_NAV, KC_TAB), LT(_NAV, KC_SPACE), LT(_NAV, KC_ESC),        LT(_SYM, KC_DEL), LT(_SYM, KC_ENTER), LT(_SYM, KC_BSPC), KC_PSCR
  ),

    /* NAV (left thumb) - tap
  * ,-----------------------------------.    ,-----------------------------------------.
  * |  ~   |  +   |  :   |   _  | ScUp |      |    |      | Home | PgDn | PgUp |  End |   |  |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  `   |  =   |  ;   |   -  | ScDn |      |    |      | Left | Down |  Up  | Right|  ESC |
  * +------+------+------+------+------|      |    |      |------+------+------+------+------+
  * |  !   |   }  |   ]  |   )  | click|      |    |      |   >  |   (  |   [  |  {   |   \  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | LEAD | ScLt | ScRt |      |(this)|      |    | spc  | _ADJ |      | ScDn | ScUp |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_NAV] = LAYOUT(
    KC_TILDE, KC_PLUS, KC_COLON, KC_UNDS, KC_WH_U,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_PIPE, 
    LALT_T(KC_GRAVE), LGUI_T(KC_EQL), LSFT_T(KC_SCLN), LCTL_T(KC_MINUS), KC_WH_D,         KC_LEFT, RCTL_T(KC_DOWN), RSFT_T(KC_UP), RGUI_T(KC_RIGHT), RALT_T(KC_ESC), 
    KC_EXLM, KC_RCBR, KC_RBRC, KC_RPRN, KC_MS_BTN1,                                       KC_GT, KC_LPRN, KC_LBRC, KC_LCBR, KC_BSLS,
             KC_LEAD, _______, _______, _______,                              _______, LT(_ADJUST, KC_SPACE), LT(_ADJUST, KC_BSPC), _______
  ),
  [_SYM] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
    LALT_T(KC_1), LGUI_T(KC_2), LSFT_T(KC_3), LCTL_T(KC_4), KC_5,             KC_6, RCTL_T(KC_7), RSFT_T(KC_8), RGUI_T(KC_9), RALT_T(KC_0), 
    KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                                KC_CIRC, KC_AMPR,  KC_ASTR, KC_F11, KC_F12,
    KC_LEAD, _______, LT(_ADJUST, KC_TAB), LT(_ADJUST, KC_SPACE),     _______, _______, _______, _______
  ),

  /* ADJUST (both thumbs) - tap
  * ,-----------------------------------------.    ,-----------------------------------------.
  * | qwer | qwe2 |      |      |reload|      |    |   X  |      |      |      |      | SYM  |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * | caps | prsc |coledh| caps |      |      |    |   X  |      | caps |ls ahl|      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      | cole |railsc|      | fold |    |unfold|      |      |      |      |      |
  * |------+------+------+------+------+------|    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |    |      |      |      |      |      |      |
  * `-----------------------------------------'    `-----------------------------------------'
  */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______,                     _______, _______, _______, _______, TO(_SYM),
    KC_CAPS, KC_PSCR, _______, KC_CAPS, _______,                     _______, KC_CAPS, M_LSAHL, _______, _______,
    _______, _______, _______, M_RAILSC, C(S(KC_LBRC)),                  C(S(KC_RBRC)), _______, _______, _______, _______,
             _______, _______, _______, _______,             _______, _______, _______, _______
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
  [_MOUSE] = LAYOUT(
    M_MS_DOWN, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U,            KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS, 
    M_MS_UP, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,              KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN, 
    KC_TILDE, KC_X, KC_C, KC_V, KC_GT,                        KC_ACL0, KC_ACL1, KC_ACL2, KC_QUES, KC_PIPE, 
              KC_WH_L, KC_WH_R, _______, _______,    _______, _______, KC_WH_D, KC_WH_U
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
  [_GAME] = LAYOUT(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R,            KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F,           KC_K, RCTL_T(KC_N), RSFT_T(KC_E), RGUI_T(KC_I), RALT_T(KC_O),
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V,           KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLSH,
    KC_LEAD, KC_H, KC_GRAVE, KC_SPACE,         LT(_SYM, KC_ENTER), LT(_SYM, KC_BSPC), KC_DEL, KC_LALT
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
      SEND_STRING("sudo make the_snap:hogdog:avrdude\n");
    }

    SEQ_THREE_KEYS(KC_E, KC_E, KC_P) {
      eeconfig_init();
    }
  }
}

// const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
// const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
// const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // [WF_ESC] = COMBO(wf_combo, KC_ESC),
  // [FP_SFT] = COMBO(fp_combo, KC_LSFT),
  [UY_QUOTE] = COMBO(uy_combo, KC_DQUO)
  // [LU_SFT] = COMBO(lu_combo, KC_RSFT)
};
// these don't seem to work if you also need modifiers?

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

#ifdef OLED_DRIVER_ENABLE

static void oled_status(void) {
  oled_write_P(PSTR("Layer: "), false);

  switch (get_highest_layer(layer_state)) {
      case _COLEMAK_DH:
          oled_write_P(PSTR("Default\n"), false);
          break;
      case _MOUSE:
          oled_write_P(PSTR("Mouse\n"), false);
          break;
      case _GAME:
          oled_write_P(PSTR("Game\n"), false);
          break;
      case _NAV:
          oled_write_P(PSTR("Navigation\n"), false);
          break;
      case _SYM:
          oled_write_P(PSTR("Symbols\n"), false);
          break;
      case _ADJUST:
          oled_write_P(PSTR("Adjust\n"), false);
          break;
      default:
          // Or use the write_ln shortcut over adding '\n' to the end of your string
          oled_write_ln_P(PSTR("Undefined"), false);
  }
  led_t led_state = host_keyboard_led_state();
  if (led_state.caps_lock) {
    oled_write_P(PSTR("\nCAPS"), false);
  } else {
    oled_write_P(PSTR("\n    "), false);
  }
}

static void oled_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
      0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
  };

  oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    if (is_keyboard_master()) {
      oled_write_P(PSTR("Hello, world!\n"), false);
      oled_status();
    } else {
      oled_write_P(PSTR("Oh, hello\n"), false);
      oled_qmk_logo();
    }
}
#endif

void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_WH_U);
  } else {
    tap_code(KC_WH_D);
  }
  return;
}
