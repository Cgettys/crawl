#pragma once

// removing from or reordering this enum will break the save browser, not
// just save compat
enum game_type: uint8_t
{
    GAME_TYPE_UNSPECIFIED,
    GAME_TYPE_NORMAL,
    GAME_TYPE_TUTORIAL,
    GAME_TYPE_ARENA,
    GAME_TYPE_SPRINT,
    GAME_TYPE_HINTS,
    GAME_TYPE_ZOTDEF,
    GAME_TYPE_INSTRUCTIONS,
    GAME_TYPE_HIGH_SCORES,
    GAME_TYPE_CUSTOM_SEED,
    GAME_TYPE_DESCENT,
    NUM_GAME_TYPE
};
