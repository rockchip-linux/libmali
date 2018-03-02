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

#ifndef _X11_IMUTIL_H_
#define _X11_IMUTIL_H_

extern int
_XGetScanlinePad(
    Display *dpy,
    int depth);

extern int
_XGetBitsPerPixel(
 Display *dpy,
 int depth);

extern int
_XSetImage(
    XImage *srcimg,
    register XImage *dstimg,
    register int x,
    register int y);

extern int
_XReverse_Bytes(
    register unsigned char *bpt,
    register int nb);
extern void
_XInitImageFuncPtrs(
    register XImage *image);

#endif /* _X11_IMUTIL_H_ */
