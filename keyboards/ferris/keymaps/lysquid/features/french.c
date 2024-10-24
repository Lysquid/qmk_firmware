#include "../keymap.h"
#include "../features.h"


void dead_key_accents(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KF_ACRC: dead_key_accent(FR_A, CIRCUMFLEX, record); break;
    case KF_ECRC: dead_key_accent(FR_E, CIRCUMFLEX, record); break;
    case KF_ICRC: dead_key_accent(FR_I, CIRCUMFLEX, record); break;
    case KF_OCRC: dead_key_accent(FR_O, CIRCUMFLEX, record); break;
    case KF_UCRC: dead_key_accent(FR_U, CIRCUMFLEX, record); break;
    case KF_EDIA: dead_key_accent(FR_E, DIAERESIS, record); break;
    case KF_IDIA: dead_key_accent(FR_I, DIAERESIS, record); break;
    case KF_UDIA: dead_key_accent(FR_U, DIAERESIS, record); break;
    }
}
