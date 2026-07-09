#ifndef BN_SPRITE_ITEMS_MAN_H
#define BN_SPRITE_ITEMS_MAN_H

#include "bn_sprite_item.h"

//{{BLOCK(man_bn_gfx)

//======================================================================
//
//	man_bn_gfx, 16x32@8, 
//	+ palette 160 entries, not compressed
//	+ 8 tiles Metatiled by 2x1 not compressed
//	Total size: 320 + 512 = 832
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAN_BN_GFX_H
#define GRIT_MAN_BN_GFX_H

#define man_bn_gfxTilesLen 512
extern const bn::tile man_bn_gfxTiles[16];

#define man_bn_gfxPalLen 320
extern const bn::color man_bn_gfxPal[160];

#endif // GRIT_MAN_BN_GFX_H

//}}BLOCK(man_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item man(sprite_shape_size(sprite_shape::WIDE, sprite_size::SMALL), 
            sprite_tiles_item(span<const tile>(man_bn_gfxTiles, 16), bpp_mode::BPP_8, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(man_bn_gfxPal, 160), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

