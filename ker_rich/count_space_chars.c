#include <stdio.h>

int main()
{
    int c, spaces, tabs, nl;

    spaces = tabs = nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++spaces;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++nl;
    }
    printf("Spaces: %d; Tabs: %d; NewLines: %d\n", spaces, tabs, nl);
}
