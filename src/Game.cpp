#include "Game.h"
#include "raylib.h"

void Game::Initialize()
{
    cellCountX = 64;
    cellCountY = 64;

    cellSize = 16.0f;

    width = cellCountX * cellSize;
    height = cellCountY * cellSize;
    screenScale = 1.0f;

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(width * screenScale, height * screenScale, "Game");

    for (int y = 0; y < cellCountY; y++)
    {
        for (int x = 0; x < cellCountX; x++)
        {
            cells.push_back(Cell(cellSize));

            cells[y * cellCountX + x].SetPosition((Vector2){(float)x, (float)y});
            cells[y * cellCountX + x].SetCellType(CellType::Empty);
        }
    }

    newCells = cells;
}

void Game::Update()
{
    timer += GetFrameTime();

    if (timer >= 0.001f)
    {
        timer -= 0.001f;

        for (int i = cells.size() - 1; i >= 0; i--)
        {
            cells[i].Update(cells, newCells, i, cellCountX, random);
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        newCells[(int)(GetMouseY() / cellSize) * cellCountX + (int)GetMouseX() / cellSize].SetCellType(CellType::Sand);
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        newCells[(int)(GetMouseY() / cellSize) * cellCountX + (int)GetMouseX() / cellSize].SetCellType(CellType::Water);
    }

    cells = newCells;
}

void Game::Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < cells.size(); i++)
    {
        cells[i].Draw();
    }

    DrawFPS(0, 0);

    EndDrawing();
}

void Game::Deinitialize()
{
    CloseWindow();
}
