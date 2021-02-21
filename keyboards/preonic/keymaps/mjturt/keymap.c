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
  _GAM
};

enum preonic_keycodes {
  LOWER,
  RAISE,
  /* Songs */
  SONG_1 = SAFE_RANGE,
  SONG_2,
  SONG_3,
  SONG_4,
  SONG_5,
  SONG_6
};

#ifdef AUDIO_ENABLE
    #include "audio.h"
    float tone_startup[][2]         = SONG(STARTUP_SOUND);
    float tone_goodbye[][2]         = SONG(GOODBYE_SOUND);
    float tone_colemak[][2]         = SONG(COLEMAK_SOUND);
    float tone_swcole[][2]          = SONG(QWERTY_SOUND);
    float tone_capslock_on[][2]     = SONG(CAPS_LOCK_ON_SOUND);
    float tone_capslock_off[][2]    = SONG(CAPS_LOCK_OFF_SOUND);
    float tone_copy[][2]            = SONG(SCROLL_LOCK_ON_SOUND);
    float tone_paste[][2]           = SONG(SCROLL_LOCK_OFF_SOUND);
    float tone_uniwin[][2]          = SONG(UNICODE_WINDOWS);
    float tone_unilin[][2]          = SONG(UNICODE_LINUX);
    float tone_coin[][2]            = SONG(COIN_SOUND);
    float tone_one_up[][2]          = SONG(ONE_UP_SOUND);
    float tone_trek[][2]            = SONG(TO_BOLDLY_GO);
    float tone_rick[][2]            = SONG(RICK_ROLL);
    float tone_game_over[][2]       = SONG(MARIO_GAMEOVER);
    float tone_mario[][2]           = SONG(MARIO_THEME);
    float tone_ussr[][2]            = SONG(USSR_ANTHEM);
    float tone_numb[][2]            = SONG(LP_NUMB);
    float tone_zelda[][2]           = SONG(ZELDA_TREASURE);
    float tone_mush[][2]            = SONG(MARIO_MUSHROOM);
    float tone_no1[][2]             = SONG(NUMBER_ONE);
    float tone_all_star[][2]        = SONG(ALL_STAR);
    float tone_victory[][2]         = SONG(VICTORY_FANFARE_SHORT);
    float tone_star_wars[][2]       = SONG(IMPERIAL_MARCH);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Mute |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ´   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | _ADJ | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | GUI  | Alt  | Ctrl |'/Shft|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_MUTE,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  MO(_ADJUST), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, KC_RCTL, RSFT_T(KC_BSLS)
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
  KC_MPLY, _______, RALT(KC_2), _______, _______, _______,    _______,       _______,    _______,    _______,       _______, _______,
  KC_TILD, KC_EXLM, KC_AT,      KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC,       KC_AMPR,    KC_ASTR,    KC_LPRN,       KC_RPRN, _______,
  _______, KC_RBRC, _______,    _______, _______, RALT(KC_4), RALT(KC_RBRC), KC_ASTR,    KC_LPRN,    RALT(KC_MINS), KC_RCBR, KC_PIPE,
  _______, KC_PLUS, KC_EQL,     KC_LBRC, _______, _______,    _______,       RALT(KC_7), RALT(KC_0), KC_MINS,       KC_UNDS, _______,
  _______, _______, _______,    _______, _______, _______,    _______,       _______,    _______,    _______,       _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Play |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_MPLY, KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,
  KC_GRV,  KC_1,          KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,    KC_F12,
  _______, KC_LBRC,       _______, _______, _______, _______, _______, RALT(KC_8), RALT(KC_9), _______, _______, _______,
  _______, RALT(KC_NUBS), _______, _______, _______, _______, _______, KC_NUBS,    S(KC_NUBS), _______, _______, _______,
  _______, _______,       _______, _______, _______, KC_MPLY, KC_MPLY, _______,    KC_MPRV,    KC_VOLD, KC_VOLU, KC_MNXT
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * | RESET|Song1 |Song2 |Song3 |Song4 |Song5 |Song6 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TG_GAM|RGB_TG|RGB_MO|RGB_HI|PrnScr| PgUp |      | Home | End  |      | Bspc | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AU_TOG|CK_TOG|      |      | PgDn | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MU_TOG|MU_MOD|      |      |      |      |      |      |M BTN1| M Up |M BTN3|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |M Left|M Down|M Rght|
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] = LAYOUT_preonic_grid(
  RESET,    SONG_1,  SONG_2,  SONG_3,  SONG_4,  SONG_5,  SONG_6,  _______, _______, _______, _______, _______,
  TG(_GAM), RGB_TOG, RGB_MOD, RGB_HUI, KC_PSCR, KC_PGUP, _______, KC_HOME, KC_END,  _______, KC_BSPC, KC_DEL,
  _______,  AU_TOG,  CK_TOGG, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______,  MU_TOG,  MU_MOD,  _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN3,
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
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

[_GAM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
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
        /* Songs */
        case SONG_1:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(tone_star_wars);
                }
             #endif
            return true;
        case SONG_2:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(tone_numb);
                }
             #endif
            return true;
        case SONG_3:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(tone_one_up);
                }
             #endif
            return true;
        case SONG_4:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(tone_game_over);
                }
             #endif
            return true;
        case SONG_5:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(tone_mush);
                }
             #endif
            return true;
        case SONG_6:
            #ifdef AUDIO_ENABLE
                if (record->event.pressed) {
                    PLAY_SONG(tone_ussr);
                }
             #endif
            return true;
        default:
            return true;
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

int RGB_GRADIENT_INT = 6;

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(0,255,255);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + RGB_GRADIENT_INT);
}

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {1,5,5};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _LOWER:
            rgblight_sethsv_noeeprom(180,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _RAISE:
            rgblight_sethsv_noeeprom(14,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _GAM:
            rgblight_sethsv_noeeprom(85,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case _ADJUST:
            rgblight_sethsv_noeeprom(0,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            break;
        default:
            rgblight_sethsv_noeeprom(0,255,255);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT + RGB_GRADIENT_INT);
            break;
    }

    return state;
}
