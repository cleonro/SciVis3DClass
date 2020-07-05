project(HelloWorld)

include_directories(${Core_SOURCE_DIR})

set(SRCS
    helloworldstate.cpp helloworldstate.h
    helloworldcontroller.cpp helloworldcontroller.h
    )

add_library(HelloWorldSciVis3DClassPlugin SHARED ${SRCS})

set_target_properties(HelloWorldSciVis3DClassPlugin PROPERTIES
                                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins")
set_target_properties(HelloWorldSciVis3DClassPlugin PROPERTIES
                                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins")


target_link_libraries(HelloWorldSciVis3DClassPlugin ${Core_LIB} Qt5::Widgets ${VTK_LIBRARIES})
