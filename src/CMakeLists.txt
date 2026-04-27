cmake_minimum_required(VERSION 3.24)
PROJECT(ttttt)

SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()


SUBDIRLIST(SUBDIRS ${PROJECT_DIR})

# 指定可执行程序输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	${publish_bin_debug})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	${publish_bin_release})

FOREACH(subdir ${SUBDIRS})
  message("curdir:" ${subdir})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
