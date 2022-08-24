# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

cmake_minimum_required(VERSION 3.5)
project(Engine2D)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(
    GLTest
    GLTest/Includes
    GLTest/Includes/GLFW
    ${OPENGL_INCLUDE_DIRS}
)


set (SRCS
    GLTest/Includes/GLFW/glfw3.h
    GLTest/Includes/stb_image.h
    GLTest/Cactus.cpp
    GLTest/Cactus.hpp
    GLTest/CallbackDelegate.h
    GLTest/Clock.hpp
    GLTest/Collidable.cpp
    GLTest/Collidable.hpp
    GLTest/ColliderSystem.cpp
    GLTest/ColliderSystem.hpp
    GLTest/Color.hpp
    GLTest/Defines.hpp
    GLTest/Dino.cpp
    GLTest/Dino.hpp
    GLTest/EngineHeader.hpp
    GLTest/Floor.cpp
    GLTest/Floor.hpp
    GLTest/GameObject.cpp
    GLTest/GameObject.hpp
    GLTest/GameObjectSystem.cpp
    GLTest/GameObjectSystem.hpp
    GLTest/IterationTimer.hpp
    GLTest/KeyListener.cpp
    GLTest/KeyListener.hpp
    GLTest/Line.cpp
    GLTest/Line.hpp
    GLTest/Main.cpp
    GLTest/ObjectSystemBase.hpp
    GLTest/PhysicBody.cpp
    GLTest/PhysicBody.hpp
    GLTest/PhysicBodySystem.cpp
    GLTest/PhysicBodySystem.hpp
    GLTest/PrimitiveShape.cpp
    GLTest/PrimitiveShape.hpp
    GLTest/Program.hpp
    GLTest/RectangleShape.cpp
    GLTest/RectangleShape.hpp
    GLTest/Shape.hpp
    GLTest/Sprite.cpp
    GLTest/Sprite.hpp
    GLTest/Texture.cpp
    GLTest/Texture.hpp
    GLTest/Utils.hpp
    GLTest/Vector2.hpp
    GLTest/Window.cpp
    GLTest/Window.hpp
    WindowSystem/UiWindow.cpp
    WindowSystem/UiWindow.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME} glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} OpenGL::GL)

