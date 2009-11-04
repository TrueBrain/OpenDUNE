/* $Id$ */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "libemu.h"
#include "house.h"
#include "structure.h"
#include "unit.h"
#include "../decompiled/decompiled.h"

void emu_Scenario_Load_General()
{
	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1EC7); /* WinFlags */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x00C6); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->scenario.winFlags = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1ED0); /* LoseFlags */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x00E5); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->scenario.loseFlags = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1EDE); /* Seed */
	emu_push(emu_ds); emu_push(0x1EDA); /* MAP */
	emu_push(emu_cs); emu_push(0x0104); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->scenario.mapSeed = (int16)emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1EE3); /* TimeOut */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x0127); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->scenario.timeOut = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->variable_39FC);
	emu_push(emu_ds); emu_push(0x1EEB); /* TacticalPos */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x0146); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->variable_39FC = emu_ax;
	g_global->variable_39FE = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->variable_3A00);
	emu_push(emu_ds); emu_push(0x1EF7); /* CursorPos */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x0168); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->variable_3A00 = emu_ax;
	g_global->variable_3A02 = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1F01); /* MapScale */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x018A); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	g_global->scenario.mapScale = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(14);
	emu_push(emu_ds); emu_push(0x8D0D); /* g_global->scenario.pictureBriefing */
	emu_push(emu_ds); emu_push(0x1F17); /* HARVEST.WSA */
	emu_push(emu_ds); emu_push(0x1F0A); /* BriefPicture */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x01B3); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(14);
	emu_push(emu_ds); emu_push(0x8D1B); /* g_global->scenario.pictureWin */
	emu_push(emu_ds); emu_push(0x1F2E); /* WIN1.WSA */
	emu_push(emu_ds); emu_push(0x1F23); /* WinPicture */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x01D9); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(14);
	emu_push(emu_ds); emu_push(0x8D29); /* g_global->scenario.pictureLose */
	emu_push(emu_ds); emu_push(0x1F43); /* LOSTBILD.WSA */
	emu_push(emu_ds); emu_push(0x1F37); /* LosePicture */
	emu_push(emu_ds); emu_push(0x1EC1); /* BASIC */
	emu_push(emu_cs); emu_push(0x01FF); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;
}

void emu_Scenario_Load_House(uint8 houseID)
{
	House *h;

	emu_get_memory8(emu_ss, emu_bp, -0xA2) = 0x0;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_ds); emu_push(0x1F56); /* NONE */
	emu_push(emu_ds); emu_push(0x1F50); /* Brain */
	emu_push(g_houseInfo[houseID].name.s.cs); emu_push(g_houseInfo[houseID].name.s.ip);
	emu_push(emu_cs); emu_push(0x025C); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x026A); emu_cs = 0x01F7; f__01F7_3CD5_000D_9D98();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_ds); emu_push(0x1F5B); /* HUMAN$CPU */
	emu_push(emu_cs); emu_push(0x0278); emu_cs = 0x01F7; f__01F7_3A8A_0018_E4EE();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x8;

	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	if (emu_ax == 0 && emu_dx == 0) return;

	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0297); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	if (emu_ax == 0) return;

	/* Create the house */
	h = House_Allocate(houseID);
	assert(h != NULL);

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1F65); /* Credits */
	emu_push(g_houseInfo[houseID].name.s.cs); emu_push(g_houseInfo[houseID].name.s.ip);
	emu_push(emu_cs); emu_push(0x02C6); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	h->credits = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0);
	emu_push(emu_ds); emu_push(0x1F6D); /* Quota */
	emu_push(g_houseInfo[houseID].name.s.cs); emu_push(g_houseInfo[houseID].name.s.ip);
	emu_push(emu_cs); emu_push(0x02E9); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	h->creditsQuota = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x27);
	emu_push(emu_ds); emu_push(0x1F73); /* MaxUnit */
	emu_push(g_houseInfo[houseID].name.s.cs); emu_push(g_houseInfo[houseID].name.s.ip);
	emu_push(emu_cs); emu_push(0x030D); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xE;
	h->unitCountMax = emu_ax;

	/* For 'Brain = Human' we have to set a few additional things */
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x10));
	if (emu_get_memory8(emu_es, emu_bx, 0x0) != 'H') return;

	h->flags |= 0x0002;

	g_global->playerHouseID       = houseID;
	g_global->playerHouse.s.cs    = g_global->houseStartPos.s.cs;
	g_global->playerHouse.s.ip    = g_global->houseStartPos.s.ip + h->index * sizeof(House);
	g_global->playerCreditsNoSilo = h->credits;
}

