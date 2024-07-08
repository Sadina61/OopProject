#pragma once

#include <raylib.h>

class Paddle
{
protected:
    void LimitMovement();

public:
    float x, y;
    float width, height;
    int speed;

    Paddle(float xpos, float ypos, float w, float h, int s);
    void Draw() const;
    void Update();
};