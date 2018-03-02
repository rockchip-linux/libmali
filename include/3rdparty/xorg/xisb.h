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

#ifndef	_xisb_H_
#define _xisb_H_

#include <unistd.h>

/******************************************************************************
 *		Definitions
 *									structs, typedefs, #defines, enums
 *****************************************************************************/

typedef struct _XISBuffer {
    int fd;
    int trace;
    int block_duration;
    ssize_t current;            /* bytes read */
    ssize_t end;
    ssize_t buffer_size;
    unsigned char *buf;
} XISBuffer;

/******************************************************************************
 *		Declarations
 *								variables:	use xisb_LOC in front
 *											of globals.
 *											put locals in the .c file.
 *****************************************************************************/
extern _X_EXPORT XISBuffer *XisbNew(int fd, ssize_t size);
extern _X_EXPORT void XisbFree(XISBuffer * b);
extern _X_EXPORT int XisbRead(XISBuffer * b);
extern _X_EXPORT ssize_t XisbWrite(XISBuffer * b, unsigned char *msg,
                                   ssize_t len);
extern _X_EXPORT void XisbTrace(XISBuffer * b, int trace);
extern _X_EXPORT void XisbBlockDuration(XISBuffer * b, int block_duration);

/*
 *	DO NOT PUT ANYTHING AFTER THIS ENDIF
 */
#endif
