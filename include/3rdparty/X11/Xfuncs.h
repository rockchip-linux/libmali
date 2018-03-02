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
/*
 * 
Copyright 1990, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.
 *
 */

#ifndef _XFUNCS_H_
# define _XFUNCS_H_

# include <X11/Xosdefs.h>

/* the old Xfuncs.h, for pre-R6 */
# if !(defined(XFree86LOADER) && defined(IN_MODULE))

#  ifdef X_USEBFUNCS
void bcopy();
void bzero();
int bcmp();
#  else
#   if defined(SYSV) && !defined(__SCO__) && !defined(__sun) && !defined(__UNIXWARE__) && !defined(_AIX)
#    include <memory.h>
void bcopy();
#    define bzero(b,len) memset(b, 0, len)
#    define bcmp(b1,b2,len) memcmp(b1, b2, len)
#   else
#    include <string.h>
#    if defined(__SCO__) || defined(__sun) || defined(__UNIXWARE__) || defined(__CYGWIN__) || defined(_AIX) || defined(__APPLE__)
#     include <strings.h>
#    endif
#    define _XFUNCS_H_INCLUDED_STRING_H
#   endif
#  endif /* X_USEBFUNCS */

/* the new Xfuncs.h */

/* the ANSI C way */
#  ifndef _XFUNCS_H_INCLUDED_STRING_H
#   include <string.h>
#  endif
#  undef bzero
#  define bzero(b,len) memset(b,0,len)

#  if defined WIN32 && defined __MINGW32__
#   define bcopy(b1,b2,len) memmove(b2, b1, (size_t)(len))
#  endif

# endif /* !(defined(XFree86LOADER) && defined(IN_MODULE)) */

#endif /* _XFUNCS_H_ */
