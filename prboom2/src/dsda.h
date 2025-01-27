//
// Copyright(C) 2020 by Ryan Krafnick
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	DSDA Tools
//

#ifndef __DSDA__
#define __DSDA__

#include "doomdef.h"
#include "p_mobj.h"
#include "d_player.h"

typedef struct {
  int m, s, t;
} dsda_level_time_t;

typedef struct {
  int h, m, s;
} dsda_movie_time_t;

#define LINE_ACTIVATION_INDEX_MAX 8

void dsda_ReadCommandLine(void);
void dsda_DisplayNotifications(void);
void dsda_WatchCard(card_t card);
void dsda_WatchCrush(mobj_t* thing, int damage);
void dsda_WatchDamage(mobj_t* target, mobj_t* inflictor, mobj_t* source, int damage);
void dsda_WatchDeath(mobj_t* thing);
void dsda_WatchKill(player_t* player, mobj_t* target);
void dsda_WatchResurrection(mobj_t* target);
void dsda_WatchFailedSpawn(mobj_t* spawned);
void dsda_WatchMorph(mobj_t* morphed);
void dsda_WatchUnMorph(mobj_t* morphed);
void dsda_WatchSpawn(mobj_t* spawned);
void dsda_WatchIconSpawn(mobj_t* spawned);
void dsda_WatchCommand(void);
void dsda_WatchBeforeLevelSetup(void);
void dsda_WatchAfterLevelSetup(void);
void dsda_WatchNewLevel(void);
void dsda_WatchLevelCompletion(void);
void dsda_WatchWeaponFire(weapontype_t weapon);
void dsda_WatchSecret(void);
void dsda_WatchDeferredInitNew(skill_t skill, int episode, int map);
void dsda_WatchNewGame(void);
void dsda_WatchLevelReload(int* reloaded);
void dsda_WatchLineActivation(line_t* line, mobj_t* mo);
void dsda_WatchPTickCompleted(void);

dboolean dsda_ILComplete(void);
dboolean dsda_MovieComplete(void);
void dsda_DecomposeILTime(dsda_level_time_t* level_time);
void dsda_DecomposeMovieTime(dsda_movie_time_t* total_time);
int dsda_MaxKillRequirement(void);
int* dsda_PlayerActivatedLines(void);

int dsda_TurboScale(void);
int dsda_StartInBuildMode(void);

#endif
