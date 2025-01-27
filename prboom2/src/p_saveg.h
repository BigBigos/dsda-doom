/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
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
 *      Savegame I/O, archiving, persistence.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __P_SAVEG__
#define __P_SAVEG__

#ifdef __GNUG__
#pragma interface
#endif

#include "doomtype.h"

/* Persistent storage/archiving.
 * These are the load / save game routines. */
void P_ArchivePlayers(void);
void P_UnArchivePlayers(void);
void P_ArchiveWorld(void);
void P_UnArchiveWorld(void);
void P_ThinkerToIndex(void); /* phares 9/13/98: save soundtarget in savegame */
void P_IndexToThinker(void); /* phares 9/13/98: save soundtarget in savegame */

/* 1/18/98 killough: add RNG info to savegame */
void P_ArchiveRNG(void);
void P_UnArchiveRNG(void);

/* 2/21/98 killough: add automap info to savegame */
void P_ArchiveMap(void);
void P_UnArchiveMap(void);

// dsda - fix save / load synchronization
void P_TrueArchiveThinkers(void);
void P_TrueUnArchiveThinkers(void);

extern byte *save_p;
void CheckSaveGame(size_t,const char*, int);              /* killough */
#define CheckSaveGame(a) (CheckSaveGame)(a, __FILE__, __LINE__)

// heretic

void P_ArchiveAmbientSound(void);
void P_UnArchiveAmbientSound(void);

// hexen

void P_ArchiveACS(void);
void P_UnArchiveACS(void);
void P_ArchivePolyobjs(void);
void P_UnArchivePolyobjs(void);
void P_ArchiveScripts(void);
void P_UnArchiveScripts(void);
void P_ArchiveSounds(void);
void P_UnArchiveSounds(void);
void P_ArchiveMisc(void);
void P_UnArchiveMisc(void);

#endif
