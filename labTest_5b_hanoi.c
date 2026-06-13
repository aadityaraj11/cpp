#include <stdio.h>

void hanoi(int n, char s, char t, char d)
{
  if (n == 0)
  {
    return;
  }

  hanoi(n - 1, s, d, t);
  printf("moved %d from %c to %c\n", n, s, d);
  hanoi(n - 1, t, s, d);
}

int main()
{
  int n;
  printf("ENter n:\n");
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  return 0;
}