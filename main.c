#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pol.h"

int main()
{

    setlocale (LC_CTYPE, "Russian");
    char *str, **sep_str;
    size_t len;
    double r;

    printf("������� ������: ");
    str = input();

    sep_str = sep(str, " ", &len);

    r = pol(sep_str, len);

    if (r == r) printf("���������: %lg", r);




    return 0;
}
