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

/**
 * \file xf86dri.h
 * Protocol numbers and function prototypes for DRI X protocol.
 *
 * \author Kevin E. Martin <martin@valinux.com>
 * \author Jens Owen <jens@tungstengraphics.com>
 * \author Rickard E. (Rik) Faith <faith@valinux.com>
 */

#ifndef _XF86DRI_H_
#define _XF86DRI_H_

#include <xf86drm.h>

#define X_XF86DRIQueryVersion			0
#define X_XF86DRIQueryDirectRenderingCapable	1
#define X_XF86DRIOpenConnection			2
#define X_XF86DRICloseConnection		3
#define X_XF86DRIGetClientDriverName		4
#define X_XF86DRICreateContext			5
#define X_XF86DRIDestroyContext			6
#define X_XF86DRICreateDrawable			7
#define X_XF86DRIDestroyDrawable		8
#define X_XF86DRIGetDrawableInfo		9
#define X_XF86DRIGetDeviceInfo			10
#define X_XF86DRIAuthConnection                 11
#define X_XF86DRIOpenFullScreen                 12   /* Deprecated */
#define X_XF86DRICloseFullScreen                13   /* Deprecated */

#define XF86DRINumberEvents		0

#define XF86DRIClientNotLocal		0
#define XF86DRIOperationNotSupported	1
#define XF86DRINumberErrors		(XF86DRIOperationNotSupported + 1)

#endif /* _XF86DRI_H_ */

