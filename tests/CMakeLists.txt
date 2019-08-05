# We need thread support
find_package(Threads REQUIRED)

##################################
# Download and install GoogleTest

include(ExternalProject)

ExternalProject_Add(
  gtest
  URL  https://github.com/google/googletest/archive/master.zip

  # https://github.com/google/googletest/archive/release-1.8.0.zip
  # https://github.com/google/googletest/archive/master.zip
  
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND ""

  LOG_DOWNLOAD ON
  LOG_CONFIGURE ON
  LOG_BUILD ON
)


# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

include_directories(${source_dir}/googletest/include)


# add_subdirectory(${source_dir} ${binary_dir})

message(STATUS "Gtest source dir: " ${source_dir})
message(STATUS "Gtest binary dir: " ${binary_dir})
message(STATUS "CMake source dir: " ${CMAKE_SOURCE_DIR})


add_subdirectory ("matrix-ioc-tests")

enable_testing()