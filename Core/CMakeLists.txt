project(Core)

set(SRCS
    CoreDefines.h
    mainwindow.cpp mainwindow.h
    mainwindow.ui
    stagemanager.cpp stagemanager.h
    stagestate.cpp stagestate.h
    )

add_library(Core SHARED ${SRCS})

set_target_properties(Core PROPERTIES
                                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(Core PROPERTIES
                                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

target_link_libraries(Core Qt5::Widgets)
