#include <raylib.h>
#include "visualiser.h"

#define screenWidth 1250
#define screenHeight 700
#define size 42

int tower_width = 15;

int tower_height[size]; ////
int tower_pos[size];    ///

const char *algos[] = {
    "selection sort",
    "bubble sort"};
int algo_ = 0;

void genArr(int arr[], int MAX)
{

  for (int i = 0; i < size; i++)
  {
    arr[i] = 10 + rand() % (MAX - 10 + 1);
  }
}

void towers()
{

  srand(time(0));
  genArr(tower_height, 500);

  for (int i = 0; i < size; i++)
  {
    tower_pos[i] = i;
  }
}

void VisualizeArray(int arr[], int SIZE, int highlightedIndex1, int highlightedIndex2)
{
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText(algos[algo_], 0, 0, 20, RED); // x y size
  DrawText("press enter to begin", 0, 20, 20, GREEN);

  for (int i = 0; i < size; i++)
  {
    Color color = BLUE;
    if (i == highlightedIndex1)
      color = RED;
    else if (i == highlightedIndex2)
      color = GREEN;
    DrawRectangle(0 + 2 * tower_width * tower_pos[i], 600 - tower_height[i], tower_width, tower_height[i], color);
  }
  EndDrawing();
}


void controls()
{
  if (IsKeyPressed(KEY_UP))
  {
    algo_++;
    if (algo_ >= sizeof(algos) / sizeof(algos[0]))
    {
      algo_ = 0;
    }
  }
  if (IsKeyPressed(KEY_DOWN))
  {
    algo_--;
    if (algo_ <= -1)
    {
      algo_ = sizeof(algos) / sizeof(algos[0]) - 1;
    }
  }
  
}

int render()
{
  towers();
  InitWindow(screenWidth, screenHeight, "Sorting Algorithm visualiser");
  SetTargetFPS(100);
  while (!WindowShouldClose())
  {
    // BeginDrawing();

    // ClearBackground(BLACK);
    if (IsKeyPressed(KEY_ENTER))
    {
      if (algos[algo_] == "selection sort")
      {
        selectionSort(tower_height, size);
      }
    }

    VisualizeArray(tower_height, size, -1, -1);
  }

  CloseWindow();
  return 0;
}