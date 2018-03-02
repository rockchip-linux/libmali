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

/* $Revision: 11708 $ on $Date: 2010-06-13 23:36:24 -0700 (Sun, 13 Jun 2010) $ */

/* cl_gl_ext.h contains vendor (non-KHR) OpenCL extensions which have           */
/* OpenGL dependencies.                                                         */

#ifndef __OPENCL_CL_GL_EXT_H
#define __OPENCL_CL_GL_EXT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __APPLE__
    #include <OpenCL/cl_gl.h>
#else
    #include <CL/cl_gl.h>
#endif

/*
 * For each extension, follow this template
 *  cl_VEN_extname extension  */
/* #define cl_VEN_extname 1
 * ... define new types, if any
 * ... define new tokens, if any
 * ... define new APIs, if any
 *
 *  If you need GLtypes here, mirror them with a cl_GLtype, rather than including a GL header
 *  This allows us to avoid having to decide whether to include GL headers or GLES here.
 */

/* 
 *  cl_khr_gl_event  extension
 *  See section 9.9 in the OpenCL 1.1 spec for more information
 */
#define CL_COMMAND_GL_FENCE_SYNC_OBJECT_KHR     0x200D

extern CL_API_ENTRY cl_event CL_API_CALL
clCreateEventFromGLsyncKHR(cl_context           /* context */,
                           cl_GLsync            /* cl_GLsync */,
                           cl_int *             /* errcode_ret */) CL_EXT_SUFFIX__VERSION_1_1;

#ifdef __cplusplus
}
#endif

#endif	/* __OPENCL_CL_GL_EXT_H  */
