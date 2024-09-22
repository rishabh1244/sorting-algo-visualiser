#include <stdio.h>
#include "algo.h"
#include <unistd.h> // for sleep()

void displayArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

}
void swap(int *xp,int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n,int size)
{
  int i, j, minIndex;

  for (i = 0; i < n - 1; i++)
  {
    minIndex = i;
    for (j = i + 1; j < n; j++)
    {


      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
      VisualizeArray(arr, size, i, minIndex);
      // sleep(50000);
    }
    if (minIndex != i)
    {
      swap(&arr[i], &arr[minIndex]);
    }
    VisualizeArray(arr, size, i, minIndex);

    // sleep(500000);
  }
}
