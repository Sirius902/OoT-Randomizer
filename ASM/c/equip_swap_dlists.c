#include "equip_swap_dlists.h"

#include <stdint.h>
#include <n64.h>

#define VTX(x,y,z,s,t,crnx,cgny,cbnz,a) { { { x, y, z }, 0, { s, t }, { crnx, cgny, cbnz, a } } }

// Deku Stick texture
#define D_04001A00 ((int32_t*) 0x04001A00)
#define D_0B000000 ((void*)    0x0B000000)
#define D_0B000040 ((void*)    0x0B000040)
#define D_0C000000 ((Gfx*)     0x0C000000)
#define D_0D0001C0 ((void*)    0x0D0001C0)

Vtx deku_stick_verts[] = {
    VTX(1, 1289, -119, 342, 246, 0x16, 0xFF, 0x8B, 0xFF),
    VTX(-19, 3934, -151, -124, 464, 0x2F, 0xFD, 0x92, 0xFF),
    VTX(84, 1289, -24, 320, 208, 0x77, 0x02, 0xF8, 0xFF),
    VTX(-81, 1289, 35, 363, 283, 0xA1, 0xFD, 0x49, 0xFF),
    VTX(-19, 3934, 150, -124, 464, 0x3D, 0xFC, 0x67, 0xFF),
    VTX(-163, 3934, 99, -87, 529, 0x92, 0x02, 0x2E, 0xFF),
    VTX(1, 1289, 71, 342, 246, 0x37, 0x01, 0x6A, 0xFF),
    VTX(-81, 1289, -83, 363, 283, 0x91, 0xFD, 0xD3, 0xFF),
    VTX(-163, 3934, -99, -87, 529, 0x9F, 0x00, 0xBA, 0xFF),
    VTX(88, 5604, 120, -448, 548, 0xC6, 0x18, 0x66, 0xFF),
    VTX(-27, 5494, 82, -399, 591, 0x8D, 0x11, 0x1E, 0xFF),
    VTX(39, -37, -105, 568, 124, 0x04, 0xF5, 0x89, 0xFF),
    VTX(120, 35, -10, 534, 93, 0x74, 0xFE, 0xE5, 0xFF),
    VTX(39, -63, 155, 572, 122, 0xBA, 0x04, 0x61, 0xFF),
    VTX(-103, 35, 49, 591, 194, 0xA2, 0xFE, 0x49, 0xFF),
    VTX(39, -63, 155, 572, 122, 0x63, 0xEF, 0x40, 0xFF),
    VTX(-83, 35, -69, 586, 185, 0x96, 0xF2, 0xCC, 0xFF),
    VTX(57, 3934, -16, -143, 429, 0x77, 0xFC, 0x05, 0xFF),
    VTX(-27, 5366, -191, -376, 581, 0x94, 0x0F, 0xCE, 0xFF),
    VTX(175, 5366, -130, -428, 489, 0x76, 0xFC, 0x12, 0xFF),
    VTX(88, 5604, 120, -448, 548, 0x71, 0x02, 0x26, 0xFF),
    VTX(88, 5476, -228, -426, 537, 0x62, 0xFD, 0xBC, 0xFF),
    VTX(88, 5476, -228, -426, 537, 0xCA, 0x14, 0x97, 0xFF),
    VTX(-27, 5366, -191, 0, 512, 0x94, 0x0F, 0xCE, 0xFF),
    VTX(-27, 5494, 82, 0, 512, 0x8D, 0x11, 0x1E, 0xFF),
    VTX(88, 5604, 120, 0, 512, 0xC6, 0x18, 0x66, 0xFF),
    VTX(39, -63, 155, 0, 512, 0x63, 0xEF, 0x40, 0xFF),
    VTX(-83, 35, -69, 0, 512, 0x96, 0xF2, 0xCC, 0xFF),
    VTX(39, -37, -105, 0, 512, 0x04, 0xF5, 0x89, 0xFF),
    VTX(-103, 35, 49, 0, 512, 0xA2, 0xFE, 0x49, 0xFF),
    VTX(88, 5476, -228, 0, 512, 0xCA, 0x14, 0x97, 0xFF),
    VTX(39, -37, -105, 0, 512, 0x54, 0xAC, 0xF8, 0xFF),
    VTX(120, 35, -10, 0, 512, 0x74, 0xFE, 0xE5, 0xFF),
    VTX(88, 5476, -228, 0, 512, 0x62, 0xFD, 0xBC, 0xFF),
    VTX(88, 5604, 120, 0, 512, 0x71, 0x02, 0x26, 0xFF),
    VTX(175, 5366, -130, 0, 512, 0x76, 0xFC, 0x12, 0xFF),
};

