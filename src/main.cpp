/*
 * PROJECT ARKA
 * (C) 2026 Alessio Saltarin

 * This software is licensed under MIT license.
 * See LICENSE.
 */

#include "raylib.h"
#include "ball.h"
#include "paddle.h"

enum class GameState {
    INTRO,
    PLAYING,
    GAME_OVER
};

int main()
{
    InitWindow(800, 600, "Arka");
    SetTargetFPS(60);

    GameState state = GameState::INTRO;

    Ball ball(400.0f, 300.0f, 8.0f, 300.0f, 300.0f);
    Paddle paddle(350.0f, 550.0f, 100.0f, 15.0f, 500.0f, SKYBLUE);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        switch (state)
        {
            case GameState::INTRO:
            {
                if (IsKeyPressed(KEY_SPACE))
                {
                    ball.Reset(400.0f, 300.0f, 300.0f, 300.0f);
                    paddle.Reset(350.0f, 550.0f);
                    state = GameState::PLAYING;
                }
                break;
            }
            case GameState::PLAYING:
            {
                paddle.Update(dt);
                ball.Update(dt);
                ball.CheckCollisionWithPaddle(paddle.GetRect());

                if (ball.IsLost())
                {
                    state = GameState::GAME_OVER;
                }
                break;
            }
            case GameState::GAME_OVER:
            {
                if (IsKeyPressed(KEY_SPACE))
                {
                    state = GameState::INTRO;
                }
                break;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        switch (state)
        {
            case GameState::INTRO:
            {
                const auto titleText = "Arka";
                const int titleFontSize = 80;
                const int titleWidth = MeasureText(titleText, titleFontSize);
                DrawText(titleText, (GetScreenWidth() - titleWidth) / 2, 200, titleFontSize, SKYBLUE);

                const auto subtitleText = "Press SPACE to play";
                constexpr int subtitleFontSize = 24;
                const int subtitleWidth = MeasureText(subtitleText, subtitleFontSize);
                DrawText(subtitleText, (GetScreenWidth() - subtitleWidth) / 2, 350, subtitleFontSize, LIGHTGRAY);
                break;
            }
            case GameState::PLAYING:
            {
                ball.Draw();
                paddle.Draw();
                break;
            }
            case GameState::GAME_OVER:
            {
                const auto overText = "Game Over";
                constexpr int overFontSize = 60;
                const int overWidth = MeasureText(overText, overFontSize);
                DrawText(overText, (GetScreenWidth() - overWidth) / 2, 220, overFontSize, RED);

                const auto subText = "Press SPACE";
                constexpr int subFontSize = 24;
                const int subWidth = MeasureText(subText, subFontSize);
                DrawText(subText, (GetScreenWidth() - subWidth) / 2, 350, subFontSize, LIGHTGRAY);
                break;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
