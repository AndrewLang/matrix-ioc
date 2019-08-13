
include_directories(
	${CMAKE_SOURCE_DIR}/include/matrix-ioc
	${CMAKE_SOURCE_DIR}/include/matrix-ioc/common
	${CMAKE_SOURCE_DIR}/include/matrix-ioc/configuration
	${CMAKE_SOURCE_DIR}/include/matrix-ioc/ioc
	${CMAKE_SOURCE_DIR}/include/matrix-ioc/logging
	${CMAKE_SOURCE_DIR}/include/matrix-ioc/pipeline
	${CMAKE_SOURCE_DIR}/include/matrix-ioc/task
)


project(ioc-tests)

set(HeaderFiles 
	pch.h
	main.h
)

set(SourceFiles 
	pch.cpp
	main.cpp
	test-demo.cpp

	# mocks

	# tests
	tests/common/TypeInfoTests.cpp
	
	#[[
	tests/common/StringExtensionsTests.cpp
	tests/common/ArgumentNullExceptionTests.cpp
	tests/common/DataContextTests.cpp
	tests/common/ObjectMapTests.cpp
	tests/common/GuardTests.cpp
	tests/common/StopwatchTests.cpp
	tests/common/TextFormatterTests.cpp
	
	tests/common/TypeMapTests.cpp
	]]

	# tests/ConsoleLoggerTests.cpp
)


add_executable (${PROJECT_NAME} ${SourceFiles} ${HeaderFiles} )


target_link_libraries(${PROJECT_NAME} gtest_main matrix-ioc)


add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

if(MSVC)
	# add_precompiled_header(${PROJECT_NAME} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)
endif()
