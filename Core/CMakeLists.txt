cmake_minimum_required(VERSION 4.0)
project(Core)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
)

add_library(Core::library ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include/
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Core/
)

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/Dependencies/SDL2/Linux/libSDL2-2.0.so")
endif()

if(WIN32)
    #target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/../Dependencies/glew/libSDL2.a")
endif()

