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

#ifndef XF86OPTIONSTR_H
#define XF86OPTIONSTR_H
#include "list.h"

/*
 * All options are stored using this data type.
 */
typedef struct _XF86OptionRec {
    GenericListRec list;
    const char *opt_name;
    const char *opt_val;
    int opt_used;
    const char *opt_comment;
} XF86OptionRec;

typedef struct _InputOption *XF86OptionPtr;

#endif
