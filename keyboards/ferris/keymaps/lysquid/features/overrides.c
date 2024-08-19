#include "../keymap.h"
#include "../features.h"


#define DEF_MASK (1 << DEF | 1 << DEF2)
#define NAV_MASK (1 << NAV)
#define SYM_MASK (1 << SYM)
#define NUM_MASK (1 << NUM)


#define ko_make_no_suppressed_mods_with_options(trigger_mods_, trigger_key, replacement_key, options_) \
    ((const key_override_t){                                                                \
        .trigger_mods                           = (trigger_mods_),                          \
        .layers                                 = ~0,                                       \
        .suppressed_mods                        = 0,                                        \
        .options                                = (options_),                               \
        .negative_mod_mask                      = 0,                                        \
        .custom_action                          = NULL,                                     \
        .context                                = NULL,                                     \
        .trigger                                = (trigger_key),                            \
        .replacement                            = (replacement_key),                        \
        .enabled                                = NULL                                      \
    })


// Layout symbols
const key_override_t comma_override = ko_make_with_layers(MOD_MASK_SHIFT, KF_COMM, KF_QUES, DEF_MASK);
const key_override_t dot_override   = ko_make_with_layers(MOD_MASK_SHIFT, KF_DOT,  KF_EXLM, DEF_MASK);
const key_override_t minus_override = ko_make_with_layers(MOD_MASK_SHIFT, KF_MINS, KF_UNDS, DEF_MASK);

// NAV combinations
const key_override_t power_override = ko_make_with_layers(MOD_MASK_CTRL,  KF_PSTE, KC_PWR,  NAV_MASK);
const key_override_t sleep_override = ko_make_with_layers(MOD_MASK_CTRL,  KF_UNDO, KC_SLEP,  NAV_MASK);

#ifdef FRENCH
// Keypad variant to fix some shortcuts
const key_override_t slash_override = ko_make_with_layers(MOD_MASK_SHIFT, FR_SLSH, KC_PSLS, SYM_MASK);

// Azerty window manager compatibility
const key_override_t override_1 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_1, FR_AMPR, ko_option_one_mod);
const key_override_t override_2 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_2, FR_EACU, ko_option_one_mod);
const key_override_t override_3 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_3, FR_DQUO, ko_option_one_mod);
const key_override_t override_4 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_4, FR_QUOT, ko_option_one_mod);
const key_override_t override_5 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_5, FR_LPRN, ko_option_one_mod);
const key_override_t override_6 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_6, FR_MINS, ko_option_one_mod);
const key_override_t override_7 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_7, FR_EGRV, ko_option_one_mod);
const key_override_t override_8 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_8, FR_UNDS, ko_option_one_mod);
const key_override_t override_9 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_9, FR_CCED, ko_option_one_mod);
const key_override_t override_0 = ko_make_no_suppressed_mods_with_options(MOD_MASK_CAG, FR_0, FR_AGRV, ko_option_one_mod);
#endif


const key_override_t **key_overrides = (const key_override_t *[]) {
    &comma_override,
    &dot_override,
    &minus_override,
    &power_override,
    &sleep_override,
    #ifdef FRENCH
    &slash_override,
    &override_1,
    &override_2,
    &override_3,
    &override_4,
    &override_5,
    &override_6,
    &override_7,
    &override_8,
    &override_9,
    &override_0,
    #endif
    NULL
};


bool overrides_with_unicode(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KF_QUOT && get_mods() & MOD_MASK_SHIFT && (IS_LAYER_ON(SPC) || IS_LAYER_ON(SPC2))) {
        if (record->event.pressed) {
            register_unicodemap(NNBSP);
        }
        return true;
    }
    return false;
}
