#include <raylib.h>

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

public:
    Ball(int x_pos, int y_pos, int sx, int sy, int r);
    void Draw() const;
    void Update();
    void ResetBall();
};