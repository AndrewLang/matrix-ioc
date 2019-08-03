
option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc)

add_subdirectory ("matrix-ioc-tests")