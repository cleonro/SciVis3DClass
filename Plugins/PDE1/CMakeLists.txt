project(PDE1)

set(SRCS
    pde1state.cpp pde1state.h
    )
set(UIS

    )
set(RCS

    )

include_directories(${Core_SOURCE_DIR})

add_library(PDE1SciVis3DClassPlugin SHARED ${SRCS} ${UIS} ${RCS})

set_target_properties(PDE1SciVis3DClassPlugin PROPERTIES
                                LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins")
set_target_properties(PDE1SciVis3DClassPlugin PROPERTIES
                                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/plugins")


target_link_libraries(PDE1SciVis3DClassPlugin ${Core_LIB} Qt5::Widgets ${VTK_LIBRARIES} GSL::gsl GSL::gslcblas)
