
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

#ifndef _XF86XVPRIV_H_
#define _XF86XVPRIV_H_

#include "xf86xv.h"
#include "privates.h"

/*** These are DDX layer privates ***/

extern _X_EXPORT DevPrivateKey XF86XvScreenKey;

typedef struct {
    DestroyWindowProcPtr DestroyWindow;
    ClipNotifyProcPtr ClipNotify;
    WindowExposuresProcPtr WindowExposures;
    PostValidateTreeProcPtr PostValidateTree;
    void (*AdjustFrame) (ScrnInfoPtr, int, int);
    Bool (*EnterVT) (ScrnInfoPtr);
    void (*LeaveVT) (ScrnInfoPtr);
    xf86ModeSetProc *ModeSet;
    CloseScreenProcPtr CloseScreen;
} XF86XVScreenRec, *XF86XVScreenPtr;

typedef struct {
    int flags;
    PutVideoFuncPtr PutVideo;
    PutStillFuncPtr PutStill;
    GetVideoFuncPtr GetVideo;
    GetStillFuncPtr GetStill;
    StopVideoFuncPtr StopVideo;
    SetPortAttributeFuncPtr SetPortAttribute;
    GetPortAttributeFuncPtr GetPortAttribute;
    QueryBestSizeFuncPtr QueryBestSize;
    PutImageFuncPtr PutImage;
    ReputImageFuncPtr ReputImage;
    QueryImageAttributesFuncPtr QueryImageAttributes;
} XvAdaptorRecPrivate, *XvAdaptorRecPrivatePtr;

typedef struct {
    ScrnInfoPtr pScrn;
    DrawablePtr pDraw;
    unsigned char type;
    unsigned int subWindowMode;
    RegionPtr clientClip;
    RegionPtr ckeyFilled;
    RegionPtr pCompositeClip;
    Bool FreeCompositeClip;
    XvAdaptorRecPrivatePtr AdaptorRec;
    XvStatus isOn;
    Bool clipChanged;
    int vid_x, vid_y, vid_w, vid_h;
    int drw_x, drw_y, drw_w, drw_h;
    DevUnion DevPriv;
} XvPortRecPrivate, *XvPortRecPrivatePtr;

typedef struct _XF86XVWindowRec {
    XvPortRecPrivatePtr PortRec;
    struct _XF86XVWindowRec *next;
} XF86XVWindowRec, *XF86XVWindowPtr;

#endif                          /* _XF86XVPRIV_H_ */
