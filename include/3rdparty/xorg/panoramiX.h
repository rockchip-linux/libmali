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

/*
 *	PanoramiX definitions
 */

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif

#ifndef _PANORAMIX_H_
#define _PANORAMIX_H_

#define _PANORAMIX_SERVER
#include <X11/extensions/panoramiXproto.h>
#undef _PANORAMIX_SERVER
#include "gcstruct.h"
#include "dixstruct.h"

typedef struct _PanoramiXInfo {
    XID id;
} PanoramiXInfo;

typedef struct {
    PanoramiXInfo info[MAXSCREENS];
    RESTYPE type;
    union {
        struct {
            char visibility;
            char class;
            char root;
        } win;
        struct {
            Bool shared;
        } pix;
        struct {
            Bool root;
        } pict;
        char raw_data[4];
    } u;
} PanoramiXRes;

#define FOR_NSCREENS_FORWARD(j) for(j = 0; j < PanoramiXNumScreens; j++)
#define FOR_NSCREENS_FORWARD_SKIP(j) for(j = 1; j < PanoramiXNumScreens; j++)
#define FOR_NSCREENS_BACKWARD(j) for(j = PanoramiXNumScreens - 1; j >= 0; j--)
#define FOR_NSCREENS(j) FOR_NSCREENS_FORWARD(j)

#define IS_SHARED_PIXMAP(r) (((r)->type == XRT_PIXMAP) && (r)->u.pix.shared)

#define IS_ROOT_DRAWABLE(d) (((d)->type == XRT_WINDOW) && (d)->u.win.root)
#endif                          /* _PANORAMIX_H_ */
