
PROJECT(glad)
SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


FILE(GLOB_RECURSE CPPS ${PROJECT_DIR}/*.c)
FILE(GLOB_RECURSE HEADS ${PROJECT_DIR}/*.h)

source_group("Header" FILES ${HEADS})
source_group("Source" FILES ${CPPS})

add_definitions(-DGLAD_GLAPI_EXPORT -DGLAD_GLAPI_EXPORT_BUILD)

add_library(glad  SHARED
                ${HEADS}
                ${CPPS}
                )


TARGET_INCLUDE_DIRECTORIES(glad 
    PUBLIC "${PROJECT_DIR}/include"
)