void emu_Scenario_Load_Units()
{
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC) + 2);
	emu_push(emu_cs); emu_push(0x0400); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(0); emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_ds); emu_push(0x1F7B); /* UNITS */
	emu_push(emu_cs); emu_push(0x042B); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x043E); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_si = House_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));
	if (emu_si == HOUSE_INVALID) return;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0464); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_di = Unit_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));
	if (emu_di == UNIT_INVALID) return;

	emu_push(emu_si);
	emu_push(emu_di);
	emu_push(0xFFFF);
	emu_push(emu_cs); emu_push(0x0485); emu_cs = 0x0FE4; emu_Unit_Allocate();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 6;

	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;

	if (emu_ax == 0 && emu_dx == 0) return;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_get_memory16(emu_es, emu_bx, 0x4) |= 0x0200;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x04B2); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x04BC); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_ax);
	emu_push(g_unitInfo[emu_get_memory8(emu_es, emu_bx, 0x2)].hitpoints);
	emu_push(emu_cs); emu_push(0x04DD); emu_cs = 0x34C1; overlay(0x34C1, 0); emu_PercentToValue();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_get_memory16(emu_es, emu_bx, 0xE) = emu_ax;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x04F6); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0500); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0508); emu_cs = 0x0F3F; emu_Tile_Unpack();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 2;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_get_memory16(emu_es, emu_bx, 0xC) = emu_dx;
	emu_get_memory16(emu_es, emu_bx, 0xA) = emu_ax;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0524); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x052E); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_get_memory8(emu_es, emu_bx, 0x64) = emu_al;

	emu_push(emu_ds); emu_push(0x1F83); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0547); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0551); emu_cs = 0x1381; emu_Action_StringToID();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_get_memory8(emu_es, emu_bx, 0x4F) = emu_al;
	emu_get_memory8(emu_es, emu_bx, 0x50) = 0xFF;

	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC)); emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x0572); emu_cs = 0x0F3F; emu_Tile_PackTile();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x057A); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_0F8B_0015_1689();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 2;

	if (emu_ax == 0 && g_global->campaignID > 2) {
		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x0591); emu_cs = 0x0FE4; emu_Unit_Free();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;
		return;
	}

	/* There is no way this is ever possible, as the 0x4 flag is set by Unit_Allocate() */
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	if ((emu_get_memory16(emu_es, emu_bx, 0x4) & 0x4) != 0) {
		/* Unresolved jump */ emu_ip = 0x05B8; emu_last_cs = 0xB4B5; emu_last_ip = 0x059F; emu_last_length = 0x001F; emu_last_crc = 0x757D; emu_call(); return;
	}

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_get_memory8(emu_es, emu_bx, 0x4F));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_cs); emu_push(0x05B5); emu_cs = 0x176C; f__176C_000E_000E_633D();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 6;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_get_memory8(emu_es, emu_bx, 0x9) = 0x0;

	emu_push(emu_get_memory8(emu_es, emu_bx, 0x8));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_cs); emu_push(0x05D4); emu_cs = 0x1423; f__1423_08CD_0012_0004();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 6;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(0);
	emu_push(1);
	emu_push(emu_get_memory8(emu_es, emu_bx, 0x64));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_cs); emu_push(0x05F3); emu_cs = 0x1A34; f__1A34_1E99_0012_1117();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 10;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(1);
	emu_push(1);
	emu_push(emu_get_memory8(emu_es, emu_bx, 0x64));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_cs); emu_push(0x0613); emu_cs = 0x1A34; f__1A34_1E99_0012_1117();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 10;

	emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_cs); emu_push(0x0624); emu_cs = 0x1A34; f__1A34_204C_0043_B1ED();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 6;
}

void emu_Scenario_Load_Structures()
{
	emu_push(0x3);
	emu_push(emu_ds); emu_push(0x1F92); /* GEN */
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_cs); emu_push(0x06A9); emu_cs = 0x01F7; f__01F7_28DC_0009_EE56();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xA;

	/* String starts with GEN, meaning slabs and walls */
	if (emu_ax == 0) {
		/* Position is part of the key */
		emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC) + 3);
		emu_push(emu_cs); emu_push(0x06C2); emu_cs = 0x01F7; emu_String_ToInteger();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;
		emu_get_memory16(emu_ss, emu_bp, -0x12) = emu_ax;

		emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
		emu_push(0x7F);
		emu_push(emu_ss); emu_push(emu_bp - 0xA2);
		emu_push(0); emu_push(0);
		emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
		emu_push(emu_ds); emu_push(0x1F87); /* STRUCTURES */
		emu_push(emu_cs); emu_push(0x06ED); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 0x16;

		emu_push(emu_ds); emu_push(0x1F81); /* , */
		emu_push(emu_ss); emu_push(emu_bp - 0xA2);
		emu_push(emu_cs); emu_push(0x0700); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 0x8;

		emu_si = House_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));

		emu_push(emu_ds); emu_push(0x1F81); /* , */
		emu_push(0); emu_push(0);
		emu_push(emu_cs); emu_push(0x071E); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 0x8;

		emu_di = Structure_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));

		if (emu_si == HOUSE_INVALID) return;
		if (emu_di == STRUCTURE_INVALID) return;

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x12));
		emu_push(emu_si);
		emu_push(emu_di);
		emu_push(0xFFFF);
		emu_push(emu_cs); emu_push(0x0744); emu_cs = 0x0C3A; emu_Structure_Create();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 8;

		return;
	}

	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC) + 2);
	emu_push(emu_cs); emu_push(0x0759); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(0); emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_ds); emu_push(0x1F87); /* STRUCTURES */
	emu_push(emu_cs); emu_push(0x0784); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0797); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_si = House_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x07B5); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_di = Structure_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));

	if (emu_si == HOUSE_INVALID) return;
	if (emu_di == STRUCTURE_INVALID) return;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x07E3); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x07ED); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0x14) = emu_ax;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0802); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x080C); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0x12) = emu_ax;

	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x12));
	emu_push(emu_cs); emu_push(0x0819); emu_cs = 0x34CD; overlay(0x34CD, 0); emu_Structure_GetByPackedTile();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 2;

	if (emu_ax != 0 || emu_dx != 0) return;

	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x12));
	emu_push(emu_si);
	emu_push(emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_push(emu_cs); emu_push(0x082B); emu_cs = 0x0C3A; emu_Structure_Create();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;

	if (emu_ax == 0 && emu_dx == 0) return;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	/* XXX -- DUNE2 BUG -- The percent hp read at -0x14 is ignored, and 100% is always given */
	emu_get_memory16(emu_es, emu_bx, 0xE) = g_structureInfo[emu_get_memory8(emu_es, emu_bx, 0x2)].hitpoints;
	emu_get_memory16(emu_es, emu_bx, 0x4) &= 0xFBFF;
	emu_get_memory16(emu_es, emu_bx, 0x54) = 0x0;
}

