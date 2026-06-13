#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000 // Define maximum size of the array

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
  int i, j, minIndex, temp;
  for (i = 0; i < n - 1; i++)
  {
    minIndex = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    // Swap the found minimum element with the first element
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

int main()
{
  int n, i;
  int arr[MAX]; // Use statically allocated array
  clock_t start, end;
  double cpu_time_used;

  printf("Enter the number of elements (n): ");
  scanf("%d", &n);

  if (n > MAX)
  {
    printf("Please enter a value of n less than or equal to %d.\n", MAX);
    return 1;
  }
  else if (n < 5000)
  {
    printf("Please enter a value of n greater than or equal to 5000.\n");
    return 1;
  }

  // Generate n random numbers
  srand(time(NULL));
  for (i = 0; i < n; i++)
  {
    arr[i] = rand() % 10000; // Generating random numbers between 0 to 9999
  }

  // Record the starting time
  start = clock();

  // Perform Selection Sort
  selectionSort(arr, n);

  // Record the ending time
  end = clock();

  // Calculate the time taken
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Time taken for sorting: %lf seconds\n", cpu_time_used);

  return 0;
}