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

#ifndef EVENTS_H
#define EVENTS_H
typedef struct _DeviceEvent DeviceEvent;
typedef struct _DeviceChangedEvent DeviceChangedEvent;
typedef struct _TouchOwnershipEvent TouchOwnershipEvent;
typedef struct _BarrierEvent BarrierEvent;

#if XFreeXDGA
typedef struct _DGAEvent DGAEvent;
#endif
typedef struct _RawDeviceEvent RawDeviceEvent;

#ifdef XQUARTZ
typedef struct _XQuartzEvent XQuartzEvent;
#endif
typedef union _InternalEvent InternalEvent;

#endif
