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

/* THIS IS NOT AN X CONSORTIUM STANDARD OR AN X PROJECT TEAM SPECIFICATION */

#ifndef _XF86VIDMODE_H_
#define _XF86VIDMODE_H_

#include <X11/Xfuncproto.h>
#include <X11/Xmd.h>
#include <X11/extensions/xf86vm.h>

#define CLKFLAG_PROGRAMABLE		1

#ifdef XF86VIDMODE_EVENTS
#define XF86VidModeNotify		0
#define XF86VidModeNumberEvents		(XF86VidModeNotify + 1)

#define XF86VidModeNotifyMask		0x00000001

#define XF86VidModeNonEvent		0
#define XF86VidModeModeChange		1
#else
#define XF86VidModeNumberEvents		0
#endif

#define XF86VidModeBadClock		0
#define XF86VidModeBadHTimings		1
#define XF86VidModeBadVTimings		2
#define XF86VidModeModeUnsuitable	3
#define XF86VidModeExtensionDisabled	4
#define XF86VidModeClientNotLocal	5
#define XF86VidModeZoomLocked		6
#define XF86VidModeNumberErrors		(XF86VidModeZoomLocked + 1)

#define XF86VM_READ_PERMISSION	1
#define XF86VM_WRITE_PERMISSION	2

#ifndef _XF86VIDMODE_SERVER_

typedef struct {
    unsigned short	hdisplay;
    unsigned short	hsyncstart;
    unsigned short	hsyncend;
    unsigned short	htotal;
    unsigned short	hskew;
    unsigned short	vdisplay;
    unsigned short	vsyncstart;
    unsigned short	vsyncend;
    unsigned short	vtotal;
    unsigned int	flags;
    int			privsize;
#if defined(__cplusplus) || defined(c_plusplus)
    /* private is a C++ reserved word */
    INT32		*c_private;
#else
    INT32		*private;
#endif
} XF86VidModeModeLine;

typedef struct {
    unsigned int	dotclock;
    unsigned short	hdisplay;
    unsigned short	hsyncstart;
    unsigned short	hsyncend;
    unsigned short	htotal;
    unsigned short	hskew;
    unsigned short	vdisplay;
    unsigned short	vsyncstart;
    unsigned short	vsyncend;
    unsigned short	vtotal;
    unsigned int	flags;
    int			privsize;
#if defined(__cplusplus) || defined(c_plusplus)
    /* private is a C++ reserved word */
    INT32		*c_private;
#else
    INT32		*private;
#endif
} XF86VidModeModeInfo;

typedef struct {
    float		hi;
    float		lo;
} XF86VidModeSyncRange;

typedef struct {
    char*			vendor;
    char*			model;
    float			EMPTY;
    unsigned char		nhsync;
    XF86VidModeSyncRange*	hsync;
    unsigned char		nvsync;
    XF86VidModeSyncRange*	vsync;
} XF86VidModeMonitor;

typedef struct {
    int type;			/* of event */
    unsigned long serial;	/* # of last request processed by server */
    Bool send_event;		/* true if this came from a SendEvent req */
    Display *display;		/* Display the event was read from */
    Window root;		/* root window of event screen */
    int state;			/* What happened */
    int kind;			/* What happened */
    Bool forced;		/* extents of new region */
    Time time;			/* event timestamp */
} XF86VidModeNotifyEvent;

typedef struct {
    float red;			/* Red Gamma value */
    float green;		/* Green Gamma value */
    float blue;			/* Blue Gamma value */
} XF86VidModeGamma;


#define XF86VidModeSelectNextMode(disp, scr) \
	XF86VidModeSwitchMode(disp, scr, 1)
#define XF86VidModeSelectPrevMode(disp, scr) \
	XF86VidModeSwitchMode(disp, scr, -1)

_XFUNCPROTOBEGIN

Bool XF86VidModeQueryVersion(
    Display*		/* dpy */,
    int*		/* majorVersion */,
    int*		/* minorVersion */
);

Bool XF86VidModeQueryExtension(
    Display*		/* dpy */,
    int*		/* event_base */,
    int*		/* error_base */
);

Bool XF86VidModeSetClientVersion(
    Display*		/* dpy */
);

Bool XF86VidModeGetModeLine(
    Display*			/* dpy */,
    int				/* screen */,
    int*			/* dotclock */,
    XF86VidModeModeLine*	/* modeline */
);

Bool XF86VidModeGetAllModeLines(
    Display*			/* dpy */,
    int				/* screen */,
    int*			/* modecount */,
    XF86VidModeModeInfo***	/* modelinesPtr */
);

Bool XF86VidModeAddModeLine(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeModeInfo*	/* new modeline */,
    XF86VidModeModeInfo*	/* after modeline */
);

Bool XF86VidModeDeleteModeLine(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeModeInfo*	/* modeline */
);

Bool XF86VidModeModModeLine(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeModeLine*	/* modeline */
);

Status XF86VidModeValidateModeLine(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeModeInfo*	/* modeline */
);

Bool XF86VidModeSwitchMode(
    Display*		/* dpy */,
    int			/* screen */,
    int			/* zoom */
);

Bool XF86VidModeSwitchToMode(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeModeInfo*	/* modeline */
);

Bool XF86VidModeLockModeSwitch(
    Display*		/* dpy */,
    int			/* screen */,
    int			/* lock */
);

Bool XF86VidModeGetMonitor(
    Display*		/* dpy */,
    int			/* screen */,
    XF86VidModeMonitor*	/* monitor */
);

Bool XF86VidModeGetViewPort(
    Display*		/* dpy */,
    int			/* screen */,
    int*		/* x return */,
    int*		/* y return */
);

Bool XF86VidModeSetViewPort(
    Display*		/* dpy */,
    int			/* screen */,
    int			/* x */,
    int			/* y */
);

Bool XF86VidModeGetDotClocks(
    Display*		/* dpy */,
    int			/* screen */,
    int*		/* flags return */,
    int*		/* number of clocks return */,
    int*		/* max dot clock return */,
    int**		/* clocks return */
);

Bool XF86VidModeGetGamma(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeGamma*		/* Gamma */
);

Bool XF86VidModeSetGamma(
    Display*			/* dpy */,
    int				/* screen */,
    XF86VidModeGamma*		/* Gamma */
);

Bool XF86VidModeSetGammaRamp(
    Display*                    /* dpy */,
    int                         /* screen */,
    int				/* size */,
    unsigned short*             /* red array */,
    unsigned short*             /* green array */,
    unsigned short*             /* blue array */
);

Bool XF86VidModeGetGammaRamp(
    Display*                    /* dpy */,
    int                         /* screen */,
    int                         /* size */,
    unsigned short*             /* red array */,
    unsigned short*             /* green array */,
    unsigned short*             /* blue array */
);

Bool XF86VidModeGetGammaRampSize(
    Display*                    /* dpy */,
    int                         /* screen */,
    int*                        /* size */
);

Bool XF86VidModeGetPermissions(
    Display*                    /* dpy */,
    int                         /* screen */,
    int*			/* permissions */
);

_XFUNCPROTOEND

#endif

#endif
