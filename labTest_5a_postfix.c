#include <stdio.h>
#include <ctype.h>

int compute(int op1, int op2, char c)
{
  int res;
  switch (c)
  {
  case '+':
    res = op1 + op2;
    break;

  case '-':
    res = op1 - op2;
    break;
  case '*':
    res = op1 * op2;
    break;
  case '/':
    res = op1 / op2;
    break;
  default:
    return -1;
  }
  return res;
}
int main()
{
  char expression[50], symbol, a;
  int i = 0;
  int stack[50];
  int top = -1;
  int op1, op2, res;

  printf("Enter postfix");
  scanf("%s", expression);

  printf("evaluation:\n");

  while (expression[i] != '\0')
  {
    symbol = expression[i];
    if (isdigit(symbol))
    {
      stack[++top] = symbol - '0';
    }

    else
    {
      op2 = stack[top--];
      op1 = stack[top--];
      res = compute(op1, op2, symbol);
      stack[++top] = res;
    }
    i++;
  }
  int final = stack[top--];
  printf("Answer is: %d", final);
}