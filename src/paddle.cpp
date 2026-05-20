/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin

 * This software is licensed under MIT license.
 * See LICENSE.
 */

#include "paddle.h"

Paddle::Paddle(float x, float y, float width, float height, float speed, Color color)
    : position{x, y}, width(width), height(height), speed(speed), color(color) {}

void Paddle::Update(float dt) {
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        position.x -= speed * dt;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        position.x += speed * dt;
    }

    // Clamp paddle within screen bounds
    const float screenWidth = static_cast<float>(GetScreenWidth());
    if (position.x < 0.0f) {
        position.x = 0.0f;
    } else if (position.x + width > screenWidth) {
        position.x = screenWidth - width;
    }
}

void Paddle::Draw() const {
    DrawRectangleRounded(GetRect(), 0.5f, 12, color);
}

Rectangle Paddle::GetRect() const {
    return Rectangle{position.x, position.y, width, height};
}

void Paddle::Reset(float x, float y) {
    position = {x, y};
}
