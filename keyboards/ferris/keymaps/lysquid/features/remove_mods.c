#include "../keymap.h"
#include "../features.h"


uint8_t saved_mods;

void save_incompatible_mods(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        return;
    }

    bool mod_layer_on =
        IS_LAYER_ON(SYM_SFT) ||
        IS_LAYER_ON(NAV_ALT) ||
        IS_LAYER_ON(NAV_GUI) ||
        IS_LAYER_ON(NAV_CTL);

    uint8_t removed_mods = 0;

    switch (keycode)
    {
    case KC_WBAK:
    case KC_WFWD:
    case KC_WREF:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CSAG;
        }
        break;
    case KF_WPRV:
    case KF_WNXT:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_AG;
        }
        break;
    case KF_CL_A:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CSG;
        }
        break;
    case WP_GO_1:
    case WP_GO_2:
    case WP_GO_3:
    case WP_GO_4:
    case WP_GO_P:
    case WP_GO_N:
    case ZM_IN_1:
    case ZM_OU_1:
    case ZM_RS_1:
    case ZM_IN_2:
    case ZM_OU_2:
    case ZM_RS_2:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CSA;
        }
        break;
    case WP_MV_1:
    case WP_MV_2:
    case WP_MV_3:
    case WP_MV_4:
    case WP_MV_P:
    case WP_MV_N:
        if (mod_layer_on) {
            removed_mods = MOD_MASK_CA;
        }
        break;
    case KC_DELETE:
        if (mod_layer_on && record->event.key.row < 3) {
            removed_mods = MOD_MASK_CAG;
        }
        break;
    case KF_RAQT:
    case KF_LAQT:
    case KF_EURO:
    #ifdef FRENCH
    case KF_RARW:
    case KF_LARW:
    case KF_MDOT:
    case KF_BDOT:
    case KF_SUP2:
    case KF_UNDS:
    #endif
        if (IS_LAYER_ON(SPC) || IS_LAYER_ON(SPC2)) {
            removed_mods = MOD_MASK_SHIFT;
        }
        break;
    }

    // Disable shift on symbol layer
    if ((get_mods() & MOD_MASK_SHIFT) == get_mods() && (
        get_highest_layer(layer_state) == SYM ||
        get_highest_layer(layer_state) == SYM_SFT
    )) {
        removed_mods = MOD_MASK_SHIFT;
    }

    saved_mods = get_mods() & removed_mods;
    del_mods(saved_mods);
}


void restore_incompatible_mods(void) {
    if (saved_mods) {
        add_mods(saved_mods);
        saved_mods = 0;
    }
}
