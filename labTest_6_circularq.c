#include <stdio.h>
#define MAX 3

int cnt = 0;
int q[MAX];
int rear = -1;
int front = 0;

void push(int item)
{
  if (cnt == MAX)
  {
    printf("Queue full\n");
    return;
  }
  rear = (rear + 1) % MAX;
  q[rear] = item;
  cnt++;
}

void pop()
{
  if (cnt == 0)
  {
    printf("Queue empty\n");
    return;
  }
  int item = q[front];
  front = (front + 1) % MAX;
  cnt--;
  printf("Item deleted %d\n", item);
}

void display()
{
  if (cnt == 0)
  {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue content:\n");
  for (int i = 0, j = front; i < cnt; i++)
  {
    printf("%d\n", q[j]);
    j = (j + 1) % MAX;
  }
}

int main()
{
  push(10);
  push(20);
  push(30);
  display();
  pop();
  display();
  push(40);
  display();
  pop();
  display();
  return 0;
}
