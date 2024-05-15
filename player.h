// player.h
#include<GLFW/glfw3.h>
#ifndef PLAYER_H
#define PLAYER_H


// Inicializar el jugador
void initPlayer();

// Actualizar la posición del jugador
void updatePlayer(int windowWidth, int windowHeight, GLFWwindow* window);

// Dibujar al jugador
void drawPlayer();

#endif // PLAYER_H
