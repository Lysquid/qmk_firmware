#pragma once

#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "unicodes.h"


#ifdef FRENCH

// Letters
#define KF_A    FR_A    // A
#define KF_Z    FR_Z    // Z
#define KF_E    FR_E    // E
#define KF_R    FR_R    // R
#define KF_T    FR_T    // T
#define KF_Y    FR_Y    // Y
#define KF_U    FR_U    // U
#define KF_I    FR_I    // I
#define KF_O    FR_O    // O
#define KF_P    FR_P    // P
#define KF_Q    FR_Q    // Q
#define KF_S    FR_S    // S
#define KF_D    FR_D    // D
#define KF_F    FR_F    // F
#define KF_G    FR_G    // G
#define KF_H    FR_H    // H
#define KF_J    FR_J    // J
#define KF_K    FR_K    // K
#define KF_L    FR_L    // L
#define KF_M    FR_M    // M
#define KF_W    FR_W    // W
#define KF_X    FR_X    // X
#define KF_C    FR_C    // C
#define KF_V    FR_V    // V
#define KF_B    FR_B    // B
#define KF_N    FR_N    // N

// Numbers
#define KF_1    FR_1    // 1
#define KF_2    FR_2    // 2
#define KF_3    FR_3    // 3
#define KF_4    FR_4    // 4
#define KF_5    FR_5    // 5
#define KF_6    FR_6    // 6
#define KF_7    FR_7    // 7
#define KF_8    FR_8    // 8
#define KF_9    FR_9    // 9
#define KF_0    FR_0    // 0

// Symbols
#define KF_DOT  FR_DOT  // .
#define KF_COMM FR_COMM // ,
#define KF_SCLN FR_SCLN // ;
#define KF_COLN FR_COLN // :
#define KF_EXLM FR_EXLM // !
#define KF_QUES FR_QUES // ?
#define KF_PERC FR_PERC // %
#define KF_PLUS FR_PLUS // +
#define KF_HASH FR_HASH // #
#define KF_CIRC ALGR(FR_CCED) // ^
#define KF_COLN FR_COLN // :
#define KF_DQUO FR_DQUO // "
#define KF_QUOT FR_QUOT // '
#define KF_GRV  FR_GRV  // `
#define KF_ASTR FR_ASTR // *
#define KF_DLR  FR_DLR  // $
#define KF_LBRC FR_LBRC // [
#define KF_RBRC FR_RBRC // ]
#define KF_LCBR FR_LCBR // {
#define KF_RCBR FR_RCBR // }
#define KF_LPRN FR_LPRN // (
#define KF_RPRN FR_RPRN // )
#define KF_SLSH FR_SLSH // /
#define KF_EQL  FR_EQL  // =
#define KF_MINS FR_MINS // -
#define KF_UNDS FR_UNDS // _
#define KF_TILD FR_TILD // ~
#define KF_LABK FR_LABK // <
#define KF_RABK FR_RABK // >
#define KF_PIPE FR_PIPE // |
#define KF_AMPR FR_AMPR // &
#define KF_SCLN FR_SCLN // ;
#define KF_AT   FR_AT   // @
#define KF_BSLS FR_BSLS // (backslash)

// Dead keys
#define KF_DIAE FR_DIAE // ¨
#define KF_DCRC FR_CIRC // ^

// Specials
#define KF_AGRV FR_AGRV         // à
#define KF_EACU FR_EACU         // é
#define KF_EGRV FR_EGRV         // è
#define KF_UGRV FR_UGRV         // ù
#define KF_AE   ALGR(FR_A)      // æ
#define KF_OE   UP(OE1,OE2)     // œ
#define KF_CCED FR_CCED         // ç
#define KF_NTLD UP(NT1,NT2)     // ñ
#define KF_MICR FR_MICR         // µ
#define KF_EURO FR_EURO         // €
#define KF_IQES SAGR(FR_RPRN)   // ¿
#define KF_LAQT ALGR(FR_Z)      // «
#define KF_RAQT ALGR(FR_X)      // »
#define KF_LDQT ALGR(FR_B)      // “
#define KF_RDQT ALGR(FR_N)      // ”
#define KF_CPRT SAGR(FR_C)      // ©
#define KF_TM   SAGR(FR_8)      // ™
#define KF_SUP2 FR_SUP2         // ²
#define KF_BDOT ALGR(FR_SCLN)   // •
#define KF_MDOT ALGR(FR_COLN)   // ·
#define KF_LARW ALGR(FR_Y)      // ←
#define KF_RARW ALGR(FR_I)      // →
#define KF_DEG  FR_DEG          // °
#define KF_CROS SAGR(FR_SCLN)   // ×
#define KF_DIFF UM(DIFF)        // ≠
#define KF_PSMS SAGR(FR_9)      // ±

#else

