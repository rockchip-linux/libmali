/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from Rockchip.
 * Copyright (c) 2017 FUZHOU ROCKCHIP ELECTRONICS CO., LTD. ("Rockchip").
 * 	http://www.rock-chips.com
 * 		ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from Rockchip.
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif

#ifndef _MISYNC_H_
#define _MISYNC_H_

typedef struct _SyncFence SyncFence;
typedef struct _SyncTrigger SyncTrigger;

typedef void (*SyncScreenCreateFenceFunc) (ScreenPtr pScreen,
                                           SyncFence * pFence,
                                           Bool initially_triggered);
typedef void (*SyncScreenDestroyFenceFunc) (ScreenPtr pScreen,
                                            SyncFence * pFence);

typedef struct _syncScreenFuncs {
    SyncScreenCreateFenceFunc CreateFence;
    SyncScreenDestroyFenceFunc DestroyFence;
} SyncScreenFuncsRec, *SyncScreenFuncsPtr;


extern _X_EXPORT void
miSyncScreenCreateFence(ScreenPtr pScreen, SyncFence * pFence,
                        Bool initially_triggered);
extern _X_EXPORT void
 miSyncScreenDestroyFence(ScreenPtr pScreen, SyncFence * pFence);

typedef void (*SyncFenceSetTriggeredFunc) (SyncFence * pFence);
typedef void (*SyncFenceResetFunc) (SyncFence * pFence);
typedef Bool (*SyncFenceCheckTriggeredFunc) (SyncFence * pFence);
typedef void (*SyncFenceAddTriggerFunc) (SyncTrigger * pTrigger);
typedef void (*SyncFenceDeleteTriggerFunc) (SyncTrigger * pTrigger);

typedef struct _syncFenceFuncs {
    SyncFenceSetTriggeredFunc SetTriggered;
    SyncFenceResetFunc Reset;
    SyncFenceCheckTriggeredFunc CheckTriggered;
    SyncFenceAddTriggerFunc AddTrigger;
    SyncFenceDeleteTriggerFunc DeleteTrigger;
} SyncFenceFuncsRec, *SyncFenceFuncsPtr;

extern _X_EXPORT void

miSyncInitFence(ScreenPtr pScreen, SyncFence * pFence,
                Bool initially_triggered);
extern _X_EXPORT void
 miSyncDestroyFence(SyncFence * pFence);
extern _X_EXPORT void
 miSyncTriggerFence(SyncFence * pFence);

extern _X_EXPORT SyncScreenFuncsPtr miSyncGetScreenFuncs(ScreenPtr pScreen);
extern _X_EXPORT Bool
 miSyncSetup(ScreenPtr pScreen);

Bool
miSyncFenceCheckTriggered(SyncFence * pFence);

void
miSyncFenceSetTriggered(SyncFence * pFence);

void
miSyncFenceReset(SyncFence * pFence);

void
miSyncFenceAddTrigger(SyncTrigger * pTrigger);

void
miSyncFenceDeleteTrigger(SyncTrigger * pTrigger);

int
miSyncInitFenceFromFD(DrawablePtr pDraw, SyncFence *pFence, int fd, BOOL initially_triggered);

int
miSyncFDFromFence(DrawablePtr pDraw, SyncFence *pFence);

#endif                          /* _MISYNC_H_ */
