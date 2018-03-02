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

/* THIS IS NOT AN X PROJECT TEAM SPECIFICATION */

#ifndef _PANORAMIXPROTO_H_
#define _PANORAMIXPROTO_H_

#define PANORAMIX_MAJOR_VERSION         1       /* current version number */
#define PANORAMIX_MINOR_VERSION         1

#define PANORAMIX_PROTOCOL_NAME "XINERAMA"

#define X_PanoramiXQueryVersion		0
#define X_PanoramiXGetState		1
#define X_PanoramiXGetScreenCount	2
#define X_PanoramiXGetScreenSize	3

#define X_XineramaIsActive		4
#define X_XineramaQueryScreens		5

typedef struct _PanoramiXQueryVersion {
	CARD8	reqType;		/* always PanoramiXReqCode */
	CARD8	panoramiXReqType;	/* always X_PanoramiXQueryVersion */
	CARD16	length B16;
	CARD8	clientMajor;
	CARD8	clientMinor;
	CARD16	unused B16;           
} xPanoramiXQueryVersionReq;

#define sz_xPanoramiXQueryVersionReq	8

typedef struct {
	CARD8	type;			/* must be X_Reply */
	CARD8	pad1;			/* unused	*/
	CARD16	sequenceNumber  B16;	/* last sequence number */
	CARD32	length  B32;		/* 0 */
	CARD16	majorVersion  B16;	
	CARD16	minorVersion  B16;	
	CARD32	pad2	B32;		/* unused */
	CARD32	pad3	B32;		/* unused */
	CARD32	pad4	B32;		/* unused */
	CARD32	pad5	B32;		/* unused */
	CARD32	pad6	B32;		/* unused */
} xPanoramiXQueryVersionReply;

#define sz_xPanoramiXQueryVersionReply	32


typedef	struct	_PanoramiXGetState {
        CARD8   reqType;	        /* always PanoramiXReqCode */
        CARD8   panoramiXReqType;    	/* always X_PanoramiXGetState */
        CARD16  length B16;
	CARD32  window B32;
} xPanoramiXGetStateReq;
#define sz_xPanoramiXGetStateReq	8	

typedef struct {
	BYTE	type;
	BYTE	state;
	CARD16	sequenceNumber B16;
	CARD32	length	B32;
	CARD32  window  B32;
	CARD32	pad1	B32;		/* unused */
	CARD32	pad2	B32;		/* unused */
	CARD32	pad3	B32;		/* unused */
	CARD32	pad4	B32;		/* unused */
	CARD32	pad5	B32;		/* unused */
} xPanoramiXGetStateReply;

#define sz_panoramiXGetStateReply	32

typedef	struct	_PanoramiXGetScreenCount {
        CARD8   reqType;             /* always PanoramiXReqCode */
        CARD8   panoramiXReqType;    /* always X_PanoramiXGetScreenCount */
        CARD16  length B16;
	CARD32  window B32;
} xPanoramiXGetScreenCountReq;
#define sz_xPanoramiXGetScreenCountReq	8

typedef struct {
	BYTE	type;
	BYTE	ScreenCount;
	CARD16	sequenceNumber B16;
	CARD32	length B32;
	CARD32  window  B32;
	CARD32	pad1	B32;		/* unused */
	CARD32	pad2	B32;		/* unused */
	CARD32	pad3	B32;		/* unused */
	CARD32	pad4	B32;		/* unused */
	CARD32	pad5	B32;		/* unused */
} xPanoramiXGetScreenCountReply;
#define sz_panoramiXGetScreenCountReply	32

typedef	struct	_PanoramiXGetScreenSize {
        CARD8   reqType;                /* always PanoramiXReqCode */
        CARD8   panoramiXReqType;	/* always X_PanoramiXGetState */
        CARD16  length B16;
	CARD32  window B32;
	CARD32	screen B32;
} xPanoramiXGetScreenSizeReq;
#define sz_xPanoramiXGetScreenSizeReq	12	

typedef struct {
	BYTE	type;
	CARD8	pad1;			
	CARD16	sequenceNumber B16;
	CARD32	length	B32;
	CARD32	width	B32;
	CARD32	height	B32;
	CARD32  window  B32;
	CARD32  screen  B32;
	CARD32	pad2	B32;		/* unused */
	CARD32	pad3	B32;		/* unused */
} xPanoramiXGetScreenSizeReply;
#define sz_panoramiXGetScreenSizeReply 32	

/************  Alternate protocol  ******************/

typedef struct {
        CARD8   reqType;
        CARD8   panoramiXReqType;
        CARD16  length B16;
} xXineramaIsActiveReq;
#define sz_xXineramaIsActiveReq 4

typedef struct {
	BYTE	type;
	CARD8	pad1;			
	CARD16	sequenceNumber B16;
	CARD32	length	B32;
	CARD32	state	B32;
	CARD32	pad2	B32;
	CARD32  pad3  	B32;
	CARD32  pad4  	B32;
	CARD32	pad5	B32;
	CARD32	pad6	B32;
} xXineramaIsActiveReply;
#define sz_XineramaIsActiveReply 32	


typedef struct {
        CARD8   reqType;
        CARD8   panoramiXReqType;
        CARD16  length B16;
} xXineramaQueryScreensReq;
#define sz_xXineramaQueryScreensReq 4

typedef struct {
	BYTE	type;
	CARD8	pad1;			
	CARD16	sequenceNumber B16;
	CARD32	length	B32;
	CARD32	number	B32;
	CARD32	pad2	B32;
	CARD32  pad3  	B32;
	CARD32  pad4  	B32;
	CARD32	pad5	B32;
	CARD32	pad6	B32;
} xXineramaQueryScreensReply;
#define sz_XineramaQueryScreensReply 32	

typedef struct {
	INT16   x_org   B16;
	INT16   y_org   B16;
	CARD16  width   B16;
	CARD16  height  B16;
} xXineramaScreenInfo;
#define sz_XineramaScreenInfo 8

#endif 
