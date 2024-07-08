#pragma once
#include <raylib.h>

extern Color Dark_Blue;
extern Color Light_Blue;

bool CheckButtonCollision(int mouseX, int mouseY, int x, int y, int width, int height);
bool DisplayPauseMenu(int screenWidth, int screenHeight);
void DisplayGameOverScreen(bool playerWins, const char* playerName, int screenWidth, int screenHeight);
