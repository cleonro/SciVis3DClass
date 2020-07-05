project(ODE)

set(SRCS
    odestate.cpp odestate.h
    )

include_directories(${Core_SOURCE_DIR})

add_library(ODESciVis3DClassPlugin SHARED ${SRCS})

set_target_properties(ODESciVis3DClassPlugin PROPERTIES
                                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins")
set_target_properties(ODESciVis3DClassPlugin PROPERTIES
                                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins")


target_link_libraries(ODESciVis3DClassPlugin ${Core_LIB} Qt5::Widgets ${VTK_LIBRARIES})

