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

/* Binary compatibility entry points. */

/* This file includes code to make modules compiled for earlier
   versions of the fontenc interfaces link with this one.  It does
   *not* provide source compatibility, as many of the data structures
   now have different names. */

extern char *font_encoding_from_xlfd(const char*, int);
extern unsigned font_encoding_recode(unsigned, FontEncPtr, FontMapPtr);
extern FontEncPtr font_encoding_find(const char*, const char*);
extern char *font_encoding_name(unsigned, FontEncPtr, FontMapPtr);
extern char **identifyEncodingFile(const char *fileName);

