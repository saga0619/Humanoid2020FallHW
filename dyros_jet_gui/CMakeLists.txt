##############################################################################
# CMake
##############################################################################

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
project(dyros_jet_gui)

##############################################################################
# Catkin
##############################################################################
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS roscpp dyros_jet_msgs rqt_gui rqt_gui_cpp)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui PrintSupport)


# message($ENV{QT5_DIR})
# if($ENV{QT5_DIR})
#   set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{QT5_DIR}/lib/cmake")
# endif()

include_directories(${catkin_INCLUDE_DIRS}
    core
    gui
    ${Qt5Gui_PRIVATE_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}/..
    include)

    # include/qcustomplot)

# link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/qcustomplot)
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything. 
catkin_package()

add_subdirectory(third_party/qcustomplot)

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically 
# included via the dependency call in package.xml
# rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/dyros_jet_gui/*.hpp)

qt5_wrap_cpp(QT_MOC_HPP ${QT_MOC})
qt5_wrap_ui(QT_FORMS_HPP ${QT_FORMS})

# QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
# QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
# QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS  src/*.cpp )

##############################################################################
# Binaries
##############################################################################

add_executable(dyros_jet_gui ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(dyros_jet_gui ${catkin_LIBRARIES} qcustomplot)
target_link_libraries(dyros_jet_gui Qt5::Widgets Qt5::Gui Qt5::Core Qt5::PrintSupport)
# qt5_use_modules(dyros_jet_gui Widgets Gui Core)
install(TARGETS dyros_jet_gui RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_dependencies(dyros_jet_gui ${catkin_EXPORTED_TARGETS})
