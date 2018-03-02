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

#ifndef XDBE_H
#define XDBE_H

#include <X11/Xfuncproto.h>
#include <X11/extensions/dbe.h>

typedef struct
{
    VisualID    visual;    /* one visual ID that supports double-buffering */
    int         depth;     /* depth of visual in bits                      */
    int         perflevel; /* performance level of visual                  */
}
XdbeVisualInfo;

typedef struct
{
    int                 count;          /* number of items in visual_depth   */
    XdbeVisualInfo      *visinfo;       /* list of visuals & depths for scrn */
}
XdbeScreenVisualInfo;


typedef Drawable XdbeBackBuffer;

typedef unsigned char XdbeSwapAction;

typedef struct
{
    Window		swap_window;    /* window for which to swap buffers   */
    XdbeSwapAction	swap_action;    /* swap action to use for swap_window */
}
XdbeSwapInfo;

typedef struct
{
    Window	window;			/* window that buffer belongs to */
}
XdbeBackBufferAttributes;

typedef struct
{
    int			type;
    Display		*display;	/* display the event was read from */
    XdbeBackBuffer	buffer;		/* resource id                     */
    unsigned long	serial;		/* serial number of failed request */
    unsigned char	error_code;	/* error base + XdbeBadBuffer      */
    unsigned char	request_code;	/* major opcode of failed request  */
    unsigned char	minor_code;	/* minor opcode of failed request  */
}
XdbeBufferError;

/* _XFUNCPROTOBEGIN and _XFUNCPROTOEND are defined as noops
 * (for non-C++ builds) in X11/Xfuncproto.h.
 */
_XFUNCPROTOBEGIN

extern Status XdbeQueryExtension(
    Display*		/* dpy                  */,
    int*		/* major_version_return */,
    int*		/* minor_version_return */
);

extern XdbeBackBuffer XdbeAllocateBackBufferName(
    Display*		/* dpy         */,
    Window		/* window      */,
    XdbeSwapAction	/* swap_action */
);

extern Status XdbeDeallocateBackBufferName(
    Display*		/* dpy    */,
    XdbeBackBuffer	/* buffer */
);

extern Status XdbeSwapBuffers(
    Display*		/* dpy         */,
    XdbeSwapInfo*	/* swap_info   */,
    int			/* num_windows */
);

extern Status XdbeBeginIdiom(
    Display*		/* dpy */
);

extern Status XdbeEndIdiom(
    Display*		/* dpy */
);

extern XdbeScreenVisualInfo *XdbeGetVisualInfo(
    Display*		/* dpy               */,
    Drawable*		/* screen_specifiers */,
    int*		/* num_screens       */
);

extern void XdbeFreeVisualInfo(
    XdbeScreenVisualInfo*	/* visual_info */
);

extern XdbeBackBufferAttributes *XdbeGetBackBufferAttributes(
    Display*		/* dpy    */,
    XdbeBackBuffer	/* buffer */
);

_XFUNCPROTOEND

#endif /* XDBE_H */

