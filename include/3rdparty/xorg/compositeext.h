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

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif

#ifndef _COMPOSITEEXT_H_
#define _COMPOSITEEXT_H_

#include "misc.h"
#include "scrnintstr.h"

extern _X_EXPORT Bool CompositeRegisterAlternateVisuals(ScreenPtr pScreen,
                                                        VisualID * vids,
                                                        int nVisuals);

extern _X_EXPORT Bool CompositeRegisterImplicitRedirectionException(ScreenPtr pScreen,
                                                                    VisualID parentVisual,
                                                                    VisualID winVisual);

extern _X_EXPORT RESTYPE CompositeClientWindowType;

#endif                          /* _COMPOSITEEXT_H_ */
