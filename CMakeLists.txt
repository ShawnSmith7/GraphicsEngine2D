cmake_minimum_required(VERSION 4.1)
project(GraphicsEngine2D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(glad dependencies/glad/src/glad.c)
target_include_directories(glad PUBLIC dependencies/glad/include)

include(FetchContent)
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

#add_library(GraphicsEngine2DLib)
#target_include_directories(GraphicsEngine2DLib PUBLIC src)
#target_link_libraries(GraphicsEngine2DLib PUBLIC opengl32 glad)

add_executable(GraphicsEngine2DApp src/main.cpp)
target_link_libraries(GraphicsEngine2DApp PRIVATE opengl32 glad glfw)
#target_link_libraries(GraphicsEngine2DApp PRIVATE GraphicsEngine2DLib)