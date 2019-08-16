
include_directories(
	${CMAKE_SOURCE_DIR}/src/matrix-ioc/include
	${CMAKE_SOURCE_DIR}/tests/matrix-ioc-tests/include
)


project(ioc-unit-tests)

set(HeaderFiles 
	pch.h
	main.h
	
	include/ApiHandleComponent.h
	include/ApiHandler.h
	include/Circle.h
	include/IApiHandler.h
	include/InitializeComponent.h
	include/LoggerCreator.h
	include/MockApplication.h
	include/MockServiceContainer.h
	include/MockServiceProvider.h
	include/Rectangle.h
	include/Shape.h
	include/TestServices.h
	
)

set(SourceFiles 
	pch.cpp
	main.cpp
	test-demo.cpp

	src/ApiHandleComponent.cpp
	src/ApiHandler.cpp
	src/Circle.cpp
	src/IApiHandler.cpp
	src/InitializeComponent.cpp
	src/LoggerCreator.cpp
	src/MockApplication.cpp
	src/MockServiceContainer.cpp
	src/MockServiceProvider.cpp
	src/Rectangle.cpp
	src/Shape.cpp
	src/TestServices.cpp


	# common
	tests/common/TypeInfoTests.cpp		
	tests/common/StringExtensionsTests.cpp
	tests/common/ArgumentNullExceptionTests.cpp
	tests/common/DataContextTests.cpp
	tests/common/ObjectMapTests.cpp
	tests/common/GuardTests.cpp
	tests/common/StopwatchTests.cpp
	tests/common/TextFormatterTests.cpp	
	tests/common/TypeMapTests.cpp
	
	# configuration
	tests/configuration/ConfigurationBuilderTests.cpp
	tests/configuration/ConfigurationRootTests.cpp
	tests/configuration/MemoryConfigurationProviderTests.cpp

	# ioc
	tests/ioc/ApplicationBuilderTests.cpp
	tests/ioc/ApplicationTests.cpp
	tests/ioc/InstanceCreatorContextTests.cpp
	tests/ioc/ServiceContainerTests.cpp
	tests/ioc/ServiceDescriptorTests.cpp
	tests/ioc/ServiceLifetimeTests.cpp


	# logging 
	tests/logging/ConsoleLoggerProvidertests.cpp
	tests/logging/ConsoleLoggerTests.cpp
	tests/logging/InternalLoggerTests.cpp
	tests/logging/LoggerFactoryTests.cpp
	tests/logging/LogLevelConverterTests.cpp
	tests/logging/VsOutputLoggerProviderTests.cpp

	# pipeline
	tests/pipeline/PipelineBlockTests.cpp
	tests/pipeline/PipelineBuilderTests.cpp
	tests/pipeline/PipelineContextTests.cpp
	tests/pipeline/PipelineTests.cpp

	# task
	tests/task/DoTests.cpp
	tests/task/DoWithResultTests.cpp
	tests/task/TaskTests.cpp
	tests/task/TaskWithResultTests.cpp

)


add_executable (${PROJECT_NAME} ${SourceFiles} ${HeaderFiles} )


target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main matrix-ioc)


add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

