#include <GL/glew.h>
#include "background.h"
#include <iostream>



#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint textureID; // Global variable to hold the texture ID

bool cargarTexturaBackground(const std::string& nombreArchivo) {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    int width, height, channels;
    unsigned char* image = stbi_load(nombreArchivo.c_str(), &width, &height, &channels, STBI_rgb_alpha);
    if (!image) {
        std::cerr << "Error al cargar la imagen " << nombreArchivo << std::endl;
        return false;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);

    return true;
}

void drawBackground() {
    glBindTexture(GL_TEXTURE_2D, textureID);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1920, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1920, 1080);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(0, 1080);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
