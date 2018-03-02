
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

#ifndef _XF86CMAP_H
#define _XF86CMAP_H

#include "xf86str.h"
#include "colormapst.h"

#define CMAP_PALETTED_TRUECOLOR		0x0000001
#define CMAP_RELOAD_ON_MODE_SWITCH	0x0000002
#define CMAP_LOAD_EVEN_IF_OFFSCREEN	0x0000004

extern _X_EXPORT Bool xf86HandleColormaps(ScreenPtr pScreen,
                                          int maxCol,
                                          int sigRGBbits,
                                          xf86LoadPaletteProc * loadPalette,
                                          xf86SetOverscanProc * setOverscan,
                                          unsigned int flags);

extern _X_EXPORT Bool xf86ColormapAllocatePrivates(ScrnInfoPtr pScrn);

extern _X_EXPORT int
 xf86ChangeGamma(ScreenPtr pScreen, Gamma newGamma);

extern _X_EXPORT int

xf86ChangeGammaRamp(ScreenPtr pScreen,
                    int size,
                    unsigned short *red,
                    unsigned short *green, unsigned short *blue);

extern _X_EXPORT int xf86GetGammaRampSize(ScreenPtr pScreen);

extern _X_EXPORT int

xf86GetGammaRamp(ScreenPtr pScreen,
                 int size,
                 unsigned short *red,
                 unsigned short *green, unsigned short *blue);

#endif                          /* _XF86CMAP_H */
