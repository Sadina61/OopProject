#pragma once
#include "Paddle.h"

class CpuPaddle : public Paddle
{
public:
    CpuPaddle(float xpos, float ypos, float w, float h, int s);
    void Update(int ball_y);
};
