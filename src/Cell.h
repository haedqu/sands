#pragma once

#include <vector>
#include "raylib.h"
#include "Random.h"

enum class CellType
{
    Empty,
    Sand,
    Water
};

class Cell
{
public:
    Cell(const float cellSize);

    Cell& operator=(const Cell& argument);

    void SetPosition(const Vector2& position);
    void SetCellType(const CellType cellType);

    void Update(std::vector<Cell>& cells, std::vector<Cell>& newCells, int i, int width, Random& random);

    void Draw();

private:
    Vector2 position;

    float cellSize;

    CellType cellType;
};
