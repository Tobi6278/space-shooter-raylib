#include <raylib.h>

int main(){

    InitWindow(800, 800, "First Raylib Game");
    SetTargetFPS(60);
    
    while(WindowShouldClose() == false){
        BeginDrawing();

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}