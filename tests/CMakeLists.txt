

##################################
# Download and install GoogleTest

include(ExternalProject)

set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_SOURCE_DIR}/extern)

ExternalProject_Add(gtest
  URL https://github.com/google/googletest/archive/release-1.8.0.zip
  
  PREFIX ${CMAKE_SOURCE_DIR}/extern/gtest
  INSTALL_COMMAND ""
)
ExternalProject_Get_Property(gtest source_dir binary_dir)
include_directories(${CMAKE_SOURCE_DIR}/extern/gtest)

include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc)

add_subdirectory ("matrix-ioc-tests")