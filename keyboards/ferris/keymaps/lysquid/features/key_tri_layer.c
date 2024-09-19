#include "../keymap.h"
#include "../features.h"


void update_key_tri_layer(
    uint8_t layer,
    uint16_t key,
    uint8_t tri_layer,
    bool* key_down,
    uint16_t keycode,
    keyrecord_t *record,
    uint8_t mod_blacklist
) {
    if (keycode == key) {
        *key_down = record->event.pressed;
    }
    if (IS_LAYER_ON(layer) && *key_down && !(get_mods() & mod_blacklist)) {
        if (IS_LAYER_OFF(tri_layer)) {
            layer_on(tri_layer);
        }
    } else {
        if (IS_LAYER_ON(tri_layer)) {
            layer_off(tri_layer);
        }
    }
}


bool sym_sft_key_down = false;
bool nav_alt_key_down = false;
bool nav_gui_key_down = false;
bool nav_ctl_key_down = false;

void update_key_tri_layers(uint16_t keycode, keyrecord_t *record) {
    update_key_tri_layer(SYM, OS_RSFT, SYM_SFT,
        &sym_sft_key_down, keycode, record, MOD_MASK_CAG
    );
    update_key_tri_layer(NAV, OS_LALT, NAV_ALT,
        &nav_alt_key_down, keycode, record, 0
    );
    update_key_tri_layer(NAV, OS_LGUI, NAV_GUI,
        &nav_gui_key_down, keycode, record, 0
    );
    update_key_tri_layer(NAV, OS_LCTL, NAV_CTL,
        &nav_ctl_key_down, keycode, record, 0
    );
}
