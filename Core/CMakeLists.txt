project(Core)

set(SRCS
    CoreDefines.h
    mainwindow.cpp mainwindow.h
    mainwindow.ui
    stagemanager.cpp stagemanager.h
    stagestate.cpp stagestate.h
    )

add_library(Core ${SRCS})
target_link_libraries(Core Qt5::Widgets)
