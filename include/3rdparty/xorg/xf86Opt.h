
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

/* Option handling things that ModuleSetup procs can use */

#ifndef _XF86_OPT_H_
#define _XF86_OPT_H_
#include "xf86Optionstr.h"

typedef struct {
    double freq;
    int units;
} OptFrequency;

typedef union {
    unsigned long num;
    const char *str;
    double realnum;
    Bool bool;
    OptFrequency freq;
} ValueUnion;

typedef enum {
    OPTV_NONE = 0,
    OPTV_INTEGER,
    OPTV_STRING,                /* a non-empty string */
    OPTV_ANYSTR,                /* Any string, including an empty one */
    OPTV_REAL,
    OPTV_BOOLEAN,
    OPTV_PERCENT,
    OPTV_FREQ
} OptionValueType;

typedef enum {
    OPTUNITS_HZ = 1,
    OPTUNITS_KHZ,
    OPTUNITS_MHZ
} OptFreqUnits;

typedef struct {
    int token;
    const char *name;
    OptionValueType type;
    ValueUnion value;
    Bool found;
} OptionInfoRec, *OptionInfoPtr;

extern _X_EXPORT int xf86SetIntOption(XF86OptionPtr optlist, const char *name,
                                      int deflt);
extern _X_EXPORT double xf86SetRealOption(XF86OptionPtr optlist,
                                          const char *name, double deflt);
extern _X_EXPORT char *xf86SetStrOption(XF86OptionPtr optlist, const char *name,
                                        const char *deflt);
extern _X_EXPORT int xf86SetBoolOption(XF86OptionPtr list, const char *name,
                                       int deflt);
extern _X_EXPORT double xf86SetPercentOption(XF86OptionPtr list,
                                             const char *name, double deflt);
extern _X_EXPORT int xf86CheckIntOption(XF86OptionPtr optlist, const char *name,
                                        int deflt);
extern _X_EXPORT double xf86CheckRealOption(XF86OptionPtr optlist,
                                            const char *name, double deflt);
extern _X_EXPORT char *xf86CheckStrOption(XF86OptionPtr optlist,
                                          const char *name, const char *deflt);
extern _X_EXPORT int xf86CheckBoolOption(XF86OptionPtr list, const char *name,
                                         int deflt);
extern _X_EXPORT double xf86CheckPercentOption(XF86OptionPtr list,
                                               const char *name, double deflt);
extern _X_EXPORT XF86OptionPtr xf86AddNewOption(XF86OptionPtr head,
                                                const char *name,
                                                const char *val);
extern _X_EXPORT XF86OptionPtr xf86NewOption(char *name, char *value);
extern _X_EXPORT XF86OptionPtr xf86NextOption(XF86OptionPtr list);
extern _X_EXPORT XF86OptionPtr xf86OptionListCreate(const char **options,
                                                    int count, int used);
extern _X_EXPORT XF86OptionPtr xf86OptionListMerge(XF86OptionPtr head,
                                                   XF86OptionPtr tail);
extern _X_EXPORT XF86OptionPtr xf86OptionListDuplicate(XF86OptionPtr list);
extern _X_EXPORT void xf86OptionListFree(XF86OptionPtr opt);
extern _X_EXPORT char *xf86OptionName(XF86OptionPtr opt);
extern _X_EXPORT char *xf86OptionValue(XF86OptionPtr opt);
extern _X_EXPORT void xf86OptionListReport(XF86OptionPtr parm);
extern _X_EXPORT XF86OptionPtr xf86FindOption(XF86OptionPtr options,
                                              const char *name);
extern _X_EXPORT const char *xf86FindOptionValue(XF86OptionPtr options,
                                                 const char *name);
extern _X_EXPORT void xf86MarkOptionUsed(XF86OptionPtr option);
extern _X_EXPORT void xf86MarkOptionUsedByName(XF86OptionPtr options,
                                               const char *name);
extern _X_EXPORT Bool xf86CheckIfOptionUsed(XF86OptionPtr option);
extern _X_EXPORT Bool xf86CheckIfOptionUsedByName(XF86OptionPtr options,
                                                  const char *name);
extern _X_EXPORT void xf86ShowUnusedOptions(int scrnIndex,
                                            XF86OptionPtr options);
extern _X_EXPORT void xf86ProcessOptions(int scrnIndex, XF86OptionPtr options,
                                         OptionInfoPtr optinfo);
extern _X_EXPORT OptionInfoPtr xf86TokenToOptinfo(const OptionInfoRec * table,
                                                  int token);
extern _X_EXPORT const char *xf86TokenToOptName(const OptionInfoRec * table,
                                                int token);
extern _X_EXPORT Bool xf86IsOptionSet(const OptionInfoRec * table, int token);
extern _X_EXPORT const char *xf86GetOptValString(const OptionInfoRec * table,
                                           int token);
extern _X_EXPORT Bool xf86GetOptValInteger(const OptionInfoRec * table,
                                           int token, int *value);
extern _X_EXPORT Bool xf86GetOptValULong(const OptionInfoRec * table, int token,
                                         unsigned long *value);
extern _X_EXPORT Bool xf86GetOptValReal(const OptionInfoRec * table, int token,
                                        double *value);
extern _X_EXPORT Bool xf86GetOptValFreq(const OptionInfoRec * table, int token,
                                        OptFreqUnits expectedUnits,
                                        double *value);
extern _X_EXPORT Bool xf86GetOptValBool(const OptionInfoRec * table, int token,
                                        Bool *value);
extern _X_EXPORT Bool xf86ReturnOptValBool(const OptionInfoRec * table,
                                           int token, Bool def);
extern _X_EXPORT int xf86NameCmp(const char *s1, const char *s2);
extern _X_EXPORT char *xf86NormalizeName(const char *s);
extern _X_EXPORT XF86OptionPtr xf86ReplaceIntOption(XF86OptionPtr optlist,
                                                    const char *name,
                                                    const int val);
extern _X_EXPORT XF86OptionPtr xf86ReplaceRealOption(XF86OptionPtr optlist,
                                                     const char *name,
                                                     const double val);
extern _X_EXPORT XF86OptionPtr xf86ReplaceBoolOption(XF86OptionPtr optlist,
                                                     const char *name,
                                                     const Bool val);
extern _X_EXPORT XF86OptionPtr xf86ReplacePercentOption(XF86OptionPtr optlist,
                                                        const char *name,
                                                        const double val);
extern _X_EXPORT XF86OptionPtr xf86ReplaceStrOption(XF86OptionPtr optlist,
                                                    const char *name,
                                                    const char *val);
#endif
