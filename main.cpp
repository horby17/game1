#include <GL/glew.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "background.h"
#include "plataforma.h"
#include "player.h"

void ajustarViewport(int ancho, int alto) {
    glViewport(0, 0, ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, ancho, alto, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Ventana de Visualización", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Error al crear la ventana" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        std::cerr << "Error al inicializar GLEW" << std::endl;
        return -1;
    }

    int ancho, alto;
    glfwGetFramebufferSize(window, &ancho, &alto);
    ajustarViewport(ancho, alto);

    if (!cargarTexturaBackground("../2/background.png")) { // Asumiendo que esta función está definida en background.cpp
        glfwTerminate();
        return -1;
    }

    initPlataforma(); // Asumiendo que esta función está definida en plataforma.cpp
    initPlayer(); // Inicializar estado del jugador.

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        drawBackground(); // Dibujar el fondo.
        drawPlataforma(); // Dibujar la plataforma.
        updatePlayer(ancho, alto, window); // Actualiza la posición y estado del jugador.
        drawPlayer(); // Dibuja al jugador en su nueva posición.

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
