cmake_minimum_required(VERSION 3.6)
enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

set(CMAKE_CXX_FLAGS "-Wpedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused")
#"  " -Wlogical-op"
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(test_file_logger
  src/file_logger.cpp
  test/test_file_logger.cpp)

target_link_libraries(test_file_logger GTest::GTest GTest::Main)

gtest_discover_tests(test_file_logger)
