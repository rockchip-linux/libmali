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

#ifndef HOTPLUG_H
#define HOTPLUG_H

#include "list.h"

extern _X_EXPORT void config_pre_init(void);
extern _X_EXPORT void config_init(void);
extern _X_EXPORT void config_fini(void);

/* Bump this each time you add something to the struct
 * so that drivers can easily tell what is available
 */
#define ODEV_ATTRIBUTES_VERSION         1

struct OdevAttributes {
    /* path to kernel device node - Linux e.g. /dev/dri/card0 */
    char        *path;

    /* system device path - Linux e.g. /sys/devices/pci0000:00/0000:00:01.0/0000:01:00.0/drm/card1 */
    char        *syspath;

    /* DRI-style bus id */
    char        *busid;

    /* Server managed FD */
    int         fd;

    /* Major number of the device node pointed to by ODEV_ATTRIB_PATH */
    int         major;

    /* Minor number of the device node pointed to by ODEV_ATTRIB_PATH */
    int         minor;

    /* kernel driver name */
    char        *driver;
};

/* Note starting with xserver 1.16 this function never fails */
struct OdevAttributes *
config_odev_allocate_attributes(void);

void
config_odev_free_attributes(struct OdevAttributes *attribs);

typedef void (*config_odev_probe_proc_ptr)(struct OdevAttributes *attribs);
void config_odev_probe(config_odev_probe_proc_ptr probe_callback);

#ifdef CONFIG_UDEV_KMS
void NewGPUDeviceRequest(struct OdevAttributes *attribs);
void DeleteGPUDeviceRequest(struct OdevAttributes *attribs);
#endif

#define ServerIsNotSeat0() (SeatId && strcmp(SeatId, "seat0"))

struct xf86_platform_device *
xf86_find_platform_device_by_devnum(int major, int minor);

#endif                          /* HOTPLUG_H */
