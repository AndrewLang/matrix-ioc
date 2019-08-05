
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/src/matrix-ioc/task)

message(STATUS ${CMAKE_SOURCE_DIR}/src/matrix-ioc)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

project(demo)


add_executable(${PROJECT_NAME} main.cpp main.h )

# target_link_libraries(${PROJECT_NAME} matrix-ioc.lib)