#pragma once

// This order is *critical*. Don't mess with it (see mon_enchant)
enum kill_category: uint8_t
{
    KC_YOU,
    KC_FRIENDLY,
    KC_OTHER,
    KC_NCATEGORIES
};
