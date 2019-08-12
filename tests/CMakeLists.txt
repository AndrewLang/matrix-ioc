
# We need thread support
find_package(Threads REQUIRED)



# Get GTest source and binary directories from CMake project

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)


include_directories(${gtest_SOURCE_DIR}/include)


message(STATUS "CMAKE Binary dir: " ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "Gtest source dir: " ${gtest_SOURCE_DIR})
message(STATUS "Gtest binary dir: " ${binary_dir})
message(STATUS "CMake source dir: " ${CMAKE_SOURCE_DIR})


add_subdirectory ("matrix-ioc-tests")

