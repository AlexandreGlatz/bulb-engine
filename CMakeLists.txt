cmake_minimum_required(VERSION 4.0)
project(QuackEngineProject)

file(COPY ${PROJECT_SOURCE_DIR}/res/ 
     DESTINATION ${PROJECT_BINARY_DIR}/res  
)  

add_subdirectory(Core)
add_subdirectory(Render)
add_subdirectory(Engine)
add_subdirectory(Game)
add_subdirectory(QuackEngine)
