#include "equip_swap_dlists.h"

#include <stdint.h>
#include <n64.h>

#define VTX(x,y,z,s,t,crnx,cgny,cbnz,a) { { { x, y, z }, 0, { s, t }, { crnx, cgny, cbnz, a } } }

// texture
#define D_04001A00 ((int32_t*) 0x04001A00)
#define D_0C000000 ((Gfx*)     0x0C000000)

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
