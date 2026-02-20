#include <raylib.h>

int main() {
    InitWindow(1000, 600, "Space Shooter");
    SetTargetFPS(60);

    Rectangle player = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f, 30, 30 };
    

    float velX = 0.0f;
    float velY = 0.0f;
    
    float max_speed = 400.0f;       
    float acceleration = 600.0f;    
    float deceleration = 500.0f;   

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_UP))    velY -= acceleration * dt;
        if (IsKeyDown(KEY_DOWN))  velY += acceleration * dt;
        if (IsKeyDown(KEY_LEFT))  velX -= acceleration * dt;
        if (IsKeyDown(KEY_RIGHT)) velX += acceleration * dt;

        if (velX > max_speed) velX = max_speed;
        if (velX < -max_speed) velX = -max_speed;
        if (velY > max_speed) velY = max_speed;
        if (velY < -max_speed) velY = -max_speed;

        if (!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
            if (velX > 0) {
                velX -= deceleration * dt;
                if (velX < 0) velX = 0;
            } else if (velX < 0) {
                velX += deceleration * dt;
                if (velX > 0) velX = 0;
            }
        }
        if (!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN)) {
            if (velY > 0) {
                velY -= deceleration * dt;
                if (velY < 0) velY = 0;
            } else if (velY < 0) {
                velY += deceleration * dt;
                if (velY > 0) velY = 0;
            }
        }

        player.x += velX * dt;
        player.y += velY * dt;


        if (player.x < 0) { player.x = 0; velX = 0; }
        if (player.x + player.width > GetScreenWidth()) { player.x = GetScreenWidth() - player.width; velX = 0; }
        if (player.y < 0) { player.y = 0; velY = 0; }
        if (player.y + player.height > GetScreenHeight()) { player.y = GetScreenHeight() - player.height; velY = 0; }

   
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(player.x, player.y, player.width, player.height, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
