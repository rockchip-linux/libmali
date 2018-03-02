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

#ifndef _XF86MODES_H_
#define _XF86MODES_H_

#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "xf86.h"
#include "xorgVersion.h"
#include "edid.h"
#include "xf86Parser.h"

extern _X_EXPORT double xf86ModeHSync(const DisplayModeRec * mode);
extern _X_EXPORT double xf86ModeVRefresh(const DisplayModeRec * mode);
extern _X_EXPORT unsigned int xf86ModeBandwidth(DisplayModePtr mode, int depth);

extern _X_EXPORT int
 xf86ModeWidth(const DisplayModeRec * mode, Rotation rotation);

extern _X_EXPORT int
 xf86ModeHeight(const DisplayModeRec * mode, Rotation rotation);

extern _X_EXPORT DisplayModePtr xf86DuplicateMode(const DisplayModeRec * pMode);
extern _X_EXPORT DisplayModePtr xf86DuplicateModes(ScrnInfoPtr pScrn,
                                                   DisplayModePtr modeList);
extern _X_EXPORT void xf86SetModeDefaultName(DisplayModePtr mode);
extern _X_EXPORT void xf86SetModeCrtc(DisplayModePtr p, int adjustFlags);
extern _X_EXPORT Bool xf86ModesEqual(const DisplayModeRec * pMode1,
                                     const DisplayModeRec * pMode2);
extern _X_EXPORT void xf86PrintModeline(int scrnIndex, DisplayModePtr mode);
extern _X_EXPORT DisplayModePtr xf86ModesAdd(DisplayModePtr modes,
                                             DisplayModePtr new);

extern _X_EXPORT DisplayModePtr xf86DDCGetModes(int scrnIndex, xf86MonPtr DDC);
extern _X_EXPORT DisplayModePtr xf86CVTMode(int HDisplay, int VDisplay,
                                            float VRefresh, Bool Reduced,
                                            Bool Interlaced);
extern _X_EXPORT DisplayModePtr xf86GTFMode(int h_pixels, int v_lines,
                                            float freq, int interlaced,
                                            int margins);

extern _X_EXPORT Bool
 xf86ModeIsReduced(const DisplayModeRec * mode);

extern _X_EXPORT void
 xf86ValidateModesFlags(ScrnInfoPtr pScrn, DisplayModePtr modeList, int flags);

extern _X_EXPORT void

xf86ValidateModesClocks(ScrnInfoPtr pScrn, DisplayModePtr modeList,
                        int *min, int *max, int n_ranges);

extern _X_EXPORT void

xf86ValidateModesSize(ScrnInfoPtr pScrn, DisplayModePtr modeList,
                      int maxX, int maxY, int maxPitch);

extern _X_EXPORT void
 xf86ValidateModesSync(ScrnInfoPtr pScrn, DisplayModePtr modeList, MonPtr mon);

extern _X_EXPORT void

xf86ValidateModesBandwidth(ScrnInfoPtr pScrn, DisplayModePtr modeList,
                           unsigned int bandwidth, int depth);

extern _X_EXPORT void
 xf86ValidateModesReducedBlanking(ScrnInfoPtr pScrn, DisplayModePtr modeList);

extern _X_EXPORT void

xf86PruneInvalidModes(ScrnInfoPtr pScrn, DisplayModePtr * modeList,
                      Bool verbose);

extern _X_EXPORT DisplayModePtr xf86PruneDuplicateModes(DisplayModePtr modes);

extern _X_EXPORT void
 xf86ValidateModesUserConfig(ScrnInfoPtr pScrn, DisplayModePtr modeList);

extern _X_EXPORT DisplayModePtr
xf86GetMonitorModes(ScrnInfoPtr pScrn, XF86ConfMonitorPtr conf_monitor);

extern _X_EXPORT DisplayModePtr xf86GetDefaultModes(void);

extern _X_EXPORT void
xf86SaveModeContents(DisplayModePtr intern, const DisplayModeRec *mode);

extern _X_EXPORT void
 xf86DDCApplyQuirks(int scrnIndex, xf86MonPtr DDC);

#endif                          /* _XF86MODES_H_ */
