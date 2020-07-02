project(Core)

set(SRCS
    CoreDefines.h
    mainwindow.cpp mainwindow.h
    mainwindow.ui
    )

add_library(Core ${SRCS})
target_link_libraries(Core Qt5::Widgets)
