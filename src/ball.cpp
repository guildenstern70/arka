#include "ball.h"

Ball::Ball(float x, float y, float radius, float vx, float vy)
    : position{x, y}, velocity{vx, vy}, radius(radius) {}

void Ball::Update(float dt) {
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
    } else if (position.y + radius >= static_cast<float>(screenHeight)) {
        position.y = static_cast<float>(screenHeight) - radius;
        velocity.y = -velocity.y;
    }
}

void Ball::Draw() const {
    DrawCircleV(position, radius, WHITE);
}
