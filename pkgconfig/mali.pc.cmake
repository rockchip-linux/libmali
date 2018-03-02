prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=${prefix}/@CMAKE_INSTALL_LIBDIR@
includedir=${prefix}/@CMAKE_INSTALL_INCLUDEDIR@

Name: mali
Description: Mali EGL library
Version: @GPU_LIBRARY_VER_RELEASE@.@GPU_LIBRARY_VER_PATCH@
Libs: -L${libdir} -l@TARGET_LIB_LINK_NAME@
Cflags: -I${includedir} 
Libs.private: -lm -lpthread -ldl
