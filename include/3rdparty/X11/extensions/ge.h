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

#ifndef _GE_H_
#define _GE_H_

#define GE_NAME         "Generic Event Extension"
#define GE_MAJOR        1
#define GE_MINOR        0

/*********************************************************
 *
 * Requests
 *
 */

#define X_GEQueryVersion        0

#define GENumberRequests       (X_GEQueryVersion + 1)

/*********************************************************
 *
 * Events
 *
 */

#define GENumberEvents        0

/*********************************************************
 *
 * Errors
 *
 */

#define GENumberErrors        0

#endif /* _GE_H_ */
