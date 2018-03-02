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

#ifndef _X11_EXTENSIONS_DPMS_H
#define _X11_EXTENSIONS_DPMS_H 1

#include <X11/X.h>
#include <X11/Xmd.h>
#include <X11/extensions/dpmsconst.h>

#ifndef DPMS_SERVER
_XFUNCPROTOBEGIN

extern Bool DPMSQueryExtension(Display *, int *, int *);
extern Status DPMSGetVersion(Display *, int *, int *);
extern Bool DPMSCapable(Display *);
extern Status DPMSSetTimeouts(Display *, CARD16, CARD16, CARD16);
extern Bool DPMSGetTimeouts(Display *, CARD16 *, CARD16 *, CARD16 *);
extern Status DPMSEnable(Display *);
extern Status DPMSDisable(Display *);
extern Status DPMSForceLevel(Display *, CARD16);
extern Status DPMSInfo(Display *, CARD16 *, BOOL *);

_XFUNCPROTOEND
#endif

#endif /* !_X11_EXTENSIONS_DPMS_H */

