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

#ifndef __MIOVERLAY_H
#define __MIOVERLAY_H

typedef void (*miOverlayTransFunc) (ScreenPtr, int, BoxPtr);
typedef Bool (*miOverlayInOverlayFunc) (WindowPtr);

extern _X_EXPORT Bool

miInitOverlay(ScreenPtr pScreen,
              miOverlayInOverlayFunc inOverlay, miOverlayTransFunc trans);

extern _X_EXPORT Bool

miOverlayGetPrivateClips(WindowPtr pWin,
                         RegionPtr *borderClip, RegionPtr *clipList);

extern _X_EXPORT Bool miOverlayCollectUnderlayRegions(WindowPtr, RegionPtr *);
extern _X_EXPORT void miOverlayComputeCompositeClip(GCPtr, WindowPtr);
extern _X_EXPORT Bool miOverlayCopyUnderlay(ScreenPtr);
extern _X_EXPORT void miOverlaySetTransFunction(ScreenPtr, miOverlayTransFunc);
extern _X_EXPORT void miOverlaySetRootClip(ScreenPtr, Bool);

#endif                          /* __MIOVERLAY_H */