void emu_Scenario_Load_Map()
{
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	if (emu_get_memory8(emu_es, emu_bx, 0x0) != 'C') return;

	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8) + 6);
	emu_push(emu_cs); emu_push(0x08FD); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_di = emu_ax;

	emu_push(2);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8) + 4);
	emu_push(emu_ss); emu_push(emu_bp - 0xC);
	emu_push(emu_cs); emu_push(0x0919); emu_cs = 0x01F7; emu_Tools_Memmove();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 10;
	emu_get_memory8(emu_ss, emu_bp, -0x9) = 0x0;

	emu_push(emu_ss); emu_push(emu_bp - 0xC);
	emu_push(emu_cs); emu_push(0x092B); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 2;

	emu_push(emu_di);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0933); emu_cs = 0x0F3F; emu_Tile_PackXY();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_di = emu_ax & 0xFFF;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(0); emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_ds); emu_push(0x1EDA); /* MAP */
	emu_push(emu_cs); emu_push(0x096A); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x097D); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0987); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_bx += emu_di * 4;
	emu_get_memory8(emu_es, emu_bx, 0x2) = emu_al;

	emu_push(emu_ds); emu_push(0x1F83); /* ,\r\n */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x09A9); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x09B3); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_bx += emu_di * 4;
	emu_ax &= 0x1FF;

	emu_get_memory16(emu_es, emu_bx, 0x0) &= 0xFE00;
	emu_get_memory16(emu_es, emu_bx, 0x0) |= emu_ax;

	if (emu_get_memory16(0x2E9C, emu_di * 2, 0x323F) != emu_ax) {
		emu_get_memory16(0x2E9C, emu_di * 2, 0x323F) |= 0x8000;
	}

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_bx += emu_di * 4;

	if ((emu_get_memory8(emu_es, emu_bx, 0x2) & 0x8) == 0) {
		emu_ax = (g_global->variable_39F2 & 0x7F) * 2;
		emu_get_memory8(emu_es, emu_bx, 0x1) &= 0x1;
		emu_get_memory8(emu_es, emu_bx, 0x1) |= emu_al;
	}
}

void emu_Scenario_Load_Reinforcements()
{
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_cs); emu_push(0x0CAD); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_si = emu_ax;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(0); emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_ds); emu_push(0x1FAD); /* REINFORCEMENTS */
	emu_push(emu_cs); emu_push(0x0CD7); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0CEA); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_di = House_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));
	if (emu_di == HOUSE_INVALID) return;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0D10); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_get_memory16(emu_ss, emu_bp, -0xE) = Unit_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));
	if (emu_get_memory16(emu_ss, emu_bp, -0xE) == UNIT_INVALID) return;

	emu_push(0);
	emu_push(0xFFFF); emu_push(0xFFFF);
	emu_push(emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_push(0xFFFF);
	emu_push(emu_cs); emu_push(0x0D40); emu_cs = 0x1A34; emu_Unit_Create();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 12;

	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;
	if (emu_ax == 0 && emu_dx == 0) return;

	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
	g_global->scenario.reinforcement[emu_si].unitID = emu_get_memory16(emu_es, emu_bx, 0x0);

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0D77); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0D81); emu_cs = 0x01F7; f__01F7_3CD5_000D_9D98();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_ds); emu_push(0x1FBC); /* 0NORTH$1EAST$2SOUTH$3WEST$4AIR$5VISIBLE$6ENEMYBASE$7HOMEBASE */
	emu_push(emu_cs); emu_push(0x0D8F); emu_cs = 0x01F7; f__01F7_3A8A_0018_E4EE();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	g_global->scenario.reinforcement[emu_si].locationID = emu_get_memory8(emu_dx, emu_ax, 0xFFFF) - '0';

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0DBD); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0DC7); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	g_global->scenario.reinforcement[emu_si].timeLeft = (emu_ax * 6) + 1;
	g_global->scenario.reinforcement[emu_si].timeBetween = g_global->scenario.reinforcement[emu_si].timeLeft;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0DEE); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	/* XXX -- DUNE2 BUG -- this '+' is read from the wrong place, and so repeat is always 0 */
	if (emu_get_memory8(emu_dx, emu_ax, 0x0) == '+') {
		g_global->scenario.reinforcement[emu_si].repeat = 1;
	} else {
		g_global->scenario.reinforcement[emu_si].repeat = 0;
	}
}

