/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file engine_arrays.h
 *     Header file for engine_arrays.c.
 * @par Purpose:
 *     Helper arrays for the engine.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   Tomasz Lis
 * @date     02 Apr 2010 - 06 Nov 2010
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/

#ifndef DK_ENGNARR_H
#define DK_ENGNARR_H

#include "bflib_basics.h"
#include "globals.h"

#define TD_ISO_POINTS        982
#define FLOOR_TO_CEILING_MAP_LEN 592
#define RANDOMISORS_LEN      512
#define RANDOMISORS_MASK   0x1ff
#define RANDOMISORS_RANGE     63

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************/
#pragma pack(1)

struct WibbleTable {
  long field_0;
  long field_4;
  long field_8;
  long field_C;
  long field_10;
  long field_14;
  long field_18;
  long field_1C;
};

#pragma pack()
/******************************************************************************/
DLLIMPORT long _DK_randomisors[512];
#define randomisors _DK_randomisors
DLLIMPORT struct WibbleTable _DK_wibble_table[128];
#define wibble_table _DK_wibble_table
DLLIMPORT extern unsigned short _DK_floor_to_ceiling_map[592];
DLLIMPORT extern long _DK_floor_height[256];
#define floor_height _DK_floor_height
DLLIMPORT extern long _DK_lintel_top_height[256];
#define lintel_top_height _DK_lintel_top_height
DLLIMPORT extern long _DK_lintel_bottom_height[256];
#define lintel_bottom_height _DK_lintel_bottom_height
/******************************************************************************/
extern unsigned short floor_to_ceiling_map[FLOOR_TO_CEILING_MAP_LEN];
/******************************************************************************/
long convert_td_iso(unsigned long n);
long straight_td_iso(unsigned long n);
long straight_iso_td(unsigned long n);

void init_iso_3d_conversion_tables(void);
void setup_3d(void);

TbBool load_ceiling_table(void);
void generate_wibble_table(void);
void fill_floor_heights_table(void);

/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif
