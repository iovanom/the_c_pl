#include <ctype.h>
#include <stdio.h>

double my_atof(char s[]);

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Error, to few arguments\n");
        return 1;
    }

    void my_print(char str[])
    {
        printf("%s\n", str);
    }
    my_print("test");

    printf("%lf\n", my_atof(argv[1]));

    return 0;
}

double my_atof(char s[])
{
    double val, power, result;
    int i, sign, exp_sign, exp;

    exp = 0.0;
    exp_sign = 0;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }

    result = sign * val / power;

    while (exp--)
        if(exp_sign > 0) 
            result *= 10;
        else if (exp_sign < 0)
            result /= 10;

    return result;
}
