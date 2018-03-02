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
#ifndef _FONTUTIL_H_
#define _FONTUTIL_H_

#include <X11/fonts/FSproto.h>

extern int FontCouldBeTerminal(FontInfoPtr);
extern int CheckFSFormat(fsBitmapFormat, fsBitmapFormatMask, int *, int *,
			 int *, int *, int *);
extern void FontComputeInfoAccelerators(FontInfoPtr);

extern void GetGlyphs ( FontPtr font, unsigned long count,
			unsigned char *chars, FontEncoding fontEncoding,
			unsigned long *glyphcount, CharInfoPtr *glyphs );
extern void QueryGlyphExtents ( FontPtr pFont, CharInfoPtr *charinfo,
				unsigned long count, ExtentInfoRec *info );
extern Bool QueryTextExtents ( FontPtr pFont, unsigned long count,
			       unsigned char *chars, ExtentInfoRec *info );
extern Bool ParseGlyphCachingMode ( char *str );
extern void InitGlyphCaching ( void );
extern void SetGlyphCachingMode ( int newmode );
extern int add_range ( fsRange *newrange, int *nranges, fsRange **range,
		       Bool charset_subset );

#endif /* _FONTUTIL_H_ */
