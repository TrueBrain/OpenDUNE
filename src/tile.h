/* $Id$ */

#ifndef TILE_H
#define TILE_H

extern bool Tile_IsValid(tile32 tile);
extern uint16 Tile_GetX(tile32 tile);
extern uint16 Tile_GetY(tile32 tile);
extern uint32 Tile_GetXY(tile32 tile);
extern uint8 Tile_GetPosX(tile32 tile);
extern uint8 Tile_GetPosY(tile32 tile);
extern uint16 Tile_PackTile(tile32 tile);
extern uint16 Tile_PackXY(uint16 x, uint16 y);
extern tile32 Tile_UnpackTile(uint16 packed);
extern uint8 Tile_GetPackedX(uint16 packed);
extern uint8 Tile_GetPackedY(uint16 packed);
extern uint16 Tile_GetDistance(tile32 from, tile32 to);
extern tile32 Tile_AddTileDiff(tile32 from, tile32 diff);
extern void Tile_Center(tile32 *tile);

extern void emu_Tile_IsValid();
extern void emu_Tile_GetX();
extern void emu_Tile_GetY();
extern void emu_Tile_GetXY();
extern void emu_Tile_GetPosX();
extern void emu_Tile_GetPosY();
extern void emu_Tile_GetPosXY();
extern void emu_Tile_PackTile();
extern void emu_Tile_PackXY();
extern void emu_Tile_Unpack();
extern void emu_Tile_GetPackX();
extern void emu_Tile_GetPackY();
extern void emu_Tile_GetDistance();
extern void emu_Tile_AddTileDiff();
extern void emu_Tile_Center();

#endif /* TILE_H */