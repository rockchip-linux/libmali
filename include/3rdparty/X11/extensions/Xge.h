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


/* XGE Client interfaces */

#ifndef _XGE_H_
#define _XGE_H_

#include <X11/Xlib.h>
#include <X11/Xfuncproto.h>

_XFUNCPROTOBEGIN

/**
 * Generic Event mask.
 * To be used whenever a list of masks per extension has to be provided.
 *
 * But, don't actually use the CARD{8,16,32} types.  We can't get them them
 * defined here without polluting the namespace.
 */
typedef struct {
    unsigned char       extension;
    unsigned char       pad0;
    unsigned short      pad1;
    unsigned int      evmask;
} XGenericEventMask;

Bool XGEQueryExtension(Display* dpy, int *event_basep, int *err_basep);
Bool XGEQueryVersion(Display* dpy, int *major, int* minor);

_XFUNCPROTOEND

#endif /* _XGE_H_ */
