include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/task)

link_directories(${binary_dir}/lib)

 # file(GLOB_RECURSE )

project(ioc-tests)

add_executable (${PROJECT_NAME} 
	main.cpp 	
	# test-demo.cpp
	)

# Include sub-projects.

add_dependencies(${PROJECT_NAME} gtest)

if(MSVC)
	
	# target_link_libraries(${PROJECT_NAME} gtest)
	# target_link_libraries(${PROJECT_NAME} ${binary_dir}/lib/gtestd.lib)
	# target_link_libraries(${PROJECT_NAME} ${binary_dir}/lib/gtest_maind.lib)	
endif(MSVC)

# target_link_libraries(${PROJECT_NAME} ${binary_dir}/lib/gtestd.lib)

# add_test( NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})