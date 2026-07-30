#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int abc[26] = {0};
    int count = 0;
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        count++;
        argv[1][i] = toupper(argv[1][i]);
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        abc[argv[1][i] - 65] += 1;
        if (abc[argv[1][i] - 65] > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    if (count != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string plain = get_string("plaintext:  ");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            int a = plain[i] -= 65;
            plain[i] = toupper(argv[1][a]);
        }
        else if (islower(plain[i]))
        {
            int b = plain[i] -= 97;
            plain[i] = tolower(argv[1][b]);
        }
        else
        {
            continue;
        }
    }
    printf("ciphertext: %s\n", plain);
}
