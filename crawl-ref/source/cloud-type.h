#pragma once

#include "tag-version.h"

enum struct cloud_type: uint8_t
{
    NONE,
    FIRE,
    MEPHITIC,
    COLD,
    POISON,
    BLACK_SMOKE,
    GREY_SMOKE,
    BLUE_SMOKE,
    PURPLE_SMOKE,
    TLOC_ENERGY,
    FOREST_FIRE,
    STEAM,
#if TAG_MAJOR_VERSION == 34
    GLOOM,
#endif
    INK,
    PETRIFY,
    HOLY,
    MIASMA,
    MIST,
    CHAOS,
    RAIN,
    MUTAGENIC,
    MAGIC_TRAIL,
    VORTEX,
    DUST,
    SPECTRAL,
    ACID,
    STORM,
    MISERY,
    FLUFFY,
    XOM_TRAIL,
    SALT,
    GOLD_DUST,
#if TAG_MAJOR_VERSION == 34
    EMBERS,
#endif
    FLAME,
    ALCOHOL,
    BLASTMOTES,
    ELECTRICITY,
    FAINT_MIASMA,
    MAGNETISED_DUST,
    NUM_CLOUD_TYPES,

    // Random per-square.
    RANDOM_SMOKE = 97,
    RANDOM,
    DEBUGGING,
};

inline cloud_type operator+(cloud_type lhs, int rhs) {
    return static_cast<cloud_type>(static_cast<int>(lhs) + rhs);
};
