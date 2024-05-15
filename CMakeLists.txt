cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};/home/horby/glfw/install/lib/cmake/glfw3")  # Ajusta la ruta según tu sistema
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};/home/horby/glad")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)



add_executable(untitled main.cpp
        stb_image.h
        stb_image.cpp
        background.cpp
        background.h
        plataforma.cpp
        plataforma.h
        player.cpp
        player.h
        #shinobi.cpp
        #  pruebas'.cpp
)


target_link_libraries(untitled PRIVATE glfw GL GLEW::glew  ${GLUT_LIBRARIES})  # Eliminadas librerías GLUT innecesarias