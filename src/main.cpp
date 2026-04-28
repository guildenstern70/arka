/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin

 * This software is licensed under MIT license.
 * See LICENSE.
 */

#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Arka");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
