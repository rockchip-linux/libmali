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

#ifndef _SAVER_H_
#define _SAVER_H_

#define ScreenSaverName	"MIT-SCREEN-SAVER"
#define ScreenSaverPropertyName "_MIT_SCREEN_SAVER_ID"

#define ScreenSaverNotifyMask	0x00000001
#define ScreenSaverCycleMask	0x00000002

#define ScreenSaverMajorVersion	1
#define ScreenSaverMinorVersion	1

#define ScreenSaverOff		0
#define ScreenSaverOn		1
#define ScreenSaverCycle	2
#define ScreenSaverDisabled	3

#define ScreenSaverBlanked	0
#define ScreenSaverInternal	1
#define ScreenSaverExternal	2

#define ScreenSaverNotify	0
#define ScreenSaverNumberEvents	1

#endif /* _SAVER_H_ */
