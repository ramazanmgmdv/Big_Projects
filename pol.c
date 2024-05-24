#include "pol.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char * input()
{
    char in, *str, *p, *s;
    size_t z;

    if (!(str = malloc (10))) return NULL;

    s = str;

    do
    {
        scanf("%c", &in);
        *s = in;

        ++s;

        if (!((z = s - str) % 10))
        {
            if(!(p = realloc (str, z + 10)))
            {
                free (str);
                return NULL;
            }
            str = p;
            s = str + z;
        }
    }
    while (in != '\n');

    *(s - 1) = '\0';

    return str;
}

char ** sep (char *str, char *sep, size_t *len)
{
    char **sep_str, **u, *t;
    size_t i = 1;

    if (!(sep_str = malloc(sizeof(char*)))) return NULL;

    *sep_str = strtok(str, sep);

    while ((t = strtok(NULL, sep)))
    {
        if (!(u = realloc(sep_str, (i + 1) * sizeof(char*))))
        {
            free(sep_str);
            return NULL;
        }
        sep_str = u;

        *(sep_str + i) = t;
        ++i;
    }

    *len = i;

    return sep_str;
}

double f (double x, char **str, size_t len, char ***x_places)
{
    char *x_str = malloc(30);
    double r;
    if (!x_str) exit(-1);
    sprintf(x_str, "%lf", x);

    for (char ***i = x_places; *i; ++i) **i = x_str;

    r = pol(str, len);

    free (x_str);

    if (r == r) return r;
    return 0/0.;
}

double quad_middle_rec (double a, double b, size_t n, char **str, size_t len, char ***x_places)
{
    double h=(b-a)/n, sum = 0;
    a += (h/2);

    for (size_t i=0; i<n; ++i)
    {
        sum += f(a+(h*i), str, len, x_places);
        if (sum != sum) return 0/0.;
    }
    return (h*sum);
}

double iter_formula (double a, double b, double eps, char **str, size_t len, char ***x_places)
{
    size_t n = 10;

    double r2 = quad_middle_rec(a, b, n, str, len, x_places), r1;

    do
    {
        if (r2 != r2) return 0/0.;
        r1 = r2;
        n *= 2;
        r2 = quad_middle_rec(a, b, n, str, len, x_places);
    }
    while (fabs(r2-r1) > eps);

    return r2;
}

char ** integral (char **p, double *r, char **str_end)
{
    double a, b, eps;
    char ***x_places = malloc(sizeof(char**)), ***x_places_end = x_places, **beg = p, **p2, **end;

    if (!x_places) return NULL;

    do
    {
        if (!strcmp(*p, "x"))
        {

            *x_places_end = p;
            ++x_places_end;

            size_t x_places_len = x_places_end - x_places + 1;
            char ***temp_x_places = realloc(x_places, (x_places_len + 1) * sizeof(char**));
            if (!temp_x_places)
            {
                free (x_places);
                return NULL;
            }
            x_places = temp_x_places;
            x_places_end = x_places + x_places_len - 1;
        }

        ++p;

        if (!strcmp(*p, "(")) break;




    } while (strcmp(*p, "dx") && p < str_end);

    *x_places_end = NULL;

    if (!(*x_places))
    {
        printf ("Ошибка: отсутствует 'x'\n");
        return NULL;
    }

    if (!strcmp(*p, "("))
        {
            p2 = end = p;

            do
            {
                ++p2;
                if (p2 >= str_end)
                {
                    printf ("Ошибка: отсутствует ')'\n");
                    return NULL;
                }

            } while (strcmp(*p2, ")"));

            if ((p2 + 2) >= str_end)
            {
                printf("Ошибка: отсутствует точность - '%s'\n", *p);
                return NULL;
            }

            if (!strcmp(*(p2 + 2), "dx"))
            {
                b = pol(p + 1, p2 - p - 1);

                --end;
                if (!sscanf(*end, "%lf", &a))
                {
                    printf("Ошибка в '%s'\n", *end);
                    return NULL;
                };
                p = p2;
            }
            else
            {
                a = pol(p + 1, p2 - p - 1);
                p = p2 + 1;
                if (!strcmp(*p, "("))
                {
                    do
                    {
                        ++p2;
                        if (p2 >= str_end)
                        {
                            printf ("Ошибка: отсутствует ')'\n");
                            return NULL;
                        }
                    } while (strcmp(*p2, ")"));

                    if ((p2 + 2) >= str_end)
                    {
                        printf ("Ошибка: отсутствует точность или 'dx'\n");
                        return NULL;
                    }

                    if (!strcmp(*(p2 + 2), "dx")) b = pol(p + 1, p2 - p - 1);
                    else
                    {
                        printf("Ошибка в 'dx' - '%s'\n", *p);
                        return NULL;
                    }
                    p = p2;
                }
                else if(!sscanf(*p, "%lf", &b))
                {
                    printf("Ошибка в '%s'\n", *p);
                    return NULL;
                }
            }
            ++p;
            if (!sscanf(*p, "%lf", &eps))
            {
                printf("Ошибка в '%s'\n", *p);
                return NULL;
            }
        }
    else
    {
        if (strcmp(*p, "dx"))
        {
            printf ("Ошибка: отсутствует 'dx'\n");
            return NULL;
        }
        if (!sscanf(*(p - 1), "%lf", &eps))
        {
            printf("Ошибка: отсутствует точность или предел интегрирования - '%s'\n", *(p - 3));
            return NULL;
        }
        if (!sscanf(*(p - 2), "%lf", &b))
        {
            printf("Ошибка: отсутствует точность или предел интегрирования - '%s'\n", *(p - 2));
            return NULL;
        }
        if (!sscanf(*(p - 3), "%lf", &a))
        {
            printf("Ошибка: отсутствует точность или предел интегрирования - '%s'\n", *(p - 3));
            return NULL;
        }
        end = p - 3;

        *r = iter_formula(a, b, eps, beg, end - beg, x_places);

        free (x_places);

        return p;
    }

    *r = iter_formula(a, b, eps, beg, end - beg, x_places);

    free (x_places);

    if (*r != *r) return NULL;

    return p + 1;
}


