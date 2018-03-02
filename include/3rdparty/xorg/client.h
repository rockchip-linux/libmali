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

/* Author: Rami Ylimäki <rami.ylimaki@vincit.fi> */

#ifndef CLIENT_H
#define CLIENT_H

#ifdef HAVE_DIX_CONFIG_H
#include <dix-config.h>
#endif                          /* HAVE_DIX_CONFIG_H */
#include <X11/Xfuncproto.h>
#include <sys/types.h>

/* Client IDs. Use GetClientPid, GetClientCmdName and GetClientCmdArgs
 * instead of accessing the fields directly. */
typedef struct {
    pid_t pid;                  /* process ID, -1 if not available */
    const char *cmdname;        /* process name, NULL if not available */
    const char *cmdargs;        /* process arguments, NULL if not available */
} ClientIdRec, *ClientIdPtr;

struct _Client;

/* Initialize and clean up. */
void ReserveClientIds(struct _Client *client);
void ReleaseClientIds(struct _Client *client);

/* Determine client IDs for caching. Exported on purpose for
 * extensions such as SELinux. */
extern _X_EXPORT pid_t DetermineClientPid(struct _Client *client);
extern _X_EXPORT void DetermineClientCmd(pid_t, const char **cmdname,
                                         const char **cmdargs);

/* Query cached client IDs. Exported on purpose for drivers. */
extern _X_EXPORT pid_t GetClientPid(struct _Client *client);
extern _X_EXPORT const char *GetClientCmdName(struct _Client *client);
extern _X_EXPORT const char *GetClientCmdArgs(struct _Client *client);

#endif                          /* CLIENT_H */
