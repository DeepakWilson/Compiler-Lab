#include <stdio.h>
#include <string.h>
char states[20][20];
char closure[20][20];
char from[100][20];
char symbol[100][20];
char to[100][20];

int count, transitions;

void epsilonClosure(char state[])
{
    for (int i = 0; i < transitions; i++)
    {
        if (strcmp(from[i], state) == 0 &&
            strcmp(symbol[i], "e") == 0)
        {
            int found = 0;

            for (int j = 0; j < count; j++)
            {
                if (strcmp(closure[j], to[i]) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                strcpy(closure[count++], to[i]);
                epsilonClosure(to[i]);
            }
        }
    }
}

int main()
{
    FILE *fp = fopen("input.dat", "r");

    if (fp == NULL)
    {
        printf("Cannot open input.dat\n");
        return 1;
    }

    int n, i;
    transitions = 0;

    while (transitions < 100 &&
           fscanf(fp, "%19s %19s %19s",
                  from[transitions],
                  symbol[transitions],
                  to[transitions]) == 3)
    {
        transitions++;
    }

    fclose(fp);

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter state names:\n");
    for (i = 0; i < n; i++)
        scanf("%19s", states[i]);

    for (i = 0; i < n; i++)
    {
        count = 0;
        strcpy(closure[count++], states[i]);

        epsilonClosure(states[i]);

        printf("Epsilon closure of %s = { ", states[i]);

        for (int j = 0; j < count; j++)
            printf("%s ", closure[j]);

        printf("}\n");
    }

    return 0;
}