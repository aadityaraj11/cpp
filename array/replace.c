#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char *replace(char *before, char *oldsub, char *newsub);

int main()
{
    char string[] = " Hate the sin, love the sinner";
    char *result = replace(string, "the", "abababa");

    printf("Before : %s\n", string);
    printf("After : %s\n", result);

    free(result);

    return 0;
}

char *replace(char *before, char *oldsub, char *newsub)
{
    int old_length = strlen(oldsub);
    int new_length = strlen(newsub);
    int before_length = strlen(before);
    char *after;
    if (old_length == new_length)
    {
        after = malloc((before_length + 1) * sizeof(char));
    }
    else
    {
        int occurences = 0;
        int i = 0;
        while (i < before_length)
        {
            if (strstr(&before[i],oldsub) == &before[i])
            {
                occurences++;
                i += old_length;
            }
            else
            {
                i++;
            }
        }
        int sub_diff = new_length - old_length;
        int after_length = before_length;
        after_length += occurences * sub_diff;

        after = malloc((after_length + 1) * sizeof(char));
    }

    int i=0;
    int j=0;
    while(i<strlen(before))
    {
        if (strstr(&before[i],oldsub) == &before[i])
        {
            strcpy(&after[j],newsub);
            i+=old_length;
            j+=new_length;
        }
        else
        {
            after[j]=before[i];
            i++;
            j++;
        }
    }
    after[j]='\0';

    return after;
}

