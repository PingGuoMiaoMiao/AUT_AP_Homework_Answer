cmake_minimum_required(VERSION 3.14)
project(AUT_AP_2025_Spring_HW2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 使用FetchContent获取GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# 包含目录
include_directories(
        include
        ${googletest_SOURCE_DIR}/googletest/include
)

# 添加可执行文件
add_executable(main
        src/main.cpp
        src/unit_test.cpp
        src/Q1_Variadic_Template_sum.cpp
        src/Q2_Word_Frequency.cpp
)

# 链接库
target_link_libraries(main
        PRIVATE
        gtest
        gtest_main
)

enable_testing()
add_test(NAME MainTest COMMAND main)