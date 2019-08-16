
cmake_minimum_required (VERSION 3.12)


if(WIN32)
	#[[
		Export all symbold on windows
		see https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
	]]
   
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)   
endif(WIN32)

include_directories(
	${CMAKE_SOURCE_DIR}/src/matrix-ioc
)

project(matrix-ioc VERSION 0.0.1 )

set(DEFAULT_BUILD_TYPE "Release")


# header files
SET(HeaderFiles 
	pch.h	
)


# source files
SET(SourceFiles 
	pch.cpp

	src/common/ArgumentNullException.cpp
	src/common/BaseException.cpp
	src/common/DataContext.cpp
	src/common/FileLoadException.cpp
	src/common/FileNotExistsException.cpp	
	src/common/TextFormatter.cpp	
	src/common/Guard.cpp
	src/common/Stopwatch.cpp
	src/common/StringExtensions.cpp
	
	
	src/configuration/ConfigurationBuilder.cpp
	src/configuration/ConfigurationProvider.cpp
	src/configuration/ConfigurationRoot.cpp
	src/configuration/MemoryConfigurationProvider.cpp

	src/ioc/ApplicationBase.cpp
	src/ioc/ApplicationBuilder.cpp
	src/ioc/ApplicationStartBlock.cpp
	src/ioc/InstanceCreatorContext.cpp
	src/ioc/InstanceDescriptor.cpp
	src/ioc/ServiceContainer.cpp
	src/ioc/ServiceDescriptor.cpp
	src/ioc/TypeInfo.cpp
	src/ioc/TypeMap.cpp

	src/logging/ConsoleLogger.cpp
	src/logging/ConsoleLoggerProvider.cpp
	src/logging/InternalLogger.cpp
	src/logging/LoggerBase.cpp
	src/logging/LoggerFactory.cpp
	src/logging/LogLevelConverter.cpp
	src/logging/VsOutput.cpp
	src/logging/VsOutputLogger.cpp
	src/logging/VsOutputLoggerProvider.cpp

	src/pipeline/Pipeline.cpp
	src/pipeline/PipelineBlock.cpp
	src/pipeline/Pipelinebuilder.cpp
	src/pipeline/PipelineContext.cpp

	src/task/DoWithResult.cpp
	src/task/CancellationToken.cpp
	src/task/Task.cpp
	src/task/TaskWithResult.cpp
)

# add library definition
add_library( ${PROJECT_NAME} SHARED ${SourceFiles} ${HeaderFiles})

add_definitions(-DEXPMODULE)

add_precompiled_header(${PROJECT_NAME} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)

# 
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR}/include )


set_target_properties( ${PROJECT_NAME} PROPERTIES 
	VERSION ${PROJECT_VERSION}
	PUBLIC_HEADER "${HeaderFiles}"
)
