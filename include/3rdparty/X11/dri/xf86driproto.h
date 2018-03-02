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

/*
 * Authors:
 *   Kevin E. Martin <martin@valinux.com>
 *   Jens Owen <jens@tungstengraphics.com>
 *   Rickard E. (Rik) Faith <faith@valinux.com>
 *
 */

#ifndef _XF86DRISTR_H_
#define _XF86DRISTR_H_

#include "xf86dri.h"

#define XF86DRINAME "XFree86-DRI"

/* The DRI version number.  This was originally set to be the same of the
 * XFree86 version number.  However, this version is really indepedent of
 * the XFree86 version.
 *
 * Version History:
 *    4.0.0: Original
 *    4.0.1: Patch to bump clipstamp when windows are destroyed, 28 May 02
 *    4.1.0: Add transition from single to multi in DRMInfo rec, 24 Jun 02
 */
#define XF86DRI_MAJOR_VERSION	4
#define XF86DRI_MINOR_VERSION	1
#define XF86DRI_PATCH_VERSION	0

typedef struct _XF86DRIQueryVersion {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIQueryVersion */
    CARD16	length B16;
} xXF86DRIQueryVersionReq;
#define sz_xXF86DRIQueryVersionReq	4

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD16	majorVersion B16;	/* major version of DRI protocol */
    CARD16	minorVersion B16;	/* minor version of DRI protocol */
    CARD32	patchVersion B32;       /* patch version of DRI protocol */
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86DRIQueryVersionReply;
#define sz_xXF86DRIQueryVersionReply	32

typedef struct _XF86DRIQueryDirectRenderingCapable {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* X_DRIQueryDirectRenderingCapable */
    CARD16	length B16;
    CARD32	screen B32;
} xXF86DRIQueryDirectRenderingCapableReq;
#define sz_xXF86DRIQueryDirectRenderingCapableReq	8

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    BOOL	isCapable;
    BOOL	pad2;
    BOOL	pad3;
    BOOL	pad4;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
    CARD32	pad7 B32;
    CARD32	pad8 B32;
    CARD32	pad9 B32;
} xXF86DRIQueryDirectRenderingCapableReply;
#define sz_xXF86DRIQueryDirectRenderingCapableReply	32

typedef struct _XF86DRIOpenConnection {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIOpenConnection */
    CARD16	length B16;
    CARD32	screen B32;
} xXF86DRIOpenConnectionReq;
#define sz_xXF86DRIOpenConnectionReq	8

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	hSAREALow B32;
    CARD32	hSAREAHigh B32;
    CARD32	busIdStringLength B32;
    CARD32	pad6 B32;
    CARD32	pad7 B32;
    CARD32	pad8 B32;
} xXF86DRIOpenConnectionReply;
#define sz_xXF86DRIOpenConnectionReply	32

typedef struct _XF86DRIAuthConnection {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRICloseConnection */
    CARD16	length B16;
    CARD32	screen B32;
    CARD32      magic B32;
} xXF86DRIAuthConnectionReq;
#define sz_xXF86DRIAuthConnectionReq	12

typedef struct {
    BYTE        type;
    BOOL        pad1;
    CARD16      sequenceNumber B16;
    CARD32      length B32;
    CARD32      authenticated B32;
    CARD32      pad2 B32;
    CARD32      pad3 B32;
    CARD32      pad4 B32;
    CARD32      pad5 B32;
    CARD32      pad6 B32;
} xXF86DRIAuthConnectionReply;
#define zx_xXF86DRIAuthConnectionReply  32

typedef struct _XF86DRICloseConnection {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRICloseConnection */
    CARD16	length B16;
    CARD32	screen B32;
} xXF86DRICloseConnectionReq;
#define sz_xXF86DRICloseConnectionReq	8

typedef struct _XF86DRIGetClientDriverName {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIGetClientDriverName */
    CARD16	length B16;
    CARD32	screen B32;
} xXF86DRIGetClientDriverNameReq;
#define sz_xXF86DRIGetClientDriverNameReq	8

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	ddxDriverMajorVersion B32;
    CARD32	ddxDriverMinorVersion B32;
    CARD32	ddxDriverPatchVersion B32;
    CARD32	clientDriverNameLength B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86DRIGetClientDriverNameReply;
#define sz_xXF86DRIGetClientDriverNameReply	32

typedef struct _XF86DRICreateContext {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRICreateContext */
    CARD16	length B16;
    CARD32	screen B32;
    CARD32	visual B32;
    CARD32	context B32;
} xXF86DRICreateContextReq;
#define sz_xXF86DRICreateContextReq	16

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	hHWContext B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86DRICreateContextReply;
#define sz_xXF86DRICreateContextReply	32

