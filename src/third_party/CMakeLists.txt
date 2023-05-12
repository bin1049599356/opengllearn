cmake_minimum_required(VERSION 3.24)
PROJECT(third)

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

FOREACH(subdir ${SUBDIRS})
  message("curdir:" ${subdir})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
