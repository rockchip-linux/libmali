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
/***********************************************************

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************/

#ifndef DIX_REGISTRY_H
#define DIX_REGISTRY_H

/*
 * Result returned from any unsuccessful lookup
 */
#define XREGISTRY_UNKNOWN "<unknown>"

#include "resource.h"
#include "extnsionst.h"

#if defined(XSELINUX) || defined(RES)
#define X_REGISTRY_RESOURCE       1
#endif

#if defined(XSELINUX) || defined(XCSECURITY) || defined(XSERVER_DTRACE)
#define X_REGISTRY_REQUEST        1
#endif

/* Internal string registry - for auditing, debugging, security, etc. */

#ifdef X_REGISTRY_RESOURCE
/* Functions used by the X-Resource extension */
extern _X_EXPORT void RegisterResourceName(RESTYPE type, const char *name);
extern _X_EXPORT const char *LookupResourceName(RESTYPE rtype);
#endif

#ifdef X_REGISTRY_REQUEST
extern _X_EXPORT void RegisterExtensionNames(ExtensionEntry * ext);

/*
 * Lookup functions.  The returned string must not be modified or freed.
 */
extern _X_EXPORT const char *LookupMajorName(int major);
extern _X_EXPORT const char *LookupRequestName(int major, int minor);
extern _X_EXPORT const char *LookupEventName(int event);
extern _X_EXPORT const char *LookupErrorName(int error);
#endif

/*
 * Setup and teardown
 */
extern _X_EXPORT void dixResetRegistry(void);
extern _X_EXPORT void dixFreeRegistry(void);
extern _X_EXPORT void dixCloseRegistry(void);

#endif                          /* DIX_REGISTRY_H */
