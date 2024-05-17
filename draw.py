# Stolen from Callum
# https://github.com/callum-oakley/keymap

KEY_W = 55
KEY_H = 45
KEY_RX = 6
KEY_RY = 6
INNER_PAD_W = 2
INNER_PAD_H = 2
OUTER_PAD_W = KEY_W / 2
OUTER_PAD_H = KEY_H / 2
LINE_SPACING = 18

STYLE = """
    svg {
        font-family: SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace;
        font-size: 14px;
        font-kerning: normal;
        text-rendering: optimizeLegibility;
        fill: #24292e;
    }

    rect {
        fill: #f6f8fa;
    }

    .held {
        fill: #fbb;
    }
"""


def held(key):
    return {"key": key, "class": "held"}


KEYMAP = [
    {
        "left": [
            ["Y", "SPEC", "O", "F", "K"],
            ["I", "A", "E", "U", "? ,"],
            ["J", "! .", "_ -", "H", "Z"],
        ],
        "right": [
            ["V", "P", "L", "C", "Q"],
            ["G", "T", "N", "S", "R"],
            ["B", "D", "M", "W", "X"],
        ],
        "thumbs": {"left": ["NAV", "space"], "right": ["shift", "SYM"],},
    },
    {
        "left": [
            ["%", "+", "[", "]", "#"],
            ["{", "(", ")", "}", "/"],
            ["~", "\\", "&lt;", "&gt;", "&amp;"],
        ],
        "right": [
            ["^", ":", "\"", "'", "$"],
            ["=", "ctrl", "shift", "super", "alt"],
            ["|", ";", "*", "`", "@"],
        ],
        "thumbs": {"left": ["NAV", "space"], "right": ["shift", held("SYM")],},
    },
    {
        "left": [
            ["prnt scrn", "esc", "redo", "undo", "vol+"],
            ["alt", "super", "shift", "ctrl", "vol-"],
            ["selct all", "cut", "copy", "paste", "play pause"],
        ],
        "right": [
            ["home", "bksp", "up", "del", "end"],
            ["tab", "left", "down", "right", "enter"],
            ["half scrol", "page down", "page up", "menu", "MOUS"],
        ],
        "thumbs": {"left": [held("NAV"), "space"], "right": ["shift", "SYM"],},
    },
    {
        "left": [
            ["F6", "F7", "F8", "F9", "F10"],
            ["alt", "super", "shift", "ctrl", "space"],
            ["F1", "F2", "F3", "F4", "F5"],
        ],
        "right": [
            ["F12", "7", "8", "9", ","],
            ["tab", "4", "5", "6", "0"],
            ["F11", "1", "2", "3", "."],
        ],
        "thumbs": {
            "left": [held("NAV"), "space"],
            "right": ["shift", held("SYM")],
        },
    },
    {
        "left": [
            ["", "right onesht", "middle onesht", "left onesht", "erglce"],
            ["mouse back", "right click", "middle click", "left click", "mouse fwd"],
            ["alt", "super", "shift", "ctrl", "reboot"],
        ],
        "right": [
            ["azerty", "wheel left", "mouse up", "wheel right", ""],
            ["", "mouse left", "mouse down", "mouse right", ""],
            ["boot", "wheel down", "wheel up", "", held("MOUS")],
        ],
        "thumbs": {
            "left": ["NAV", "slow mouse"],
            "right": ["shift", "SYM"],
        },
    },
    {
        "left": [
            ["œ", held("SPEC"), "ô", "è", "ù"],
            ["î", "æ", "ê", "é", "û"],
            ["²", "•", "¿", "←", "→"],
        ],
        "right": [
            ["«", "»", "·", "ç", "°"],
            ["€", "à", "â", "_", "caps word"],
            ["“", "”", "µ", "≠", "×"],
        ],
        "thumbs": {"left": ["NAV", "'"], "right": ["shift", "SYM"],},
    },
]

KEYSPACE_W = KEY_W + 2 * INNER_PAD_W
KEYSPACE_H = KEY_H + 2 * INNER_PAD_H
HAND_W = 5 * KEYSPACE_W
HAND_H = 4 * KEYSPACE_H
LAYER_W = 2 * HAND_W + OUTER_PAD_W
LAYER_H = HAND_H
BOARD_W = LAYER_W + 2 * OUTER_PAD_W
BOARD_H = 6 * LAYER_H + 7 * OUTER_PAD_H


def print_key(x, y, key):
    key_class = ""
    if type(key) is dict:
        key_class = key["class"]
        key = key["key"]
    print(
        f'<rect rx="{KEY_RX}" ry="{KEY_RY}" x="{x + INNER_PAD_W}" y="{y + INNER_PAD_H}" width="{KEY_W}" height="{KEY_H}" class="{key_class}" />'
    )
    words = key.split()
    y += (KEYSPACE_H - (len(words) - 1) * LINE_SPACING) / 2
    for word in key.split():
        print(
            f'<text text-anchor="middle" dominant-baseline="middle" x="{x + KEYSPACE_W / 2}" y="{y}">{word}</text>'
        )
        y += LINE_SPACING


def print_row(x, y, row):
    for key in row:
        print_key(x, y, key)
        x += KEYSPACE_W


def print_block(x, y, block):
    for row in block:
        print_row(x, y, row)
        y += KEYSPACE_H


def print_layer(x, y, layer):
    print_block(x, y, layer["left"])
    print_block(
        x + HAND_W + OUTER_PAD_W, y, layer["right"],
    )
    print_row(
        x + 3 * KEYSPACE_W, y + 3 * KEYSPACE_H, layer["thumbs"]["left"],
    )
    print_row(
        x + HAND_W + OUTER_PAD_W, y + 3 * KEYSPACE_H, layer["thumbs"]["right"],
    )


def print_board(x, y, keymap):
    x += OUTER_PAD_W
    for layer in keymap:
        y += OUTER_PAD_H
        print_layer(x, y, layer)
        y += LAYER_H


print(
    f'<svg width="{BOARD_W}" height="{BOARD_H}" viewBox="0 0 {BOARD_W} {BOARD_H}" xmlns="http://www.w3.org/2000/svg">'
)
print(f"<style>{STYLE}</style>")
print_board(0, 0, KEYMAP)
print("</svg>")
