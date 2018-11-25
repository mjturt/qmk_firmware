#include "amj40.h"
#include "quantum.h"
// Custom layout
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

// Layer definitions
#define DEF 0
#define SPC 1
#define NUM 2
#define NAV 3
#define FUN 4
#define NUP 5
#define GAM 6

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   // 0: Default
   [DEF] = KEYMAP(
         LT(NUP, KC_TAB), KC_Q,    KC_W,             KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSPC, 
         LT(NAV, KC_ESC), KC_A,    KC_S,             KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOT, 
         KC_LSFT,         KC_Z,    KC_X,             KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    LT(NAV,KC_ENT), 
         KC_LCTL,         KC_LGUI, KC_LEAD, KC_LALT, MO(SPC),          LT(FUN, KC_SPC),          MO(NUM), KC_RALT, RALT(KC_2), RSFT_T(KC_BSLS)),

   // 1: Special characters
   [SPC] = KEYMAP(
         KC_TILD, KC_EXLM,       KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,       KC_AMPR,    KC_ASTR,    KC_LPRN,       KC_RPRN, _______, 
         _______, KC_RBRC,       _______, _______, _______, RALT(KC_4), RALT(KC_RBRC), KC_ASTR,    KC_LPRN,    RALT(KC_MINS), KC_RCBR, KC_PIPE, 
         _______, KC_PLUS,       KC_EQL,  KC_LBRC, _______, _______,    _______,       RALT(KC_8), RALT(KC_9), KC_MINS,       KC_UNDS, _______, 
         _______, _______,       _______, _______, _______,                 _______,               _______,    _______,       _______, _______),

   // 2: Numbers
   [NUM] = KEYMAP(
         KC_GRV,  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
         _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
         _______, RALT(KC_NUBS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
         _______, _______,       _______, _______, _______,          _______,          _______, _______, _______, _______),

   // 3: Navigation, arrows(jklö)
   [NAV] = KEYMAP(
         TG(NUP), _______, _______, _______, KC_PSCR, _______, KC_PGUP, KC_HOME, KC_ESC,  KC_END,  KC_BSPC, KC_DEL, 
         _______, TG(GAM), _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT, 
         _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, KC_MUTE, _______, KC_VOLU, _______, 
         _______, _______, _______, _______, _______,            KC_MPLY,        _______, KC_MPRV, KC_VOLD, KC_MNXT),

   // 4: Function keys
   [FUN] = KEYMAP(
         KC_GRV,  KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,       KC_F9,   KC_F10,  _______, 
         _______, KC_F11,        KC_F12,  _______, _______, _______, _______, RALT(KC_7), RALT(KC_0),  _______, _______, _______, 
         _______, RALT(KC_NUBS), _______, _______, _______, _______, _______, KC_NUBS,    S(KC_NUBS),  _______, _______, _______, 
         _______, _______,       _______, _______, _______,          _______,             _______,     _______, _______, _______),

   // 5: Numpad
   [NUP] = KEYMAP(
         _______, _______, _______, _______, _______, _______, KC_7, KC_8, KC_9,    KC_MINS, KC_SLSH, _______, 
         _______, _______, _______, _______, _______, _______, KC_4, KC_5, KC_6,    KC_PIPE, KC_AMPR, _______, 
         _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3,    _______, KC_COMM, _______, 
         _______, _______, _______, _______, _______,          KC_0,       KC_RPRN, _______, _______, _______),

   // 6: Arrow layer for some games
   [GAM] = KEYMAP(
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, 
         _______, _______, _______, _______, _______,          _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT),

};

/*
 * Empty macro function
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
   return MACRO_NONE;
}

/*
 * Empty init function
 */
void matrix_init_user(void) {
}

/*
 * Scan function. Has leader key and led stuff.
 */
LEADER_EXTERNS();
bool has_layer_changed = true;

void matrix_scan_user(void) {

   /*
    * Leader key macros
    */
   LEADER_DICTIONARY() {
      leading = false;
      leader_end();
      // VM workspace changing
      SEQ_ONE_KEY(KC_Q) {
         SEND_STRING(SS_LGUI("1"));
      }
      SEQ_ONE_KEY(KC_W) {
         SEND_STRING(SS_LGUI("2"));
      }
      SEQ_ONE_KEY(KC_E) {
         SEND_STRING(SS_LGUI("3"));
      }
      SEQ_ONE_KEY(KC_R) {
         SEND_STRING(SS_LGUI("4"));
      }
      SEQ_ONE_KEY(KC_T) {
         SEND_STRING(SS_LGUI("5"));
      }
      // IP
      SEQ_TWO_KEYS(KC_I, KC_P) {
         SEND_STRING("192.168.8.101");
      }
   }

   /*
    * Caps Lock led on when non-default layer is active
    * AMJ40 caps lock led is under ESC in my layout
    */
   uint8_t layer = biton32(layer_state);
   static uint8_t old_layer = 0;

   if (old_layer != layer) {
      has_layer_changed = true;
      old_layer = layer;
   }

   if (has_layer_changed) {
      has_layer_changed = false;

      switch (layer) {
         case SPC:
            DDRB |= (1 << 2); PORTB &= ~(1 << 2);
            break;
         case NUM:
            DDRB |= (1 << 2); PORTB &= ~(1 << 2);
            break;
         case NAV:
            DDRB |= (1 << 2); PORTB &= ~(1 << 2);
            break;
         case FUN:
            DDRB |= (1 << 2); PORTB &= ~(1 << 2);
            break;
         case NUP:
            DDRB |= (1 << 2); PORTB &= ~(1 << 2);
            break;
         case GAM:
            DDRB |= (1 << 2); PORTB &= ~(1 << 2);
            break;
         case DEF:
            DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
            break;
      }
   }
}

/*
 * Key press processing. Nothing at the moment.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case KC_A:
         if (record->event.pressed) {
         }
         return true;
      case KC_S:
         if (record->event.pressed) {
         }
      default:
         return true;
   }
}

 /*
  * For future RGB led stuff. For now just controls backlighting brightness.
  */
uint32_t layer_state_set_user(uint32_t state) {
   switch (biton32(state)) {
      case SPC:
         //rgblight_setrgb (0x00,  0x00, 0xFF);
         break;
      case NUM:
         //rgblight_setrgb (0xFF,  0x00, 0x00);
         break;
      case NAV:
         //rgblight_setrgb (0x00,  0xFF, 0x00);
         break;
      case FUN:
         //rgblight_setrgb (0x7A,  0x00, 0xFF);
         break;
      case NUP:
         //rgblight_setrgb (0x7A,  0x00, 0xFF);
         backlight_set(2);
         break;
      case GAM:
         //rgblight_setrgb (0x7A,  0x00, 0xFF);
         backlight_set(2);
         break;
      default:
         backlight_set(4);
         //rgblight_setrgb (0x00,  0xFF, 0xFF);
         break;
   }
   return state;
}

/*
 * Lock keys and leds, does nothing at the moment
 */
void led_set_user(uint8_t usb_led) {

   if (usb_led & (1 << USB_LED_NUM_LOCK)) {
   } else {
   }

   if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
   } else {
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
