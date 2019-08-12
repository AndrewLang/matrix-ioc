# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.12)



set(CMAKE_CXX_STANDARD 17)

# PrecompiledHeader.cmake from https://github.com/larsch/cmake-precompiled-header
include(./cmake/PrecompiledHeader.cmake)


project ("matrix-ioc-solution")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

if(MSVC)
	# set(CMAKE_CXX_STANDARD 17)
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()

enable_testing()

# Include sub-projects.
add_subdirectory ("src")
add_subdirectory ("tests")


