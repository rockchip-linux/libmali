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

#ifndef _MISYNCSTR_H_
#define _MISYNCSTR_H_

#include "dix.h"
#include "misync.h"
#include "scrnintstr.h"
#include <X11/extensions/syncconst.h>

#define CARD64 XSyncValue       /* XXX temporary! need real 64 bit values for Alpha */

/* Sync object types */
#define SYNC_COUNTER		0
#define SYNC_FENCE		1

typedef struct _SyncObject {
    ClientPtr client;           /* Owning client. 0 for system counters */
    struct _SyncTriggerList *pTriglist; /* list of triggers */
    XID id;                     /* resource ID */
    unsigned char type;         /* SYNC_* */
    Bool beingDestroyed;        /* in process of going away */
} SyncObject;

typedef struct _SyncCounter {
    SyncObject sync;            /* Common sync object data */
    CARD64 value;               /* counter value */
    struct _SysCounterInfo *pSysCounterInfo;    /* NULL if not a system counter */
} SyncCounter;

struct _SyncFence {
    SyncObject sync;            /* Common sync object data */
    ScreenPtr pScreen;          /* Screen of this fence object */
    SyncFenceFuncsRec funcs;    /* Funcs for performing ops on fence */
    Bool triggered;             /* fence state */
    PrivateRec *devPrivates;    /* driver-specific per-fence data */
};

struct _SyncTrigger {
    SyncObject *pSync;
    CARD64 wait_value;          /* wait value */
    unsigned int value_type;    /* Absolute or Relative */
    unsigned int test_type;     /* transition or Comparision type */
    CARD64 test_value;          /* trigger event threshold value */
    Bool (*CheckTrigger) (struct _SyncTrigger * /*pTrigger */ ,
                          CARD64        /*newval */
        );
    void (*TriggerFired) (struct _SyncTrigger * /*pTrigger */
        );
    void (*CounterDestroyed) (struct _SyncTrigger *     /*pTrigger */
        );
};

typedef struct _SyncTriggerList {
    SyncTrigger *pTrigger;
    struct _SyncTriggerList *next;
} SyncTriggerList;

extern DevPrivateKeyRec miSyncScreenPrivateKey;

#define SYNC_SCREEN_PRIV(pScreen) 				\
    (SyncScreenPrivPtr) dixLookupPrivate(&pScreen->devPrivates,	\
					 &miSyncScreenPrivateKey)

typedef struct _syncScreenPriv {
    /* Wrappable sync-specific screen functions */
    SyncScreenFuncsRec funcs;

    /* Wrapped screen functions */
    CloseScreenProcPtr CloseScreen;
} SyncScreenPrivRec, *SyncScreenPrivPtr;

#endif                          /* _MISYNCSTR_H_ */
