#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "CpuPaddle.h"
#include "Game.h"

using namespace std;

int player_score = 0;
int cpu_score = 0;

int main()
{
    cout << "Starting the game" << endl;
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "Ping Pong Game");
    SetTargetFPS(60);

    // Load sound effect
    InitAudioDevice();
    Sound hitSound = LoadSound("sound.ogg");

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
        if (enterName)
        {
            BeginDrawing();
            ClearBackground(Dark_Blue);
            DrawText("Enter your name:", screen_width / 2 - 100, screen_height / 2 - 50, 20, WHITE);
            DrawText(playerName, screen_width / 2 - 100, screen_height / 2, 20, WHITE);
            EndDrawing();

            int key = GetCharPressed();
            while (key > 0)
            {
                if ((key >= 32) && (key <= 125) && (nameLength < 29))
                {
                    playerName[nameLength] = (char)key;
                    nameLength++;
                    playerName[nameLength] = '\0';
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                enterName = false;
            }

            continue;
        }

        if (gameOver)
        {
            DisplayGameOverScreen(playerWins, playerName, screen_width, screen_height);
            if (IsKeyPressed(KEY_ESCAPE))
            {
                break;
            }
            continue;
        }

        // Check for pause state
        if (IsKeyPressed(KEY_SPACE))
        {
            paused = !paused;
        }

        if (!paused)
        {
            ball.Update();
            player.Update();
            cpu.Update(ball.y);

            // Check collision with player paddle
            if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ player.x, player.y, player.width, player.height }))
            {
                ball.speed_x *= -1;
                PlaySound(hitSound);
            }

            // Check collision with CPU paddle
            if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpu.x, cpu.y, cpu.width, cpu.height }))
            {
                ball.speed_x *= -1;
                PlaySound(hitSound);
            }

            // check wall collision for sound
            if (ball.x + ball.radius >= GetScreenWidth() - 5 || ball.x - ball.radius <= 5)
            {
                PlaySound(hitSound);
            }

            if (player_score >= winning_score)
            {
                gameOver = true;
                playerWins = true;
            }
            else if (cpu_score >= winning_score)
            {
                gameOver = true;
                playerWins = false;
            }
        }

        BeginDrawing();
        ClearBackground(Dark_Blue);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        ball.Draw();
        cpu.Draw();
        player.Draw();
        DrawText(TextFormat("%i", cpu_score), screen_width / 4, 20, 80, WHITE);
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4, 20, 80, WHITE);

        if (paused)
        {
            int buttonWidth = 200;
            int buttonHeight = 50;
            int buttonX = screen_width / 2 - buttonWidth / 2;

            int resumeButtonY = screen_height / 2 - 60;
            DrawRectangle(buttonX, resumeButtonY, buttonWidth, buttonHeight, Light_Blue);
            DrawText("Resume", buttonX + 40, resumeButtonY + 10, 30, DARKGRAY);

            int exitButtonY = screen_height / 2 + 10;
            DrawRectangle(buttonX, exitButtonY, buttonWidth, buttonHeight, Light_Blue);
            DrawText("Exit", buttonX + 70, exitButtonY + 10, 30, DARKGRAY);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                int mouseX = GetMouseX();
                int mouseY = GetMouseY();

                if (CheckButtonCollision(mouseX, mouseY, buttonX, resumeButtonY, buttonWidth, buttonHeight))
                {
                    paused = false;
                }
                else if (CheckButtonCollision(mouseX, mouseY, buttonX, exitButtonY, buttonWidth, buttonHeight))
                {
                    break;
                }
            }
        }

        EndDrawing();
    }

    // Unload sound effect
    UnloadSound(hitSound);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

