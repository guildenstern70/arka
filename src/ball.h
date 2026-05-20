/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin
 * This software is licensed under MIT license.
 * See LICENSE.
 */

#pragma once
#include "raylib.h"

class Ball {
public:
    Ball(float x, float y, float radius, float vx, float vy);
    void Update(float dt);
    void CheckCollisionWithPaddle(const Rectangle& paddleRect);
    void Draw() const;
    bool IsLost() const;
    void Reset(float x, float y, float vx, float vy);

private:
    Vector2 position;
    Vector2 velocity;
    float radius;
};
