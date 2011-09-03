/* $Id$ */

/** @file src/gui/font.c Font routines. */

#include <stdlib.h>
#include "types.h"

#include "font.h"

#include "../config.h"
#include "../file.h"
#include "../opendune.h"

void *g_fontIntro = NULL;
void *g_fontNew6p = NULL;
void *g_fontNew8p = NULL;

uint16 g_var_6C70;
uint8 g_var_6C71;
int8 g_fontCharOffset = -1;

FontHeader *g_fontCurrent = NULL;

/**
 * Get the width of a char in pixels.
 *
 * @param c The char to get the width of.
 * @return The width of the char in pixels.
 */
uint16 Font_GetCharWidth(char c)
{
	uint16 width;

	width = *((uint8 *)g_fontCurrent + g_fontCurrent->widthOffset + c);
	return width + g_fontCharOffset;
}

/**
 * Get the width of the string in pixels.
 *
 * @param string The string to get the width of.
 * @return The width of the string in pixels.
 */
uint16 Font_GetStringWidth(char *string)
{
	uint16 width = 0;

	if (string == NULL) return 0;

	while (*string != '\0') {
		width += Font_GetCharWidth(*string++);
	}

	return width;
}

/**
 * Load a font file.
 *
 * @param filename The name of the font file.
 * @return The pointer of the allocated memory where the file has been read.
 */
void *Font_LoadFile(const char *filename)
{
	uint8 index;
	uint16 length;
	uint8 *buf;

	if (!File_Exists(filename)) return NULL;

	index = File_Open(filename, 1);

	if (File_Read(index, &length, 2) != 2) {
		File_Close(index);
		return NULL;
	}

	buf = malloc(length);

	*(uint16 *)buf = length;

	File_Read(index, buf + 2, length - 2);
	File_Close(index);

	if (buf[2] != 0 || buf[3] != 5) {
		free(buf);
		return NULL;
	}

	return buf;
}

/**
 * Select a font.
 *
 * @param font The pointer of the font to use.
 */
void Font_Select(void *font)
{
	FontHeader *f = (FontHeader *)font;

	if (f == NULL) return;

	g_fontCurrent = f;

	g_var_6C71 = ((uint8 *)f + f->heightOffset)[4];
	g_var_6C70 = ((uint8 *)f + f->heightOffset)[5];
}

bool Font_Init()
{
	g_fontIntro = Font_LoadFile("INTRO.FNT");
	g_fontNew6p = Font_LoadFile((g_config.language == LANGUAGE_GERMAN) ? "new6pg.fnt" : "new6p.fnt");
	g_fontNew8p = Font_LoadFile("new8p.fnt");

	return g_fontNew8p != NULL;
}

void Font_Uninit()
{
	free(g_fontIntro); g_fontIntro = NULL;
	free(g_fontNew6p); g_fontNew6p = NULL;
	free(g_fontNew8p); g_fontNew8p = NULL;
}
