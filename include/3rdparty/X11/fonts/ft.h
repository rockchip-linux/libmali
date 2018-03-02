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

#ifndef _FT_H_
#define _FT_H_

#include <X11/Xfuncproto.h>

#define FREETYPE_VERSION (FREETYPE_MAJOR * 1000000 + FREETYPE_MINOR * 1000 + FREETYPE_PATCH)

#undef DEBUG_TRUETYPE

#ifdef DEBUG_TRUETYPE
#define MUMBLE ErrorF
#else
#define MUMBLE(...)
#endif

#undef MAX
#define MAX(h,i) ((h) > (i) ? (h) : (i))
#define ADJUSTMAX(m,v) if((v)>(m)) (m)=(v)
#undef MIN
#define MIN(l,o) ((l) < (o) ? (l) : (o))
#define ADJUSTMIN(m,v) if ((v)<(m)) (m)=(v)

/* When comparing floating point values, we want to ignore small errors. */
#define NEGLIGIBLE ((double)0.001)
/* Are x and y significantly different? */
#define DIFFER(x,y) (fabs((x)-(y))>=NEGLIGIBLE*fabs(x))
/* Is x significantly different from 0 w.r.t. y? */
#define DIFFER0(x,y) (fabs(x)>=NEGLIGIBLE*fabs(y))

#ifndef ABS
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#endif

/* Two to the sixteenth power, as a double. */
#define TWO_SIXTEENTH ((double)(1<<16))
#define TWO_SIXTH ((double)(1<<6))

/* Data structures used across files */

typedef struct _FTMapping
{
    int named;
    FT_CharMap cmap;
    int base;
    struct _FontMap *mapping;     /* allow inclusion without fontenc.h */
} FTMappingRec, *FTMappingPtr;

/* Prototypes */

/* ftfuncs.c */

/* ftenc.c */

int FTPickMapping(char*, int, char*, FT_Face, FTMappingPtr);
unsigned FTRemap(FT_Face face, FTMappingPtr, unsigned code);

/* fttools.c */

int FTtoXReturnCode(int);
int FTGetEnglishName(FT_Face, int, char *, int);

extern void ErrorF(const char*, ...);

#endif /* _FT_H_ */
