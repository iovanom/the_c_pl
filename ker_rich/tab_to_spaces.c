#include <stdio.h>

#define SPACES_IN_TAB 4

int main()
{
    int i, c;

    while ((c = getchar()) != EOF)
        if (c == '\t')
            for (i = 0; i <= SPACES_IN_TAB; i++)
                putchar('_');
        else
            putchar(c);

    return 0;
}
