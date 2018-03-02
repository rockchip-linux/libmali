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

#ifndef POINTERVELOCITY_H
#define POINTERVELOCITY_H

#include <input.h>

/* constants for acceleration profiles */

#define AccelProfileNone -1
#define AccelProfileClassic  0
#define AccelProfileDeviceSpecific 1
#define AccelProfilePolynomial 2
#define AccelProfileSmoothLinear 3
#define AccelProfileSimple 4
#define AccelProfilePower 5
#define AccelProfileLinear 6
#define AccelProfileSmoothLimited 7
#define AccelProfileLAST AccelProfileSmoothLimited

/* fwd */
struct _DeviceVelocityRec;

/**
 * profile
 * returns actual acceleration depending on velocity, acceleration control,...
 */
typedef double (*PointerAccelerationProfileFunc)
 (DeviceIntPtr dev, struct _DeviceVelocityRec * vel,
  double velocity, double threshold, double accelCoeff);

/**
 * a motion history, with just enough information to
 * calc mean velocity and decide which motion was along
 * a more or less straight line
 */
typedef struct _MotionTracker {
    double dx, dy;              /* accumulated delta for each axis */
    int time;                   /* time of creation */
    int dir;                    /* initial direction bitfield */
} MotionTracker, *MotionTrackerPtr;

/**
 * Contains all data needed to implement mouse ballistics
 */
typedef struct _DeviceVelocityRec {
    MotionTrackerPtr tracker;
    int num_tracker;
    int cur_tracker;            /* current index */
    double velocity;            /* velocity as guessed by algorithm */
    double last_velocity;       /* previous velocity estimate */
    double last_dx;             /* last time-difference */
    double last_dy;             /* phase of last/current estimate */
    double corr_mul;            /* config: multiply this into velocity */
    double const_acceleration;  /* config: (recipr.) const deceleration */
    double min_acceleration;    /* config: minimum acceleration */
    short reset_time;           /* config: reset non-visible state after # ms */
    short use_softening;        /* config: use softening of mouse values */
    double max_rel_diff;        /* config: max. relative difference */
    double max_diff;            /* config: max. difference */
    int initial_range;          /* config: max. offset used as initial velocity */
    Bool average_accel;         /* config: average acceleration over velocity */
    PointerAccelerationProfileFunc Profile;
    PointerAccelerationProfileFunc deviceSpecificProfile;
    void *profile_private;      /* extended data, see  SetAccelerationProfile() */
    struct {                    /* to be able to query this information */
        int profile_number;
    } statistics;
} DeviceVelocityRec, *DeviceVelocityPtr;

/**
 * contains the run-time data for the predictable scheme, that is, a
 * DeviceVelocityPtr and the property handlers.
 */
typedef struct _PredictableAccelSchemeRec {
    DeviceVelocityPtr vel;
    long *prop_handlers;
    int num_prop_handlers;
} PredictableAccelSchemeRec, *PredictableAccelSchemePtr;

extern _X_EXPORT void
InitVelocityData(DeviceVelocityPtr vel);

extern _X_EXPORT void
InitTrackers(DeviceVelocityPtr vel, int ntracker);

extern _X_EXPORT BOOL
ProcessVelocityData2D(DeviceVelocityPtr vel, double dx, double dy, int time);

extern _X_EXPORT double
BasicComputeAcceleration(DeviceIntPtr dev, DeviceVelocityPtr vel,
                         double velocity, double threshold, double acc);

extern _X_EXPORT void
FreeVelocityData(DeviceVelocityPtr vel);

extern _X_EXPORT int
SetAccelerationProfile(DeviceVelocityPtr vel, int profile_num);

extern _X_EXPORT DeviceVelocityPtr
GetDevicePredictableAccelData(DeviceIntPtr dev);

extern _X_EXPORT void
SetDeviceSpecificAccelerationProfile(DeviceVelocityPtr vel,
                                     PointerAccelerationProfileFunc profile);

extern _X_INTERNAL void
AccelerationDefaultCleanup(DeviceIntPtr dev);

extern _X_INTERNAL Bool
InitPredictableAccelerationScheme(DeviceIntPtr dev,
                                  struct _ValuatorAccelerationRec *protoScheme);

extern _X_INTERNAL void
acceleratePointerPredictable(DeviceIntPtr dev, ValuatorMask *val,
                             CARD32 evtime);

extern _X_INTERNAL void
acceleratePointerLightweight(DeviceIntPtr dev, ValuatorMask *val,
                             CARD32 evtime);

#endif                          /* POINTERVELOCITY_H */
