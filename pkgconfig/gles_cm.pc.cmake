prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=${prefix}
libdir=${prefix}/@CMAKE_INSTALL_LIBDIR@
includedir=${prefix}/@CMAKE_INSTALL_INCLUDEDIR@

Name: gles_cm
Description: Mali OpenGL ES 1.1 CM library
Version: @GPU_LIBRARY_VER_RELEASE@.@GPU_LIBRARY_VER_PATCH@
Libs: -L${libdir} -l@TARGET_LIB_LINK_NAME@
Libs.private: -lm -lpthread -ldl
Cflags: -I${includedir}
