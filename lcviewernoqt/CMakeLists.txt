CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT (LCVIEWERNOQT)
ADD_DEFINITIONS(-std=c++14)
ADD_DEFINITIONS("-Wall")
#ADD_DEFINITIONS("-Wno-missing-braces")

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# SOURCE FILES
set(viewer_srcs
lcdrawoptions.cpp
drawitems/lcvdrawitem.cpp
drawitems/lcvarc.cpp
drawitems/lcvcircle.cpp
drawitems/lcvpoint.cpp
drawitems/lcvdrawitem.cpp
drawitems/lcvellipse.cpp
drawitems/lcvline.cpp
drawitems/lcvtext.cpp
drawitems/lcvspline.cpp
drawables/grid.cpp
drawitems/endcaps.cpp
drawables/gradientbackground.cpp
drawitems/lcdimension.cpp
drawitems/lcdimradial.cpp
drawitems/lcdimdiametric.cpp
drawitems/lcdimlinear.cpp
drawitems/lcdimaligned.cpp
drawitems/lcdimangular.cpp
drawitems/lclwpolyline.cpp
drawables/lccursor.cpp
documentcanvas.cpp
managers/snapmanagerimpl.cpp
managers/EventManager.cpp
managers/dragmanager.cpp
drawitems/lcimage.cpp
drawables/dragpoints.cpp
)

# HEADER FILES
set(viewer_hdrs
lcdrawoptions.h
drawitems/lcvdrawitem.h
drawitems/lcvarc.h
drawitems/lcvcircle.h
drawitems/lcvpoint.h
drawitems/lcvdrawitem.h
drawitems/lcvellipse.h
drawitems/lcvline.h
drawitems/lcvtext.h
drawitems/lcvspline.h
drawables/grid.h
drawitems/endcaps.h
drawables/gradientbackground.h
drawitems/lcdimension.h
drawitems/lcdimradial.h
drawitems/lcdimdiametric.h
drawitems/lcdimlinear.h
drawitems/lcdimaligned.h
drawitems/lcdimangular.h
drawitems/lclwpolyline.h
drawables/lccursor.h
events/drawevent.h
events/mousemoveevent.h
events/mousereleaseevent.h
events/selecteditemsevent.h
events/snappointevent.h
lcpainter.h
lccairopainter.tcc
documentcanvas.h
managers/snapmanager.h
managers/snapmanagerimpl.h
managers/EventManager.h
managers/dragmanager.h
events/LocationEvent.h
drawitems/lcimage.h
drawables/dragpoints.h
events/dragpointsevent.h
)

# Cairo
find_package(PkgConfig)
pkg_check_modules(CAIRO REQUIRED cairo>=1.14)
include_directories(${CAIRO_INCLUDE_DIRS})
link_directories(${CAIRO_LIBRARY_DIRS})

# Pango
pkg_check_modules(PANGO REQUIRED pango>=1.38)
include_directories(${PANGO_INCLUDE_DIRS})
link_directories(${PANGO_LIBRARY_DIRS})

# Eigen 3
find_package(Eigen3 REQUIRED)
include_directories( ${EIGEN3_INCLUDE_DIR})

# BUILDING CONFIG
# SEPERATE BUILDING FLAG
set(SEPARATE_BUILD OFF)
 
if (SEPARATE_BUILD STREQUAL "ON")
    include_directories("${CMAKE_SOURCE_DIR}/../lckernel")
else()
    include_directories("${CMAKE_SOURCE_DIR}/lckernel")
endif()

# DEBUGING PATHS

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach(dir ${dirs})
#  message(STATUS "dir='${dir}'")
#endforeach()

add_library(lcviewernoqt SHARED ${viewer_srcs} ${viewer_hdrs}   drawables/CursorLocation.cpp drawables/CursorLocation.h)
target_link_libraries(lcviewernoqt ${CAIRO_LIBRARIES} ${PANGO_LIBRARIES} lckernel)
