CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT (LC)
ADD_DEFINITIONS(-std=c++14)
ADD_DEFINITIONS("-Wall")
#ADD_DEFINITIONS("-Wno-missing-braces")

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Designer)
find_package(Qt5Gui REQUIRED)
find_package(Qt5UiTools REQUIRED)
#include(${QT_USE_FILE})
SET(QT_USE_QTDESIGNER ON)

# HEADERS
set(UI_hdrs
cadmdichild.h
const.h
luainterface.h
operations/circlecreateoperation.h
operations/groupoperations.h
operations/guioperationfinishedevent.h
operations/guioperation.h
operations/linecreateoperation.h
operations/operationmanager.h
operations/qsnappedstate.h
operations/trimoperation.h
widgets/clicommand.h
widgets/luascript.h
lua/qtbridge.h
lua/luaqobject.h)

set(UI_srcs
cadmdichild.cpp
main.cpp
luainterface.cpp
operations/circlecreateoperation.cpp
operations/linecreateoperation.cpp
operations/operationmanager.cpp
operations/qsnappedstate.cpp
operations/trimoperation.cpp
widgets/clicommand.cpp
widgets/luascript.cpp
lua/qtbridge.cpp
lua/luaqobject.cpp)

QT5_WRAP_UI(UI_HEADERS
widgets/clicommand.ui
widgets/luascript.ui)

qt5_add_resources(UI_RESOURCES
ui/resource.qrc)

# LOG4CXX
find_package(PkgConfig)
pkg_check_modules(LOG4CXX REQUIRED liblog4cxx)
include_directories(${LOG4CXX_INCLUDE_DIRS})
link_directories(${LOG4CXX_LIBRARY_DIRS})

# Eigen 3
find_package(Eigen3 REQUIRED)
include_directories( ${EIGEN3_INCLUDE_DIR})

# BUILDING CONFIG
# SEPERATE BUILDING FLAG
set(SEPARATE_BUILD OFF)

if (SEPARATE_BUILD STREQUAL "ON")
include_directories("${CMAKE_SOURCE_DIR}/../lckernel")
include_directories("${CMAKE_SOURCE_DIR}/../lcDXFDWG")
include_directories("${CMAKE_SOURCE_DIR}/../lcviewernoqt")
include_directories("${CMAKE_SOURCE_DIR}/../lcviewerqt")
include_directories("${CMAKE_SOURCE_DIR}/../lcadluascript")
include_directories("${CMAKE_SOURCE_DIR}/../lcUI")
else() 
include_directories("${CMAKE_SOURCE_DIR}/lckernel")
include_directories("${CMAKE_SOURCE_DIR}/lcDXFDWG")
include_directories("${CMAKE_SOURCE_DIR}/lcviewernoqt")
include_directories("${CMAKE_SOURCE_DIR}/lcviewerqt")
include_directories("${CMAKE_SOURCE_DIR}/lcadluascript")
include_directories("${CMAKE_SOURCE_DIR}/lcUI")
endif()

# DEBUGGING PATHS 
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach(dir ${dirs})
#  message(STATUS "dir='${dir}'")
#endforeach()

set(EXTRA_LIBS
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::UiTools
        ${LOG4CXX_LIBRARIES}
        lckernel
        lcluascript
        lcviewerqt
        lcviewernoqt
        lcdxfdwg)

#Create library for unit tests
if(WITH_UNITTESTS)
    add_library(lcui SHARED ${UI_srcs} ${UI_hdrs})
    target_link_libraries(lcui ${EXTRA_LIBS})
endif(WITH_UNITTESTS)

add_executable(librecad ${UI_srcs} ${UI_hdrs} ${UI_HEADERS})
target_link_libraries(librecad ${EXTRA_LIBS})
