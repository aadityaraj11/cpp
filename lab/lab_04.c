#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[low]; // Choose the first element as pivot
  int i = low + 1, j = high, temp;

  while (i <= j)
  {
    while (i <= high && arr[i] <= pivot)
      i++;
    while (j > low && arr[j] > pivot)
      j--;
    if (i < j)
    {
      // Swap arr[i] and arr[j]
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  // Swap pivot with arr[j] (correct position)
  temp = arr[j];
  arr[j] = arr[low];
  arr[low] = temp;

  return j; // Pivot final position
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int j = partition(arr, low, high);
    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
  }
}

int main()
{
  int n, i, arr[MAX];
  clock_t start, end;
  double cpu_time_used;

  printf("Enter the number of elements (n > 5000): ");
  scanf("%d", &n);

  if (n > MAX)
  {
    printf("Limit exceeded. Max allowed is %d.\n", MAX);
    return 1;
  }

  printf("Randomly generated array:\n");
  for (i = 0; i < n; i++)
  {
    arr[i] = rand() % 50000; // Random numbers between 0 and 49999
    printf("%d ", arr[i]);
  }

  start = clock();          // Start timing
  quickSort(arr, 0, n - 1); // Sort the array
  end = clock();            // End timing

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("\nSorted array:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\nTime taken for sorting: %lf seconds\n", cpu_time_used);
  return 0;
}
