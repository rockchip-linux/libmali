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

#ifndef DBE_H
#define DBE_H

/* Values for swap_action field of XdbeSwapInfo structure */
#define XdbeUndefined    0
#define XdbeBackground   1
#define XdbeUntouched    2
#define XdbeCopied       3

/* Errors */
#define XdbeBadBuffer    0

#define DBE_PROTOCOL_NAME "DOUBLE-BUFFER"

/* Current version numbers */
#define DBE_MAJOR_VERSION       1
#define DBE_MINOR_VERSION       0

/* Used when adding extension; also used in Xdbe macros */
#define DbeNumberEvents			0
#define DbeBadBuffer			0
#define DbeNumberErrors			(DbeBadBuffer + 1)

#endif /* DBE_H */

