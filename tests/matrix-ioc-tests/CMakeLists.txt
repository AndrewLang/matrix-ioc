include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/task)

project(ioc-tests)

add_executable (${PROJECT_NAME} 
	main.cpp 	
	test-demo.cpp

	# mocks

	# tests
	tests/common/StringExtensionsTests.cpp
	tests/common/ArgumentNullExceptionTests.cpp
	tests/common/DataContextTests.cpp
	tests/common/ObjectMapTests.cpp
	tests/common/GuardTests.cpp
	tests/common/StopwatchTests.cpp
	tests/common/TextFormatterTests.cpp
	tests/common/TypeInfoTests.cpp
	tests/common/TypeMapTests.cpp

	)

# Include sub-projects.


target_link_libraries(${PROJECT_NAME} gtest_main)
target_link_libraries(${PROJECT_NAME} matrix-ioc)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
