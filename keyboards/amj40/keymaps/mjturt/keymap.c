#include "amj40.h"

#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
      K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
      K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
      K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
      K300, K301, K302, K303, K304, K305,             K308, K309, K310, K311  \
) { \
      { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011 }, \
      { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111 }, \
      { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211 }, \
      { K300,  K301,  K302,  K303,  K304,  K305,  KC_NO, KC_NO, K308,  K309,  K310,  K311 }  \
}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   // 0: default
   KEYMAP(
         KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
         KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
         KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_ENT, 
         KC_LCTL, KC_LGUI, KC_LALT, MO(3), MO(1), KC_SPC, MO(2), KC_RALT, KC_RGUI, KC_RCTL),

   // 1: special characters
   KEYMAP(
         KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT(KC_7), RALT(KC_0), KC_TRNS, KC_SLSH, KC_TRNS, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

   // 2: numbers
   KEYMAP(
         KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
         KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, 
         KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RALT(KC_8), RALT(KC_9), KC_TRNS, KC_TRNS, KC_TRNS, 
         RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

   // 3: controls, arrows(jklö)
   KEYMAP(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_ESC, KC_END, KC_PSCR, KC_DEL, 
         KC_TRNS, TG(4), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_VOLU, KC_TRNS, 
         BL_TOGG, BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT),

   // 4: arrow layer for some games (toggle)
   KEYMAP(
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, 
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
   return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   return true;
}

void led_set_user(uint8_t usb_led) {

   if (usb_led & (1 << USB_LED_NUM_LOCK)) {

   } else {

   }

   if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
      DDRB |= (1 << 2); PORTB &= ~(1 << 2);
   } else {
      DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
   }

   if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

   } else {

   }

   if (usb_led & (1 << USB_LED_COMPOSE)) {

   } else {

   }

   if (usb_led & (1 << USB_LED_KANA)) {

   } else {

   }

}
