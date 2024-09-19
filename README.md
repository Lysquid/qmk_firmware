A QMK keymap for the [Sweep][sweep], a split keyboard with 34 keys. It makes extensive use of layers to fit all keys, and uses callum-style mods.

[sweep]: https://github.com/davidphilipbarr/Sweep

## Features

- Custom layout optimized for French and English, [Erglace][erglace] (can be dynamically switched with AZERTY)
- A layer for all symbols
- A layer for navigation keys, like the arrow keys
- A [tri layer][tri layer] for numbers and function keys
- One shot modifiers, taken from the awesome [Callum's keymap][callum]
- One shot layer for French accents and useful Unicode characters, inspired by [QWERTY Lafayette][lafayette]
- Swapper keys to emulate Alt+Tab like behaviors with one key, once again from [Callum's keymap][callum]
- A layer to emulate a mouse
- [Key overrides][key overrides] with modifiers to fit media keys and useful shortcuts
- Compilation for QWERTY or AZERTY depending on a config flag (by default, the computer should be set to French input)

[erglace]: https://github.com/Lysquid/Erglace
[tri layer]: https://docs.qmk.fm/features/tri_layer
[callum]: https://github.com/qmk/qmk_firmware/tree/user-keymaps-still-present/users/callum
[lafayette]: https://qwerty-lafayette.org/
[key overrides]: https://docs.qmk.fm/features/key_overrides

## Layers

![keymap][keymap]

[Full version][keymap-full], with mouse layer and key overrides.

[keymap]: keymap.svg
[keymap-full]: https://raw.githubusercontent.com/Lysquid/qmk_keymap/lysquid/keymap_full.svg

## Special behaviors

### Modifiers

- The one shot modifiers are on the `NAV` and `SYM` layers. When a mod is tapped, it is queued and will be applied to the next key (for exemple a letter on the base layer).
- Pressing `NAV` or `SYM` again cancels any queued modifier.
- To do the same shortcut multiple times, the modifier can be held. It stays active even if the layer changes.
- `caps word` is a [QMK feature][caps word] that enables caps lock for one word only, useful to write constants.
- Accented letters from the one shot layer can be made uppercase with `shift`.
- An override is defined to be able to do a quick press of the `super` key, achieved with `super`+`ctrl` on the `NAV` layer

[caps word]: https://docs.qmk.fm/#/feature_caps_word

### Navigation lock

- Because it is used very often, the `NAV` layer can be locked by pressing `shift` with the thumb when on the layer.
- Alternatively, `shift` and then `NAV` does the same (if shift was not used to make a letter uppercase).
- Any layer key unlocks the layer, except for `SYM` if a modifier is active, to be able to navigate with `super`+`<number>` on a window manager.
- Holding `shift` or pressing `caps word` also disables the layer.

### Key tri layers

- This feature is a mix between key overrides and tri layers: activating a layer AND pressing a key activates another layer. This is useful to put many shortcuts on the left split, to be used with the mouse.
- `NAV`+`alt` activates a media keys layer
- `NAV`+`super` activates a browser navigation layer
- `NAV`+`ctrl` activates a shortcuts layer
- `SYM`+`shift` activates a zoom layer

### Mouse layer

- `slow mouse` button make the cursor speed slower for more precision.
- `onesht` buttons stand for 'one shot click'. The mouse layer is disabled after the button is clicked, unlike the other buttons.
- A tap on `NAV`, `SYM` or `shift` exits the mouse layer.
- `erglce` stands for [Erglace][erglace], my custom layout. It can be switched with AZERTY (including the one shot special characters layer, see the [keymap definition][keymap.c]).

[keymap.c]: keyboards/ferris/keymaps/lysquid/keymap.c

## Installation

- Install the [QMK CLI][qmk cli] (available on Arch repos as `qmk`)
- Download the latest [release][releases]
- Run `qmk flash ferris_sweep_lysquid.hex`
- Put your keyboard in bootloader mode (with a `boot` key or a reset button)
- If you are flashing your keyboard for the first time, you must flash the two sides separately with the flags `-bl avrdude-split-left` and `-bl avrdude-split-right`

[qmk cli]: https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment
[releases]: /releases
