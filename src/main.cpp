#include <raylib.h>

int main(){

    InitWindow(800, 800, "First Raylib Game");
    SetTargetFPS(60);
    
    while(WindowShouldClose() == false){
        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        DrawLine(100, 100, 700, 500, RED);
        
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}