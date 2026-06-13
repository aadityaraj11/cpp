#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 5
struct Stack
{
  int data[Max];
  int top;
};

void initialize(struct Stack *stack)
{
  stack->top = -1;
}

void push(struct Stack *stack, int item)
{
  if (stack->top == Max - 1)
  {
    printf("Stack is full");
    return;
  }
  else
  {
    stack->data[++stack->top] = item;
    printf("Pushed %d to stack", item);
  }
}

int pop(struct Stack *stack)
{
  if (stack->top == -1)
  {
    printf("Stack is empty");
    return -1;
  }
  else
  {
    int item = stack->data[stack->top--];
    return item;
  }
}

void display(struct Stack *stack)
{
  if (stack->top == -1)
  {
    printf("Stack is empty");
    return;
  }
  else
  {
    printf("stack content \n");
    for (int i = stack->top; i >= 0; i--)
    {
      printf("%d", stack->data[i]);
    }
  }
}

bool isPallindrome(struct Stack *stack)
{
  for (int i = 0; i <= stack->top / 2; i++)
  {
    if (stack->data[i] != stack->data[stack->top - i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  struct Stack stack;
  int choice;
  int item, res;
  bool ans;
  initialize(&stack);
  while (1)
  {
    printf("1.push\n2.pop\n3.display\n4.pallindrome check\n5.exit");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter item");
      scanf("%d", &item);
      push(&stack, item);
      break;

    case 2:
      res = pop(&stack);
      printf("item %d deleted", res);
      break;

    case 3:
      display(&stack);
      break;

    case 4:
      ans = isPallindrome(&stack);
      if (ans)
      {
        printf("pallindrome");
      }
      else
      {
        printf("not a pallindrome");
      }
      break;

    case 5:
      exit(0);

    default:
      printf("invalid");
    }
  }
  return 0;
}