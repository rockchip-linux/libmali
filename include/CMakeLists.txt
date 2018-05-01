cmake_minimum_required(VERSION 3.2)

PROJECT(MailHeaders NONE)
INCLUDE(GNUInstallDirs)

add_subdirectory(${GPU_ARCHITECTURE})

# Except the for gbm display platform, only for wayland
# included the gbm features actually.
INSTALL(FILES "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gbm.h"
DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

