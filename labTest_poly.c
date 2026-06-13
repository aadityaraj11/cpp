#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a term in the polynomial
struct term
{
  int coef, xexp, yexp, zexp;
  struct term *link;
};

typedef struct term tm;

// Function prototypes
void create(tm *);
void display(tm *);
void evaluate(tm *);
void add(tm *, tm *, tm *);
void delete_list(tm *);

int main()
{
  tm p1 = {.link = &p1}, p2 = {.link = &p2}, p3 = {.link = &p3}; // initialize circular linked lists
  int ch;

  while (1)
  {
    printf("1. Evaluate\n2. Polynomial addition\n3. Exit\n");
    printf("Choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      if (p1.link == &p1)
        create(&p1); // create polynomial only if empty
      printf("Terms in polynomial are...\n");
      display(&p1);
      evaluate(&p1);
      break;

    case 2:
      if (p1.link == &p1)
        create(&p1);
      if (p2.link == &p2)
        create(&p2);

      printf("Terms in poly1 are...\n");
      display(&p1);
      printf("Terms in poly2 are...\n");
      display(&p2);

      add(&p1, &p2, &p3); // Perform addition
      printf("Resultant polynomial...\n");
      display(&p3);
      break;

    case 3:
      delete_list(&p1);
      delete_list(&p2);
      delete_list(&p3); // Free the allocated memory
      return 0;

    default:
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}

// Function to compare terms in two polynomials
int compare(tm *p, tm *q)
{
  return (p->xexp == q->xexp && p->yexp == q->yexp && p->zexp == q->zexp);
}

// Function to attach a term to the polynomial
void attach(int s, tm *p, tm *r)
{
  tm *t = (tm *)malloc(sizeof(tm));
  t->coef = (s != 0) ? s : p->coef;
  t->xexp = p->xexp;
  t->yexp = p->yexp;
  t->zexp = p->zexp;
  t->link = r->link;
  r->link = t;
}

// Function to delete the linked list after use
void delete_list(tm *p)
{
  tm *current = p->link;
  tm *next_node;
  while (current != p)
  {
    next_node = current->link;
    free(current);
    current = next_node;
  }
}

// Function to add two polynomials
void add(tm *p, tm *q, tm *r)
{
  int val;
  tm *tp = p->link, *tq = q->link, *tr = r;

  while (tp != p || tq != q)
  {
    if (tp == p)
    {
      // Attach remaining terms from polynomial q
      attach(0, tq, r);
      tq = tq->link;
    }
    else if (tq == q)
    {
      // Attach remaining terms from polynomial p
      attach(tp->coef, tp, r);
      tp = tp->link;
    }
    else
    {
      val = compare(tp, tq);
      if (val)
      {
        // If terms are equal, combine them
        val = tp->coef + tq->coef;
        if (val != 0)
        {
          attach(val, tp, r);
        }
        tp = tp->link;
        tq = tq->link;
      }
      else if (tp->xexp > tq->xexp)
      {
        attach(tp->coef, tp, r);
        tp = tp->link;
      }
      else
      {
        attach(tq->coef, tq, r);
        tq = tq->link;
      }
    }
  }
}

// Function to evaluate the polynomial at given values of x, y, and z
void evaluate(tm *p)
{
  int x, y, z, res = 0;
  tm *t;

  printf("Enter value of x, y, and z: ");
  scanf("%d%d%d", &x, &y, &z);

  for (t = p->link; t != p; t = t->link)
  {
    res += t->coef * pow(x, t->xexp) * pow(y, t->yexp) * pow(z, t->zexp);
  }

  printf("Evaluation of polynomial: %d\n", res);
}

// Function to display the polynomial
void display(tm *p)
{
  tm *t;
  if (p->link == p)
  {
    printf("Polynomial is empty.\n");
    return;
  }

  for (t = p->link; t != p; t = t->link)
  {
    printf("(%dx^%dy^%dz^%d) ", t->coef, t->xexp, t->yexp, t->zexp);
    if (t->link != p)
      printf(" + ");
  }
  printf("\n");
}

// Function to create the polynomial by adding terms to the linked list
void create(tm *p)
{
  int n, i;
  tm *t;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    t = (tm *)malloc(sizeof(tm));
    printf("Enter coef, xexp, yexp, zexp for term %d: ", i + 1);
    scanf("%d%d%d%d", &t->coef, &t->xexp, &t->yexp, &t->zexp);

    t->link = p->link;
    p->link = t;
  }
}
