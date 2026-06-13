#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

struct Stack
{
  char data[100];
  int top;
};

void initialize(struct Stack *stack)
{
  stack->top = -1;
}

void push(struct Stack *stack, char item)
{
  if (stack->top == MAX - 1)
  {
    printf("stack full");
    return;
  }
  else
  {
    stack->data[++stack->top] = item;
  }
}

char pop(struct Stack *stack)
{
  if (stack->top == -1)
  {
    return '\0';
  }
  return stack->data[stack->top--];
}

int priority(char c)
{
  if (c == '(')
    return 1;
  if (c == '+' || c == '-')
    return 2;
  if (c == '*' || c == '/')
    return 3;
  if (c == '^' || c == '$')
    return 4;
  return 1;
}

void main()
{
  char expression[100], symbol, a;
  struct Stack stack;
  initialize(&stack);
  int i = 0;
  printf("Enter infix \n");
  scanf("%s", expression);
  printf("postfix:\n");
  for (i = 0; i < strlen(expression); i++)
  {
    symbol = expression[i];
    if (isalnum(symbol))
    {
      printf("%c", symbol);
    }
    else if (symbol == '(')
    {
      push(&stack, symbol);
    }
    else if (symbol == ')')
    {
      while (a = pop(&stack) != '(')
      {
        printf("%c", a);
      }
    }
    else
    {
      while (priority(stack.data[stack.top]) >= priority(symbol))
      {
        printf("%c", pop(&stack));
      }
      push(&stack, symbol);
    }
  }

  while (stack.top != -1)
  {
    printf("%c", pop(&stack));
  }
  return;
}