typedef struct _XF86DRIDestroyContext {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIDestroyContext */
    CARD16	length B16;
    CARD32	screen B32;
    CARD32	context B32;
} xXF86DRIDestroyContextReq;
#define sz_xXF86DRIDestroyContextReq	12

typedef struct _XF86DRICreateDrawable {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRICreateDrawable */
    CARD16	length B16;
    CARD32	screen B32;
    CARD32	drawable B32;
} xXF86DRICreateDrawableReq;
#define sz_xXF86DRICreateDrawableReq	12

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	hHWDrawable B32;
    CARD32	pad2 B32;
    CARD32	pad3 B32;
    CARD32	pad4 B32;
    CARD32	pad5 B32;
    CARD32	pad6 B32;
} xXF86DRICreateDrawableReply;
#define sz_xXF86DRICreateDrawableReply	32

typedef struct _XF86DRIDestroyDrawable {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIDestroyDrawable */
    CARD16	length B16;
    CARD32	screen B32;
    CARD32	drawable B32;
} xXF86DRIDestroyDrawableReq;
#define sz_xXF86DRIDestroyDrawableReq	12

typedef struct _XF86DRIGetDrawableInfo {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIGetDrawableInfo */
    CARD16	length B16;
    CARD32	screen B32;
    CARD32	drawable B32;
} xXF86DRIGetDrawableInfoReq;
#define sz_xXF86DRIGetDrawableInfoReq	12

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	drawableTableIndex B32;
    CARD32	drawableTableStamp B32;
    INT16	drawableX B16;
    INT16	drawableY B16;
    INT16	drawableWidth B16;
    INT16	drawableHeight B16;
    CARD32	numClipRects B32;
    INT16       backX B16;
    INT16       backY B16;
    CARD32      numBackClipRects B32;
} xXF86DRIGetDrawableInfoReply;

#define sz_xXF86DRIGetDrawableInfoReply	36


typedef struct _XF86DRIGetDeviceInfo {
    CARD8	reqType;		/* always DRIReqCode */
    CARD8	driReqType;		/* always X_DRIGetDeviceInfo */
    CARD16	length B16;
    CARD32	screen B32;
} xXF86DRIGetDeviceInfoReq;
#define sz_xXF86DRIGetDeviceInfoReq	8

typedef struct {
    BYTE	type;			/* X_Reply */
    BOOL	pad1;
    CARD16	sequenceNumber B16;
    CARD32	length B32;
    CARD32	hFrameBufferLow B32;
    CARD32	hFrameBufferHigh B32;
    CARD32	framebufferOrigin B32;
    CARD32	framebufferSize B32;
    CARD32	framebufferStride B32;
    CARD32	devPrivateSize B32;
} xXF86DRIGetDeviceInfoReply;
#define sz_xXF86DRIGetDeviceInfoReply	32

typedef struct _XF86DRIOpenFullScreen {
    CARD8       reqType;	/* always DRIReqCode */
    CARD8       driReqType;	/* always X_DRIOpenFullScreen */
    CARD16      length B16;
    CARD32      screen B32;
    CARD32      drawable B32;
} xXF86DRIOpenFullScreenReq;
#define sz_xXF86DRIOpenFullScreenReq    12

typedef struct {
    BYTE        type;
    BOOL        pad1;
    CARD16      sequenceNumber B16;
    CARD32      length B32;
    CARD32      isFullScreen B32;
    CARD32      pad2 B32;
    CARD32      pad3 B32;
    CARD32      pad4 B32;
    CARD32      pad5 B32;
    CARD32      pad6 B32;
} xXF86DRIOpenFullScreenReply;
#define sz_xXF86DRIOpenFullScreenReply  32

typedef struct _XF86DRICloseFullScreen {
    CARD8       reqType;	/* always DRIReqCode */
    CARD8       driReqType;	/* always X_DRICloseFullScreen */
    CARD16      length B16;
    CARD32      screen B32;
    CARD32      drawable B32;
} xXF86DRICloseFullScreenReq;
#define sz_xXF86DRICloseFullScreenReq   12

typedef struct {
    BYTE        type;
    BOOL        pad1;
    CARD16      sequenceNumber B16;
    CARD32      length B32;
    CARD32      pad2 B32;
    CARD32      pad3 B32;
    CARD32      pad4 B32;
    CARD32      pad5 B32;
    CARD32      pad6 B32;
    CARD32      pad7 B32;
} xXF86DRICloseFullScreenReply;
#define sz_xXF86DRICloseFullScreenReply  32


#endif /* _XF86DRISTR_H_ */
