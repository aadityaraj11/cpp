#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_LOCATIONS 100
#define MAX_KEYS 100

// Structure to represent an employee record
struct EmployeeRecord
{
  int key; // 4-digit key     // Add other fields as needed
};

// Structure to represent a memory location in the hash table
struct MemoryLocation
{
  int key;
  struct EmployeeRecord employee;
};

// Function to initialize the hash table with empty memory locations
void initializeHashTable(struct MemoryLocation hashTable[], int m)
{
  for (int i = 0; i < m; i++)
  {
    hashTable[i].key = -1; // Empty memory location
  }
}

// Function to perform linear probing and insert an employee record into the hash table
void insertEmployee(struct MemoryLocation hashTable[], int m, struct EmployeeRecord employee)
{
  int key = employee.key;
  int index = key % m; // Initial index using the hash function

  // Linear probing to resolve collisions
  while (hashTable[index].key != -1)
  {
    index = (index + 1) % m; // Move to the next location
  }

  // Insert the employee record at the empty memory location
  hashTable[index].key = key;
  hashTable[index].employee = employee;
}

// Function to display the contents of the hash table
void displayHashTable(struct MemoryLocation hashTable[], int m)
{
  printf("\nHash Table Contents:\n");
  for (int i = 0; i < m; i++)
  {
    if (hashTable[i].key != -1)
    {
      printf("Location %d: Key: %d\n", i, hashTable[i].key);
      // You can print other employee record fields here
    }
  }
}

int main()
{
  int m; // Number of memory locations in the hash table
  int n; // Number of employee records
  struct EmployeeRecord employeeRecords[MAX_KEYS];
  struct MemoryLocation hashTable[MAX_MEMORY_LOCATIONS];

  printf("Enter the number of memory locations (m) in the hash table: ");
  scanf("%d", &m);
  printf("Enter the number of employee records (n): ");
  scanf("%d", &n);

  if (m <= 0 || n <= 0)
  {
    printf("Invalid input. Please enter valid values for m and n.\n");
    return 1;
  }

  initializeHashTable(hashTable, m);

  printf("Enter the %d employee records (each record includes a 4-digit key):\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &employeeRecords[i].key);
    // You can add code to input other fields of the employee record here
    insertEmployee(hashTable, m, employeeRecords[i]);
  }

  displayHashTable(hashTable, m);

  return 0;
}
