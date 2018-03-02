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
#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif

#ifndef _GEINT_H_
#define _GEINT_H_

#include <X11/X.h>
#include <X11/Xproto.h>
#include "misc.h"
#include "os.h"
#include "dixstruct.h"
#include "extnsionst.h"
#include <X11/extensions/geproto.h>

extern _X_EXPORT DevPrivateKeyRec GEClientPrivateKeyRec;

#define GEClientPrivateKey (&GEClientPrivateKeyRec)

typedef struct _GEClientInfo {
    CARD32 major_version;
    CARD32 minor_version;
} GEClientInfoRec, *GEClientInfoPtr;

#define GEGetClient(pClient)    ((GEClientInfoPtr)(dixLookupPrivate(&((pClient)->devPrivates), GEClientPrivateKey)))

extern _X_EXPORT int (*ProcGEVector[ /*GENumRequests */ ]) (ClientPtr);
extern _X_EXPORT int (*SProcGEVector[ /*GENumRequests */ ]) (ClientPtr);

#endif                          /* _GEINT_H_ */
