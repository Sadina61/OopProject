
#include "CpuPaddle.h"

CpuPaddle::CpuPaddle(float xpos, float ypos, float w, float h, int s)
    : Paddle(xpos, ypos, w, h, s) {}

void CpuPaddle::Update(int ball_y)
{
    if (y + height / 2 > ball_y)
    {
        y -= speed;
    }

    if (y + height / 2 <= ball_y)
    {
        y += speed;
    }

    LimitMovement();
}
