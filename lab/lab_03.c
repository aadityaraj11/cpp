#include <stdio.h>
#include <time.h>

#define MAX 50000

int temp[MAX]; // Static array for merge operations

void mergeSort(int arr[], int low, int mid, int high)
{
  int i = low, j = mid + 1, k = 0;

  // Merge two sorted subarrays
  while (i <= mid && j <= high)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid)
    temp[k++] = arr[i++];
  while (j <= high)
    temp[k++] = arr[j++];

  // Copy sorted elements back into original array
  for (i = low, k = 0; i <= high; i++, k++)
  {
    arr[i] = temp[k];
  }
}

void partition(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    partition(arr, low, mid);       // Divide left half
    partition(arr, mid + 1, high);  // Divide right half
    mergeSort(arr, low, mid, high); // Merge the two halves
  }
}

int main()
{
  int arr[MAX];
  int n;
  clock_t start, end;
  double tc;

  printf("Enter the number of elements (n <= %d): ", MAX);
  scanf("%d", &n);

  if (n > MAX)
  {
    printf("Exceeded maximum array size.\n");
    return 1;
  }

  // Generate random numbers
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 10000;
  }

  // Start timer
  start = clock();

  // Perform merge sort
  partition(arr, 0, n - 1);

  // End timer
  end = clock();

  // Calculate time taken
  tc = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Time taken for merge sort: %lf seconds\n", tc);

  return 0;
}