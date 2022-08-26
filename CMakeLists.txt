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
    Resources
    ${OPENGL_INCLUDE_DIRS}
)


set (SRCS
    GLTest/Includes/GLFW/glfw3.h
    GLTest/Includes/stb_image.h
    GLTest/Cactus.cpp
    GLTest/Cactus.hpp
    GLTest/CallbackDelegate.h
    GLTest/Collidable.cpp
    GLTest/Collidable.hpp
    GLTest/ColliderSystem.cpp
    GLTest/ColliderSystem.hpp
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
    GLTest/Main.cpp
    GLTest/ObjectSystemBase.hpp
    GLTest/PhysicBody.cpp
    GLTest/PhysicBody.hpp
    GLTest/PhysicBodySystem.cpp
    GLTest/PhysicBodySystem.hpp
    GLTest/Program.hpp
    GLTest/Window.cpp
    GLTest/Window.hpp
    WindowSystem/UiWindow.cpp
    WindowSystem/UiWindow.hpp
    Utils/Clock.hpp
    Utils/Utils.hpp
    Utils/Vector2.hpp
    Utils/Texture.cpp
    Utils/Texture.hpp
    Utils/RectangleShape.cpp
    Utils//RectangleShape.hpp
    Utils/Shape.hpp
    Utils/Sprite.cpp
    Utils/Sprite.hpp
    Utils/Line.cpp
    Utils/Line.hpp
    Utils/PrimitiveShape.cpp
    Utils/PrimitiveShape.hpp
    Utils/Color.hpp
)

set(RESOURCES
    Resources/border.png
    Resources/cactus.jpg
)

#file(COPY Resources DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

foreach(item IN LISTS RESOURCES)
    add_custom_command(
                OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
                DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
           )
endforeach()

add_custom_target(data-target ALL DEPENDS ${RESOURCES})

add_executable(${CMAKE_PROJECT_NAME}
    ${SRCS}
    )


target_link_libraries(${CMAKE_PROJECT_NAME} glfw)
target_link_libraries(${CMAKE_PROJECT_NAME} OpenGL::GL)

