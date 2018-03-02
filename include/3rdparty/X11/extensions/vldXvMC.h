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


#ifndef _VLDXVMC_H
#define _VLDXVMC_H

#include <X11/Xlib.h>
#include <X11/extensions/XvMC.h>

/*
 * New "Motion compensation type".
 */

#define XVMC_VLD 0x0020000

/*
 * Below Flags to be passed in the XvMCMpegControl structure 'flag' field.
 */

#define XVMC_PROGRESSIVE_SEQUENCE 0x00000010

/*
 * Zig-Zag Scan / Alternative Scan.
 */

#define XVMC_ZIG_ZAG_SCAN         0x00000000
#define XVMC_ALTERNATE_SCAN       0x00000100

/*
 * Frame DCT and frame prediction are used. /
 * Field prediction
 */

#define XVMC_PRED_DCT_FRAME       0x00000040
#define XVMC_PRED_DCT_FIELD       0x00000000

/*
 * Top / Bottom field first
 */

#define XVMC_TOP_FIELD_FIRST      0x00000080
#define XVMC_BOTTOM_FIELD_FIRST   0x00000000

/*
 * Motion vectors coded in intra macroblocks
 */

#define XVMC_CONCEALMENT_MOTION_VECTORS 0x00000200

/*
 * Which of two mappings between quantiser_scale_code
 * and quantiser_scale shall apply.
 */

#define XVMC_Q_SCALE_TYPE         0x00000400

/*
 * Intra VLC Format: Bit = 0,  Bit = 1
 * Intra blocks      B-14      B-15
 * Non-intra blocks  B-14      B-14
 */
#define XVMC_INTRA_VLC_FORMAT     0x00000800

/*
 * Also XVMC_SECOND_FIELD should be set in flags if active.
 */

#define XVMC_I_PICTURE 1
#define XVMC_P_PICTURE 2
#define XVMC_B_PICTURE 3

typedef struct _XvMCMpegControl{
    unsigned
        BVMV_range,        /* Backward vertical motion vector range */
	BHMV_range,        /* Backward horizontal motion vector range */
	FVMV_range,        /* Forward vertical motion vector range */
	FHMV_range,        /* Forward horizontal motion vector range */
	picture_structure, /* XVMC_TOP_FIELD, XVMC_BOTTOM_FIELD,
			    *  XVMC_FRAME_PICTURE
			    */
	intra_dc_precision, /* 0x00 - 0x03 corresponds to 8 to 11 bits prec. */
	picture_coding_type,/* XVMC_X_PICTURE */
	mpeg_coding,        /* XVMC_MPEG_2 */
	flags;              /* See above */
}XvMCMpegControl;


/*
 * The following function is called BEFORE starting sending slices to the
 * lib. It grabs the decoder hardware and prepares it for coming slices.
 * The function XvMCSyncSurface will release the hardware for other contexts
 * in addition to it's current functionality.
 */

extern Status XvMCBeginSurface(Display *display,
			       XvMCContext *context,
			       XvMCSurface *target_surface,
			       XvMCSurface *past_surface,
			       XvMCSurface *future_surface,
			       const XvMCMpegControl *control);


/*
 * The quantizer matrix structure. This should be filled in by the user and
 * uploaded whenever a change is needed. The lib initializes with
 * default matrices and will automatically load the hardware with new matrices
 * on decoder context switches. To load data, set the corresponding load flag
 * to true and fill in the values. The VIA MPEG2 engine only uses the
 * intra_quantiser_matrix and the non_intra_quantiser_matrix.
 */

typedef struct _XvMCQMatrix {
    int load_intra_quantiser_matrix;
    int load_non_intra_quantiser_matrix;
    int load_chroma_intra_quantiser_matrix;
    int load_chroma_non_intra_quantiser_matrix;
    unsigned char intra_quantiser_matrix[64];
    unsigned char non_intra_quantiser_matrix[64];
    unsigned char chroma_intra_quantiser_matrix[64];
    unsigned char chroma_non_intra_quantiser_matrix[64];
} XvMCQMatrix;

/*
 * Upload a XvMCQMatrix structure to the clientlib.
 * The hardware will start using it the next XvMCBeginSurface.
 */

extern Status XvMCLoadQMatrix(Display *display, XvMCContext *context,
			      const XvMCQMatrix *qmx);


/*
 * Put a slice to the decoder. The hardware will start processing it
 * immediately.
 */

extern Status XvMCPutSlice(Display *display,XvMCContext *context,
			   char *slice, int nBytes);
/*
 * Put a slice without the slice start code to the decoder.
 * The hardware will start processing it
 * immediately. This function is for client optimization.
 * XvMCPutSlice(display,context,slice,nBytes) is equivalent to
 * XvMCPutSlice2(display,context,slice+4,nBytes-4,slice[3]);
 */

extern Status XvMCPutSlice2(Display *display,XvMCContext *context,
			   char *slice, int nBytes, int sliceCode);

#endif
