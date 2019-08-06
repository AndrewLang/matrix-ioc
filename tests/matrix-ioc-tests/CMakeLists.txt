include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/task)

link_directories(${binary_dir}/lib)


project(ioc-tests)

add_executable (${PROJECT_NAME} 
	main.cpp 	
	test-demo.cpp
	)

# Include sub-projects.


target_link_libraries(${PROJECT_NAME} gtest_main)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
