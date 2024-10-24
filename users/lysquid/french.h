#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    CIRCUMFLEX,
    DIAERESIS,
} accent_t;

void dead_key_accent(uint16_t keycode, accent_t accent, keyrecord_t *record);

bool is_uppercase_dk_accent(uint16_t keycode);

// Uppercase accented letters: use caps lock instead of shift (Linux only).
// It saves shift mods to be restored in the post process, so it's better
// near to the end of the process function
void process_uppercase_dk_accents(uint16_t keycode, keyrecord_t *record);

void post_process_uppercase_dk_accents(uint16_t keycode, keyrecord_t *record);

bool french_caps_word_fix(uint16_t keycode, keyrecord_t *record);

bool diaeresis_accent(uint16_t keycode, keyrecord_t *record, uint16_t diaeresis_keycode);
