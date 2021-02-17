/* Copyright 2015-2017 Jack Humbert
 * Edited by mjturt 2021
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV
};

enum preonic_keycodes {
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_MUTE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  MO(_NAV), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   RSFT_T(KC_BSLS)
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_MPLY, _______, _______, _______, _______, _______,    _______,       _______,    _______,    _______,       _______, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,       KC_AMPR,    KC_ASTR,    KC_LPRN,       KC_RPRN, KC_DEL,
  _______, KC_RBRC, _______, _______, _______, RALT(KC_4), RALT(KC_RBRC), KC_ASTR,    KC_LPRN,    RALT(KC_MINS), KC_RCBR, KC_PIPE,
  _______, KC_PLUS, KC_EQL,  KC_LBRC, _______, _______,    _______,       RALT(KC_7), RALT(KC_0), KC_MINS,       KC_UNDS, _______,
  _______, _______, _______, _______, _______, _______,    _______,       _______,    _______,    _______,       _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,
  KC_GRV,  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    KC_F12,
  _______, KC_LBRC,       _______, _______, _______, _______, _______, RALT(KC_8), RALT(KC_9), _______, _______, _______,
  _______, RALT(KC_NUBS), _______, _______, _______, _______, _______, KC_NUBS,    S(KC_NUBS), _______, _______, _______,
  _______, _______,       _______, _______, _______, KC_MPLY, KC_MPLY, _______,    KC_MPRV,    KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

[_NAV] = LAYOUT_preonic_grid(
  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
  _______, _______,  _______, _______, KC_PSCR, KC_PGUP, _______, KC_HOME, KC_END,  KC_ESC,  KC_BSPC, KC_DEL,
  _______, RGB_TOG,  RGB_MOD, RGB_HUI, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ENT,
  _______, BL_TOGG,  BL_DEC,  BL_INC,  _______, _______, _______, KC_MUTE, _______, _______, _______, _______,
  _______, _______,  _______, _______, _______, KC_MPLY, KC_MPLY, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