double pol (char **str, size_t len)
{
    double result;
    stack *s = stack_alloc();
    if (!s)
    {
        printf("Ошибка выделения памяти\n");
        return 0/0.;
    }

    for (char **p = str, **e = str + len; p < e; ++p)
    {
        double *e2, e1;

        if (!strcmp(*p, "I"))
        {
            if (!(p = integral(p + 1, &e1, e))) return 0/0.;
            stack_push(s, e1);
        }

        else
        {

            if ((**p >= '0' && **p <= '9') || (**p == '-' && *(*p + 1)))
            {
                if (!(sscanf(*p, "%lf", &e1)))
                {
                    printf("Ошибка в '%s' на %lu месте\n", *p, (long unsigned int)(p - str + 1));
                    stack_free(s);
                    return 0/0.;
                }
                stack_push(s, e1);
            }
            else if (!strcmp(*p, "pi")) stack_push(s, M_PI);
            else if (!strcmp(*p, "e")) stack_push(s, M_E);


            else
            {
                if (!(e2 = stack_get_front(s)))
                {
                    printf("Ошибка в '%s' на %lu месте\n", *p, (long unsigned int)(p - str + 1));
                    stack_free(s);
                    return 0/0.;
                }

                if      (!strcmp(*p, "sqrt"))   *e2 = sqrt(*e2);
                else if (!strcmp(*p, "sin"))    *e2 = sin(*e2);
                else if (!strcmp(*p, "sh"))     *e2 = sinh(*e2);
                else if (!strcmp(*p, "cos"))    *e2 = cos(*e2);
                else if (!strcmp(*p, "ch"))     *e2 = cosh(*e2);
                else if (!strcmp(*p, "tg"))     *e2 = tan(*e2);
                else if (!strcmp(*p, "th"))     *e2 = tanh(*e2);
                else if (!strcmp(*p, "arcsin")) *e2 = asin(*e2);
                else if (!strcmp(*p, "arccos")) *e2 = acos(*e2);
                else if (!strcmp(*p, "arctg"))  *e2 = atan(*e2);
                else if (!strcmp(*p, "ln"))     *e2 = log(*e2);
                else if (!strcmp(*p, "lg"))     *e2 = log10(*e2);
                else if (!strcmp(*p, "exp"))    *e2 = exp(*e2);
                else
                {
                    if (stack_pop(s, &e1))
                    {
                        printf("Ошибка в '%s' на %lu месте\n", *p, (long unsigned int) (p - str + 1));
                        stack_free(s);
                        return 0/0.;
                    }
                    if (!(e2 = stack_get_front(s)))
                    {
                        printf("Ошибка в '%s' на %lu месте\n", *p, (long unsigned int) (p - str + 1));
                        stack_free(s);
                        return 0/0.;
                    }

                    if      (!strcmp(*p, "*")) *e2 *= e1;
                    else if (!strcmp(*p, "+")) *e2 += e1;
                    else if (!strcmp(*p, "-")) *e2 -= e1;
                    else if (!strcmp(*p, "/")) *e2 /= e1;
                    else if (!strcmp(*p, "^")) *e2 = pow(*e2, e1);
                    else
                    {
                        printf("Ошибка в '%s' на %lu месте\n", *p, (long unsigned int) (p - str + 1));
                        stack_free(s);
                        return 0/0.;
                    }
                }
            }
        }
    }

    if (s->top->next)
    {
        printf ("Ошибка: не хватает операций или введено слишком много чисел\n");
        stack_free(s);
        return 0/0.;
    }

    result = s->top->data;
    stack_free(s);

    return result;
}


