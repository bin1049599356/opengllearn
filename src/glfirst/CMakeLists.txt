
PROJECT(glfirst)
SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


FILE(GLOB_RECURSE CPPS ${PROJECT_DIR}/*.cpp)
FILE(GLOB_RECURSE HEADS ${PROJECT_DIR}/*.h)

source_group("Header" FILES ${HEADS})
source_group("Source" FILES ${CPPS})


ADD_EXECUTABLE(glfirst
                ${HEADS}
                ${CPPS}
                )

#TARGET_INCLUDE_DIRECTORIES(glfirst 
#    PRIVATE "F:\\tjb\\opensrc\\glfw-3.3.8\\build\\install\\include"
#)
#
#
#TARGET_LINK_DIRECTORIES(glfirst 
#    PRIVATE "F:/tjb/opensrc/glfw-3.3.8/build/install/lib"
#)

target_link_libraries(glfirst 
    glfw
    glad
)


SET_PROPERTY(TARGET glfirst PROPERTY FOLDER "learn")