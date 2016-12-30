#include <stdio.h>

int expand(char *str, const char *tmpl);

static int validate_tmpl(const char *tmpl);

int main(int argc, char **argv)
{
    char buf[256];

    if (argc < 2) {
        fprintf(stderr, "Error, to few arguments\n");
        return 1;
    }

    if (expand(buf, argv[1]) == -1) {
        fprintf(stderr, "Error on expand function\n");
        return 1;
    }

    printf("%s\n", buf);

    return 0;
}

int expand(char *str, const char *tmpl)
{
    char start, end;
    int i, len, is_start;

    if (!validate_tmpl(tmpl))
        return -1;

    len = i = 0;
    is_start = 0;
    while (tmpl[i]) {
        if (!is_start && tmpl[i] == '-') {
            str[len++] = tmpl[i];
        } else if ( tmpl[i] == '-') {
            if (tmpl[i+1] == '-' || tmpl[i+1] == '\0' || tmpl[i-1] == '-') 
                str[len++] = tmpl[i];
            else
                for (start = (tmpl[i-1] + 1), end = tmpl[i+1];
                       start < end; start++)
                    str[len++] = start;
        } else {
            str[len++] = tmpl[i];
        }
        is_start = 1;
        i++;
    }
    str[len] = '\0';

    return 0;
}

static int validate_tmpl(const char *tmpl)
{
    int i, j, first_char;

    first_char = 0;
    i = 0;
    while (tmpl[i]) {
        if (tmpl[i] == '-' && !first_char) {
            i++;
            continue;
        } else if (tmpl[i] == '-') {
            if (tmpl[i+1] == '-') {
                j = i + 1;
                while (tmpl[j])
                    if (tmpl[j++] != '-')
                        return 0;
            } else if (tmpl[i+1] != '\0' && tmpl[i-1] >= tmpl[i+1])
                return 0;
        }
        first_char = 1;
        i++;
    }
    return 1;
}
