cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(shvm C)
add_subdirectory(vendor/libft)

set(BUILD_SHARED_LIBS OFF)
set(shvm_ENABLE_TEST ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(shvm_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(shvm_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(shvm_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

option(COVERAGE "Turn on COVERAGE support" OFF)
if (COVERAGE AND NOT MSVC)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} --coverage")
endif ()

set(shvm_HDR ${shvm_INC_DIR}/shvm.h)
file(GLOB_RECURSE shvm_HDRS ${shvm_HDRS}
  ${shvm_INC_DIR}/shvm/*.h)
file(GLOB_RECURSE shvm_SRCS ${shvm_SRCS}
  ${shvm_SRC_DIR}/*.c)
file(GLOB_RECURSE shvm_SRCS ${shvm_SRCS}
  ${shvm_SRC_DIR}/*.h)

add_library(shvm ${shvm_HDR} ${shvm_HDRS} ${shvm_SRCS})
set_property(TARGET shvm PROPERTY C_STANDARD 90)
target_include_directories(shvm PUBLIC ${shvm_INC_DIR})
target_link_libraries(shvm PUBLIC ft)

target_compile_definitions(shvm
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>
  PRIVATE API_COMPILE)
if (MSVC)
  target_compile_options(shvm
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(shvm
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()

if (shvm_ENABLE_TEST)
  enable_testing()
  add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
  file(GLOB shvm_TEST_SRCS ${shvm_TEST_SRCS}
    ${shvm_TEST_DIR}/*.c)
  foreach (shvm_TEST_SRC ${shvm_TEST_SRCS})
    get_filename_component(shvm_TEST_NAME ${shvm_TEST_SRC} NAME_WE)
    set(test test_shvm_${shvm_TEST_NAME})
    add_executable(${test} ${shvm_TEST_SRC})
    set_property(TARGET ${test}
      PROPERTY C_STANDARD 90)
    add_dependencies(${test} shvm)
    add_dependencies(check ${test})
    target_include_directories(${test} PUBLIC
      ${shvm_TEST_DIR})
    target_link_libraries(${test} shvm)
    target_compile_definitions(${test}
      PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
    add_test(shvm_${shvm_TEST_NAME} ${test}
      WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
    if (MSVC)
      target_compile_options(${test}
        PRIVATE /MTd /Oy /W3
        PRIVATE /D_CRT_SECURE_NO_WARNINGS
        PRIVATE /Od)
    else ()
      target_compile_options(${test}
        PRIVATE -fomit-frame-pointer -ansi
        PRIVATE -O0 -g3)
    endif ()
  endforeach ()
endif ()
