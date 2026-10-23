cmake_minimum_required(VERSION 4.0)
project(QuackEngine)

set(SOURCE
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)
    
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/../Dependencies/SDL2/libSDL2.a")

