#pragma once

#include QMK_KEYBOARD_H
#include "../../../../users/lysquid/azerty_keycodes.h"
#include "../../../../users/lysquid/custom_keycodes.h"


enum layers {
    DEF,
    DEF2,
    SYM,
    SYM_SFT,
    NAV,
    NAV_ALT,
    NAV_CTL,
    NAV_GUI,
    NUM,
    SPC,
    SPC2,
    MOS,
};

enum keycodes {
    OS_LSFT = SAFE_RANGE,
    OS_RSFT,
    OS_LCTL,
    OS_RCTL,
    OS_LALT,
    OS_RALT,
    OS_LGUI,
    OS_RGUI,
    OS_BTN1,
    OS_BTN2,
    OS_BTN3,
    SW_ESC,
    SW_TAB,
    SW_GRV,
    KC_HSCL,
    #ifdef FRENCH
    KF_ACRC,
    KF_ECRC,
    KF_OCRC,
    KF_ICRC,
    KF_UCRC,
    KF_EDIA,
    KF_IDIA,
    KF_UDIA,
    #endif
};
