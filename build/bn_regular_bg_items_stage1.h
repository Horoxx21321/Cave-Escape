#ifndef BN_REGULAR_BG_ITEMS_STAGE1_H
#define BN_REGULAR_BG_ITEMS_STAGE1_H

#include "bn_regular_bg_item.h"

//{{BLOCK(stage1_bn_gfx)

//======================================================================
//
//	stage1_bn_gfx, 1024x1024@8, 
//	+ palette 240 entries, not compressed
//	+ 493 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 128x128 
//	Total size: 480 + 31552 + 32768 = 64800
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STAGE1_BN_GFX_H
#define GRIT_STAGE1_BN_GFX_H

#define stage1_bn_gfxTilesLen 31552
extern const bn::tile stage1_bn_gfxTiles[986];

#define stage1_bn_gfxMapLen 32768
extern const bn::regular_bg_map_cell stage1_bn_gfxMap[16384];

#define stage1_bn_gfxPalLen 480
extern const bn::color stage1_bn_gfxPal[240];

#endif // GRIT_STAGE1_BN_GFX_H

//}}BLOCK(stage1_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item stage1(
            regular_bg_tiles_item(span<const tile>(stage1_bn_gfxTiles, 986), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(stage1_bn_gfxPal, 240), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(stage1_bn_gfxMap[0], size(128, 128), compression_type::NONE, 1, true));
}

#endif