void emu_Scenario_Load_Teams()
{
	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(0); emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_ds); emu_push(0x1FF9); /* TEAMS */
	emu_push(emu_cs); emu_push(0x0EC4); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0ED7); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_si = House_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));
	if (emu_si == HOUSE_INVALID) return;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0EFD); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0F07); emu_cs = 0x1381; emu_Action2_StringToID();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0xA) = emu_ax;

	if (emu_get_memory16(emu_ss, emu_bp, -0xA) == 0xFFFF) return;

	emu_push(emu_ds); emu_push(0x1F81); /* , */
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0F22); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0F2C); emu_cs = 0x1381; emu_Movement_StringToID();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0xC) = emu_ax;

	if (emu_get_memory16(emu_ss, emu_bp, -0xC) == 0xFFFF) return;

	emu_push(emu_ds); emu_push(0x1F81);
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0F47); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0F51); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_ax;

	emu_push(emu_ds); emu_push(0x1F81);
	emu_push(0); emu_push(0);
	emu_push(emu_cs); emu_push(0x0F66); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;

	emu_push(emu_dx); emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0F70); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;

	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA));
	emu_push(emu_si);
	emu_push(emu_cs); emu_push(0x0F87); emu_cs = 0x104B; f__104B_024D_0012_1DC4();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 10;
}

void emu_Scenario_Load_Choam()
{
	emu_si = Unit_StringToType((const char *)&emu_get_memory8(emu_dx, emu_ax, 0));;
	if (emu_si == UNIT_INVALID) return;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(0); emu_push(0);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_ds); emu_push(0x1FFF); /* CHOAM */
	emu_push(emu_cs); emu_push(0x102E); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x103C); emu_cs = 0x01F7; emu_String_ToInteger();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	g_global->variable_97E7[emu_si] = emu_ax;
}

