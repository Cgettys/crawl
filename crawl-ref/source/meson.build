project('source', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++11'])

prog_python = find_program('python3')
# TODO: Eventually, no make will be left
prog_make = find_program('make')
# TODO: which of these can be optional?
#AR = ar
#RANLIB = ranlib
#CC = $(GCC)
#CXX = $(GXX)
#RM = rm -f
#COPY = cp
#COPY_R = cp -r
#STRIP = strip -s
#SED = sed
#WINDRES = windres
#CHMOD = chmod 2>/dev/null
#CHOWN = chown 2>/dev/null
#PNGCRUSH = $(COPY)
#PNGCRUSH_LABEL = COPY
#ADVPNG = advpng -z -2
#PKGCONFIG = pkg-config
#DOXYGEN = doxygen
#DOXYGEN_SIMPLE_CONF = crawl_simple.doxy
#DOXYGEN_ALL_CONF = crawl_all.doxy
#DOXYGEN_HTML_GEN = html/
## Prefer python3, if available
#PYTHON = python

#source = executable('source', 'main.cc', install : true)

#test('test', source)

# -------------------------------------------------
# BEGIN Makefile.obj Port
# -------------------------------------------------
MAIN_SRC = files('ability.cc', 'abyss.cc', 'acquire.cc',
    'act-iter.cc', 'actor-los.cc', 'actor.cc',
    'adjust.cc', 'areas.cc', 'arena.cc', 'artefact.cc', 'attack.cc',
    'attitude-change.cc','beam.cc', 'behold.cc', 'bitary.cc',
    'branch.cc', 'branch-data-json.cc', 'bloodspatter.cc',
    'chardump.cc', 'cio.cc', 'cloud.cc', 'clua.cc', 'cluautil.cc', 'colour.cc',
    'command.cc', 'coord.cc','coord-circle.cc','coordit.cc', 'corpse.cc',
    'crash.cc', 'ctest.cc', 'dactions.cc', 'database.cc',
    'dbg-asrt.cc', 'dbg-maps.cc', 'dbg-objstat.cc', 'dbg-scan.cc',
    'dbg-util.cc',
    'death-curse.cc', 'decks.cc', 'delay.cc',
    'describe.cc', 'describe-god.cc', 'describe-spells.cc',
    'dgl-message.cc',
    'dgn-delve.cc', 'dgn-height.cc', 'dgn-irregular-box.cc', 'dgn-layouts.cc',
    'dgn-overview.cc', 'dgn-proclayouts.cc', 'dgn-shoals.cc', 'dgn-swamp.cc',
    'dgn-event.cc',
    'directn.cc', 'dlua.cc',
    'domino.cc', 'dungeon.cc', 'end.cc', 'english.cc', 'errors.cc', 'evoke.cc',
    'exclude.cc', 'exercise.cc', 'fearmonger.cc', 'feature.cc', 'fight.cc',
    'files.cc', 'fineff.cc', 'format.cc', 'fprop.cc', 'game-options.cc', 'geom2d.cc',
    'ghost.cc',
    'god-abil.cc', 'god-blessing.cc', 'god-companions.cc', 'god-conduct.cc',
    'god-item.cc', 'god-menu.cc', 'god-passive.cc', 'god-prayer.cc', 'god-wrath.cc',
    'hash.cc', 'hints.cc', 'hiscores.cc', 'initfile.cc', 'invent.cc',
    'item-use.cc', 'item-name.cc', 'item-prop.cc', 'items.cc',
    'jobs.cc', 'json.cc', 'kills.cc', 'known-items.cc',
    # TODO: subfolder for lua API?
    'l-colour.cc', 'l-crawl.cc', 'l-debug.cc', 'l-dgn.cc', 'l-dgnbld.cc',
    'l-dgnevt.cc', 'l-dgngrd.cc', 'l-dgnit.cc', 'l-dgnlvl.cc', 'l-dgnmon.cc',
    'l-dgntil.cc', 'l-feat.cc', 'l-file.cc', 'l-global.cc', 'l-item.cc',
    'l-los.cc', 'l-mapgrd.cc', 'l-mapmrk.cc', 'l-moninf.cc', 'l-mons.cc',
    'l-option.cc', 'l-spells.cc', 'l-subvault.cc', 'l-travel.cc', 'l-view.cc',
    'l-wiz.cc', 'l-you.cc',
    'lang-fake.cc', 'lev-pand.cc', 'libutil.cc', 'loading-screen.cc',
    'lookup-help.cc',
    'los.cc', 'los-def.cc', 'losglobal.cc', 'losparam.cc',
    'luaterp.cc', 'macro.cc', 'makeitem.cc',
    'map-knowledge.cc', 'mapdef.cc', 'mapmark.cc', 'maps.cc',
    'maybe-bool.cc', 'melee-attack.cc', 'menu.cc',
    'message-stream.cc', 'message.cc', 'misc.cc',
    'mon-abil.cc', 'mon-act.cc', 'mon-aura.cc', 'mon-behv.cc', 'mon-cast.cc',
    'mon-clone.cc', 'mon-death.cc', 'mon-ench.cc', 'mon-explode.cc',
    'mon-gear.cc', 'mon-info.cc', 'mon-movetarget.cc', 'mon-pathfind.cc',
    'mon-pick.cc', 'mon-place.cc', 'mon-poly.cc', 'mon-project.cc',
    'mon-speak.cc', 'mon-tentacle.cc', 'mon-transit.cc', 'mon-util.cc',
    'monster.cc',
    'movement.cc', 'mutation.cc',
    'nearby-danger.cc',
    # TODO: folder for newgame?
    'newgame.cc', 'ng-init.cc', 'ng-init-branches.cc', 'ng-input.cc',
    'ng-restr.cc', 'ng-setup.cc', 'ng-wanderer.cc',
    'notes.cc',
    'orb.cc', 'ouch.cc', 'outer-menu.cc', 'output.cc',
    'package.cc', 'pattern.cc', 'pcg.cc', 'perlin.cc',
    'place-info.cc', 'place.cc',
    'playable.cc', 'player-act.cc',
    'player-equip.cc', 'player-reacts.cc', 'player-stats.cc', 'player.cc',
    'potion.cc',
    # TODO: maybe a subfolder for all the menu stuff?
    'precision-menu.cc', 'prompt.cc', 'quiver.cc',
    # TODO: all the rand stuff should maybe have a folder?
    'randbook.cc', 'random.cc', 'random-var.cc',
    'ranged-attack.cc', 'ray.cc', 'religion.cc',
    'scroller.cc', 'shopping.cc', 'shout.cc',
    'show.cc', 'showsymb.cc',
    'skill-menu.cc', 'skills.cc',
    'sound.cc',
    'species.cc',
    # TODO folder for spells for sure
    'spl-book.cc', 'spl-cast.cc', 'spl-clouds.cc', 'spl-damage.cc',
    'spl-goditem.cc', 'spl-miscast.cc', 'spl-monench.cc', 'spl-other.cc',
    'spl-selfench.cc', 'spl-summoning.cc', 'spl-transloc.cc', 'spl-util.cc',
    'spl-vortex.cc', 'spl-zap.cc',
    'sprint.cc', 'sqldbm.cc', 'stairs.cc', 'startup.cc', 'stash.cc',
    'state.cc', 'status.cc', 'stepdown.cc', 'store.cc', 'stringutil.cc',
    'syscalls.cc',
    'tags.cc',
    'target.cc', 'target-compass.cc',
    'teleport.cc', 'terrain.cc', 'throw.cc', 'timed-effects.cc',
    'transform.cc', 'traps.cc', 'travel.cc',
    'tutorial.cc',
    'ui.cc', 'uncancel.cc', 'unicode.cc',
    'view.cc', 'viewchar.cc', 'viewgeom.cc',
    'viewmap.cc', 'wcwidth.cc',
    'wiz-dgn.cc', 'wiz-dump.cc', 'wiz-fsim.cc', 'wiz-item.cc', 'wiz-mon.cc',
    'wiz-you.cc', 'wizard.cc', 'worley.cc',
    'xom.cc',
    'tilepick.cc', 'tileview.cc',
    'zot.cc')

TILES_SRC= files('tiledoll.cc', 'tilemcache.cc', 'tilepick-p.cc', 'tilecell.cc')

# TODO: subfolder for sure
GLTILES_SRC = files(
    'glwrapper.cc',
    'libgui.cc',
    'tilebuf.cc', 'tiledgnbuf.cc', 'tilefont.cc', 'tilereg.cc',
    'tilereg-abl.cc', 'tilereg-cmd.cc', 'tilereg-crt.cc', 'tilereg-dgn.cc',
    'tilereg-doll.cc', 'tilereg-grid.cc', 'tilereg-inv.cc', 'tilereg-map.cc',
    'tilereg-mem.cc', 'tilereg-mon.cc', 'tilereg-msg.cc', 'tilereg-skl.cc',
    'tilereg-spl.cc', 'tilereg-stat.cc', 'tilereg-tab.cc', 'tilereg-text.cc',
    'tilesdl.cc', 'tiletex.cc',
    'windowmanager-sdl.cc', 'glwrapper-ogl.cc', 'fontwrapper-ft.cc')

# TODO: already a subfolder, make it a proper subdir(
TEST_SRC = files(
    'catch2-tests/test_branch.cc', 'catch2-tests/test_coordit.cc',
    'catch2-tests/test_describe.cc', 'catch2-tests/test_english.cc',
    'catch2-tests/test_files.cc', 'catch2-tests/test_items.cc',
    'catch2-tests/test_mon-util.cc', 'catch2-tests/test_ng-init-branches.cc',
    'catch2-tests/test_player.cc', 'catch2-tests/test_player_fixture.cc',
    'catch2-tests/test_randbook.cc', 'catch2-tests/test_stringutil.cc',
    'catch2-tests/test_species.cc', 'catch2-tests/test_tags.cc',
    'catch2-tests/test_ui.cc', 'catch2-tests/test_viewmap.cc',
    'catch2-tests/test_spl-util.cc')
# TODO subdir
WEBTILES_SRC = files('tileweb.cc', 'tileweb-text.cc')

# TODO subdir
YACC_SRC = files()
# TODO: yacc generation task
#files('util/levcomp.tab.cc', 'util/levcomp.lex.cc')

HEADER_SRC = files(
    'ability.h', 'ability-type.h',
    'activity-interrupt-type.h', 'actor.h',
    'ac-type.h', 'adjust.h', 'AppHdr.h',
    'artefact-prop-type.h', 'art-enum.h', 'attribute-type.h',
    'beam.h', 'beam-type.h', 'beh-type.h', 'bitary.h', 'book-type.h',
    'branch.h', 'branch-type.h', 'build.h',
    'caction-type.h', 'canned-message-type.h', 'char-set-type.h',
    'cleansing-flame-source-type.h', 'cloud-type.h', 'cluautil.h',
    'command-type.h', 'compflag.h', 'conduct-type.h', 'config.h', 'confirm-prompt-type.h',
    'coord-def.h', 'ctest.h', 'cursor-type.h', 'daction-type.h',
    'dbg-maps.h', 'dbg-objstat.h', 'dbg-scan.h',
    'death-curse.h',
    'debug-defines.h', 'debug.h',
    'deck-type.h',
    'defines.h',
    'delay.h', 'description-level-type.h',
    'dgl-message.h',
    'dgn-delve.h', 'dgn-event.h', 'dgn-irregular-box.h', 'dgn-swamp.h',
    'disable-type.h',
    'dungeon-char-type.h','dungeon-feature-type.h',
    'duration-type.h', 'easy-confirm-type.h', 'enchant-type.h',
    'endianness.h',
    'energy-use-type.h',
    'enum.h',
    'equipment-slot.h', 'errors.h',
    'externs.h',
    'explore-greedy-options.h',
    'fight.h', 'filter-enum.h', 'fixedp.h', 'fineff.h', 'flang-t.h',
    'flush-reason-type.h', 'format.h', 'fprop.h',
    'game-chapter.h', 'game-exit-type.h', 'game-type.h', 'gender-type.h',
    'geom2d.h',
    'god-abil.h', 'god-blessing.h', 'god-companions.h', 'god-item.h',
    'god-passive.h', 'god-type.h',
    'hash.h',
    'holy-word-source-type.h',
    'item-def.h', 'item-prop-enum.h', 'item-status-flag-type.h',
    'item-type-id-state-type.h',
    'jobs.h', 'job-type.h',
    'KeymapContext.h',
    'kill-category.h', 'killer-type.h', 'kill-dump-options-type.h',
    'kill-method-type.h',
    'known-items.h',
    'lang-t.h',
    'level-gen-type.h', 'level-id.h', 'level-state-type.h', 'lev-pand.h',
    'libunix.h', 'libutil.h', 'libw32c.h',
    'lookup-help.h', 'los-type.h',
    'macro.h', 'macros.h',
    'map-cell.h', 'map-feature.h', 'map-marker-type.h',
    'maybe-bool.h', 'menu-type.h', 'mgen-enum.h',
    'mon-abil.h', 'mon-act.h', 'mon-ai-action.h', 'mon-attitude-type.h',
    'mon-behv.h', 'mon-book.h', 'mon-cast.h', 'mon-clone.h', 'mon-death.h',
    'mon-ench.h', 'mon-enum.h', 'mon-flags.h', 'mon-gear.h', 'mon-holy-type.h',
    'mon-info-flag-name.h', 'mon-info.h', 'mon-inv-type.h', 'mon-mst.h',
    'mon-movetarget.h', 'mon-pick.h', 'mon-place.h', 'mon-poly.h',
    'mon-project.h', 'mon-speak.h', 'mon-spell.h', 'mon-tentacle.h',
    'mon-transit.h', 'mon-util.h',
    'monster.h', 'monster-type.h', 'montravel-target-type.h',
    'mpr.h',
    'msvc.h',
    'mutation.h', 'mutation-type.h',
    'newgame-def.h',
    'ng-init-branches.h', 'ng-init.h', 'ng-restr.h', 'ng-wanderer.h',
    'notes.h',
    'object-class-type.h', 'operation-types.h', 'orb-type.h', 'ouch.h',
    'package.h', 'platform.h',
    'playable.h',
    'player-equip.h', 'player.h', 'player-reacts.h', 'player-stats.h',
    'potion-type.h', 'pronoun-type.h',
    'props.h',
    'randbook.h', 'random.h', 'random-pick.h', 'random-var.h',
    'reach-type.h',
    'recite-eligibility.h','recite-type.h',
    'religion-enum.h',
    'rng-type.h', 'score-format-type.h', 'screen-mode.h',
    'seen-context-type.h', 'shop-type.h',
    'size-part-type.h', 'size-type.h',
    'skill-focus-mode.h', 'skill-menu-state.h', 'skills.h', 'skill-type.h',
    'slot-select-mode.h',
    'sound.h',
    'species-type.h',
    'spell-type.h',
    'spl-book.h', 'spl-cast.h', 'spl-clouds.h', 'spl-damage.h',
    'spl-goditem.h','spl-miscast.h', 'spl-monench.h', 'spl-other.h',
    'spl-selfench.h', 'spl-summoning.h', 'spl-transloc.h', 'spl-util.h',
    'spl-zap.h',
    'sprint.h', 'sqldbm.h', 'startup.h', 'stat-type.h', 'status.h',
    'stepdown.h', 'store.h',
    'stringutil.h',
    'tag-pref.h', 'tags.h', 'tag-version.h',
    'target-compass.h', 'target.h', 'targeting-type.h', 'targ-mode-type.h',
    'terrain-change-type.h',
    'text-tag-type.h',
    'threads.h',
    'tilecell.h', 'tile-env.h', 'tile-flags.h', 'tile-inventory-flags.h',
    'tile-player-flag-cut.h', 'tileview.h',
    'tileweb.h', 'tileweb-text.h',
    'timed-effect-type.h', 'torment-source-type.h',
    'transformation.h', 'transform.h', 'trap-type.h', 'travel-defs.h',
    'tutorial.h',
    'uncancel.h', 'uncancellable-type.h',
    'undead-state-type.h', 'unique-item-status-type.h',
    'viewgeom.h',
    'wizard.h', 'wizard-option-type.h', 'wiz-dgn.h', 'wiz-dump.h',
    'wiz-fsim.h', 'wiz-item.h', 'wiz-mon.h', 'wiz-you.h',
    'worley.h', 'wu-jian-attack-type.h',
    'xom.h',
    'xp-evoker-data.h', 'xp-tracking-type.h',
    'zap-type.h')


MISC_SRC = files('libw32c.cc',
                 'libunix.cc',
                 'catch2-tests/test_plug_and_play.cc',
                 'catch2-tests/catch_amalgamated.cc',
                 'catch2-tests/test_main.cc',
                 'main.cc',
                 'util/monster/monster-main.cc',
                 'version.cc')
ALL_SRC = MAIN_SRC + TEST_SRC + TILES_SRC + GLTILES_SRC + \
    WEBTILES_SRC + YACC_SRC + MISC_SRC
# -------------------------------------------------
# END Makefile.obj Port
# -------------------------------------------------



build_unmigrated = custom_target('unmigrated',
                                output: 'crawl',
                                command: [prog_make, 'debug-lite', '-j15']) # TODO pass MESON_NUM_PROCESSES
