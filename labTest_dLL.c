#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
struct Employee
{
  char SSN[15];
  char Name[50];
  char Dept[50];
  char Designation[50];
  float Sal;
  char PhNo[15];
  struct Employee *prev;
  struct Employee *next;
};

// Function to create a new employee node
struct Employee *createEmployee()
{
  struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
  if (newEmployee == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  printf("Enter Employee Details:\n");
  printf("SSN: ");
  scanf(" %[^\n]", newEmployee->SSN);
  printf("Name: ");
  scanf(" %[^\n]", newEmployee->Name);
  printf("Department: ");
  scanf(" %[^\n]", newEmployee->Dept);
  printf("Designation: ");
  scanf(" %[^\n]", newEmployee->Designation);
  printf("Salary: ");
  scanf("%f", &newEmployee->Sal);
  printf("Phone Number: ");
  scanf(" %[^\n]", newEmployee->PhNo);

  newEmployee->prev = NULL;
  newEmployee->next = NULL;
  return newEmployee;
}

// Function to display an employee's details
void displayEmployee(struct Employee *employee)
{
  printf("SSN: %s\n", employee->SSN);
  printf("Name: %s\n", employee->Name);
  printf("Department: %s\n", employee->Dept);
  printf("Designation: %s\n", employee->Designation);
  printf("Salary: %.2f\n", employee->Sal);
  printf("Phone Number: %s\n", employee->PhNo);
}

// Function to create a doubly linked list of employees with end insertion
struct Employee *createDLL(struct Employee *head, int N)
{
  for (int i = 0; i < N; i++)
  {
    struct Employee *newEmployee = createEmployee();
    if (head == NULL)
    {
      head = newEmployee;
    }
    else
    {
      struct Employee *current = head;
      while (current->next != NULL)
      {
        current = current->next;
      }
      current->next = newEmployee;
      newEmployee->prev = current;
    }
    printf("Employee added to the end of the list.\n");
  }
  return head;
}

// Function to display the status of the DLL and count the number of nodes
void displayDLL(struct Employee *head)
{
  struct Employee *current = head;
  int count = 0;
  if (current == NULL)
  {
    printf("Doubly Linked List is empty.\n");
  }
  else
  {
    printf("Doubly Linked List Contents:\n");
    while (current != NULL)
    {
      displayEmployee(current);
      current = current->next;
      count++;
    }
    printf("Total number of nodes: %d\n", count);
  }
}

// Function to insert an employee at the end of the DLL
struct Employee *insertEnd(struct Employee *head)
{
  struct Employee *newEmployee = createEmployee();
  if (head == NULL)
  {
    head = newEmployee;
  }
  else
  {
    struct Employee *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newEmployee;
    newEmployee->prev = current;
  }
  printf("Employee added to the end of the list.\n");
  return head;
}

// Function to delete an employee from the front of the DLL
struct Employee *deleteFront(struct Employee *head)
{
  if (head == NULL)
  {
    printf("Doubly Linked List is empty. Nothing to delete.\n");
  }
  else
  {
    struct Employee *temp = head;
    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }
    free(temp);
    printf("Employee deleted from the front of the list.\n");
  }
  return head;
}

// Function to demonstrate how the DLL can be used as a double-ended queue
struct Employee *enqueueFront(struct Employee *head)
{
  struct Employee *newEmployee = createEmployee();
  if (head == NULL)
  {
    head = newEmployee;
  }
  else
  {
    newEmployee->next = head;
    head->prev = newEmployee;
    head = newEmployee;
  }
  printf("Employee enqueued at the front.\n");
  return head;
}

struct Employee *dequeueEnd(struct Employee *head)
{
  if (head == NULL)
  {
    printf("Doubly Linked List is empty. Nothing to dequeue.\n");
  }
  else
  {
    struct Employee *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    if (current->prev != NULL)
    {
      current->prev->next = NULL;
    }
    else
    {
      head = NULL; // If there's only one node.
    }
    free(current);
    printf("Employee dequeued from the end.\n");
  }
  return head;
}

int main()
{
  struct Employee *head = NULL;
  int choice, N;
  while (1)
  {
    printf("\nDoubly Linked List Operations Menu:\n");
    printf("1. Create DLL of N Employees Data by End Insertion\n");
    printf("2. Display DLL and Count Nodes\n");
    printf("3. Insert Employee at End\n");
    printf("4. Delete Employee from Front\n");
    printf("5. Demonstrate DLL as Double-Ended Queue\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter the number of employees (N): ");
      scanf("%d", &N);
      head = createDLL(head, N);
      break;
    case 2:
      displayDLL(head);
      break;
    case 3:
      head = insertEnd(head);
      break;
    case 4:
      head = deleteFront(head);
      break;
    case 5:
      printf("Demonstrating DLL as a Double-Ended Queue:\n");
      printf("1. Enqueue at Front\n");
      printf("2. Dequeue at End\n");
      printf("3. Exit\n");
      int subChoice;
      while (1)
      {
        printf("Enter your choice: ");
        scanf("%d", &subChoice);
        switch (subChoice)
        {
        case 1:
          head = enqueueFront(head);
          break;
        case 2:
          head = dequeueEnd(head);
          break;
        case 3:
          break;
        default:
          printf("Invalid choice.\n");
        }
        if (subChoice == 3)
          break;
      }
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n"); // Added missing invalid choice handling
    }
  }

  return 0;
}
