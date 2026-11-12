cmake_minimum_required(VERSION 4.0)
project(Engine)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
)

add_library(Engine::library ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include/
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include/Engine
)

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/Dependencies/SDL2/Linux/libSDL2-2.0.so")
    #target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/Dependencies/glew/Linux/libGLEW.so")
endif()

if(WIN32)
    #target_link_libraries(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/../Dependencies/glew/libSDL2.a")
endif()

target_link_libraries(${PROJECT_NAME} Core::library)
target_link_libraries(${PROJECT_NAME} Render::library)
