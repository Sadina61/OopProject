#include "Paddle.h"
#include <raylib.h>

Paddle::Paddle(float xpos, float ypos, float w, float h, int s)
    : x(xpos), y(ypos), width(w), height(h), speed(s) {}

void Paddle::Draw() const
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y -= speed;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y += speed;
    }

    LimitMovement();
}

void Paddle::LimitMovement()
{
    if (y <= 0)
    {
        y = 0;
    }

    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}
