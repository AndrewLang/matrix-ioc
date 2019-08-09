
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/task)

link_directories(${binary_dir}/lib)


project(ioc-tests)

add_executable (${PROJECT_NAME} 
	main.cpp 	
	test-demo.cpp

	tests/ConsoleLoggerTests.cpp
	)

# Include sub-projects.


target_link_libraries(${PROJECT_NAME} gtest_main)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
