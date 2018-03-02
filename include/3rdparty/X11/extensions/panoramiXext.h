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
 *	PanoramiX definitions
 */

/* THIS IS NOT AN X PROJECT TEAM SPECIFICATION */

#ifndef _panoramiXext_h
#define _panoramiXext_h

#include <X11/Xfuncproto.h>

typedef struct {
    Window  window;         /* PanoramiX window - may not exist */
    int	    screen;
    int     State;          /* PanoramiXOff, PanoramiXOn */
    int	    width;	    /* width of this screen */
    int     height;	    /* height of this screen */
    int     ScreenCount;    /* real physical number of screens */
    XID     eventMask;      /* selected events for this client */
} XPanoramiXInfo;

_XFUNCPROTOBEGIN

extern Bool XPanoramiXQueryExtension (
    Display *		/* dpy */,
    int *		/* event_base_return */,
    int *		/* error_base_return */
);

extern Status XPanoramiXQueryVersion(
    Display *		/* dpy */,
    int *		/* major_version_return */,
    int *		/* minor_version_return */
);

extern XPanoramiXInfo *XPanoramiXAllocInfo (
    void
);

extern Status XPanoramiXGetState (
    Display *		/* dpy */,
    Drawable		/* drawable */,
    XPanoramiXInfo *	/* panoramiX_info */
);

extern Status XPanoramiXGetScreenCount (
    Display *		/* dpy */,
    Drawable		/* drawable */,
    XPanoramiXInfo *	/* panoramiX_info */
);

extern Status XPanoramiXGetScreenSize (
    Display *		/* dpy */,
    Drawable		/* drawable */,
    int			/* screen_num */,
    XPanoramiXInfo *	/* panoramiX_info */
);

_XFUNCPROTOEND

#endif /* _panoramiXext_h */
