#include <GL/glew.h>
#include "plataforma.h"



void initPlataforma() {
    // Aquí se pueden inicializar variables o configuraciones si es necesario.
}

void drawPlataforma() {
    glColor3f(1.0f, 1.0f, 1.0f); // Establece el color a blanco
    glLineWidth(5.0f); // Establece el grosor de la línea
    glBegin(GL_LINES);
    glVertex2f(0.0f, 979.0f); // Coordenada de inicio de la línea
    glVertex2f(1919.0f, 979.0f); // Coordenada final de la línea
    glEnd();
}
