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
 * mipointrst.h
 *
 */

/*

Copyright 1989, 1998  The Open Group

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
*/

#ifndef MIPOINTRST_H
#define MIPOINTRST_H

#include "mipointer.h"
#include "scrnintstr.h"

typedef struct {
    ScreenPtr pScreen;          /* current screen */
    ScreenPtr pSpriteScreen;    /* screen containing current sprite */
    CursorPtr pCursor;          /* current cursor */
    CursorPtr pSpriteCursor;    /* cursor on screen */
    BoxRec limits;              /* current constraints */
    Bool confined;              /* pointer can't change screens */
    int x, y;                   /* hot spot location */
    int devx, devy;             /* sprite position */
    Bool generateEvent;         /* generate an event during warping? */
} miPointerRec, *miPointerPtr;

typedef struct {
    miPointerSpriteFuncPtr spriteFuncs; /* sprite-specific methods */
    miPointerScreenFuncPtr screenFuncs; /* screen-specific methods */
    CloseScreenProcPtr CloseScreen;
    Bool waitForUpdate;         /* don't move cursor in SIGIO */
    Bool showTransparent;       /* show empty cursors */
} miPointerScreenRec, *miPointerScreenPtr;
#endif                          /* MIPOINTRST_H */
