#include "dz60.h"

/* mjturt keymap for dz60 board with ISO-layout */

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define ______ KC_TRNS
#define DL 0
#define FL 1
#define CL 2

enum custom_keycodes {
   EDIT_VIM = SAFE_RANGE,
   SETMAPFI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Default Layer(DL, 0)
    * ,-----------------------------------------------------------------------------------------.
    * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
    * |-----------------------------------------------------------------------------------------+
    * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  Å  |  ^  |        |
    * |----------------------------------------------------------------------------------| Entr +
    * | Func1    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |  '  |      |
    * |-----------------------------------------------------------------------------------------+
    * | Shift |  <  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  -  |     Shift     |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl | Super | Alt  |              Space               | Alt gr | Func1 | Super | Func2 |
    * `-----------------------------------------------------------------------------------------'
    */
   [DL] = LAYOUT(
         F(0), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
         KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
         TT(FL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
         KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
         KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, TT(FL), KC_NO, KC_RGUI, TT(CL)),

   /* Function Layer(FL, 1)
    * ,-----------------------------------------------------------------------------------------.
    * | GRV |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 |  F10 |  F11 |  F12 |  DEL   |
    * |-----------------------------------------------------------------------------------------+
    * |        |BTN1 | MUP | BTN2|     | pUp | Home| End | Esc |     |PrnSc| Up |      |        |
    * |----------------------------------------------------------------------------------|      +
    * |          | MLFT| MDWN| MRGT|     | pDn | Lft | Dwn | Up  | Rht | Lft | Dwn | Rht |      |
    * |-----------------------------------------------------------------------------------------+
    * |       |     |     |     |     |EVIM |     |     |     |     |     |     |               |
    * |-----------------------------------------------------------------------------------------+
    * |      |      |       |                                  |        |       |       |       |
    * `-----------------------------------------------------------------------------------------'
    */
   [FL] = LAYOUT(
         KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ______, KC_DEL,
         ______, KC_BTN1, KC_MS_U, KC_BTN2, ______, KC_PGUP, KC_HOME, KC_END, KC_ESC, ______, KC_PSCR, KC_UP, ______, KC_RIGHT,
         ______, KC_MS_L, KC_MS_D, KC_MS_R, ______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LEFT, KC_DOWN, ______,
         ______, ______, ______, SETMAPFI, ______, EDIT_VIM, ______, ______, ______, ______, ______, ______, ______, ______,
         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______),

   /* Control Layer(CL, 2)
    * ,-----------------------------------------------------------------------------------------.
    * | RST |     |     |     |     |     |     |     |     |     |      |      |      |        |
    * |-----------------------------------------------------------------------------------------+
    * |        |  RV+|  RH+| RS+ |RRain|     |     |     |     |     | Play| vUp|      |        |
    * |----------------------------------------------------------------------------------|      +
    * |          | RV- | RH- | RS- |     |     |     |     |     |     | Prv | vDn | Nxt |      |
    * |-----------------------------------------------------------------------------------------+
    * |       |BLON |BLSTP|     |     |     |     |     | MUTE|     |     |     |               |
    * |-----------------------------------------------------------------------------------------+
    * |      |      |       |             Play                 |        | RGBON | RGBTGL|       |
    * `-----------------------------------------------------------------------------------------'
    */
   [CL] = LAYOUT(
         RESET, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
         ______, RGB_VAI, RGB_HUI, RGB_SAI, RGB_M_R, ______, ______, ______, ______, ______, KC_MPLY, KC_VOLU, ______, KC_MNXT,
         ______, RGB_VAD, RGB_HUD, RGB_SAD, ______, ______, ______, ______, ______, ______, KC_MPRV, KC_VOLD, ______,
         ______, BL_TOGG, BL_STEP, ______, ______, ______, ______, ______, KC_MUTE, ______, ______, ______, ______, ______,
         ______, ______, ______, KC_MPLY, KC_MPLY, KC_MPLY, ______, RGB_TOG, ______, RGB_MOD, ______),
};

enum function_id {
   SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
   [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
   static uint8_t shift_esc_shift_mask;
   switch (id) {
      case SHIFT_ESC:
         shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
         if (record->event.pressed) {
            if (shift_esc_shift_mask) {
               add_key(KC_GRV);
               send_keyboard_report();
            } else {
               add_key(KC_ESC);
               send_keyboard_report();
            }
         } else {
            if (shift_esc_shift_mask) {
               del_key(KC_GRV);
               send_keyboard_report();
            } else {
               del_key(KC_ESC);
               send_keyboard_report();
            }
         }
         break;
   }
}

/* Macro function */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (record->event.pressed) {
      switch(keycode) {
         case EDIT_VIM:
            SEND_STRING("ev"SS_TAP(X_ENTER));
            return false;
         case SETMAPFI:
            SEND_STRING("setxkbmap fi"SS_TAP(X_ENTER));
            return false;
      }
   }
   return true;
};

/* Changing RGB lighting based on layer */

uint32_t layer_state_set_user(uint32_t state) {
   switch (biton32(state)) {
      case FL:
         rgblight_setrgb (0x00,  0x00, 0xFF);
         break;
      case CL:
         rgblight_setrgb (0xFF,  0x00, 0x00);
         break;
      default:
         rgblight_setrgb (0x00,  0xFF, 0xFF);
         break;
   }
   return state;
}
