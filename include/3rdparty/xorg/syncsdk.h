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

#ifndef _SYNCSDK_H_
#define _SYNCSDK_H_

#include "misync.h"

extern _X_EXPORT int
 SyncVerifyFence(SyncFence ** ppFence, XID fid, ClientPtr client, Mask mode);

#define VERIFY_SYNC_FENCE(pFence, fid, client, mode)			\
    do {								\
	int rc;								\
	rc = SyncVerifyFence(&(pFence), (fid), (client), (mode));	\
	if (Success != rc) return rc;					\
    } while (0)

#define VERIFY_SYNC_FENCE_OR_NONE(pFence, fid, client, mode)		\
    do {								\
        pFence = 0;							\
        if (None != fid)						\
	    VERIFY_SYNC_FENCE((pFence), (fid), (client), (mode));	\
    } while (0)

#endif                          /* _SYNCSDK_H_ */
