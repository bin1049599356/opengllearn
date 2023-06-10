
PROJECT(glfirst)
SET(TARGETNAME glfirst)
SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})


FILE(GLOB_RECURSE CPPS ${PROJECT_DIR}/*.cpp)
FILE(GLOB_RECURSE HEADS ${PROJECT_DIR}/*.h)

source_group("Header" FILES ${HEADS})
source_group("Source" FILES ${CPPS})

FILE(GLOB_RECURSE GLSL ${PROJECT_DIR}/*.glsl)
source_group("Glsl" FILES ${GLSL})

ADD_EXECUTABLE(${TARGETNAME}
                ${HEADS}
                ${CPPS}
                ${GLSL}
                )   

TARGET_INCLUDE_DIRECTORIES(${TARGETNAME} 
    PRIVATE ${PROJECT_DIR}
)

target_link_libraries(${TARGETNAME} 
    common
    glfw
    glad
    stb
    glm
)


SET_PROPERTY(TARGET ${TARGETNAME} PROPERTY FOLDER "learn")