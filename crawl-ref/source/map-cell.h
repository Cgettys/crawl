#pragma once

#include <libutil.h>

#include "enum.h"
#include "mon-info.h"
#include "tag-version.h"
#include "trap-type.h"

#define MAP_MAGIC_MAPPED_FLAG   0x01
#define MAP_SEEN_FLAG           0x02
#define MAP_CHANGED_FLAG        0x04 // FIXME: this doesn't belong here
#define MAP_DETECTED_MONSTER    0x08
#define MAP_INVISIBLE_MONSTER   0x10
#define MAP_DETECTED_ITEM       0x20
#define MAP_VISIBLE_FLAG        0x40
#define MAP_GRID_KNOWN          0xFF

#define MAP_EMPHASIZE          0x100
#define MAP_MORE_ITEMS         0x200
#define MAP_HALOED             0x400
#define MAP_SILENCED           0x800
#define MAP_BLOODY            0x1000
#define MAP_CORRODING         0x2000
#define MAP_INVISIBLE_UPDATE  0x4000 // Used for invis redraws by show_init()
#define MAP_ICY               0x8000

/* these flags require more space to serialize: put infrequently used ones there */
#define MAP_EXCLUDED_STAIRS  0x10000
#define MAP_SANCTUARY_1      0x80000
#define MAP_SANCTUARY_2     0x100000
#define MAP_WITHHELD        0x200000
#define MAP_LIQUEFIED       0x400000
#define MAP_ORB_HALOED      0x800000
#define MAP_UMBRAED        0x1000000
#define MAP_QUAD_HALOED    0X4000000
#define MAP_DISJUNCT       0X8000000
#define MAP_BLASPHEMY     0X10000000
#define MAP_BFB_CORPSE    0X20000000

struct cloud_info
{
    cloud_info() : type(cloud_type::NONE), colour(0), duration(3),
                   killer(KILL_NONE), tile(0)
    { }

    cloud_info(const cloud_type t, const colour_t c,
               const uint8_t dur, const unsigned short til,
               const killer_type kill)
        : type(t), colour(c), duration(dur), killer(kill), tile(til)
    { }

    bool defined() const {
        return type != cloud_type::NONE;
    }

    cloud_type type;
    colour_t colour;
    uint8_t duration; // decay/20, clamped to 0-3
    killer_type killer;
    // TODO: should this be tileidx_t?
    unsigned short tile;
};

/*
 * A map_cell stores what the player knows about a cell.
 * These go in env.map_knowledge.
 */
struct map_cell
{
    map_cell() : flags(0), _feat_colour(0), _feat(DNGN_UNSEEN),
                _trap(TRAP_UNASSIGNED), _item(nullptr), _mons(nullptr)
    {
    }

    ~map_cell() = default;

    // copy constructor
    map_cell(const map_cell& c):
    flags(c.flags), _feat_colour(c.feat_colour()), _feat(c._feat),
    _trap(c._trap)
    {
        if (c._mons)
            _mons = make_unique<monster_info>(*c._mons);
        if (c._item)
            _item = make_unique<item_def>(*c._item);
    }

    // copy assignment
    map_cell& operator=(const map_cell& c)
    {
        if (&c == this)
            return *this;

        flags = c.flags;
        _feat_colour = c.feat_colour();
        _feat= c._feat;
        _trap = c._trap;
        if (c._mons)
            _mons = make_unique<monster_info>(*c._mons);
        if (c._item)
            _item = make_unique<item_def>(*c._item);
        return *this;
    }

    // move constructor
    map_cell(map_cell&& other) noexcept = default;

    // move assignment
    map_cell& operator=(map_cell&& other) noexcept = default;

    bool operator ==(const map_cell &other) const
    {
        // TODO: these are not very correct.
        return memcmp(this, &other, sizeof(map_cell)) == 0;
    }

    bool operator !=(const map_cell &other) const
    {
        return !operator==(other);
    }

