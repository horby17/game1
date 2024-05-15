// player.cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "player.h"
#include <cmath>

const float GRAVITY = -0.0005f;
const float JUMP_VELOCITY = 0.02f;
const float PLATFORM_Y = -0.4f;
const int CIRCLE_SEGMENTS = 20;
const float RADIUS = 0.05f;

static float x = 0.0f, y = PLATFORM_Y + 0.05f; // Posición inicial en la plataforma
static float vx = 0.0f, vy = 0.0f;
static bool isJumping = false;

void initPlayer() {
    x = 0.0f; y = PLATFORM_Y + 0.05f;
    vx = 0.0f; vy = 0.0f;
    isJumping = false;
}

void updatePlayer(int windowWidth, int windowHeight, GLFWwindow* window) {
    vy += GRAVITY;
    x += vx;
    y += vy;

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) vx = 0.01f;
    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) vx = -0.01f;
    else vx *= 0.9f; // Fricción

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && !isJumping) {
        vy = JUMP_VELOCITY;
        isJumping = true;
    }

    if (y <= PLATFORM_Y + 0.05f && vy < 0) {
        y = PLATFORM_Y + 0.05f;
        vy = 0.0f;
        isJumping = false;
    }
}

void drawPlayer() {
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f); // Color rojo
    glTranslatef(x, y, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < CIRCLE_SEGMENTS; i++) {
        float theta = 2.0f * M_PI * float(i) / float(CIRCLE_SEGMENTS);
        float cx = RADIUS * cosf(theta);
        float cy = RADIUS * sinf(theta);
        glVertex2f(cx, cy);
    }
    glEnd();
    glPopMatrix();
}
