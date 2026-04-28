/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin

 * This software is licensed under MIT license.
 * See LICENSE.
 */

#include "raylib.h"
#include "ball.h"

int main()
{
    InitWindow(800, 600, "Arka");
    SetTargetFPS(60);

    Ball ball(400.0f, 300.0f, 8.0f, 300.0f, -300.0f);

    while (!WindowShouldClose())
    {
        ball.Update(GetFrameTime());

        BeginDrawing();
        ClearBackground(BLACK);
        ball.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
