cmake_minimum_required(VERSION 3.2)
find_package(PkgConfig)

PROJECT(MaliBinary C)
INCLUDE(GNUInstallDirs)

# GPU display platform:
# wayland: EGL_KHR_platform_wayland, libwayland, may depend on drm
# x11: EGL_KHR_platform_x11, xorg xserver, may depend on drm
# gbm: EGL_KHR_platform_gbm, may depend on drm
# fbdev: none EGL_KHR_platform
function(parse_mali_library_info lib_name)
STRING(REGEX REPLACE "[\.]+[a-z]+" "" lib_name ${lib_name})
STRING(REPLACE "-" ";" lib_info_list ${lib_name})

LIST(GET lib_info_list 1 GPU_ARCHITECTURE)
LIST(GET lib_info_list 2 GPU_MODEL)
LIST(GET lib_info_list 3 GPU_LIBRARY_VERSION)
LIST(GET lib_info_list 4 GPU_HWREV)

SET(GPU_ARCHITECTURE ${GPU_ARCHITECTURE} CACHE INTERNAL "GPU architecture")
SET(GPU_MODEL ${GPU_MODEL} CACHE INTERNAL "GPU model")
SET(GPU_LIBRARY_VERSION ${GPU_LIBRARY_VERSION} CACHE INTERNAL "GPU library version")
SET(GPU_HWREV ${GPU_HWREV} CACHE INTERNAL "GPU hardware revision")
endfunction(parse_mali_library_info)

if (TARGET_SOC MATCHES "rk3399")
SET(GPU_FEATURE "${GPU_FEATURE} opencl" PARENT_SCOPE)
SET(ABI "aarch64-linux-gnu" CACHE STRING "default ABI")

if (DP_FEATURE MATCHES "wayland")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t86x-r14p0-r0p0-wayland-gbm.so")

elseif (DP_FEATURE MATCHES "x11")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t86x-r14p0-r0p0-x11-gbm.so")

elseif (DP_FEATURE MATCHES "gbm")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t86x-r14p0-r0p0-gbm.so")

elseif (DP_FEATURE MATCHES "fbdev")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t86x-r14p0-r0p0-fbdev.so")
endif(DP_FEATURE MATCHES "wayland")

endif(TARGET_SOC MATCHES "rk3399")

if (TARGET_SOC MATCHES "rk3288")
SET(GPU_FEATURE "${GPU_FEATURE} opencl" PARENT_SCOPE)
SET(ABI "arm-linux-gnueabihf" CACHE STRING "default ABI")

if (DP_FEATURE MATCHES "wayland")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r0p0-wayland-gbm.so")

elseif (DP_FEATURE MATCHES "x11")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r0p0-x11-gbm.so")

elseif (DP_FEATURE MATCHES "gbm")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r0p0-gbm.so")

elseif (DP_FEATURE MATCHES "fbdev")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r0p0-fbdev.so")
endif(DP_FEATURE MATCHES "wayland")

endif(TARGET_SOC MATCHES "rk3288")

if (TARGET_SOC MATCHES "rk3288w")
SET(GPU_FEATURE "${GPU_FEATURE} opencl" PARENT_SCOPE)
SET(ABI "arm-linux-gnueabihf" CACHE STRING "default ABI")

if (DP_FEATURE MATCHES "wayland")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r1p0-wayland-gbm.so")

elseif (DP_FEATURE MATCHES "x11")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r1p0-x11-gbm.so")

elseif (DP_FEATURE MATCHES "gbm")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r1p0-gbm.so")

elseif (DP_FEATURE MATCHES "fbdev")
SET(TARGET_GPU_LIBRARY_NAME "libmali-midgard-t76x-r14p0-r1p0-fbdev.so")
endif(DP_FEATURE MATCHES "wayland")

endif(TARGET_SOC MATCHES "rk3288w")

if (TARGET_SOC MATCHES "rk3328")
SET(ABI "aarch64-linux-gnu" CACHE STRING "default ABI")

if (DP_FEATURE MATCHES "wayland")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-450-r7p0-r0p0-wayland-gbm.so")

elseif (DP_FEATURE MATCHES "x11")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-450-r7p0-r0p0-x11-gbm.so")

elseif (DP_FEATURE MATCHES "gbm")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-450-r7p0-r0p0-gbm.so")

elseif (DP_FEATURE MATCHES "fbdev")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-450-r7p0-r0p0-fbdev.so")
endif(DP_FEATURE MATCHES "wayland")

endif(TARGET_SOC MATCHES "rk3328")

if (TARGET_SOC MATCHES "rk3036")
SET(ABI "arm-linux-gnueabihf" CACHE STRING "default ABI")

if (DP_FEATURE MATCHES "wayland")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-400-r7p0-r0p0-wayland-gbm.so")

elseif (DP_FEATURE MATCHES "x11")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-400-r7p0-r0p0-x11-gbm.so")

elseif (DP_FEATURE MATCHES "gbm")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-400-r7p0-r0p0-gbm.so")

elseif (DP_FEATURE MATCHES "fbdev")
SET(TARGET_GPU_LIBRARY_NAME "libmali-utgard-400-r7p0-r0p0-fbdev.so")
endif(DP_FEATURE MATCHES "wayland")

endif(TARGET_SOC MATCHES "rk3036")

parse_mali_library_info(${TARGET_GPU_LIBRARY_NAME})
INSTALL(FILES
"${CMAKE_CURRENT_SOURCE_DIR}/${ABI}/${TARGET_GPU_LIBRARY_NAME}"
DESTINATION "${CMAKE_INSTALL_LIBDIR}"
RENAME "${TARGET_LIB_NAME}")
string(REGEX REPLACE "lib(.*)\.so(\.[0-9]+)*" "\\1" TARGET_LIB_LINK_NAME "${TARGET_LIB_NAME}")
SET(TARGET_LIB_LINK_NAME ${TARGET_LIB_LINK_NAME} CACHE INTERNAL "GPU library name for the linker")

message(STATUS "GPU model: ${GPU_MODEL}, hardware revision: ${GPU_HWREV}")
message(STATUS "GPU user-space library version: ${GPU_LIBRARY_VERSION}")
message(STATUS "install the GPU library as: ${TARGET_LIB_NAME}")
