
#include "Ball.h"
#include <raylib.h>

extern int player_score;
extern int cpu_score;
extern Color Yellow;

Ball::Ball(int x_pos, int y_pos, int sx, int sy, int r)
    : x(x_pos), y(y_pos), speed_x(sx), speed_y(sy), radius(r) {}

void Ball::Draw() const
{
    DrawCircle(x, y, radius, Yellow);
}

void Ball::Update()
{
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speed_y *= -1;
    }

    if (x + radius >= GetScreenWidth())
    {
        cpu_score++;
        ResetBall();
    }

    if (x - radius <= 0)
    {
        player_score++;
        ResetBall();
    }
}

void Ball::ResetBall()
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    int speed_choices[2] = { -1, 1 };
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];
}
