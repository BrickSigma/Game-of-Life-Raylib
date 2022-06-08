#include <stdbool.h>
#include "raylib.h"

// Header file containing basic array manipulation functions
#include "../headers/array.h"

const Color COLOR_GRID = {40, 40, 40, 255};
const Color COLOR_BG = {10, 10, 10, 255};
const Color COLOR_DIE_NEXT = {170, 170, 170, 255};

#define GRID_HEIGHT 90
#define GRID_WIDTH 160

int **update(RenderTexture2D screen, int **cells, int **updated_cells, int size, bool with_progress);

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Conways Game of Life");

    // Small FPS used to easily visualise the progress of each generation
    SetTargetFPS(20);

    // Two arrays to store the current state of all cells and the next generation
    int **cells = createArray(GRID_HEIGHT, GRID_WIDTH);
    int **updated_cells = createArray(GRID_HEIGHT, GRID_WIDTH);

    RenderTexture2D screen = LoadRenderTexture(screenWidth, screenHeight);
    update(screen, cells, updated_cells, 10, false);

    bool running = false;

    // Main game loop
    while (!WindowShouldClose()) {

        if (IsKeyReleased(KEY_SPACE)) {
            running = !running;
            update(screen, cells, updated_cells, 10, false);
        }
        if (IsMouseButtonDown(0)) {
            Vector2 pos = GetMousePosition();
            int x = (int)pos.x;
            int y = (int)pos.y;
            if ((x >= 0 && x < screenWidth) && (y >= 0 && y < screenHeight)) {
                cells[y/10][x/10] = 1;
                update(screen, cells, updated_cells, 10, false);
            }
        }

        if (running) {
            copyArray(cells, update(screen, cells, updated_cells, 10, true), GRID_HEIGHT, GRID_WIDTH);
        }

        BeginDrawing();

            DrawTextureRec(screen.texture, (Rectangle){0, 0, screenWidth, -screenHeight}, (Vector2){0, 0}, WHITE);

        EndDrawing();

    }

    // Free dynamically allocated arrays and variables:
    destroyArray(cells);
    destroyArray(updated_cells);
    UnloadRenderTexture(screen);

    CloseWindow();

    return 0;
}

/**
 * Main update function that manages the cells in the array.
 */
int **update(RenderTexture2D screen, int **cells, int **updated_cells, int size, bool with_progress) {
    // Fill the update array with zeros so that updated cells can be registered
    fillArray(updated_cells, GRID_HEIGHT, GRID_WIDTH, 0);

    BeginTextureMode(screen);
    ClearBackground(COLOR_GRID);
    // Loop through all cells and compare its surrounding cells to pre-set rules
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++) {
            int alive = sumArray(cells, GRID_HEIGHT, GRID_WIDTH, (Range){row-1, col-1, 3, 3}) - cells[row][col];
            Color color = cells[row][col] == 0 ? COLOR_BG:WHITE;

            if (cells[row][col] == 1) {
                if (alive < 2 || alive > 3) {
                    if (with_progress) {
                        color = COLOR_DIE_NEXT;
                    }
                } else if (alive >= 2 && alive <= 3) {
                    updated_cells[row][col] = 1;
                    if (with_progress) {
                        color = WHITE;
                    }
                }
            } else {
                if (alive == 3) {
                    updated_cells[row][col] = 1;
                    if (with_progress) {
                        color = WHITE;
                    }
                }
            }

            DrawRectangle(col*size, row*size, size-1, size-1, color);
            
        }
    }
    EndTextureMode();

    return updated_cells;
}