#define KF_A    KC_A    // A
#define KF_Z    KC_Z    // Z
#define KF_E    KC_E    // E
#define KF_R    KC_R    // R
#define KF_T    KC_T    // T
#define KF_Y    KC_Y    // Y
#define KF_U    KC_U    // U
#define KF_I    KC_I    // I
#define KF_O    KC_O    // O
#define KF_P    KC_P    // P
#define KF_Q    KC_Q    // Q
#define KF_S    KC_S    // S
#define KF_D    KC_D    // D
#define KF_F    KC_F    // F
#define KF_G    KC_G    // G
#define KF_H    KC_H    // H
#define KF_J    KC_J    // J
#define KF_K    KC_K    // K
#define KF_L    KC_L    // L
#define KF_M    KC_M    // M
#define KF_W    KC_W    // W
#define KF_X    KC_X    // X
#define KF_C    KC_C    // C
#define KF_V    KC_V    // V
#define KF_B    KC_B    // B
#define KF_N    KC_N    // N

// Numbers
#define KF_1    KC_1    // 1
#define KF_2    KC_2    // 2
#define KF_3    KC_3    // 3
#define KF_4    KC_4    // 4
#define KF_5    KC_5    // 5
#define KF_6    KC_6    // 6
#define KF_7    KC_7    // 7
#define KF_8    KC_8    // 8
#define KF_9    KC_9    // 9
#define KF_0    KC_0    // 0

// Symbols
#define KF_DOT  KC_DOT  // .
#define KF_COMM KC_COMM // ,
#define KF_SCLN KC_SCLN // ;
#define KF_COLN KC_COLN // :
#define KF_EXLM KC_EXLM // !
#define KF_QUES KC_QUES // ?
#define KF_PERC KC_PERC // %
#define KF_PLUS KC_PLUS // +
#define KF_HASH KC_HASH // #
#define KF_CIRC KC_CIRC // ^
#define KF_COLN KC_COLN // :
#define KF_DQUO KC_DQUO // "
#define KF_QUOT KC_QUOT // '
#define KF_GRV  KC_GRV  // `
#define KF_ASTR KC_ASTR // *
#define KF_DLR  KC_DLR  // $
#define KF_LBRC KC_LBRC // [
#define KF_RBRC KC_RBRC // ]
#define KF_LCBR KC_LCBR // {
#define KF_RCBR KC_RCBR // }
#define KF_LPRN KC_LPRN // (
#define KF_RPRN KC_RPRN // )
#define KF_SLSH KC_SLSH // /
#define KF_EQL  KC_EQL  // =
#define KF_MINS KC_MINS // -
#define KF_UNDS KC_UNDS // _
#define KF_TILD KC_TILD // ~
#define KF_LABK KC_LABK // <
#define KF_RABK KC_RABK // >
#define KF_PIPE KC_PIPE // |
#define KF_AMPR KC_AMPR // &
#define KF_SCLN KC_SCLN // ;
#define KF_AT   KC_AT   // @
#define KF_BSLS KC_BSLS // (backslash)

// Dead keys
#define KF_DIAE ALGR(KC_QUOT)   // ¨
#define KF_DCRC ALGR(KC_6)      // ^

// Specials
#define KF_AGRV ALGR(KC_A)      // à
#define KF_ACRC ALGR(KC_Z)      // â
#define KF_EACU ALGR(KC_E)      // é
#define KF_EGRV ALGR(KC_R)      // è
#define KF_ECRC ALGR(KC_D)      // ê
#define KF_EDIA ALGR(KC_F)      // ë
#define KF_ICRC ALGR(KC_K)      // î
#define KF_IDIA ALGR(KC_I)      // ï
#define KF_OCRC ALGR(KC_O)      // ô
#define KF_UGRV ALGR(KC_U)      // ù
#define KF_UCRC ALGR(KC_J)      // û
#define KF_UDIA ALGR(KC_H)      // ü
#define KF_AE   ALGR(KC_S)      // æ
#define KF_OE   ALGR(KC_P)      // œ
#define KF_CCED ALGR(KC_C)      // ç
#define KF_NTLD UP(NT1,NT2)     // ñ
#define KF_MICR UM(MU)          // µ
#define KF_EURO ALGR(KC_5)      // €
#define KF_IQES UM(IQEST)       // ¿
#define KF_LAQT ALGR(KC_LBRC)   // «
#define KF_RAQT ALGR(KC_RBRC)   // »
#define KF_LDQT SAGR(KC_LBRC)   // “
#define KF_RDQT SAGR(KC_RBRC)   // ”
#define KF_CPRT UM(CPYRT)       // ©
#define KF_TM   UM(TM)          // ™
#define KF_SUP2 UM(SQUAR)       // ²
#define KF_BDOT UM(BDOT)        // •
#define KF_MDOT UM(MDOT)        // ·
#define KF_LARW UM(LAROW)       // ←
#define KF_RARW UM(RAROW)       // →
#define KF_DEG  SAGR(KC_QUOT)   // °
#define KF_CROS UM(CROSS)       // ×
#define KF_DIFF UM(DIFF)        // ≠
#define KF_PSMS UM(PSMS)        // ±

#endif
