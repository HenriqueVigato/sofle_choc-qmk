/* Copyright 2023 Brian Low
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

enum layer_names {
    MAIN,
    FIRST,
    SECOND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * MAIN
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | + =  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | { [  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------| PRINT |    | CAPS  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL |  WIN | LCMD | Space| / TO(1) /       \Enter \  | back | RCTL | TO(1)| WIN  |
     *            |      |      |      |      |/       /         \      \ | space|      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

   [MAIN] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_EQL,
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC,
        KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_PSCR,    KC_CAPS,KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                     KC_LGUI,  KC_RWIN, KC_LCTL,  KC_SPC,TO(FIRST), KC_ENT,KC_BSPC, KC_RCTL, TO(SECOND), KC_LWIN
    ),

    /*
     * FIRST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  ` ~ |      |      |      |      |      |                    |      |      |      |      |      | ] }  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |   <- | down |  up  |  ->  | | \  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      | Space| / TO(0) /       \Enter \  | back |      |      |      |
     *            |      |      |      |      |/       /         \      \ | space|      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [FIRST] = LAYOUT(
        KC_F1,   KC_F2,     KC_F3,      KC_F4,      KC_F5,      KC_F6,                       KC_F7,      KC_F8,    KC_F9,     KC_F11,   KC_F11,   KC_F12,
        KC_GRV,  KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_RBRC,
        KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_LEFT,  KC_DOWN,   KC_UP,    KC_RGHT,  KC_BSLS,
        KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,      KC_NO,  KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
                            KC_NO,      KC_NO,      KC_NO,      KC_SPC, TO(MAIN),   KC_ENT,KC_BSPC,   KC_NO,      KC_NO,     KC_NO
    ),

    /*
     * SECOND
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      | Space| / TO(0) /       \Enter \  | back |      |      |      |
     *            |      |      |      |      |/       /         \      \ | space|      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [SECOND] = LAYOUT(
        KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,                       KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
        KC_NO,   KC_NO,     KC_NO,      KC_NO,      KC_NO,      KC_NO,   KC_NO,      KC_NO,  KC_NO,      KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
                            KC_NO,      KC_NO,      KC_NO,      KC_SPC, TO(MAIN),   KC_ENT,KC_BSPC,   KC_NO,      KC_NO,     KC_NO
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
   [MAIN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
   [FIRST] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
   [SECOND] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
};
#endif

#ifdef OLED_ENABLE
    // Rotate the orientation
oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

// Render Cat Logo
static void render_logo(void) {
    static const char image[] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x3f, 0x7f, 0xff, 0xff, 0xfd, 0xfd, 0xfd, 0xf9, 0xfb, 0xff, 0xff, 0xff, 0xef,
        0xef, 0xff, 0xff, 0xfb, 0xf9, 0xfd, 0xfd, 0xfd, 0xfd, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
        0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0xfe, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xfc, 0xfc,
        0xfc, 0xfc, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xfe, 0xfc, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xef, 0xe7, 0xef, 0xef, 0xcf, 0xff, 0xff, 0xff, 0x7f,
        0x7f, 0xff, 0xff, 0xff, 0xcf, 0xef, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
        0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xf8, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0x7f, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xf3,
        0xf7, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03,
        0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xe0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xfc, 0xfc,
        0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf7, 0xe7, 0xef, 0xef, 0xff, 0xff, 0xff, 0x3f,
        0xbf, 0xff, 0xff, 0xff, 0xef, 0xe7, 0xe7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0x7e, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
        0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(image, sizeof(image));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Host Keyboard Layer Status
        oled_write_P(PSTR("\nLayer\n"), false);

        switch (get_highest_layer(layer_state)) {
            case MAIN:
                oled_write_P(PSTR("Main\n\n"), false);
                break;
            case FIRST:
                oled_write_P(PSTR("Fisrt\n"), false);
                break;
            case SECOND:
                oled_write_P(PSTR("Second"), false);
                break;
            default:
                // Or use the write_ln shortcut over adding '\n' to the end of your string
                oled_write_ln_P(PSTR("Undefined"), false);
        }
        render_logo();
    }

    if (!is_keyboard_left() || !is_keyboard_master()) {
        render_logo();
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM\n") : PSTR("    \n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("    \n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("    \n"), false);

    return false;
}
#endif