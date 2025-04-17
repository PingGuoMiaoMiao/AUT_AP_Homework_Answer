cmake_minimum_required(VERSION 3.14)
project(AUT_AP_2025_Spring_HW1)

set(CMAKE_CXX_STANDARD 23)

# 使用 FetchContent 自动下载 gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# 添加可执行文件
add_executable(main
        src/main.cpp
        src/unit_test.cpp
        src/Q2_Sort_By_Distance.cpp
        src/Q3_Count_Islands.cpp
)

# 链接 gtest
target_link_libraries(main
        PRIVATE
        gtest_main
)