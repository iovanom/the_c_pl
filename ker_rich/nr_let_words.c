#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_COUNT 20

int main()
{
    int i, j, c, state, count;
    int c_let[MAX_COUNT];

    for (i = 0; i < MAX_COUNT; i++)
        c_let[i] = 0;

    state = OUT;
    count = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if(state == IN) {
                ++c_let[count - 1];
                count = 0;
            }
            state = OUT;
        } else {
            state = IN;
            ++count;
        }
    }
    for (i = 0; i < MAX_COUNT; i++) {
        printf("%d -> ", i + 1);
        for (j = c_let[i]; j > 0; j--)
            printf("*");
        printf("\n");
    }
}
