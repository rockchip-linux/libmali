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
/************************************************************

Copyright 1989, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

********************************************************/

/* THIS IS NOT AN X CONSORTIUM STANDARD OR AN X PROJECT TEAM SPECIFICATION */

#ifndef _SHMSTR_H_
#define _SHMSTR_H_

#include <X11/extensions/shmproto.h>

#ifdef _XSHM_SERVER_
#define XSHM_PUT_IMAGE_ARGS \
    DrawablePtr		/* dst */, \
    GCPtr		/* pGC */, \
    int			/* depth */, \
    unsigned int	/* format */, \
    int			/* w */, \
    int			/* h */, \
    int			/* sx */, \
    int			/* sy */, \
    int			/* sw */, \
    int			/* sh */, \
    int			/* dx */, \
    int			/* dy */, \
    char *		/* data */

#define XSHM_CREATE_PIXMAP_ARGS \
    ScreenPtr	/* pScreen */, \
    int		/* width */, \
    int		/* height */, \
    int		/* depth */, \
    char *	/* addr */

typedef struct _ShmFuncs {
    PixmapPtr	(* CreatePixmap)(XSHM_CREATE_PIXMAP_ARGS);
    void	(* PutImage)(XSHM_PUT_IMAGE_ARGS);
} ShmFuncs, *ShmFuncsPtr;
#endif

#endif /* _SHMSTR_H_ */
