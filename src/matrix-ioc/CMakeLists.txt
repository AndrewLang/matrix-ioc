

include_directories(${CMAKE_SOURCE_DIR}/include)


message(STATUS "Source Dir" ${CMAKE_SOURCE_DIR})

project(matrix-ioc)

file(GLOB headers *.h)
file(GLOB sourceFiles *.cpp)

add_library( ${PROJECT_NAME} 
	SHARED 
	common/BaseException.cpp
	common/ArgumentNullException.cpp
	common/FileLoadException.cpp
	common/FileNotExistsException.cpp	
	common/TextFormatter.cpp	
	common/Guard.cpp
	common/Stopwatch.cpp
	common/StringExtensions.cpp
	

	configuration/ConfigurationBuilder.cpp
	configuration/ConfigurationProvider.cpp
	configuration/ConfigurationRoot.cpp
	configuration/MemoryConfigurationProvider.cpp

	task/DoWithResult.cpp
	)

add_definitions(-DEXPMODULE)

