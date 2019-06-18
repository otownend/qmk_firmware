#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

/* CTRL+ALT */
#define AC(X) A(C(X))
/* CTRL+SHIFT */
#define SC(X) S(C(X))
/* WIN+SHIFT */
#define SG(X) S(G(X))

enum planck_layers {
    _QWERTY,
    _SYMB,
    _MOVE,
    _FUNC,
    _MOUSE,
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    SYMB,
    MOVE,
    FUNC,
    MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------------------------------------.
     * |Tab  |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bksp |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |Move |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |Shift|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Shift|
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |Ctrl |Super|Func | Alt |Symb |Enter|Space|Move | Alt |Super|Func |Ctrl |
     * `-----------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB,       KC_Q,         KC_W,         KC_E,
        KC_R,         KC_T,         KC_Y,         KC_U,
        KC_I,         KC_O,         KC_P,         KC_BSPC,

        MOVE,         KC_A,         KC_S,         KC_D,
        KC_F,         KC_G,         KC_H,         KC_J,
        KC_K,         KC_L,         KC_SCLN,      KC_QUOT,

        KC_LSFT,      KC_Z,         KC_X,         KC_C,
        KC_V,         KC_B,         KC_N,         KC_M,
        KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,

        KC_LCTL,      KC_LGUI,      FUNC,         KC_LALT,
        SYMB,         KC_ENT,       KC_SPC,       MOVE,
        KC_RALT,      KC_RGUI,      FUNC,         KC_RCTL
    ),

    /* SYMB
     * ,-----------------------------------------------------------------------.
     * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * | Del |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |  ~  |  `  |  +  |  =  |  |  |  \  |  [  |  ]  |  {  |  }  |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |     |     |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    [_SYMB] = LAYOUT_planck_grid(
        KC_ESC,       KC_1,         KC_2,         KC_3,
        KC_4,         KC_5,         KC_6,         KC_7,
        KC_8,         KC_9,         KC_0,         KC_MINS,

        KC_DEL,       KC_EXLM,      KC_AT,        KC_HASH,
        KC_DLR,       KC_PERC,      KC_CIRC,      KC_AMPR,
        KC_ASTR,      KC_LPRN,      KC_RPRN,      _______,

        _______,      KC_TILD,      KC_GRV,       KC_PLUS,
        KC_EQL,       KC_PIPE,      KC_BSLS,      KC_LBRC,
        KC_RBRC,      KC_LCBR,      KC_RCBR,      _______,

        _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______
    ),

