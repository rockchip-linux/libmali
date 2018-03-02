
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

#ifndef XORG_VERSION_H
#define XORG_VERSION_H

#ifndef XORG_VERSION_CURRENT
#error
#endif

#define XORG_VERSION_NUMERIC(major,minor,patch,snap,dummy) \
	(((major) * 10000000) + ((minor) * 100000) + ((patch) * 1000) + snap)

#define XORG_GET_MAJOR_VERSION(vers)	((vers) / 10000000)
#define XORG_GET_MINOR_VERSION(vers)	(((vers) % 10000000) / 100000)
#define XORG_GET_PATCH_VERSION(vers)	(((vers) % 100000) / 1000)
#define XORG_GET_SNAP_VERSION(vers)	((vers) % 1000)

#define XORG_VERSION_MAJOR	XORG_GET_MAJOR_VERSION(XORG_VERSION_CURRENT)
#define XORG_VERSION_MINOR	XORG_GET_MINOR_VERSION(XORG_VERSION_CURRENT)
#define XORG_VERSION_PATCH	XORG_GET_PATCH_VERSION(XORG_VERSION_CURRENT)
#define XORG_VERSION_SNAP	XORG_GET_SNAP_VERSION(XORG_VERSION_CURRENT)

#endif
