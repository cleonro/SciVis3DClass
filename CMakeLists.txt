cmake_minimum_required(VERSION 3.5)

project(SciVis3DClass LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(VTK REQUIRED)

# GSL finding stuff
set(GSL_DIR CACHE PATH "GSL build directory")
set(GSL_INCLUDE_DIR ${GSL_DIR})
find_library(GSL_CBLAS_LIBRARY NAMES gslcblas libgslcblas PATHS ${GSL_DIR})
find_library(GSL_LIBRARY NAMES gsl libgsl PATHS ${GSL_DIR})
find_package(GSL REQUIRED)

add_subdirectory(Core)
add_subdirectory(Plugins/HelloWorld)
add_subdirectory(Plugins/ODE)
add_subdirectory(Plugins/PDE1)
add_subdirectory(Libs/FortranTest)

include_directories(${Core_SOURCE_DIR})
include_directories(${GSL_INCLUDE_DIRS})

set(SRCS
    main.cpp
    )

if(ANDROID)
  add_library(SciVis3DClass SHARED
    ${SRCS}
  )
else()
  add_executable(SciVis3DClass
    main.cpp
    ${SRCS}
  )
endif()

set_target_properties(SciVis3DClass PROPERTIES
                                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(SciVis3DClass PROPERTIES
                                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(SciVis3DClass PRIVATE Qt5::Widgets Core)
