#include "french.h"
#include "keymap_french.h"
#include <modifiers.h>
#include "keycodes.h"

void dead_key_accent(uint16_t keycode, accent_t accent, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t mods = get_mods();
        switch (accent) {
        case circonflexe:
            del_mods(MOD_MASK_SHIFT);
            break;
        case trema:
            add_mods(MOD_MASK_SHIFT);
            break;
        }
        tap_code(FR_CIRC);
        set_mods(mods);
        tap_code(keycode);
    }
}

bool uppercase_accent(uint16_t keycode, keyrecord_t *record) {
    if ((get_mods() & MOD_MASK_SHIFT) && record->event.pressed) {
        uint8_t mods;
        switch (keycode)
        {
        case FR_EACU:
        case FR_EGRV:
        case FR_CCED:
        case FR_AGRV:
        case FR_UGRV:
            mods = get_mods();
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_CAPS);
            unregister_code(KC_CAPS);
            tap_code(keycode);
            set_mods(mods);
            register_code(KC_CAPS);
            unregister_code(KC_CAPS);
            return true;
        }
    }
    return false;
}