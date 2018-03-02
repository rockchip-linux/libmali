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

#ifndef __XF86VGAARBITER_H
#define __XF86VGAARBITER_H

#include "screenint.h"
#include "misc.h"
#include "xf86.h"

/* Functions */
extern void xf86VGAarbiterInit(void);
extern void xf86VGAarbiterFini(void);
void xf86VGAarbiterScrnInit(ScrnInfoPtr pScrn);
extern Bool xf86VGAarbiterWrapFunctions(void);
extern void xf86VGAarbiterLock(ScrnInfoPtr pScrn);
extern void xf86VGAarbiterUnlock(ScrnInfoPtr pScrn);

/* allow a driver to remove itself from arbiter - really should be
 * done in the kernel though */
extern _X_EXPORT void xf86VGAarbiterDeviceDecodes(ScrnInfoPtr pScrn, int rsrc);

/* DRI and arbiter are really not possible together,
 * you really want to remove the card from arbitration if you can */
extern _X_EXPORT Bool xf86VGAarbiterAllowDRI(ScreenPtr pScreen);

#endif                          /* __XF86VGAARBITER_H */
