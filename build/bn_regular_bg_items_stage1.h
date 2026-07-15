#ifndef BN_REGULAR_BG_ITEMS_STAGE1_H
#define BN_REGULAR_BG_ITEMS_STAGE1_H

#include "bn_regular_bg_item.h"

//{{BLOCK(stage1_bn_gfx)

//======================================================================
//
//	stage1_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 630 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 20160 + 8192 = 28384
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STAGE1_BN_GFX_H
#define GRIT_STAGE1_BN_GFX_H

#define stage1_bn_gfxTilesLen 20160
extern const bn::tile stage1_bn_gfxTiles[630];

#define stage1_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell stage1_bn_gfxMap[4096];

#define stage1_bn_gfxPalLen 32
extern const bn::color stage1_bn_gfxPal[16];

#endif // GRIT_STAGE1_BN_GFX_H

//}}BLOCK(stage1_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item stage1(
            regular_bg_tiles_item(span<const tile>(stage1_bn_gfxTiles, 630), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(stage1_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(stage1_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

