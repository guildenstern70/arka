/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin
 * This software is licensed under MIT license.
 * See LICENSE.
 */

#pragma once
#include "raylib.h"

class Paddle {
public:
    Paddle(float x, float y, float width, float height, float speed, Color color);
    void Update(float dt);
    void Draw() const;
    [[nodiscard]] Rectangle GetRect() const;
    void Reset(float x, float y);

private:
    Vector2 position;
    float width;
    float height;
    float speed;
    Color color;
};