    /* MOVE
     * ,-----------------------------------------------------------------------.
     * |Mouse|CtrUp|PgUp | Up  |PgDn |Caps |CtrUp|PgUp | Up  |PgDn |Caps |Mouse|
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |CtrL |Left |Down |Right|CtrR |CtrL |Left |Down |Right|CtrR |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |CtrDn|Home | End |TabL |TabR |CtrDn|Home | End |TabL |TabR |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |     |     |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    [_MOVE] = LAYOUT_planck_grid(
        MOUSE,        C(KC_UP),     KC_PGUP,      KC_UP,
        KC_PGDN,      KC_CAPS,      C(KC_UP),     KC_PGUP,
        KC_UP,        KC_PGDN,      KC_CAPS,      MOUSE,

        _______,      C(KC_LEFT),   KC_LEFT,      KC_DOWN,
        KC_RGHT,      C(KC_RIGHT),  C(KC_LEFT),   KC_LEFT,
        KC_DOWN,      KC_RGHT,      C(KC_RIGHT),  XXXXXXX,

        _______,      C(KC_DOWN),   KC_HOME,      KC_END,
        SC(KC_TAB),   C(KC_TAB),    C(KC_DOWN),   KC_HOME,
        KC_END,       SC(KC_TAB),   C(KC_TAB),    _______,

        _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______,
        _______,      _______,      _______,      _______
    ),

    /* FUNC
     * ,-----------------------------------------------------------------------.
     * |Reset| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 |VolUp|
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 |VolDn|
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     |     |     |     |     |     |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |Prev |Mute |Play |Next |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    [_FUNC] = LAYOUT_planck_grid(
        RESET,        KC_F1,        KC_F2,        KC_F3,
        KC_F4,        KC_F5,        KC_F6,        KC_F7,
        KC_F8,        KC_F9,        KC_F10,       KC_VOLU,

        _______,      KC_F11,       KC_F12,       KC_F13,
        KC_F14,       KC_F15,       KC_F16,       KC_F17,
        KC_F18,       KC_F19,       KC_F20,       KC_VOLD,

        _______,      XXXXXXX,      KC_HOME,      SC(KC_TAB),
        C(KC_TAB),    KC_END,       XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,       _______,

        _______,      _______,      _______,      _______,
        KC_MPRV,      KC_MUTE,      KC_MPLY,      KC_MNXT,
        _______,      _______,      _______,      _______
    ),

    /* MOUSE
     * ,-----------------------------------------------------------------------.
     * |     |     | ScU |Up   | ScD | B5  | Ac0 | ScU |Up   | ScD |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |Left |Down |Right| B4  | Ac1 |Left |Down |Right|     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     | ScL |     | ScR | B3  | Ac2 | ScL |     | ScR |     |     |
     * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
     * |     |     |     |     |     | B2  | B1  |     |     |     |     |     |
     * `-----------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_planck_grid(
        _______,      XXXXXXX,      KC_WH_U,      KC_MS_U,
        KC_WH_D,      KC_BTN5,      KC_ACL0,      KC_WH_U,
        KC_MS_U,      KC_WH_D,      XXXXXXX,      XXXXXXX,

        _______,      XXXXXXX,      KC_MS_L,      KC_MS_D,
        KC_MS_R,      KC_BTN4,      KC_ACL1,      KC_MS_L,
        KC_MS_D,      KC_MS_R,      XXXXXXX,      XXXXXXX,

        _______,      XXXXXXX,      KC_WH_L,      XXXXXXX,
        KC_WH_R,      KC_BTN3,      KC_ACL2,      KC_WH_L,
        XXXXXXX,      KC_WH_R,      XXXXXXX,      _______,

        _______,      _______,      _______,      _______,
        _______,      KC_BTN2,      KC_BTN1,      _______,
        _______,      _______,      _______,      _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYMB:
            if (record->event.pressed) {
                layer_off(_MOUSE);
                layer_on(_SYMB);
            } else {
                layer_off(_SYMB);
            }
            return false;
        case MOVE:
            if (record->event.pressed) {
                layer_off(_MOUSE);
                layer_on(_MOVE);
            } else {
                layer_off(_MOVE);
            }
            return false;
        case FUNC:
            if (record->event.pressed) {
                layer_off(_MOUSE);
                layer_on(_FUNC);
            } else {
                layer_off(_FUNC);
            }
            return false;
        case MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            }
            return false;

        // Override the defualt auto shifted symbols to use SEND_STRING
        // See https://github.com/qmk/qmk_firmware/issues/4072
        case KC_EXLM:
            if (record->event.pressed) { SEND_STRING("!"); }
            return false;
        case KC_AT:
            if (record->event.pressed) { SEND_STRING("@"); }
            return false;
        case KC_HASH:
            if (record->event.pressed) { SEND_STRING("#"); }
            return false;
        case KC_DLR:
            if (record->event.pressed) { SEND_STRING("$"); }
            return false;
        case KC_PERC:
            if (record->event.pressed) { SEND_STRING("%"); }
            return false;
        case KC_CIRC:
            if (record->event.pressed) { SEND_STRING("^"); }
            return false;
        case KC_AMPR:
            if (record->event.pressed) { SEND_STRING("&"); }
            return false;
        case KC_ASTR:
            if (record->event.pressed) { SEND_STRING("*"); }
            return false;
        case KC_LPRN:
            if (record->event.pressed) { SEND_STRING("("); }
            return false;
        case KC_RPRN:
            if (record->event.pressed) { SEND_STRING(")"); }
            return false;
        case KC_TILD:
            if (record->event.pressed) { SEND_STRING("~"); }
            return false;
        case KC_GRV:
            if (record->event.pressed) { SEND_STRING("`"); }
            return false;
        case KC_PLUS:
            if (record->event.pressed) { SEND_STRING("+"); }
            return false;
        case KC_EQL:
            if (record->event.pressed) { SEND_STRING("="); }
            return false;
        case KC_PIPE:
            if (record->event.pressed) { SEND_STRING("|"); }
            return false;
        case KC_BSLS:
            if (record->event.pressed) { SEND_STRING("\\"); }
            return false;
        case KC_LBRC:
            if (record->event.pressed) { SEND_STRING("["); }
            return false;
        case KC_RBRC:
            if (record->event.pressed) { SEND_STRING("]"); }
            return false;
        case KC_LCBR:
            if (record->event.pressed) { SEND_STRING("{"); }
            return false;
        case KC_RCBR:
            if (record->event.pressed) { SEND_STRING("}"); }
            return false;
    }
    return true;
}
