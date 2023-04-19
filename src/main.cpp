#include "raylib.h"
#include "Game.h"

#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#endif

Game game;

void UpdateDrawFrame()
{
    game.Update();
    game.Draw();
}

int main()
{
    game.Initialize();

#ifdef PLATFORM_WEB
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif
    game.Deinitialize();
}
