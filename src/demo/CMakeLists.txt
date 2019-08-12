
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/common)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/configuration)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/ioc)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/logging)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/pipeline)
include_directories(${CMAKE_SOURCE_DIR}/include/matrix-ioc/task)

message(STATUS ${CMAKE_SOURCE_DIR}/src/matrix-ioc)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

project(demo)

add_executable(${PROJECT_NAME} main.cpp main.h)

target_link_libraries(${PROJECT_NAME} matrix-ioc)

# add_precompiled_header(${PROJECT_NAME} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)

