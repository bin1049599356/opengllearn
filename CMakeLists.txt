cmake_minimum_required(VERSION 3.24)
PROJECT(ttttt)

SET(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_CXX_STANDARD  20)


# 64位
if (CMAKE_CL_64)
    # 设置 可执行程序输出目录
	set(publish_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/bin/x64/debug) 
	set(publish_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/bin/x64/release)

    # 设置库文件输出目录
	set(publish_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/debug)
	set(publish_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/release)
# 32
else()
 # 设置 可执行程序输出目录
	set(publish_bin_debug 			${CMAKE_CURRENT_SOURCE_DIR}/bin/x86/debug)
	set(publish_bin_release 		${CMAKE_CURRENT_SOURCE_DIR}/bin/x86/release)

 # 设置库文件输出目录
	set(publish_lib_debug 			${CMAKE_CURRENT_SOURCE_DIR}/lib/x86/debug)
	set(publish_lib_release 		${CMAKE_CURRENT_SOURCE_DIR}/lib/x86/release)
endif()



ADD_SUBDIRECTORY(src)