#include <stdio.h>

#define MAXLINE 1000

void reverse_line(char line[]);
int mygetline(char line[], int linemaxsize);
int mystrlen(char str[]);

int main()
{
    char line[MAXLINE];

    mygetline(line, MAXLINE);
    reverse_line(line);

    printf("%s\n", line);

    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && 
            (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

void reverse_line(char s[])
{
    int i, j;
    char tmp;

    i = 0;
    j = mystrlen(s) - 1;

    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        ++i;
        --j;
    }
}

int mystrlen(char str[])
{
    int len;

    len = 0;
    while (str[len])
        ++len;
    return len;
}