Gfx deku_stick_dlist[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(D_04001A00, G_IM_FMT_I, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPSetGeometryMode(G_FOG | G_LIGHTING),
    gsSPDisplayList(D_0C000000),
    gsDPSetPrimColor(0, 0, 247, 164, 109, 255),
    gsSPVertex(&deku_stick_verts[0], 23, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 7, 5, 8, 0),
    gsSP2Triangles(7, 3, 5, 0, 0, 8, 1, 0),
    gsSP2Triangles(5, 4, 9, 0, 5, 9, 10, 0),
    gsSP2Triangles(0, 7, 8, 0, 0, 11, 7, 0),
    gsSP2Triangles(12, 0, 2, 0, 12, 11, 0, 0),
    gsSP2Triangles(13, 6, 14, 0, 15, 2, 6, 0),
    gsSP2Triangles(16, 3, 7, 0, 14, 3, 16, 0),
    gsSP2Triangles(17, 4, 6, 0, 2, 1, 17, 0),
    gsSP2Triangles(1, 8, 18, 0, 18, 8, 5, 0),
    gsSP2Triangles(18, 5, 10, 0, 19, 20, 4, 0),
    gsSP2Triangles(19, 4, 17, 0, 17, 21, 19, 0),
    gsSP2Triangles(1, 18, 22, 0, 17, 1, 21, 0),
    gsSP2Triangles(17, 6, 2, 0, 6, 3, 14, 0),
    gsSP2Triangles(15, 12, 2, 0, 7, 11, 16, 0),
    gsDPPipeSync(),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineLERP(SHADE, 0, PRIMITIVE, 0, 0, 0, 0, 1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 0, 255, 255, 127, 255),
    gsSPVertex(&deku_stick_verts[23], 13, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 4, 3, 0, 0, 2, 7, 0),
    gsSP2Triangles(8, 9, 3, 0, 10, 11, 12, 0),
    gsSPEndDisplayList(),
};

int16_t bunny_hood_texture1[] = {
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xDE5B, 0x8BD1, 0x4209, 0x1083,
    0x1083, 0x4209, 0x8BD1, 0xDE5B, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xBD97, 0x4A09, 0x0001, 0x0001, 0x0001,
    0x0001, 0x0001, 0x0001, 0x4A09, 0xBD97, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xDE5B, 0x4A4B, 0x0001, 0x0001, 0x0001, 0x0001,
    0x0001, 0x1085, 0x0001, 0x0001, 0x4A09, 0xDE5B, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0x8C11, 0x0843, 0x0001, 0x0001, 0x0001, 0x18C7,
    0x8421, 0xC631, 0x7BDF, 0x18C7, 0x0001, 0x8BD1, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0x524D, 0x1085, 0x0843, 0x0843, 0x0001, 0x6319,
    0xF7BD, 0xFFFF, 0xEF7B, 0x4211, 0x0001, 0x4209, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0x398B, 0x2109, 0x1085, 0x0843, 0x0001, 0x6319,
    0xF7BD, 0xFFFF, 0xEF7B, 0x39CF, 0x0001, 0x18C5, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0x4A51, 0x318D, 0x2109, 0x1085, 0x0843, 0x2109,
    0x9CE7, 0xCE73, 0x7BDF, 0x1085, 0x0001, 0x18C5, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0x7397, 0x4A53, 0x318D, 0x2109, 0x1085, 0x0843,
    0x0843, 0x1085, 0x1085, 0x0843, 0x0843, 0x524B, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0x9C99, 0x6319, 0x4A53, 0x318D, 0x2109, 0x1085,
    0x1085, 0x0843, 0x1085, 0x1085, 0x18C7, 0x9453, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xDE5D, 0x83D9, 0x6319, 0x4A53, 0x318D, 0x294B,
    0x2109, 0x2109, 0x2109, 0x294B, 0x62D1, 0xDE5B, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xC5DB, 0x83DB, 0x6319, 0x5295, 0x4A53,
    0x39CF, 0x39CF, 0x39CF, 0x6B13, 0xC599, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xDE5D, 0xA4DB, 0x7BD9, 0x6B19,
    0x6317, 0x7357, 0x9C97, 0xDE5B, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
};

int16_t bunny_hood_texture2[] = {
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C,
    0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71C, 0xF71D, 0xF71D, 0xF71D,
};

int16_t bunny_hood_texture3[] = {
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71B, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF6D9, 0xF6D7,
    0xF697, 0xF6D9, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF6DB, 0xF697, 0xEE4F, 0xEE0D,
    0xEE0D, 0xEE4F, 0xF695, 0xF6DB, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF6DB, 0xEE93, 0xEE4F, 0xEE0D, 0xEE0B,
    0xEE0B, 0xEE0D, 0xEE4F, 0xEE93, 0xF6DB, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71B, 0xF695, 0xEE4F, 0xF693, 0xF6D9, 0xF6DB,
    0xF6DB, 0xF6D9, 0xF693, 0xEE4F, 0xF695, 0xF71B, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF6D9, 0xEE51, 0xEE93, 0xF71F, 0xFFB1, 0xFFF9,
    0xFFF9, 0xFFB1, 0xF71F, 0xEE93, 0xEE51, 0xF6D9, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF695, 0xEE51, 0xF6D9, 0xFFB1, 0xFFFD, 0xFFFF,
    0xFFFF, 0xFFFD, 0xFFB1, 0xF6D9, 0xEE51, 0xF695, 0xF71D, 0xF71D,
    0xF71D, 0xF6DB, 0xEE53, 0xEE51, 0xF725, 0xFFFD, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFD, 0xF725, 0xEE51, 0xEE53, 0xF6DB, 0xF71D,
    0xF71D, 0xF6DB, 0xEE53, 0xF695, 0xFFAF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFAF, 0xF695, 0xEE53, 0xF6DB, 0xF71D,
    0xF71D, 0xF6D9, 0xEE53, 0xF6DB, 0xFFB3, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB3, 0xF6DB, 0xEE53, 0xF6D9, 0xF71D,
    0xF71D, 0xF697, 0xEE11, 0xF697, 0xFFB1, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB1, 0xF697, 0xEE11, 0xF695, 0xF71D,
    0xF71D, 0xEE95, 0xEE0F, 0xF697, 0xFFB1, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB1, 0xF697, 0xEE0F, 0xEE95, 0xF71D,
    0xF71D, 0xF697, 0xEE51, 0xF6D9, 0xFFB3, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB3, 0xF6D9, 0xEE51, 0xF697, 0xF71D,
    0xF71D, 0xF6D7, 0xEE51, 0xF6DB, 0xFFB3, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB3, 0xF6DB, 0xEE51, 0xF6D7, 0xF71D,
    0xF71D, 0xF6D9, 0xEE51, 0xF6DB, 0xFFB3, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB3, 0xF6DB, 0xEE51, 0xF6D9, 0xF71D,
    0xF71D, 0xF6D9, 0xEE51, 0xF6D9, 0xFFB3, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB3, 0xF6D9, 0xEE51, 0xF6D9, 0xF71D,
    0xF71D, 0xF6D9, 0xEE51, 0xF695, 0xFFB1, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFB1, 0xF695, 0xEE51, 0xF6D9, 0xF71D,
    0xF71D, 0xF6DB, 0xEE53, 0xEE93, 0xFFAF, 0xFFFB, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFB, 0xFFAF, 0xEE93, 0xEE53, 0xF6DB, 0xF71D,
    0xF71D, 0xF71D, 0xF695, 0xEE51, 0xFF6B, 0xFFF9, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFB, 0xFF6B, 0xEE51, 0xF695, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF697, 0xEE4F, 0xF723, 0xFFB7, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFF9, 0xF723, 0xEE4F, 0xF697, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF6D9, 0xEE51, 0xEE95, 0xFF6B, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFF6D, 0xEE95, 0xEE51, 0xF6D9, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF6D9, 0xEE53, 0xEE53, 0xFF6B, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFF6B, 0xEE53, 0xEE53, 0xF6D9, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF6DB, 0xF6D9, 0xEE95, 0xFF6D, 0xFFF9, 0xFFFF,
    0xFFFF, 0xFFF9, 0xFF6D, 0xEE95, 0xF6D9, 0xF6DB, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF6DB, 0xEE95, 0xEE9F, 0xFFB3, 0xFFFF,
    0xFFFF, 0xFFB3, 0xEE9F, 0xEE95, 0xF6DB, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF6DB, 0xEE55, 0xEE59, 0xFFB3, 0xFFFF,
    0xFFFF, 0xFFB3, 0xEE59, 0xEE55, 0xF6DB, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF6DB, 0xF6DB, 0xE5D1, 0xEE5D, 0xFFB9,
    0xFFB9, 0xEE5D, 0xE5D1, 0xF6DB, 0xF6DB, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71B, 0xEE13, 0xE591, 0xEEA1,
    0xEEA1, 0xE591, 0xEE13, 0xF6DB, 0xF6DB, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xEE55, 0xEE55, 0xE5D1,
    0xE5D1, 0xEE57, 0xEE97, 0xF6DB, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF6D9, 0xF71D, 0xF6DD,
    0xF6DD, 0xF6DD, 0xF6DB, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71B, 0xF6DB, 0xF71D,
    0xF71D, 0xF6DB, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF6DB, 0xF71D,
    0xF71F, 0xF6DB, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
    0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D, 0xF71D,
};

Vtx bunny_hood_verts[] = {
    VTX(-155, -1095, -250, 143, -415, 0xC2, 0xA9, 0xCB, 0xFF),
    VTX(-199, -940, -481, 32, -310, 0xE0, 0xC6, 0x9D, 0xFF),
    VTX(130, -1157, -390, 76, -457, 0x06, 0xA7, 0xB1, 0xFF),
    VTX(554, -1102, 0, 262, -419, 0x54, 0xAB, 0x00, 0xFF),
    VTX(570, -977, 0, 262, -334, 0x77, 0xF1, 0x00, 0xFF),
    VTX(488, -817, 427, 467, -226, 0x47, 0xD7, 0x57, 0xFF),
    VTX(-199, -941, 478, 491, -310, 0xE5, 0xC9, 0x66, 0xFF),
    VTX(130, -1157, 390, 449, -457, 0x07, 0xAB, 0x53, 0xFF),
    VTX(107, -915, 520, 512, -292, 0x07, 0xEC, 0x75, 0xFF),
    VTX(10, -1256, 222, 369, -524, 0xCB, 0x99, 0x1E, 0xFF),
    VTX(-155, -1095, 249, 382, -415, 0xC1, 0xA9, 0x35, 0xFF),
    VTX(-85, -1216, 0, 262, -497, 0xD9, 0x8F, 0x00, 0xFF),
    VTX(488, -852, -427, 58, -250, 0x49, 0xD5, 0xAC, 0xFF),
    VTX(107, -912, -549, 0, -291, 0x06, 0xEA, 0x8B, 0xFF),
    VTX(182, -1244, 81, 301, -516, 0x12, 0x8A, 0x04, 0xFF),
    VTX(182, -1244, -81, 224, -516, 0x12, 0x8A, 0xFC, 0xFF),
    VTX(10, -1256, -222, 156, -524, 0xCB, 0x99, 0xE2, 0xFF),
    VTX(554, -1102, 0, -309, -449, 0x54, 0xAB, 0x00, 0xFF),
    VTX(488, -817, 427, 901, -251, 0x47, 0xD7, 0x57, 0xFF),
    VTX(130, -1157, 390, 794, 831, 0x07, 0xAB, 0x53, 0xFF),
    VTX(182, -1244, 81, -79, 675, 0x12, 0x8A, 0x04, 0xFF),
    VTX(130, -1157, -390, -226, 831, 0x06, 0xA7, 0xB1, 0xFF),
    VTX(488, -852, -427, -332, -251, 0x49, 0xD5, 0xAC, 0xFF),
    VTX(554, -1102, 0, 878, -449, 0x54, 0xAB, 0x00, 0xFF),
    VTX(182, -1244, -81, 648, 675, 0x12, 0x8A, 0xFC, 0xFF),
    VTX(107, -915, 520, 308, 464, 0x07, 0xEC, 0x75, 0xFF),
    VTX(488, -817, 427, 299, 902, 0x47, 0xD7, 0x57, 0xFF),
    VTX(259, -461, 487, -21, 740, 0x0C, 0x04, 0x77, 0xFF),
    VTX(-167, -523, 481, -49, 260, 0xF7, 0x05, 0x77, 0xFF),
    VTX(-199, -941, 478, 274, 124, 0xE5, 0xC9, 0x66, 0xFF),
    VTX(488, -852, -427, 326, 894, 0x49, 0xD5, 0xAC, 0xFF),
    VTX(107, -912, -549, 306, 464, 0x06, 0xEA, 0x8B, 0xFF),
    VTX(259, -461, -487, -21, 740, 0x10, 0x0A, 0x8A, 0xFF),
    VTX(-199, -940, -481, 274, 124, 0xE0, 0xC6, 0x9D, 0xFF),
    VTX(-167, -523, -482, -49, 260, 0xF1, 0x09, 0x8A, 0xFF),
    VTX(130, -1157, -390, -17, -520, 0x06, 0xA7, 0xB1, 0xFF),
    VTX(130, -1157, -390, 426, 949, 0x06, 0xA7, 0xB1, 0xFF),
    VTX(10, -1256, -222, -14, -1800, 0xCB, 0x99, 0xE2, 0xFF),
    VTX(182, -1244, -81, -34, -2661, 0x12, 0x8A, 0xFC, 0xFF),
    VTX(182, -1244, -81, 92, 962, 0x12, 0x8A, 0xFC, 0xFF),
    VTX(386, -21, 263, -12, 526, 0xFE, 0x35, 0x6B, 0xFF),
    VTX(606, -68, -269, 544, 274, 0x0A, 0x2B, 0x91, 0xFF),
    VTX(386, -21, 263, -12, 526, 0xFE, 0x35, 0x6B, 0xFF),
    VTX(423, -316, -41, 624, -1289, 0xEA, 0x8B, 0x0A, 0xFF),
    VTX(386, -21, 263, 565, -3334, 0xFE, 0x35, 0x6B, 0xFF),
    VTX(606, -68, -269, 912, 238, 0x0A, 0x2B, 0x91, 0xFF),
    VTX(423, -316, -41, 624, -1289, 0xEA, 0x8B, 0x0A, 0xFF),
    VTX(423, -316, -41, 624, -1289, 0xEA, 0x8B, 0x0A, 0xFF),
    VTX(423, -316, -41, 624, -1289, 0xEA, 0x8B, 0x0A, 0xFF),
    VTX(606, -68, -269, 544, 274, 0x0A, 0x2B, 0x91, 0xFF),
    VTX(386, -21, 263, -12, 526, 0xFE, 0x35, 0x6B, 0xFF),
    VTX(655, 92, 296, -46, 219, 0xF6, 0x49, 0x5E, 0xFF),
    VTX(788, 177, 254, -2, 66, 0xF4, 0x63, 0x42, 0xFF),
    VTX(856, 215, 117, 140, -11, 0x53, 0x53, 0x15, 0xFF),
    VTX(882, 160, -37, 301, -41, 0x20, 0x61, 0xC3, 0xFF),
    VTX(821, 50, -159, 429, 28, 0x4C, 0x1F, 0xA9, 0xFF),
    VTX(821, 50, -159, 1251, -497, 0x4C, 0x1F, 0xA9, 0xFF),
    VTX(882, 160, -37, 1348, -1317, 0x20, 0x61, 0xC3, 0xFF),
    VTX(907, 46, 108, 1388, -2292, 0x71, 0xF2, 0x24, 0xFF),
    VTX(655, 92, 296, 989, -3553, 0xF6, 0x49, 0x5E, 0xFF),
    VTX(837, -159, 85, 1277, -2138, 0x4B, 0xA7, 0x1B, 0xFF),
    VTX(856, 215, 117, 1306, -2354, 0x53, 0x53, 0x15, 0xFF),
    VTX(788, 177, 254, 1199, -3269, 0xF4, 0x63, 0x42, 0xFF),
    VTX(386, -21, 263, 565, -3334, 0xFE, 0x35, 0x6B, 0xFF),
    VTX(423, -316, -41, 624, -1289, 0xEA, 0x8B, 0x0A, 0xFF),
    VTX(606, -68, -269, 912, 238, 0x0A, 0x2B, 0x91, 0xFF),
    VTX(130, -1157, 390, -395, 1590, 0x07, 0xAB, 0x53, 0xFF),
    VTX(130, -1157, 390, 82, 992, 0x07, 0xAB, 0x53, 0xFF),
    VTX(10, -1256, 222, -390, 2500, 0xCB, 0x99, 0x1E, 0xFF),
    VTX(182, -1244, 81, -410, 3111, 0x12, 0x8A, 0x04, 0xFF),
    VTX(182, -1244, 81, 418, 981, 0x12, 0x8A, 0x04, 0xFF),
    VTX(606, -68, 269, -62, 326, 0x0A, 0x2B, 0x6F, 0xFF),
    VTX(386, -21, -263, 516, 541, 0xFE, 0x35, 0x95, 0xFF),
    VTX(386, -21, -263, 516, 541, 0xFE, 0x35, 0x95, 0xFF),
    VTX(386, -21, -263, 203, 3589, 0xFE, 0x35, 0x95, 0xFF),
    VTX(423, -316, 41, 263, 2136, 0xEA, 0x8B, 0xF6, 0xFF),
    VTX(423, -316, 41, 263, 2136, 0xEA, 0x8B, 0xF6, 0xFF),
    VTX(423, -316, 41, 263, 2136, 0xEA, 0x8B, 0xF6, 0xFF),
    VTX(606, -68, 269, 558, 1050, 0x0A, 0x2B, 0x6F, 0xFF),
    VTX(423, -316, 41, 263, 2136, 0xEA, 0x8B, 0xF6, 0xFF),
    VTX(606, -68, 269, -62, 326, 0x0A, 0x2B, 0x6F, 0xFF),
    VTX(821, 50, 159, 24, 73, 0x4C, 0x1F, 0x57, 0xFF),
    VTX(655, 92, -296, 518, 232, 0xF6, 0x49, 0xA2, 0xFF),
    VTX(882, 160, 37, 136, -4, 0x20, 0x61, 0x3E, 0xFF),
    VTX(856, 215, -117, 296, 14, 0x53, 0x53, 0xEB, 0xFF),
    VTX(788, 177, -254, 452, 83, 0xF4, 0x63, 0xBE, 0xFF),
    VTX(386, -21, -263, 516, 541, 0xFE, 0x35, 0x95, 0xFF),
    VTX(655, 92, -296, 637, 3745, 0xF6, 0x49, 0xA2, 0xFF),
    VTX(788, 177, -254, 852, 3543, 0xF4, 0x63, 0xBE, 0xFF),
    VTX(907, 46, -108, 1045, 2849, 0x71, 0xF2, 0xDC, 0xFF),
    VTX(821, 50, 159, 906, 1574, 0x4C, 0x1F, 0x57, 0xFF),
    VTX(837, -159, -85, 932, 2739, 0x4B, 0xA7, 0xE5, 0xFF),
    VTX(856, 215, -117, 962, 2893, 0x53, 0x53, 0xEB, 0xFF),
    VTX(882, 160, 37, 1005, 2156, 0x20, 0x61, 0x3E, 0xFF),
    VTX(386, -21, -263, 203, 3589, 0xFE, 0x35, 0x95, 0xFF),
    VTX(606, -68, 269, 558, 1050, 0x0A, 0x2B, 0x6F, 0xFF),
    VTX(423, -316, 41, 263, 2136, 0xEA, 0x8B, 0xF6, 0xFF),
};

Gfx bunny_hood_dlist[] = {
    gsSPMatrix(D_0D0001C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureBlock(bunny_hood_texture1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x003C),
    gsDPSetPrimColor(0, 0x80, 255, 255, 255, 255),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_CULL_BACK),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(&bunny_hood_verts[0], 25, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
    gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
    gsSP2Triangles(12, 2, 13, 0, 12, 4, 3, 0),
    gsSP2Triangles(8, 7, 5, 0, 10, 9, 7, 0),
    gsSP2Triangles(14, 15, 3, 0, 13, 2, 1, 0),
    gsSP2Triangles(2, 16, 0, 0, 7, 6, 10, 0),
    gsSP2Triangles(11, 0, 16, 0, 14, 9, 11, 0),
    gsSP2Triangles(11, 16, 15, 0, 15, 14, 11, 0),
    gsSP2Triangles(17, 18, 19, 0, 19, 20, 17, 0),
    gsSP2Triangles(21, 22, 23, 0, 23, 24, 21, 0),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureBlock(bunny_hood_texture2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x007C),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(&bunny_hood_verts[25], 10, 0),
    gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
    gsSP2Triangles(5, 6, 7, 0, 6, 8, 9, 0),
    gsSP2Triangles(0, 2, 3, 0, 9, 7, 6, 0),
    gsSPMatrix(D_0D0001C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(&bunny_hood_verts[35], 5, 0),
    gsSPMatrix(D_0B000000, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureBlock(bunny_hood_texture3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x007C),
    gsDPSetPrimColor(0, 0x80, 255, 255, 255, 255),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(&bunny_hood_verts[40], 26, 5),
    gsSP2Triangles(5, 6, 1, 0, 1, 4, 7, 0),
    gsSP2Triangles(8, 9, 3, 0, 0, 10, 11, 0),
    gsSP2Triangles(3, 2, 12, 0, 13, 2, 0, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(19, 20, 16, 0, 19, 16, 17, 0),
    gsSP1Triangle(16, 20, 14, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 23, 0),
    gsSP2Triangles(23, 22, 26, 0, 23, 25, 21, 0),
    gsSP2Triangles(23, 27, 24, 0, 25, 24, 28, 0),
    gsSP2Triangles(25, 29, 30, 0, 26, 27, 23, 0),
    gsSP2Triangles(28, 29, 25, 0, 30, 21, 25, 0),
    gsSPMatrix(D_0D0001C0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(&bunny_hood_verts[66], 5, 0),
    gsSPMatrix(D_0B000040, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPLoadTextureBlock(bunny_hood_texture3, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x003C, 0x007C),
    gsDPSetPrimColor(0, 0x80, 255, 255, 255, 255),
    gsSPSetGeometryMode(G_CULL_BACK),
    gsSPClearGeometryMode(G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsSPVertex(&bunny_hood_verts[71], 26, 5),
    gsSP2Triangles(1, 5, 6, 0, 7, 4, 1, 0),
    gsSP2Triangles(3, 8, 9, 0, 0, 2, 10, 0),
    gsSP2Triangles(11, 12, 0, 0, 13, 2, 3, 0),
    gsSP2Triangles(14, 15, 16, 0, 17, 18, 19, 0),
    gsSP2Triangles(16, 20, 14, 0, 19, 16, 15, 0),
    gsSP1Triangle(19, 15, 17, 0),
    gsSP2Triangles(21, 22, 23, 0, 24, 25, 23, 0),
    gsSP2Triangles(23, 22, 26, 0, 26, 27, 23, 0),
    gsSP2Triangles(28, 21, 25, 0, 29, 30, 25, 0),
    gsSP2Triangles(23, 25, 21, 0, 23, 27, 24, 0),
    gsSP2Triangles(25, 24, 29, 0, 25, 30, 28, 0),
    gsSPEndDisplayList(),
};
