cmake_minimum_required(VERSION 3.4.1)

include(ExternalProject)
project(TaskScheduler)

message(STATUS "CMAKE_SYSTEM_INFO_FILE = ${CMAKE_SYSTEM_INFO_FILE}")
message(STATUS "CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMAKE_SYSTEM = ${CMAKE_SYSTEM}")
message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")

set(BUILD_FOLDER_SUFFIX "build_${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}_${CMAKE_CXX_COMPILER_ID}")
string(TOLOWER  ${BUILD_FOLDER_SUFFIX} BUILD_FOLDER_SUFFIX)
message(STATUS "BUILD_FOLDER_SUFFIX = ${BUILD_FOLDER_SUFFIX}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG -D_UNICODE=1 -DUNICODE=1")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -D_UNICODE=1 -DUNICODE=1")

if(MSVC)
    # Only for 32-bit builds 
    # add_definitions(/arch:SSE2)
    # Do not use MT_UNICODE, it produces compilation errors.
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_CRTDBG_MAP_ALLOC -DMT_INSTRUMENTED_BUILD")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DMT_INSTRUMENTED_BUILD")
endif()

file(GLOB Squish_header_files ${CMAKE_SOURCE_DIR}/ThirdParty/Squish/*.h)
file(GLOB Squish_source_files ${CMAKE_SOURCE_DIR}/ThirdParty/Squish/*.cpp)

add_library(
    Squish
    STATIC
    ${Squish_header_files}
    ${Squish_source_files}
)

target_include_directories(
    Squish
    PUBLIC
    ${CMAKE_SOURCE_DIR}/ThirdParty/Squish/
)

target_include_directories(
    Squish
    PUBLIC
    ${CMAKE_SOURCE_DIR}/ThirdParty/Squish/
)

file(GLOB Platform_common_headers ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Common/*.h)
file(GLOB Platform_posix_headers ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Posix/*.h)
file(GLOB Platform_win32_headers ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Win32/*.h)
file(GLOB Platform_scopes_headers ${CMAKE_SOURCE_DIR}/Scheduler/Include/Scopes/*.h)
file(GLOB Platform_headers ${CMAKE_SOURCE_DIR}/Scheduler/Include/*.h)
file(GLOB Platform_sources ${CMAKE_SOURCE_DIR}/Scheduler/Source/*.cpp)

if(MSVC)
    add_library(
        TaskScheduler
        STATIC
        ${Platform_common_headers}
        ${Platform_win32_headers}
        ${Platform_scopes_headers}
        ${Platform_headers}
        ${Platform_sources}
   )
    target_include_directories(
        TaskScheduler
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Common/
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Win32/
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/Scopes/
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/
        ${CMAKE_SOURCE_DIR}/Scheduler/Source/
        ${CMAKE_SOURCE_DIR}/ThirdParty/Boost.Context/
   )
else()
    add_library(
        TaskScheduler
        STATIC
        ${Platform_common_headers}
        ${Platform_posix_headers}
        ${Platform_scopes_headers}
        ${Platform_headers}
        ${Platform_sources}
   )
    target_include_directories(
        TaskScheduler
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Common/
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/Platform/Posix/
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/Scopes/
        ${CMAKE_SOURCE_DIR}/Scheduler/Include/
        ${CMAKE_SOURCE_DIR}/Scheduler/Source/
        ${CMAKE_SOURCE_DIR}/ThirdParty/Boost.Context/
   )
endif()