/**
 * Loads a scenario and prepares the map for playing.
 *
 * @name emu_Scenario_Load
 * @implements B4B5:0000:0014:F092 ()
 * @implements B4B5:000F:0005:94AD
 * @implements B4B5:0011:0003:9539
 * @implements B4B5:0014:0038:72B6
 * @implements B4B5:004C:000D:0FE8
 * @implements B4B5:0059:0008:B4CF
 * @implements B4B5:0061:0014:7874
 * @implements B4B5:0075:001B:0118
 * @implements B4B5:0090:0014:EBAA
 * @implements B4B5:00A4:0022:04BB
 * @implements B4B5:00C6:001F:0DBE
 * @implements B4B5:00E5:001F:25BE
 * @implements B4B5:0104:0023:B49E
 * @implements B4B5:0127:001F:EA8A
 * @implements B4B5:0146:0022:A358
 * @implements B4B5:0168:0022:8C57
 * @implements B4B5:018A:0029:D26D
 * @implements B4B5:01B3:0026:A872
 * @implements B4B5:01D9:0026:480D
 * @implements B4B5:01FF:0008:5475
 * @implements B4B5:0207:000D:44AD
 * @implements B4B5:0214:0007:588E
 * @implements B4B5:021B:0041:D371
 * @implements B4B5:025C:000E:4C74
 * @implements B4B5:026A:000E:B38A
 * @implements B4B5:0278:0014:E9B8
 * @implements B4B5:028C:000B:6FB9
 * @implements B4B5:0297:0009:3799
 * @implements B4B5:02A0:0006:D4F4
 * @implements B4B5:02A6:0020:939D
 * @implements B4B5:02C6:0023:D24E
 * @implements B4B5:02E9:0024:0501
 * @implements B4B5:030D:003F:A1B8
 * @implements B4B5:0343:0009:0B24
 * @implements B4B5:0344:0008:0B07
 * @implements B4B5:034C:0019:3E28
 * @implements B4B5:0365:0002:D0BA
 * @implements B4B5:0367:0021:6405
 * @implements B4B5:037D:000B:3601
 * @implements B4B5:0388:0023:F5D3
 * @implements B4B5:03A0:000B:6148
 * @implements B4B5:03AB:0040:8201
 * @implements B4B5:03EB:0006:B612
 * @implements B4B5:03F1:000F:A0F4
 * @implements B4B5:0400:002B:2569
 * @implements B4B5:042B:0013:2B96
 * @implements B4B5:043E:000A:3572
 * @implements B4B5:0448:000C:97E0
 * @implements B4B5:0454:0010:8687
 * @implements B4B5:0464:000A:B659
 * @implements B4B5:046E:000C:17F9
 * @implements B4B5:047A:000B:186A
 * @implements B4B5:0485:0014:19B1
 * @implements B4B5:0499:0019:B499
 * @implements B4B5:04B2:000A:882F
 * @implements B4B5:04BC:0021:883C
 * @implements B4B5:04DD:0019:97D1
 * @implements B4B5:04F6:000A:882F
 * @implements B4B5:0500:0008:0AE5
 * @implements B4B5:0508:001C:DBB3
 * @implements B4B5:0524:000A:882F
 * @implements B4B5:052E:0019:A2F9
 * @implements B4B5:0547:000A:7577
 * @implements B4B5:0551:0021:D3B7
 * @implements B4B5:0572:0008:3755
 * @implements B4B5:057A:0017:470E
 * @implements B4B5:0591:0005:CFC9
 * @implements B4B5:0596:001F:757D
 * @implements B4B5:05B5:001F:CB42
 * @implements B4B5:05D4:001F:E8C6
 * @implements B4B5:05F3:0020:9640
 * @implements B4B5:0613:0011:7F5A
 * @implements B4B5:0624:000E:6326
 * @implements B4B5:0627:000B:414C
 * @implements B4B5:0632:0012:AEC4
 * @implements B4B5:0638:000C:610D
 * @implements B4B5:0644:000B:6148
 * @implements B4B5:064F:0040:7E01
 * @implements B4B5:068F:0006:77BF
 * @implements B4B5:0695:0014:F457
 * @implements B4B5:06A9:000A:C412
 * @implements B4B5:06B3:000F:80F4
 * @implements B4B5:06C2:002B:D951
 * @implements B4B5:06ED:0013:2B96
 * @implements B4B5:0700:000A:3572
 * @implements B4B5:070A:0014:A580
 * @implements B4B5:071E:000A:7659
 * @implements B4B5:0728:001C:537A
 * @implements B4B5:0744:0006:1788
 * @implements B4B5:0747:0003:9DAA
 * @implements B4B5:074A:000F:A0F4
 * @implements B4B5:0759:002B:D969
 * @implements B4B5:0784:0013:2B96
 * @implements B4B5:0797:000A:3572
 * @implements B4B5:07A1:0014:A580
 * @implements B4B5:07B5:000A:7659
 * @implements B4B5:07BF:000C:177A
 * @implements B4B5:07CB:0008:105D
 * @implements B4B5:07D3:0010:8687
 * @implements B4B5:07E3:000A:882F
 * @implements B4B5:07ED:0015:F37B
 * @implements B4B5:0802:000A:882F
 * @implements B4B5:080C:000D:8573
 * @implements B4B5:0819:0012:21EC
 * @implements B4B5:082B:0054:FF92
 * @implements B4B5:0874:000B:414C
 * @implements B4B5:087F:0012:EF6E
 * @implements B4B5:0885:000C:20A7
 * @implements B4B5:0891:000B:6148
 * @implements B4B5:089C:0040:4310
 * @implements B4B5:08DC:0006:F794
 * @implements B4B5:08E2:000C:1037
 * @implements B4B5:08EE:000F:40EC
 * @implements B4B5:08FD:001C:78CD
 * @implements B4B5:0919:0012:1539
 * @implements B4B5:092B:0008:1A88
 * @implements B4B5:0933:0011:0D29
 * @implements B4B5:0944:0026:F5B1
 * @implements B4B5:096A:0013:2B96
 * @implements B4B5:097D:000A:882F
 * @implements B4B5:0987:0022:7AC5
 * @implements B4B5:09A9:000A:882F
 * @implements B4B5:09B3:0087:69AC
 * @implements B4B5:0A2F:000B:714A
 * @implements B4B5:0A3A:0012:0C4A
 * @implements B4B5:0A40:000C:A383
 * @implements B4B5:0A4C:0024:5A64
 * @implements B4B5:0A70:0013:2BE2
 * @implements B4B5:0A83:0013:90D2
 * @implements B4B5:0A96:000B:0225
 * @implements B4B5:0AA1:003E:17EA
 * @implements B4B5:0ADF:0035:0FCE
 * @implements B4B5:0AE8:002C:F21C
 * @implements B4B5:0AF0:0024:1264
 * @implements B4B5:0B14:0013:2BE2
 * @implements B4B5:0B27:0013:91B2
 * @implements B4B5:0B3A:000B:0225
 * @implements B4B5:0B45:000E:A2FD
 * @implements B4B5:0B53:002F:AC2C
 * @implements B4B5:0B72:0010:86F3
 * @implements B4B5:0B82:0035:DFC7
 * @implements B4B5:0B8B:002C:2215
 * @implements B4B5:0B93:0024:C265
 * @implements B4B5:0BB7:0013:2BE2
 * @implements B4B5:0BCA:0013:9072
 * @implements B4B5:0BDD:000B:0225
 * @implements B4B5:0BE8:003F:FEF1
 * @implements B4B5:0C27:001C:5A2C
 * @implements B4B5:0C30:0013:A189
 * @implements B4B5:0C38:000B:6148
 * @implements B4B5:0C43:001B:A229
 * @implements B4B5:0C5E:003E:84AE
 * @implements B4B5:0C6E:002E:3B47
 * @implements B4B5:0C9C:0006:F7AB
 * @implements B4B5:0CA2:000B:3223
 * @implements B4B5:0CAD:002A:1E0E
 * @implements B4B5:0CD7:0013:2B96
 * @implements B4B5:0CEA:000A:3572
 * @implements B4B5:0CF4:000C:97DE
 * @implements B4B5:0D00:0010:8687
 * @implements B4B5:0D10:000A:B659
 * @implements B4B5:0D1A:000E:D0D2
 * @implements B4B5:0D28:0018:8BBA
 * @implements B4B5:0D40:0014:D927
 * @implements B4B5:0D54:0023:4ECB
 * @implements B4B5:0D77:000A:FBE7
 * @implements B4B5:0D81:000E:548A
 * @implements B4B5:0D8F:002E:8780
 * @implements B4B5:0DBD:000A:882F
 * @implements B4B5:0DC7:0027:5285
 * @implements B4B5:0DEE:0014:EB62
 * @implements B4B5:0E02:003C:C4FF
 * @implements B4B5:0E33:000B:414C
 * @implements B4B5:0E3E:0012:6F7B
 * @implements B4B5:0E44:000C:A0B2
 * @implements B4B5:0E50:000B:6148
 * @implements B4B5:0E5B:003D:8F07
 * @implements B4B5:0E98:0006:373C
 * @implements B4B5:0E9E:0026:D6B3
 * @implements B4B5:0EC4:0013:2B96
 * @implements B4B5:0ED7:000A:3572
 * @implements B4B5:0EE1:000C:1773
 * @implements B4B5:0EED:0010:8687
 * @implements B4B5:0EFD:000A:257A
 * @implements B4B5:0F07:001B:3B64
 * @implements B4B5:0F22:000A:457E
 * @implements B4B5:0F2C:001B:0EE0
 * @implements B4B5:0F47:000A:882F
 * @implements B4B5:0F51:0015:FC7B
 * @implements B4B5:0F66:000A:882F
 * @implements B4B5:0F70:0017:CB04
 * @implements B4B5:0F87:000E:53E0
 * @implements B4B5:0F8A:000B:714A
 * @implements B4B5:0F95:0012:4C52
 * @implements B4B5:0F9B:000C:E39B
 * @implements B4B5:0FA7:000B:6148
 * @implements B4B5:0FB2:003D:8907
 * @implements B4B5:0FEF:0005:B26E
 * @implements B4B5:0FF4:000B:3C53
 * @implements B4B5:0FFF:002F:9FB4
 * @implements B4B5:102E:000E:3FBC
 * @implements B4B5:103C:001B:6488
 * @implements B4B5:104C:000B:714A
 * @implements B4B5:1057:0023:53D1
 * @implements B4B5:105D:001D:B706
 * @implements B4B5:107A:0006:F7CE
 *
 * @define 01F7:3A8A:0018:E4EE
 * @define 01F7:3AF8:001D:A439
 * @define 104B:024D:0012:1DC4
 * @define 1381:0096:0008:1ADC
 * @define 1381:00D0:0008:1ADC
 */
