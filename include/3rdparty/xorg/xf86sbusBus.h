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

#ifndef _XF86_SBUSBUS_H
#define _XF86_SBUSBUS_H

#include "xf86str.h"

#define SBUS_DEVICE_BW2		0x0001
#define SBUS_DEVICE_CG2		0x0002
#define SBUS_DEVICE_CG3		0x0003
#define SBUS_DEVICE_CG4		0x0004
#define SBUS_DEVICE_CG6		0x0005
#define SBUS_DEVICE_CG8		0x0006
#define SBUS_DEVICE_CG12	0x0007
#define SBUS_DEVICE_CG14	0x0008
#define SBUS_DEVICE_LEO		0x0009
#define SBUS_DEVICE_TCX		0x000a
#define SBUS_DEVICE_FFB		0x000b
#define SBUS_DEVICE_GT		0x000c
#define SBUS_DEVICE_MGX		0x000d

typedef struct sbus_prom_node {
    int node;
    /* Because of misdesigned openpromio */
    int cookie[2];
} sbusPromNode, *sbusPromNodePtr;

typedef struct sbus_device {
    int devId;
    int fbNum;
    int fd;
    int width, height;
    sbusPromNode node;
    const char *descr;
    const char *device;
} sbusDevice, *sbusDevicePtr;

struct sbus_devtable {
    int devId;
    int fbType;
    const char *promName;
    const char *driverName;
    const char *descr;
};

extern _X_EXPORT void xf86SbusProbe(void);
extern _X_EXPORT sbusDevicePtr *xf86SbusInfo;
extern _X_EXPORT struct sbus_devtable sbusDeviceTable[];

extern _X_EXPORT int xf86MatchSbusInstances(const char *driverName,
                                            int sbusDevId, GDevPtr * devList,
                                            int numDevs, DriverPtr drvp,
                                            int **foundEntities);
extern _X_EXPORT sbusDevicePtr xf86GetSbusInfoForEntity(int entityIndex);
extern _X_EXPORT int xf86GetEntityForSbusInfo(sbusDevicePtr psdp);
extern _X_EXPORT void xf86SbusUseBuiltinMode(ScrnInfoPtr pScrn,
                                             sbusDevicePtr psdp);
extern _X_EXPORT void *xf86MapSbusMem(sbusDevicePtr psdp,
                                        unsigned long offset,
                                        unsigned long size);
extern _X_EXPORT void xf86UnmapSbusMem(sbusDevicePtr psdp, void *addr,
                                       unsigned long size);
extern _X_EXPORT void xf86SbusHideOsHwCursor(sbusDevicePtr psdp);
extern _X_EXPORT void xf86SbusSetOsHwCursorCmap(sbusDevicePtr psdp, int bg,
                                                int fg);
extern _X_EXPORT Bool xf86SbusHandleColormaps(ScreenPtr pScreen,
                                              sbusDevicePtr psdp);

extern _X_EXPORT int promRootNode;

extern _X_EXPORT int promGetSibling(int node);
extern _X_EXPORT int promGetChild(int node);
extern _X_EXPORT char *promGetProperty(const char *prop, int *lenp);
extern _X_EXPORT int promGetBool(const char *prop);

extern _X_EXPORT int sparcPromInit(void);
extern _X_EXPORT void sparcPromClose(void);
extern _X_EXPORT char *sparcPromGetProperty(sbusPromNodePtr pnode,
                                            const char *prop, int *lenp);
extern _X_EXPORT int sparcPromGetBool(sbusPromNodePtr pnode, const char *prop);
extern _X_EXPORT void sparcPromAssignNodes(void);
extern _X_EXPORT char *sparcPromNode2Pathname(sbusPromNodePtr pnode);
extern _X_EXPORT int sparcPromPathname2Node(const char *pathName);
extern _X_EXPORT char *sparcDriverName(void);

extern Bool xf86SbusConfigure(void *busData, sbusDevicePtr sBus);
extern void xf86SbusConfigureNewDev(void *busData, sbusDevicePtr sBus,
                                    GDevRec * GDev);

#endif                          /* _XF86_SBUSBUS_H */
