#include <raylib.h>
#include "raymath.h"
#include <cmath>

int main()
{
    InitWindow(1000, 600, "Space Shooter");
    SetTargetFPS(60);

    Rectangle player = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f,
        30,
        30
    };

    float velX = 0.0f;
    float velY = 0.0f;

    float max_speed = 400.0f;
    float acceleration = 600.0f;
    float deceleration = 500.0f;

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_W))    velY -= acceleration * dt;
        if (IsKeyDown(KEY_S))  velY += acceleration * dt;
        if (IsKeyDown(KEY_A))  velX -= acceleration * dt;
        if (IsKeyDown(KEY_D)) velX += acceleration * dt;

        velX = Clamp(velX, -max_speed, max_speed);
        velY = Clamp(velY, -max_speed, max_speed);

        if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D))
        {
            if (velX > 0.0f)
            {
                velX -= deceleration * dt;
                if (velX < 0.0f) velX = 0.0f;
            }
            else if (velX < 0.0f)
            {
                velX += deceleration * dt;
                if (velX > 0.0f) velX = 0.0f;
            }
        }

        if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S))
        {
            if (velY > 0.0f)
            {
                velY -= deceleration * dt;
                if (velY < 0.0f) velY = 0.0f;
            }
            else if (velY < 0.0f)
            {
                velY += deceleration * dt;
                if (velY > 0.0f) velY = 0.0f;
            }
        }


        player.x += velX * dt;
        player.y += velY * dt;


        if (player.x < 0) { player.x = 0; velX = 0; }
        if (player.y < 0) { player.y = 0; velY = 0; }
        if (player.x + player.width > GetScreenWidth())
        {
            player.x = GetScreenWidth() - player.width;
            velX = 0;
        }
        if (player.y + player.height > GetScreenHeight())
        {
            player.y = GetScreenHeight() - player.height;
            velY = 0;
        }

    
        Vector2 playerCenter = {
            player.x + player.width / 2.0f,
            player.y + player.height / 2.0f
        };

        Vector2 mouse = GetMousePosition();
        Vector2 dir = Vector2Subtract(mouse, playerCenter);

        float angle = atan2f(dir.y, dir.x) * RAD2DEG;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectanglePro(
            player,
            { player.width / 2.0f, player.height / 2.0f },
            angle,
            BLUE
        );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