    void clear()
    {
        *this = map_cell();
    }

    // Clear prior to show update. Need to retain at least "seen" flag.
    void clear_data()
    {
        const uint32_t f = flags & (MAP_SEEN_FLAG | MAP_CHANGED_FLAG
                                    | MAP_INVISIBLE_UPDATE);
        clear();
        flags = f;
    }

    dungeon_feature_type feat() const
    {
        // Ugh; MSVC makes the bit field signed even though that means it can't
        // actually hold all the enum values. That seems to be in contradiction
        // of the standard (§9.6 [class.bit] paragraph 4) but what can you do?
        return static_cast<dungeon_feature_type>(uint8_t(_feat));
    }

    colour_t feat_colour() const
    {
        return _feat_colour;
    }

    void set_feature(dungeon_feature_type nfeat, unsigned colour = 0,
                     trap_type tr = TRAP_UNASSIGNED)
    {
        _feat = nfeat;
        _feat_colour = colour;
        _trap = tr;
    }

    item_def* item() const
    {
        return _item.get();
    }

    bool detected_item() const
    {
        const bool ret = !!(flags & MAP_DETECTED_ITEM);
        // TODO: change to an ASSERT when the underlying crash goes away
        if (ret && !_item)
        {
            //clear_item();
            return false;
        }
        return ret;
    }

    void set_item(const item_def& ii, bool more_items)
    {
        clear_item();
        _item = make_unique<item_def>(ii);
        if (more_items)
            flags |= MAP_MORE_ITEMS;
    }

    void set_detected_item();

    void clear_item()
    {
        _item.reset();
        flags &= ~(MAP_DETECTED_ITEM | MAP_MORE_ITEMS);
    }

    monster_type monster() const
    {
        return _mons ? _mons->type : MONS_NO_MONSTER;
    }

    monster_info* monsterinfo() const
    {
        return _mons.get();
    }

    void set_monster(const monster_info& mi)
    {
        clear_monster();
        _mons = make_unique<monster_info>(mi);
    }

    bool detected_monster() const
    {
        return !!(flags & MAP_DETECTED_MONSTER);
    }

    bool invisible_monster() const
    {
        return !!(flags & MAP_INVISIBLE_MONSTER);
    }

    void set_detected_monster(monster_type mons)
    {
        clear_monster();
        _mons = make_unique<monster_info>(MONS_SENSED);
        _mons->base_type = mons;
        flags |= MAP_DETECTED_MONSTER;
    }

    void set_invisible_monster()
    {
        clear_monster();
        flags |= MAP_INVISIBLE_MONSTER;
    }

    void clear_monster()
    {
        _mons.reset();
        flags &= ~(MAP_DETECTED_MONSTER | MAP_INVISIBLE_MONSTER);
    }

    cloud_info& cloudinfo()
    {
            return _cloud;
    }

    const cloud_info cloudinfo() const
    {
        return _cloud;
    }

    void set_cloud(const cloud_info ci)
    {
        _cloud = ci;
    }

    void clear_cloud()
    {
        _cloud = {};
    }

    bool update_cloud_state();

    bool known() const
    {
        return !!(flags & MAP_GRID_KNOWN);
    }

    bool seen() const
    {
        return !!(flags & MAP_SEEN_FLAG);
    }

    bool visible() const
    {
        return !!(flags & MAP_VISIBLE_FLAG);
    }

    bool changed() const
    {
        return !!(flags & MAP_CHANGED_FLAG);
    }

    bool mapped() const
    {
        return !!(flags & MAP_MAGIC_MAPPED_FLAG);
    }

    trap_type trap() const
    {
        return _trap;
    }

public:
    uint32_t flags;   // Flags describing the mappedness of this square.
private:
    colour_t _feat_colour;
    dungeon_feature_type _feat;
    trap_type _trap;
    cloud_info _cloud;
    unique_ptr<item_def> _item;
    unique_ptr<monster_info> _mons;
};
