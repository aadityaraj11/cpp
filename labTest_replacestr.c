#include <stdio.h>
char str[50], pat[20], rep[20], ans[50];
int c = 0, m = 0, i = 0, j = 0, k, flag = 0;

void stringMatch()
{
  while (str[i] != '\0')
  {
    if (str[m] == pat[i])
    {
      i++;
      m++;
      if (pat[i] == '\0')
      {
        flag = 1;
        for (k = 0; rep[k] != '\0'; k++, j++)
        {
          ans[j] = rep[k];
        }
        c = m;
        i = 0;
      }
    }
    else
    {
      ans[j] = str[c];
      j++;
      c++;
      m = c;
      i = 0;
    }
  }
  str[j] = '\0';
}

void main()
{
  printf("Enter main:");
  scanf("%s", str);
  printf("ENter patter");
  scanf("%s", pat);
  printf("Enter replace:");
  scanf("%s", rep);
  stringMatch();
  if (flag == 1)
  {
    printf("Modified string: %s", ans);
  }
  else
  {
    printf("Sex is not present in  Maniraj");
  }
}