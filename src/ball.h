#pragma once
#include "raylib.h"

class Ball {
public:
    Ball(float x, float y, float radius, float vx, float vy);
    void Update(float dt);
    void Draw() const;

private:
    Vector2 position;
    Vector2 velocity;
    float radius;
};
