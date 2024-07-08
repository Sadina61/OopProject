#include "Game.h"
#include <raylib.h>

Color Dark_Blue = { 20, 133, 160, 255 };
Color Light_Blue = { 129, 184, 204, 255 };
Color Yellow = { 204, 204, 0, 255 };

bool CheckButtonCollision(int mouseX, int mouseY, int x, int y, int width, int height)
{
    return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
}

bool DisplayPauseMenu(int screenWidth, int screenHeight)
{
    int buttonWidth = 200;
    int buttonHeight = 50;
    int buttonX = screenWidth / 2 - buttonWidth / 2;

    int resumeButtonY = screenHeight / 2 - 60;
    DrawRectangle(buttonX, resumeButtonY, buttonWidth, buttonHeight, Light_Blue);
    DrawText("Resume", buttonX + 40, resumeButtonY + 10, 30, DARKGRAY);

    int exitButtonY = screenHeight / 2 + 10;
    DrawRectangle(buttonX, exitButtonY, buttonWidth, buttonHeight, Light_Blue);
    DrawText("Exit", buttonX + 70, exitButtonY + 10, 30, DARKGRAY);

    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

void DisplayGameOverScreen(bool playerWins, const char* playerName, int screenWidth, int screenHeight)
{
    BeginDrawing();
    ClearBackground(Dark_Blue);

    if (playerWins)
    {
        DrawText(TextFormat("You win, %s!", playerName), screenWidth / 2 - 100, screenHeight / 2 - 50, 40, WHITE);
    }
    else
    {
        DrawText(TextFormat("You lose, %s!", playerName), screenWidth / 2 - 100, screenHeight / 2 - 50, 40, WHITE);
    }

    DrawText("Press ESC to exit", screenWidth / 2 - 100, screenHeight / 2, 20, WHITE);
    EndDrawing();
}