void emu_Scenario_Load()
{
	uint8 houseID;
	uint16 scenarioID;

l__0000:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_sp -= 162;

	houseID    = emu_get_memory16(emu_ss, emu_bp,  0x8);
	scenarioID = emu_get_memory16(emu_ss, emu_bp,  0x6);

	emu_push(emu_si);
	emu_push(emu_di);

	if (houseID >= HOUSE_MAX) goto exitError;
	goto l__0014;

exitError:
	emu_ax = 0;
	goto exit;

l__0014:
	g_global->scenarioID = scenarioID;

	/* Generate scenario filename */
	sprintf((char *)&emu_get_memory8(emu_ss, emu_bp, -0x22), g_global->string_scenario_file, emu_get_memorycsip(g_houseInfo[houseID].name)[0], scenarioID);

	/* Open the file, which can be hiding in a PAK file */
	emu_push(emu_ss); emu_push(emu_bp - 0x22);
	emu_push(emu_cs); emu_push(0x0059); emu_cs = 0x1FB5; f__1FB5_15B5_0015_6A00();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	/* Couldn't find the file, or failed opening it */
	if (emu_ax == 0) goto exitError;

	/* Clear the buffer we will read in */
	memset(emu_get_memorycsip(g_global->readBuffer), 0, g_global->readBufferSize);

	/* Read the file into the buffer */
	emu_push(g_global->readBufferCount);
	emu_push(g_global->readBufferSize);
	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_ss); emu_push(emu_bp - 0x22);
	emu_push(emu_cs); emu_push(0x0090); emu_cs = 0x253D; f__253D_0000_0013_38F4();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0xC;

	memset(&g_global->scenario, 0, sizeof(Scenario));
	g_global->scenario.variable_0000 = 0x290;

	emu_Scenario_Load_General();

	emu_push(emu_cs); emu_push(0x0207); emu_cs = 0x34B8; overlay(0x34B8, 0); f__B4B8_0D23_0010_BA99();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }

	emu_push(g_global->scenario.mapSeed >> 16); emu_push(g_global->scenario.mapSeed & 0xFFF);
	emu_push(emu_cs); emu_push(0x0214); emu_cs = 0x34B8; overlay(0x34B8, 0); f__B4B8_0000_001F_3BC3();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;

	for (houseID = 0; houseID < HOUSE_MAX; houseID++) {
		emu_Scenario_Load_House(houseID);
	}

	{
		House *ph = House_Get_ByMemory(g_global->playerHouse);
		/* In case there was no unitCountMax in the scenario, calculate
		 *  it based on values used for the AI controlled houses. */
		if (ph->unitCountMax == 0) {
			PoolFindStruct find;
			uint8 max;
			House *h;

			find.houseID = 0xFFFF;
			find.index   = 0xFFFF;
			find.type    = 0xFFFF;

			max = 80;
			while ((h = House_Find(&find)) != NULL) {
				/* Skip the human controlled house */
				if ((h->flags & 0x0002) != 0) continue;
				max -= h->unitCountMax;
			}

			ph->unitCountMax = max;
		}
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_cs); emu_push(0x03AB); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax + 2;

	emu_get_memory16(emu_ss, emu_bp, -0xA) = g_global->readBuffer.s.cs;
	emu_get_memory16(emu_ss, emu_bp, -0xC) = g_global->readBuffer.s.ip + emu_get_memory16(emu_ss, emu_bp, -0x10);

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->readBufferSize - emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(0); emu_push(0);
	emu_push(0); emu_push(0);
	emu_push(emu_ds); emu_push(0x1F7B); /* UNITS */
	emu_push(emu_cs); emu_push(0x03EB); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	while (true) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0xC));
		if (emu_get_memory8(emu_es, emu_bx, 0x0) == 0x0) break;

		emu_Scenario_Load_Units();

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
		emu_push(emu_cs); emu_push(0x0632); emu_cs = 0x01F7; emu_String_strlen();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_get_memory16(emu_ss, emu_bp, -0xC) += emu_ax + 1;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_cs); emu_push(0x064F); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax + 2;

	emu_get_memory16(emu_ss, emu_bp, -0xA) = g_global->readBuffer.s.cs;
	emu_get_memory16(emu_ss, emu_bp, -0xC) = g_global->readBuffer.s.ip + emu_get_memory16(emu_ss, emu_bp, -0x10);

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->readBufferSize - emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(0); emu_push(0);
	emu_push(0); emu_push(0);
	emu_push(emu_ds); emu_push(0x1F87); /* STRUCTURES */
	emu_push(emu_cs); emu_push(0x068F); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	while (true) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0xC));
		if (emu_get_memory8(emu_es, emu_bx, 0x0) == 0x0) break;

		emu_Scenario_Load_Structures();

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
		emu_push(emu_cs); emu_push(0x0632); emu_cs = 0x01F7; emu_String_strlen();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_get_memory16(emu_ss, emu_bp, -0xC) += emu_ax + 1;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_cs); emu_push(0x089C); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_ax + 2;

	emu_get_memory16(emu_ss, emu_bp, -0x6) = g_global->readBuffer.s.cs;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = g_global->readBuffer.s.ip + emu_get_memory16(emu_ss, emu_bp, -0xE);

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->readBufferSize - emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(0); emu_push(0);
	emu_push(0); emu_push(0);
	emu_push(emu_ds); emu_push(0x1EDA);/* MAP */
	emu_push(emu_cs); emu_push(0x08DC); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	while (true) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
		if (emu_get_memory8(emu_es, emu_bx, 0x0) == 0x0) break;

		emu_Scenario_Load_Map();

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x0A3A); emu_cs = 0x01F7; emu_String_strlen();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_get_memory16(emu_ss, emu_bp, -0x8) += emu_ax + 1;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_ds); emu_push(0x1EC0); /* \0 */
	emu_push(emu_ds); emu_push(0x1F96); /* Bloom */
	emu_push(emu_ds); emu_push(0x1EDA); /* MAP */
	emu_push(emu_cs); emu_push(0x0A70); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F9C); /* ,\n */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0A83); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;

	while (emu_ax != 0 || emu_dx != 0) {
		uint16 position;

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x0AA1); emu_cs = 0x01F7; emu_String_ToInteger();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;
		position = emu_ax;

		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
		emu_bx += position * 4;

		emu_get_memory16(emu_es, emu_bx, 0x0) &= 0xFE00;
		emu_get_memory16(emu_es, emu_bx, 0x0) |= g_global->variable_39F4 & 0x01FF;

		emu_bx = position * 2;
		emu_get_memory16(0x2E9C, emu_bx, 0x323F) |= 0x8000;

		emu_push(emu_ds); emu_push(0x1F9C); /* ,\n */
		emu_push(0); emu_push(0);
		emu_push(emu_cs); emu_push(0x0ADF); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 8;
		emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
		emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;
	}

	emu_push(g_global->readBuffer.s.cs);
	emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_ds); emu_push(0x1EC0); /* \0 */
	emu_push(emu_ds); emu_push(0x1F9F); /* Field */
	emu_push(emu_ds); emu_push(0x1EDA); /* MAP */
	emu_push(emu_cs); emu_push(0x0B14); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F9C); /* ,\n */
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0B27); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x8;
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;

	while (emu_ax != 0 || emu_dx != 0) {
		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x0B45); emu_cs = 0x01F7; emu_String_ToInteger();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_di = emu_ax;
		emu_push(0xFFFF);
		emu_push(emu_di);
		emu_push(emu_cs); emu_push(0x0B53); emu_cs = 0x34CD; overlay(0x34CD, 0); f__B4CD_14CA_0013_F579();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		if (g_global->variable_37A0 != 0) {
			emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
			emu_bx += emu_di * 4;
			emu_get_memory16(emu_es, emu_bx, 0x0) &= 0xFE00;
			emu_get_memory16(emu_es, emu_bx, 0x0) |= 0x01FF;
		}

		emu_push(emu_ds); emu_push(0x1F9C); /* ,\n */
		emu_push(0); emu_push(0);
		emu_push(emu_cs); emu_push(0x0B82); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 8;
		emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
		emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(0x7F);
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_ds); emu_push(0x1EC0); /* \0 */
	emu_push(emu_ds); emu_push(0x1FA5); /* Special */
	emu_push(emu_ds); emu_push(0x1EDA); /* MAP */
	emu_push(emu_cs); emu_push(0x0BB7); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	emu_push(emu_ds); emu_push(0x1F9C); /* ,\n*/
	emu_push(emu_ss); emu_push(emu_bp - 0xA2);
	emu_push(emu_cs); emu_push(0x0BCA); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 8;
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;

	while (emu_ax != 0 || emu_dx != 0) {
		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x0BE8); emu_cs = 0x01F7; emu_String_ToInteger();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;
		emu_di = emu_ax;

		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
		emu_bx += emu_di * 4;
		emu_get_memory16(emu_es, emu_bx, 0x0) &= 0xFE00;
		emu_get_memory16(emu_es, emu_bx, 0x0) |= (g_global->variable_39F4 + 1) & 0x01FF;

		emu_bx = emu_di * 2;
		emu_get_memory16(0x2E9C, emu_bx, 0x323F) |= 0x8000;

		emu_push(emu_ds); emu_push(0x1F9C); /* ,\n */
		emu_push(0); emu_push(0);
		emu_push(emu_cs); emu_push(0x0C27); emu_cs = 0x01F7; f__01F7_3AF8_001D_A439();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 8;
		emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_dx;
		emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_cs); emu_push(0x0C43); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax + 2;

	emu_get_memory16(emu_ss, emu_bp, -0xA) = g_global->readBuffer.s.cs;
	emu_get_memory16(emu_ss, emu_bp, -0xC) = g_global->readBuffer.s.ip + emu_get_memory16(emu_ss, emu_bp, -0x10);

	for (emu_si = 0; emu_si < 16; emu_si ++) {
		g_global->scenario.reinforcement[emu_si].unitID = 0xFFFF;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->readBufferSize - emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(0); emu_push(0);
	emu_push(0); emu_push(0);
	emu_push(emu_ds); emu_push(0x1FAD); /* REINFORCEMENTS */
	emu_push(emu_cs); emu_push(0x0C9C); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	while (true) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0xC));
		if (emu_get_memory8(emu_es, emu_bx, 0x0) == 0x0) break;

		emu_Scenario_Load_Reinforcements();

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
		emu_push(emu_cs); emu_push(0x0E3E); emu_cs = 0x01F7; emu_String_strlen();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_get_memory16(emu_ss, emu_bp, -0xC) += emu_ax + 1;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_cs); emu_push(0x0E5B); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_di = emu_ax + 2;

	emu_get_memory16(emu_ss, emu_bp, -0x6) = g_global->readBuffer.s.cs;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = g_global->readBuffer.s.ip + emu_di;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->readBufferSize - emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(0); emu_push(0);
	emu_push(0); emu_push(0);
	emu_push(emu_ds); emu_push(0x1FF9); /* TEAMS */
	emu_push(emu_cs); emu_push(0x0E98); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	while (true) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
		if (emu_get_memory8(emu_es, emu_bx, 0x0) == 0x0) break;

		emu_Scenario_Load_Teams();

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x0F95); emu_cs = 0x01F7; emu_String_strlen();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_get_memory16(emu_ss, emu_bp, -0x8) += emu_ax + 1;
	}

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(emu_cs); emu_push(0x0FB2); emu_cs = 0x01F7; emu_String_strlen();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 4;
	emu_di = emu_ax + 2;

	emu_get_memory16(emu_ss, emu_bp, -0x6) = g_global->readBuffer.s.cs;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = g_global->readBuffer.s.ip + emu_di;

	emu_push(g_global->readBuffer.s.cs); emu_push(g_global->readBuffer.s.ip);
	emu_push(g_global->readBufferSize - emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(0); emu_push(0);
	emu_push(0); emu_push(0);
	emu_push(emu_ds); emu_push(emu_ax); /* CHOAM */
	emu_push(emu_cs); emu_push(0x0FEF); emu_cs = 0x34FC; overlay(0x34FC, 0); emu_Ini_GetString();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
	emu_sp += 0x16;

	while (true) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x8));
		if (emu_get_memory8(emu_es, emu_bx, 0x0) == 0x0) break;

		emu_Scenario_Load_Choam();

		emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6)); emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
		emu_push(emu_cs); emu_push(0x1057); emu_cs = 0x01F7; emu_String_strlen();
		/* Check if this overlay should be reloaded */
		if (emu_cs == 0x34B5) { overlay(0x34B5, 1); }
		emu_sp += 4;

		emu_get_memory16(emu_ss, emu_bp, -0x8) += emu_ax + 1;
	}

	g_global->variable_38AC.csip = g_global->variable_76B0.csip;
	emu_ax = 0x1;

exit:
	emu_pop(&emu_di);
	emu_pop(&emu_si);
	emu_sp = emu_bp;
	emu_pop(&emu_bp);

	/* Return from this function */
	emu_pop(&emu_ip);
	emu_pop(&emu_cs);
}