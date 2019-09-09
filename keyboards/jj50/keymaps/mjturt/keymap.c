/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>
Modified 2019 Maks Turtiainen (mjturt) <maks.turtiainen@gmail.com>

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

// Layers
#define DEF 0
#define NAV 1
#define RAISE 2
#define LOWER 3

// Custom key shorteners
#define TAB_NAV LT(NAV, KC_TAB)
#define ENT_NAV LT(NAV, KC_ENT)

enum custom_keycodes {
    P_MACRO = SAFE_RANGE
};

// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case P_MACRO:
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_KP_1));
                SEND_STRING(SS_TAP(X_KP_5));
                SEND_STRING(SS_TAP(X_KP_6));
                SEND_STRING(SS_UP(X_LALT));
                return false; break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | (Hold for shift / tap for enter)
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | _FN  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [DEF] = LAYOUT( \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  \
        TAB_NAV, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_BSPC, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    ENT_NAV, \
        KC_LCTL, KC_LGUI, KC_LEAD, KC_LALT, MO(RAISE),KC_SPC,KC_SPC,MO(LOWER),  KC_RALT, KC_RGUI, RALT(KC_2), RSFT_T(KC_BSLS) \
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |ISO # |ISO / |  PUP |  PDN |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */

    [LOWER] = LAYOUT( \
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,  \
       _______, _______, _______, _______, _______, _______, _______, RALT(KC_8), RALT(KC_9), _______, _______, _______,  \
       _______, RALT(KC_NUBS), _______, _______, _______, _______, _______, KC_NUBS, S(KC_NUBS), _______, _______, _______,  \
       RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |ISO ~ |ISO | |  HOM |  END |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */

    [RAISE] = LAYOUT( \
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,           KC_F8,      KC_F9,      KC_F10,        KC_F11,  KC_F12,  \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,         KC_AMPR,    KC_ASTR,    KC_LPRN,       KC_RPRN, KC_DEL,  \
        _______, KC_RBRC, _______, _______, _______,   RALT(KC_4), RALT(KC_RBRC), KC_ASTR,    KC_LPRN,    RALT(KC_MINS), KC_RCBR, KC_PIPE, \
        _______, KC_PLUS, KC_EQL,  KC_LBRC, _______,   _______,    _______,       RALT(KC_7), RALT(KC_0), KC_MINS,       KC_UNDS, _______, \
        BL_STEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     \
    ),

    /* Navigation
     * ,-----------------------------------------------------------------------------------.
     * |      |      |  £   |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |BL_OFF|BL_DEC|BL_INC|BL_ON |
     * `-----------------------------------------------------------------------------------'
     */
    [NAV] = LAYOUT( \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, _______, KC_PSCR, KC_PGUP, _______, KC_HOME, KC_END,  KC_ESC,  KC_BSPC, KC_DEL,\
       _______, RGB_TOG, RGB_MOD, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ENT,\
       _______, BL_TOGG, BL_STEP, _______, _______, _______, _______, _______, KC_MUTE, _______, KC_VOLU, _______, \
       _______, _______, _______, _______, _______, KC_MPLY, KC_MPLY, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT    \
    )
};