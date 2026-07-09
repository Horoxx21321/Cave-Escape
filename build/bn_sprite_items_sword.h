#ifndef BN_SPRITE_ITEMS_SWORD_H
#define BN_SPRITE_ITEMS_SWORD_H

#include "bn_sprite_item.h"

//{{BLOCK(sword_bn_gfx)

//======================================================================
//
//	sword_bn_gfx, 8x8@8, 
//	+ palette 80 entries, not compressed
//	+ 1 tiles not compressed
//	Total size: 160 + 64 = 224
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SWORD_BN_GFX_H
#define GRIT_SWORD_BN_GFX_H

#define sword_bn_gfxTilesLen 64
extern const bn::tile sword_bn_gfxTiles[2];

#define sword_bn_gfxPalLen 160
extern const bn::color sword_bn_gfxPal[80];

#endif // GRIT_SWORD_BN_GFX_H

//}}BLOCK(sword_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item sword(sprite_shape_size(sprite_shape::SQUARE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(sword_bn_gfxTiles, 2), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(sword_bn_gfxPal, 80), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

