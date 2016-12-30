#include <stdio.h>

int main()
{
    int c, before_c;

    before_c = 0;

    while ((c = getchar()) != EOF) {
        if (before_c != ' ' || c != ' ')
            putchar(c);
        before_c = c;
    }
}
