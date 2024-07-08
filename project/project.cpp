#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "function.h"

using namespace std;

int player_score = 0;
int cpu_score = 0;
Color Dark_Blue = Color{ 20, 133, 160, 255 };
Color Light_Blue = Color{ 129, 184, 204, 255 };
Color Yellow = Color{ 204, 204, 0, 255 };

int main()
{
    cout << "Starting the game" << endl;
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "Ping Pong Game");
    SetTargetFPS(60);

    // Load sound effect
    InitAudioDevice();
    Sound hitSound = LoadSound("sound.ogg"); // Adjust path as needed

    Ball ball(screen_width / 2, screen_height / 2, 7, 7, 20);
    Paddle player(screen_width - 35, screen_height / 2 - 60, 25, 120, 6);
    CpuPaddle cpu(10, screen_height / 2 - 60, 25, 120, 6);

    bool paused = false;
    bool gameOver = false;
    bool playerWins = false;
    const int winning_score = 10; // Changed to 10 points to win
    char playerName[30] = "";
    int nameLength = 0;
    bool enterName = true;

    while (!WindowShouldClose())
    {
        // Game logic here
        // ...

        BeginDrawing();
        ClearBackground(Dark_Blue);
        // Draw game elements
        // ...

        if (paused)
        {
            // Draw pause menu
            // ...
        }

        EndDrawing();
    }

    // Unload sound effect
    UnloadSound(hitSound);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
