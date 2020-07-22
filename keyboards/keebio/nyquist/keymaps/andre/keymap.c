#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FUNCTION,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define SCN_LCK LCTL(LGUI(KC_Q))  // Lock screen (MacOS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOTE,
        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
        KC_LCTL, ADJUST, KC_LCTL, KC_LALT, LGUI_T(KC_ENT), LT(_RAISE, KC_SPC), LT(_LOWER, KC_SPC), KC_BSPC, KC_ENT, KC_RBRC, KC_BSLASH, KC_EQL
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | left |  down| up   |right |  |   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */

    [_LOWER] = LAYOUT_ortho_4x12(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_ENT,
        LSFT_T(KC_LBRC), KC_F7, KC_BSPC, KC_F9, KC_F10, KC_F11, KC_F12, S(KC_NUHS), S(KC_NUBS), _______, _______, RSFT_T(KC_RBRC),
        KC_LCTL, ADJUST, KC_LCTL, KC_LALT, LGUI_T(KC_ENT), LT(_RAISE, KC_SPC), LT(_LOWER, KC_SPC), KC_BSPC, KC_ENT, KC_RBRC, KC_PIPE, KC_EQL
    ),

   /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   -  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Del  |  F1  |  F2  |  F3  |M C1  | M C2 |MouseL|MouseD|MouseU|MouseR|   ]  |  -   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |BLTOGG|BLBRTH|  BLD | BL U |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12(
      KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL,
      KC_ESC, KC_F1, KC_F2, KC_F3, KC_MS_BTN1, KC_MS_BTN2, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_RBRC, KC_MINS,
      KC_LEFT_CURLY_BRACE, RGB_TOG, RGB_MOD, RGB_RMOD, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, _______, KC_RIGHT_CURLY_BRACE,
      KC_LCTL, ADJUST, KC_LCTL, KC_LALT, LGUI_T(KC_ENT), LT(_RAISE, KC_SPC), LT(_LOWER, KC_SPC), KC_BSPC, KC_ENT, KC_RBRC, KC_PIPE, KC_EQL
    ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | lock |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |vol up|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F11 |  F12 |      |      |MS_W_L|MS_W_D|MS_W_U|MS_W_R|      |      |vol dn|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | prev |LANG1 |AGswa |AGtogg|      |      |      |      |      |      |      |next  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | play | next |      |vol dn|
     * `-----------------------------------------------------------------------------------'
     */

    [_ADJUST] = LAYOUT_ortho_4x12(
      SCN_LCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_AUDIO_VOL_UP,
      _______, KC_F11, KC_F12, KC_Q, _______, _______, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, KC_AUDIO_VOL_DOWN,
      KC_MEDIA_PREV_TRACK, KC_LANG1, AG_SWAP, AG_TOGG, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_NEXT_TRACK,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, KC_AUDIO_VOL_DOWN
    ),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, KC_S, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
