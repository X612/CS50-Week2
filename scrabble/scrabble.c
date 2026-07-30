#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points(string x);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int main(void)
{

    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");
    int p1 = points(w1);
    int p2 = points(w2);
    if (p1 > p2)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1 < p2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int points(string x)
{
    int sumx = 0;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isalpha(x[i]))
    {
        sumx += POINTS[toupper(x[i]) - 65];
    }
    }
    return sumx;
}
