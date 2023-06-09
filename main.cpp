#include "include/raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

const int screenWidth = 500;
const int screenHeight = 500;

void UpdateDrawFrame(void);     // Update and Draw one frame

int main(void)
{

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();        // Close window and OpenGL context

    return 0;
}

void UpdateDrawFrame(void)
{

    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You cr!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}