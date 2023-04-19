#pragma once

#include <vector>
#include "raylib.h"
#include "Cell.h"

class Game
{
public:
    void Initialize();

    void Update();

    void Draw();

    void Deinitialize();

private:
    float screenScale;

    int width;
    int height;

    std::vector<Cell> cells;
    std::vector<Cell> newCells;

    float timer;

    int cellCountX;
    int cellCountY;

    float cellSize;

    Random random;
};
