#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DAYS 3
struct activity
{
  char *nday;
  int dday;
  char *desc;
};
typedef struct activity Plan;
Plan *create();
void read(Plan *);
void display(Plan *);

int main()
{
  Plan *cal = NULL;
  cal = create();
  read(cal);
  display(cal);
  return 0;
}

Plan *create()
{
  Plan *t = (Plan *)malloc(sizeof(Plan) * 7);
  if (t == NULL)
  {
    printf("Memoer not ");
    exit(0);
  }
  return t;
}

void read(Plan *p)
{
  int i;
  for (int i = 0; i < DAYS; i++)
  {
    p[i].nday = (char *)malloc(9);
    printf("Ented day");
    scanf("%s", p[i].nday);
    printf("Enter date");
    scanf("%d", &p[i].dday);
    p[i].desc = (char *)malloc(400);
    printf("Enter desc");
    scanf("%s", p[i].desc);
    p[i].desc = (char *)realloc(p[i].desc, strlen(p[i].desc) + 1);
  }
}

void display(Plan *p)
{
  printf("Entered Activity Plan");
  for (int i = 0; i < DAYS; i++)
  {
    printf("%s\t", p[i].nday);
    printf("%d\t", p[i].dday);
    printf("%s\n", p[i].desc);
  }
}
