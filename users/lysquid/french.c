#include "french.h"
#include "action_util.h"
#include "caps_word.h"
#include "keymap_french.h"
#include "keycodes.h"
#include "modifiers.h"

void dead_key_accent(uint16_t keycode, accent_t accent, keyrecord_t *record) {
    if (record->event.pressed) {
        // Can't use weak mods because it doesn't delete the shift for the
        uint8_t mods = get_mods();
        switch (accent) {
        case circumflex:
            del_mods(MOD_MASK_SHIFT);
            break;
        case diaeresis:
            add_mods(MOD_MASK_SHIFT);
            break;
        }
        tap_code(FR_CIRC);
        set_mods(mods);
        if (is_caps_word_on()) {
            add_weak_mods(MOD_BIT_LSHIFT);
        }
        tap_code(keycode);
    }
}

bool is_uppercase_dk_accent(uint16_t keycode) {
    switch (keycode)
    {
    case FR_EACU:
    case FR_EGRV:
    case FR_CCED:
    case FR_AGRV:
    case FR_UGRV:
        return true;
    }
    return false;
}

static bool processing_uppercase_accent = false;
static uint8_t saved_shift_mod;

void process_uppercase_dk_accents(uint16_t keycode, keyrecord_t *record) {
    if (is_uppercase_dk_accent(keycode) && record->event.pressed &&
            (get_mods() & MOD_MASK_SHIFT || is_caps_word_on())) {
        saved_shift_mod = get_mods() & MOD_MASK_SHIFT;
        del_mods(saved_shift_mod);
        // I don't use tap_code for caps lock because it takes longer, due to Mac compatibility
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
        processing_uppercase_accent = true;
    }
}

void post_process_uppercase_dk_accents(uint16_t keycode, keyrecord_t *record) {
    if (processing_uppercase_accent) {
        add_mods(saved_shift_mod);
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
        processing_uppercase_accent = false;
    }
}

bool french_caps_word_fix(uint16_t keycode, keyrecord_t *record) {
    // Key overrides doesn't work with caps word
    // Setting a one shot mod works but is unreliable when typing fast
     if (is_caps_word_on() && keycode == FR_MINS) {
        uint8_t saved_shift_mod = get_mods() & MOD_MASK_SHIFT;
        del_mods(saved_shift_mod);
        if (record->event.pressed) {
            register_code(FR_UNDS);
        } else {
            unregister_code(FR_UNDS);
        }
        add_mods(saved_shift_mod);
        return true;
    }
    return false;
}

static bool next_key_diaeresis = false;

bool diaeresis_accent(uint16_t keycode, keyrecord_t *record, uint16_t diaeresis_keycode) {
    if (record->event.pressed) {
        if (keycode == diaeresis_keycode) {
            next_key_diaeresis = true;
        } else if (next_key_diaeresis && keycode != KC_RSFT) {
            next_key_diaeresis = false;
            bool lowercase = !(get_mods() & MOD_MASK_SHIFT);
            uint16_t replacement = diaeresis_conversion(keycode, lowercase);
            if (replacement) {
                register_unicodemap(replacement);
                return true;
            }
        }
    }
    return false;
}
