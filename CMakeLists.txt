cmake_minimum_required(VERSION 3.20)
project(SortedKDTree VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(sortedKDTree
    src/sorted_kdtree.cpp
    src/distance.cpp
)

target_include_directories(sortedKDTree PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_executable(test
    test/test.cpp
)
target_include_directories(test PRIVATE sorted_kdtree)

# --- Platform-Specific Fixes ---
# Note: Your build is using MSVC, not MinGW, so the MINGW block
# won't run, which is correct for this build.
if (MINGW)
    target_link_libraries(basic_usage PRIVATE stdc++exp)
endif()

if(MSVC)
    target_compile_options(basic_usage PRIVATE /W4)
else()
    target_compile_options(basic_usage PRIVATE -Wall -Wextra -Wpedantic)
endif()