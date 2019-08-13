# find_package(matrix-ioc REQUIRED)



project(demo)

add_executable(${PROJECT_NAME} main.cpp main.h)

target_link_libraries(${PROJECT_NAME} PUBLIC matrix-ioc)

# add_precompiled_header(${PROJECT_NAME} pch.h SOURCE_CXX pch.cpp FORCEINCLUDE)

