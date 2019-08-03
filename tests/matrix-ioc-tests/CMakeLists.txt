include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/task)


project(ioc-tests)

add_executable (${PROJECT_NAME} main.cpp main.h)

# Include sub-projects.

add_dependencies (${PROJECT_NAME}, gtest)

#####################################
# Configure the test to use GoogleTest
#
# If used often, could be made a macro.

add_dependencies(registerer_test gtest)
include_directories(${source_dir}/include)
target_link_libraries(registerer_test ${binary_dir}/libgtest.a)
target_link_libraries(registerer_test ${binary_dir}/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test

enable_testing()
add_test(NAME    registerer_test COMMAND registerer_test)