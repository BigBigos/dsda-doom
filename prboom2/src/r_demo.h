/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze, Andrey Budko
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Demo stuff
 *
 *---------------------------------------------------------------------
 */

#ifndef __R_DEMO__
#define __R_DEMO__

#include "doomdef.h"
#include "doomtype.h"
#include "tables.h"
#include "d_player.h"
#include "w_wad.h"

//
// Smooth playing stuff
//

#define SMOOTH_PLAYING_MAXFACTOR 16

extern int demo_smoothturns;
extern int demo_smoothturnsfactor;

void R_SmoothPlaying_Reset(player_t *player);
void R_SmoothPlaying_Add(int delta);
angle_t R_SmoothPlaying_Get(player_t *player);
void R_ResetAfterTeleport(player_t *player);

//
// DemoEx stuff
//

typedef struct
{
  wadinfo_t header;
  filelump_t *lumps;
  char* data;
  int datasize;
} wadtbl_t;

typedef struct
{
  wadfile_info_t *wadfiles;
  size_t numwadfiles;
} waddata_t;

extern const char *demo_demoex_filename;

extern const char *getwad_cmdline;

int WadDataInit(waddata_t *waddata);
int WadDataAddItem(waddata_t *waddata, const char *filename, wad_source_t source, int handle);
void WadDataFree(waddata_t *wadfiles);

int CheckDemoExDemo(void);
void WadDataToWadFiles(waddata_t *waddata);

byte* G_GetDemoFooter(const char *filename, const byte **footer, size_t *size);
void G_SetDemoFooter(const char *filename, wadtbl_t *wadtbl);
void G_WriteDemoFooter(void);
void I_DemoExShutdown(void);

void R_DemoEx_WriteMLook(angle_t pitch);
angle_t R_DemoEx_ReadMLook(void);
void R_DemoEx_ResetMLook(void);

dboolean D_TryGetWad(const char* name);

int LoadDemo(const char *name, const byte **buffer, int *length, int *lump);

#endif // __R_DEMO__
