#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  ___ = KC_TRNS,
  VRSN = SAFE_RANGE,
};

#define R1(a,b,c,d,e,f,g) a,b,c,d,e,f,g
#define R2(a,b,c,d,e,f,g) a,b,c,d,e,f,g
#define R3(a,b,c,d,e,f) a,b,c,d,e,f
#define R4(a,b,c,d,e,f,g) a,b,c,d,e,f,g
#define R5(a,b,c,d,e) a,b,c,d,e
#define R6(a,b) a,b
#define R7(a) a
#define R8(a,b,c) c,b,a
#define LAYOUT_r(R1L, R1R, R2L, R2R, R3L, R3R, R4L, R4R, R5L, R5R, R6L, R6R, R7L, R7R, R8L, R8R) { \
	 {R1L, R1R}, \
	 {R2L, R2R}, \
	 {R3L, KC_NO, KC_NO, R3R}, \
	 {R4L, R4R}, \
	 {R5L, KC_NO, KC_NO, KC_NO, KC_NO, R5R}, \
	 {KC_NO, R8L, R7L, R6L, R6R, R7R, R8R, KC_NO} \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_r(
R1(KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5, TT(SYMB)),       R1(TT(SYMB),     KC_6,   KC_7,  KC_8,    KC_9,    KC_0,           KC_BSLS),
R2(KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_MINS),        R2(KC_EQL,       KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,           KC_QUOT),
R3(KC_LBRC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G),                 R3(              KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN,        KC_RBRC),
R4(KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_ESC),  R4(GUI_T(KC_ESC), KC_N,  KC_M,  KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_RSFT),
R5(KC_LCTL,  KC_LGUI, KC_LALT, KC_LEFT, KC_RGHT),                                             R5(KC_UP, KC_DOWN, KC_LBRC, KC_RBRC,        KC_RCTL),

                                                  R6(KC_ESC,  KC_INS),  R6(KC_DEL,   KC_RALT),
                                                          R7(KC_PGUP),  R7(KC_PGDN),
                                            R8(KC_SPC,KC_BSPC,KC_END),  R8(KC_HOME, KC_TAB, KC_ENT)

),
[SYMB] = LAYOUT_r(
R1(___,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, ___),  R1(___,       KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,         KC_F11),
R2(___,  ___,    ___,    ___,    ___,    ___, ___),             R2(KC_PSCR,     ___,   ___,  ___,   ___,   ___,             KC_F12),
R3(___,  ___,    ___,    ___,    ___,    ___),                  R3(                ___,   ___,  ___,   ___,   ___,    ___),
R4(___,  ___,    ___,    ___,    ___,    ___, KC_ESC),             R4(___, ___,   ___,  ___,___, ___,   ___),
R5(___,  ___, ___, ___, ___),                                               R5(___, ___,___,___,          ___),

                                                  R6(KC_SLEP,  KC_INS),   R6(KC_DEL,   KC_MUTE),
                                                          R7(KC_HOME),    R7(KC_PGUP),
                                            R8(KC_MNXT,KC_MPRV,KC_MPLY),  R8(KC_PGDN, KC_VOLD, KC_VOLU)

),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

#undef LAYOUT_r
#undef R1
#undef R2
#undef R3
#undef R4
#undef R5
#undef R6
#undef R7
#undef R8

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
    // stub any kb level behaviour
    return false;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_board_led_on();
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
