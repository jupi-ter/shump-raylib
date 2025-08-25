#include <raylib.h>
#include "player.h"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};
    
    const int screenDimensions = 512;
    
    InitWindow(screenDimensions, screenDimensions, "CHROMA DRIFT");
    SetTargetFPS(60);
    
    Player player;

    while (!WindowShouldClose())
    {
        player.Update();
        BeginDrawing();
            ClearBackground(darkGreen);
            player.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}