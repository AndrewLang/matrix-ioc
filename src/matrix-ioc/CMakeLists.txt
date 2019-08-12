

message(STATUS "Source Dir: " ${CMAKE_SOURCE_DIR})

project(matrix-ioc)


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

	ioc/ApplicationBase.cpp
	ioc/ApplicationBuilder.cpp
	ioc/ApplicationStartBlock.cpp
	ioc/InstanceCreatorContext.cpp
	ioc/InstanceDescriptor.cpp
	ioc/ServiceContainer.cpp
	ioc/ServiceDescriptor.cpp
	ioc/TypeInfo.cpp
	ioc/TypeMap.cpp

	logging/ConsoleLogger.cpp
	logging/ConsoleLoggerProvider.cpp
	logging/InternalLogger.cpp
	logging/LoggerBase.cpp
	logging/LoggerFactory.cpp
	logging/LogLevelConverter.cpp
	logging/VsOutput.cpp
	logging/VsOutputLogger.cpp
	logging/VsOutputLoggerProvider.cpp

	pipeline/Pipeline.cpp
	pipeline/PipelineBlock.cpp
	pipeline/Pipelinebuilder.cpp
	pipeline/PipelineContext.cpp

	task/DoWithResult.cpp
	task/CancellationToken.cpp
	task/Task.cpp
	task/TaskWithResult.cpp
	)

add_definitions(-DEXPMODULE)

