
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

#ifndef _XF86FBMAN_H
#define _XF86FBMAN_H

#include "scrnintstr.h"
#include "regionstr.h"

#define FAVOR_AREA_THEN_WIDTH		0
#define FAVOR_AREA_THEN_HEIGHT		1
#define FAVOR_WIDTH_THEN_AREA		2
#define FAVOR_HEIGHT_THEN_AREA		3

#define PRIORITY_LOW			0
#define PRIORITY_NORMAL			1
#define PRIORITY_EXTREME		2

typedef struct _FBArea {
    ScreenPtr pScreen;
    BoxRec box;
    int granularity;
    void (*MoveAreaCallback) (struct _FBArea *, struct _FBArea *);
    void (*RemoveAreaCallback) (struct _FBArea *);
    DevUnion devPrivate;
} FBArea, *FBAreaPtr;

typedef struct _FBLinear {
    ScreenPtr pScreen;
    int size;
    int offset;
    int granularity;
    void (*MoveLinearCallback) (struct _FBLinear *, struct _FBLinear *);
    void (*RemoveLinearCallback) (struct _FBLinear *);
    DevUnion devPrivate;
} FBLinear, *FBLinearPtr;

typedef void (*FreeBoxCallbackProcPtr) (ScreenPtr, RegionPtr, void *);
typedef void (*MoveAreaCallbackProcPtr) (FBAreaPtr, FBAreaPtr);
typedef void (*RemoveAreaCallbackProcPtr) (FBAreaPtr);

typedef void (*MoveLinearCallbackProcPtr) (FBLinearPtr, FBLinearPtr);
typedef void (*RemoveLinearCallbackProcPtr) (FBLinearPtr);

typedef struct {
    FBAreaPtr(*AllocateOffscreenArea) (ScreenPtr pScreen,
                                       int w, int h,
                                       int granularity,
                                       MoveAreaCallbackProcPtr moveCB,
                                       RemoveAreaCallbackProcPtr removeCB,
                                       void *privData);
    void (*FreeOffscreenArea) (FBAreaPtr area);
    Bool (*ResizeOffscreenArea) (FBAreaPtr area, int w, int h);
    Bool (*QueryLargestOffscreenArea) (ScreenPtr pScreen,
                                       int *width, int *height,
                                       int granularity,
                                       int preferences, int priority);
    Bool (*RegisterFreeBoxCallback) (ScreenPtr pScreen,
                                     FreeBoxCallbackProcPtr FreeBoxCallback,
                                     void *devPriv);
/* linear functions */
     FBLinearPtr(*AllocateOffscreenLinear) (ScreenPtr pScreen,
                                            int size,
                                            int granularity,
                                            MoveLinearCallbackProcPtr moveCB,
                                            RemoveLinearCallbackProcPtr
                                            removeCB, void *privData);
    void (*FreeOffscreenLinear) (FBLinearPtr area);
    Bool (*ResizeOffscreenLinear) (FBLinearPtr area, int size);
    Bool (*QueryLargestOffscreenLinear) (ScreenPtr pScreen,
                                         int *size,
                                         int granularity, int priority);
    Bool (*PurgeOffscreenAreas) (ScreenPtr);
} FBManagerFuncs, *FBManagerFuncsPtr;

extern _X_EXPORT Bool xf86RegisterOffscreenManager(ScreenPtr pScreen,
                                                   FBManagerFuncsPtr funcs);

extern _X_EXPORT Bool
 xf86InitFBManagerRegion(ScreenPtr pScreen, RegionPtr ScreenRegion);

extern _X_EXPORT Bool
 xf86InitFBManagerArea(ScreenPtr pScreen, int PixalArea, int Verbosity);

extern _X_EXPORT Bool
 xf86InitFBManager(ScreenPtr pScreen, BoxPtr FullBox);

extern _X_EXPORT Bool
 xf86InitFBManagerLinear(ScreenPtr pScreen, int offset, int size);

extern _X_EXPORT Bool
 xf86FBManagerRunning(ScreenPtr pScreen);

extern _X_EXPORT FBAreaPtr
xf86AllocateOffscreenArea(ScreenPtr pScreen,
                          int w, int h,
                          int granularity,
                          MoveAreaCallbackProcPtr moveCB,
                          RemoveAreaCallbackProcPtr removeCB, void *privData);

extern _X_EXPORT FBAreaPtr
xf86AllocateLinearOffscreenArea(ScreenPtr pScreen,
                                int length,
                                int granularity,
                                MoveAreaCallbackProcPtr moveCB,
                                RemoveAreaCallbackProcPtr removeCB,
                                void *privData);

extern _X_EXPORT FBLinearPtr
xf86AllocateOffscreenLinear(ScreenPtr pScreen,
                            int length,
                            int granularity,
                            MoveLinearCallbackProcPtr moveCB,
                            RemoveLinearCallbackProcPtr removeCB,
                            void *privData);

extern _X_EXPORT void xf86FreeOffscreenArea(FBAreaPtr area);
extern _X_EXPORT void xf86FreeOffscreenLinear(FBLinearPtr area);

extern _X_EXPORT Bool
 xf86ResizeOffscreenArea(FBAreaPtr resize, int w, int h);

extern _X_EXPORT Bool
 xf86ResizeOffscreenLinear(FBLinearPtr resize, int size);

extern _X_EXPORT Bool

xf86RegisterFreeBoxCallback(ScreenPtr pScreen,
                            FreeBoxCallbackProcPtr FreeBoxCallback,
                            void *devPriv);

extern _X_EXPORT Bool
 xf86PurgeUnlockedOffscreenAreas(ScreenPtr pScreen);

extern _X_EXPORT Bool

xf86QueryLargestOffscreenArea(ScreenPtr pScreen,
                              int *width, int *height,
                              int granularity, int preferences, int priority);

extern _X_EXPORT Bool

xf86QueryLargestOffscreenLinear(ScreenPtr pScreen,
                                int *size, int granularity, int priority);

#endif                          /* _XF86FBMAN_H */
