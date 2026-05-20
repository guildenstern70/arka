/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin
 * This software is licensed under MIT license.
 * See LICENSE.
 */

#include "ball.h"
#include <cmath>

Ball::Ball(float x, float y, float radius, float vx, float vy)
    : position{x, y}, velocity{vx, vy}, radius(radius) {}

void Ball::Update(const float dt) {
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    if (position.x - radius <= 0.0f) {
        position.x = radius;
        velocity.x = -velocity.x;
    } else if (position.x + radius >= static_cast<float>(screenWidth)) {
        position.x = static_cast<float>(screenWidth) - radius;
        velocity.x = -velocity.x;
    }

    if (position.y - radius <= 0.0f) {
        position.y = radius;
        velocity.y = -velocity.y;
    }
}

void Ball::CheckCollisionWithPaddle(const Rectangle& paddleRect) {
    if (CheckCollisionCircleRec(position, radius, paddleRect)) {
        if (velocity.y > 0.0f) {
            position.y = paddleRect.y - radius;
            
            // Calculate hit factor relative to paddle center (-1.0 to 1.0)
            float paddleCenter = paddleRect.x + paddleRect.width / 2.0f;
            float hitFactor = (position.x - paddleCenter) / (paddleRect.width / 2.0f);

            if (hitFactor < -1.0f) hitFactor = -1.0f;
            if (hitFactor > 1.0f) hitFactor = 1.0f;

            // Keep overall speed constant but redirect the ball
            float speed = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
            float newX = speed * hitFactor * 0.8f;
            float newYSq = speed * speed - newX * newX;
            
            velocity.x = newX;
            if (newYSq > 0.0f) {
                velocity.y = -std::sqrt(newYSq);
            } else {
                velocity.y = -velocity.y;
            }
        }
    }
}

void Ball::Draw() const {
    DrawCircleV(position, radius, WHITE);
}

bool Ball::IsLost() const {
    return position.y - radius > static_cast<float>(GetScreenHeight());
}

void Ball::Reset(float x, float y, float vx, float vy) {
    position = {x, y};
    velocity = {vx, vy};
}
