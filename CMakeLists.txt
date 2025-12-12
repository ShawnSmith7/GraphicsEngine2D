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

FetchContent_Declare(glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 1.0.2
)
FetchContent_MakeAvailable(glfw glm)

add_library(GraphicsEngine2DLib
    src/Window.cpp
    src/ShaderProgram.cpp
    src/VertexArray.cpp
    src/Buffer.cpp
    src/VertexBuffer.cpp
    src/IndexBuffer.cpp
    src/Transform.cpp
    src/Rect.cpp
    src/Circle.cpp
    src/SemiCircle.cpp
    src/Line.cpp
    src/ThickLine.cpp
    src/RoundThickLine.cpp
)
target_link_libraries(GraphicsEngine2DLib PUBLIC opengl32 glad glfw glm)

add_executable(GraphicsEngine2DApp src/main.cpp)
target_link_libraries(GraphicsEngine2DApp PRIVATE GraphicsEngine2DLib)

target_compile_definitions(GraphicsEngine2DLib PRIVATE
    SRC_DIR="${CMAKE_SOURCE_DIR}/src/"
)