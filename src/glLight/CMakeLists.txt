
PROJECT(glLight)
SET(TARGETNAME glLight)
SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


FILE(GLOB_RECURSE CPPS ${PROJECT_DIR}/*.cpp)
FILE(GLOB_RECURSE HEADS ${PROJECT_DIR}/*.h)

source_group("Header" FILES ${HEADS})
source_group("Source" FILES ${CPPS})


ADD_EXECUTABLE(${TARGETNAME}
                ${HEADS}
                ${CPPS}
                )

TARGET_INCLUDE_DIRECTORIES(${TARGETNAME} 
    PRIVATE ${PROJECT_DIR}
)
#
#
#TARGET_LINK_DIRECTORIES(${TARGETNAME} 
#    PRIVATE "F:/tjb/opensrc/glfw-3.3.8/build/install/lib"
#)

target_link_libraries(${TARGETNAME} 
    common
    glfw
    glad
    stb
    glm
)


SET_PROPERTY(TARGET ${TARGETNAME} PROPERTY FOLDER "learn")