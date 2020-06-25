/*
   Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
   Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
   Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>
   Modified 2020 Maks Turtiainen (mjturt) <maks.turtiainen@gmail.com>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public LicensezZZ
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */

#include QMK_KEYBOARD_H

#define ______ KC_TRNS

// Custom key shorteners
#define TAB_NAV LT(NAV, KC_TAB)
#define ENT_NAV LT(NAV, KC_ENT)
#define DB_CTRL RCTL(KC_LCTRL)

// Layers
enum layers {
    DEF,
    NAV,
    RAISE,
    LOWER,
    GAM,
    NUM,
};

enum custom_keycodes {
    MYRGB_TG = SAFE_RANGE
};

bool rgbinit = true;
bool rgbon = true;

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(205, 255, 255);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
    backlight_enable();
    backlight_level(1);
}

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {1,5,5};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case RAISE:
            rgblight_sethsv_noeeprom(120,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case LOWER:
            rgblight_sethsv_noeeprom(0,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case NUM:
            rgblight_sethsv_noeeprom(40,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case NAV:
            rgblight_sethsv_noeeprom(0,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            break;
        default:
            rgblight_sethsv_noeeprom(205, 255, 255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
            break;
    }

    return state;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
    } else {
        layer_state_set_user(layer_state);
    }
}

void myrgb_toggle(void) {
    if (rgbon) {
        rgblight_disable_noeeprom();
        rgbon = false;
    } else {
        rgblight_enable_noeeprom();
        layer_state_set_user(layer_state);
        led_set_user(host_keyboard_leds());
        rgbon = true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case MYRGB_TG:
            if (record->event.pressed) {
                myrgb_toggle();
            }
            return false;
        default:
            return true;
    }
}

/*
 * In comments is keys that shows in finnish layout
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Default
     * ,-----------------------------------------------------------------------------------.
     * |  ´   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   +  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Tab/M1|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ö  |  ä   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Etr/M1|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | M_NUM| LALT | GUI  |Raise |    Space    |Lower | RALT | RGUI |  @   |'/RSHT|
     * `-----------------------------------------------------------------------------------'
     */
    [DEF] = LAYOUT( \
            KC_EQL,  KC_1,    KC_2,        KC_3,    KC_4,     KC_5,  KC_6,  KC_7,       KC_8,    KC_9,    KC_0,       KC_MINS, \
            TAB_NAV, KC_Q,    KC_W,        KC_E,    KC_R,     KC_T,  KC_Y,  KC_U,       KC_I,    KC_O,    KC_P,       KC_BSPC, \
            KC_ESC,  KC_A,    KC_S,        KC_D,    KC_F,     KC_G,  KC_H,  KC_J,       KC_K,    KC_L,    KC_SCLN,    KC_QUOT, \
            KC_LSFT, KC_Z,    KC_X,        KC_C,    KC_V,     KC_B,  KC_N,  KC_M,       KC_COMM, KC_DOT,  KC_SLSH,    ENT_NAV, \
            KC_LCTL, MO(NUM), KC_LALT,     KC_LGUI, MO(RAISE),KC_SPC,KC_SPC,MO(LOWER),  KC_RALT, KC_RGUI, RALT(KC_2), RSFT_T(KC_BSLS) \
            ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   ½  |   !  |   "  |   #  |   ¤  |   %  |   &  |   /  |   (  |   )  |   =  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |   (  |   )  |   \  |   ^  |  *   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  {   |   }  |  +   |  ?   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [RAISE] = LAYOUT( \
            KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,           KC_F8,      KC_F9,      KC_F10,        KC_F11,  \
            KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,         KC_AMPR,    KC_ASTR,    KC_LPRN,       KC_RPRN, KC_DEL,  \
            _______, KC_RBRC, _______, _______, _______,   RALT(KC_4), RALT(KC_RBRC), KC_ASTR,    KC_LPRN,    RALT(KC_MINS), KC_RCBR, KC_PIPE, \
            _______, KC_PLUS, KC_EQL,  KC_LBRC, _______,   _______,    _______,       RALT(KC_7), RALT(KC_0), KC_MINS,       KC_UNDS, _______, \
            BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______     \
            ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   §  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  å   |      |      |      |      |      |   [  |   ]  |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  |   |      |      |      |      |      |   <  |   >  |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [LOWER] = LAYOUT( \
            KC_F12,  KC_F1,   KC_F2,         KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,  KC_F11,   \
            KC_GRV,  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    _______,  \
            _______, KC_LBRC,       _______, _______, _______, _______, _______, RALT(KC_8), RALT(KC_9), _______, _______, _______,  \
            _______, RALT(KC_NUBS), _______, _______, _______, _______, _______, KC_NUBS,    S(KC_NUBS), _______, _______, _______,  \
            _______, _______,       _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______   \
            ),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |Reset |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |PrnScr| PgUp |      | Home | End  | Esc  | Bspc | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |TG_GAM|RGB_TG|RGB_MO|RGB_HI|      | PgDn | Left | Down |  Up  |Right |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |BL_TG |BL_DEC|BL_INC|      |      |      | Mute |      |      |VolUp |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    Pause    |      |      | Prev |VolDn | Next |
     * `-----------------------------------------------------------------------------------'
     */
    [NAV] = LAYOUT( \
            _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
            _______, MYRGB_TG, _______, _______, KC_PSCR, KC_PGUP, _______, KC_HOME, KC_END,  KC_ESC,  KC_BSPC, KC_DEL,\
            TG(GAM), RGB_TOG,  RGB_MOD, RGB_HUI, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ENT,\
            _______, BL_TOGG,  BL_DEC,  BL_INC,  _______, _______, _______, KC_MUTE, _______, _______, KC_VOLU, _______, \
            _______, _______,  _______, _______, _______, KC_MPLY, KC_MPLY, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT    \
            ),

    /* Gaming
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |  Up  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      | Left | Down |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [GAM] = LAYOUT( \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT  \
            ),

    /* Numpad + mouse
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  7   |  8   |  9   |      |WH_UP |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |WH_DN |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  1   |  2   |  3   | MUp  |MBTN2 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      0      |      | MBTN1|MLeft |MDown |MRight|
     * `-----------------------------------------------------------------------------------'
     */
    [NUM] = LAYOUT( \
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
            _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, KC_WH_U, \
            _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, KC_WH_D, \
            _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_MS_U, KC_BTN2, \
            DB_CTRL, _______, _______, _______, _______, KC_0,    KC_0,    _______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R  \
            )
};
