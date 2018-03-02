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
 * Copyright © 2003 Keith Packard
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Keith Packard not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Keith Packard makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * KEITH PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL KEITH PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _XCOMPOSITE_H_
#define _XCOMPOSITE_H_

#include <X11/extensions/composite.h>
#include <X11/extensions/Xfixes.h>
#include <X11/Xfuncproto.h>

/*
 * This revision number also appears in configure.ac, they have
 * to be manually synchronized
 */
#define XCOMPOSITE_MAJOR	COMPOSITE_MAJOR
#define XCOMPOSITE_MINOR	COMPOSITE_MINOR
#define XCOMPOSITE_REVISION	2
#define XCOMPOSITE_VERSION	((XCOMPOSITE_MAJOR * 10000) + (XCOMPOSITE_MINOR * 100) + (XCOMPOSITE_REVISION))

_XFUNCPROTOBEGIN

Bool XCompositeQueryExtension (Display *dpy,
                               int *event_base_return,
                               int *error_base_return);

Status XCompositeQueryVersion (Display *dpy,
                               int     *major_version_return,
                               int     *minor_version_return);

int XCompositeVersion (void);

void
XCompositeRedirectWindow (Display *dpy, Window window, int update);

void
XCompositeRedirectSubwindows (Display *dpy, Window window, int update);

void
XCompositeUnredirectWindow (Display *dpy, Window window, int update);

void
XCompositeUnredirectSubwindows (Display *dpy, Window window, int update);

XserverRegion
XCompositeCreateRegionFromBorderClip (Display *dpy, Window window);

Pixmap
XCompositeNameWindowPixmap (Display *dpy, Window window);

Window
XCompositeGetOverlayWindow (Display *dpy, Window window);

void
XCompositeReleaseOverlayWindow (Display *dpy, Window window);

_XFUNCPROTOEND

#endif /* _XCOMPOSITE_H_ */
