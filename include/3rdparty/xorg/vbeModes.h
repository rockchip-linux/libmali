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

#ifndef _VBE_MODES_H

/*
 * This is intended to be stored in the DisplayModeRec's private area.
 * It includes all the information necessary to VBE information.
 */
typedef struct _VbeModeInfoData {
    int mode;
    VbeModeInfoBlock *data;
    VbeCRTCInfoBlock *block;
} VbeModeInfoData;

#define V_DEPTH_1	0x001
#define V_DEPTH_4	0x002
#define V_DEPTH_8	0x004
#define V_DEPTH_15	0x008
#define V_DEPTH_16	0x010
#define V_DEPTH_24_24	0x020
#define V_DEPTH_24_32	0x040
#define V_DEPTH_24	(V_DEPTH_24_24 | V_DEPTH_24_32)
#define V_DEPTH_30	0x080
#define V_DEPTH_32	0x100

#define VBE_MODE_SUPPORTED(m)	(((m)->ModeAttributes & 0x01) != 0)
#define VBE_MODE_COLOR(m)	(((m)->ModeAttributes & 0x08) != 0)
#define VBE_MODE_GRAPHICS(m)	(((m)->ModeAttributes & 0x10) != 0)
#define VBE_MODE_VGA(m)		(((m)->ModeAttributes & 0x40) == 0)
#define VBE_MODE_LINEAR(m)	(((m)->ModeAttributes & 0x80) != 0 && \
				 ((m)->PhysBasePtr != 0))

#define VBE_MODE_USABLE(m, f)	(VBE_MODE_SUPPORTED(m) || \
				 (f & V_MODETYPE_BAD)) && \
				VBE_MODE_GRAPHICS(m) && \
				(VBE_MODE_VGA(m) || VBE_MODE_LINEAR(m))

#define V_MODETYPE_VBE		0x01
#define V_MODETYPE_VGA		0x02
#define V_MODETYPE_BAD		0x04

extern _X_EXPORT int VBEFindSupportedDepths(vbeInfoPtr pVbe, VbeInfoBlock * vbe,
                                            int *flags24, int modeTypes);
extern _X_EXPORT DisplayModePtr VBEGetModePool(ScrnInfoPtr pScrn,
                                               vbeInfoPtr pVbe,
                                               VbeInfoBlock * vbe,
                                               int modeTypes);
extern _X_EXPORT void VBESetModeNames(DisplayModePtr pMode);
extern _X_EXPORT void VBESetModeParameters(ScrnInfoPtr pScrn, vbeInfoPtr pVbe);

/*
 * Note: These are alternatives to the standard helpers.  They should
 * usually just wrap the standard helpers.
 */
extern _X_EXPORT int VBEValidateModes(ScrnInfoPtr scrp,
                                      DisplayModePtr availModes,
                                      const char **modeNames,
                                      ClockRangePtr clockRanges,
                                      int *linePitches, int minPitch,
                                      int maxPitch, int pitchInc, int minHeight,
                                      int maxHeight, int virtualX, int virtualY,
                                      int apertureSize,
                                      LookupModeFlags strategy);
extern _X_EXPORT void VBEPrintModes(ScrnInfoPtr scrp);

#endif                          /* VBE_MODES_H */
