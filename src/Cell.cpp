#include "Cell.h"
#include <raylib.h>

Cell::Cell(const float cellSize)
{
    this->cellSize = cellSize;

    position = (Vector2){0.0f, 0.0f};
}

Cell& Cell::operator=(const Cell &argument)
{
    position = argument.position;
    cellType = argument.cellType;

    return *this;
}

void Cell::SetPosition(const Vector2 &position)
{
    this->position = position;
}

void Cell::SetCellType(const CellType cellType)
{
    this->cellType = cellType;
}

void Cell::Update(std::vector<Cell>& cells, std::vector<Cell>& newCells, int i, int width, Random& random)
{
    switch (cellType)
    {
        case CellType::Empty:
            break;

        case CellType::Sand:
            if (i + width < cells.size() - 1)
            {
                if (newCells[i + width].cellType == CellType::Empty || newCells[i + width].cellType == CellType::Water)
                {
                    newCells[i].cellType = newCells[i + width].cellType;
                    newCells[i + width].cellType = CellType::Sand;
                }

                else if (random.GenerateRandomNumber(0, 1) == 0)
                {
                    if (newCells[i + width - 1].cellType == CellType::Empty || newCells[i + width - 1].cellType == CellType::Water)
                    {
                        newCells[i].cellType = newCells[i + width - 1].cellType;
                        newCells[i + width - 1].cellType = CellType::Sand;
                    }

                    else if (newCells[i + width + 1].cellType == CellType::Empty || newCells[i + width + 1].cellType == CellType::Water)
                    {
                        newCells[i].cellType = newCells[i + width + 1].cellType;
                        newCells[i + width + 1].cellType = CellType::Sand;
                    }
                }

                else
                {
                    if (newCells[i + width + 1].cellType == CellType::Empty || newCells[i + width + 1].cellType == CellType::Water)
                    {
                        newCells[i].cellType = newCells[i + width + 1].cellType;
                        newCells[i + width + 1].cellType = CellType::Sand;
                    }

                    else if (newCells[i + width - 1].cellType == CellType::Empty || newCells[i + width - 1].cellType == CellType::Water)
                    {
                        newCells[i].cellType = newCells[i + width - 1].cellType;
                        newCells[i + width - 1].cellType = CellType::Sand;
                    }
                }

            }
            break;

        case CellType::Water:
            if (i + width < cells.size() - 1)
            {
                if (newCells[i + width].cellType == CellType::Empty)
                {
                    newCells[i].cellType = CellType::Empty;
                    newCells[i + width].cellType = CellType::Water;
                }

                else if (random.GenerateRandomNumber(0, 1) == 0)
                {
                    if (newCells[i + width - 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i + width - 1].cellType = CellType::Water;
                    }

                    else if (newCells[i + width + 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i + width + 1].cellType = CellType::Water;
                    }

                    else if (newCells[i - 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i - 1].cellType = CellType::Water;
                    }

                    else if (newCells[i + 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i + 1].cellType = CellType::Water;
                    }
                }

                else
                {
                    if (newCells[i + width + 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i + width + 1].cellType = CellType::Water;
                    }

                    else if (newCells[i + width - 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i + width - 1].cellType = CellType::Water;
                    }

                    else if (newCells[i + 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i + 1].cellType = CellType::Water;
                    }

                    else if (newCells[i - 1].cellType == CellType::Empty)
                    {
                        newCells[i].cellType = CellType::Empty;
                        newCells[i - 1].cellType = CellType::Water;
                    }
                }

            }
            break;
    }
}

void Cell::Draw()
{
    switch (cellType)
    {
        case CellType::Empty:
            DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BLACK);
            break;

        case CellType::Sand:
            DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BEIGE);
            break;

        case CellType::Water:
            DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, BLUE);
            break;
    }
}
