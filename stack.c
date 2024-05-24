#include "stack.h"
#include <stdlib.h>

int stack_pop (stack *s, double *e)
{
    node *t = s->top;
    if (!s->top) return 1;
    *e = t->data;
    s->top = t->next;
    free(t);
    return 0;
}

int stack_push (stack *s, double e)
{
    node *n = malloc (sizeof(*n));
    if (!n) return 1;
    n->data = e;
    n->next = s->top;
    s->top = n;
    return 0;
}

stack * stack_alloc ()
{
    stack *s = malloc(sizeof (*s));
    if (!s) return NULL;
    s->top = NULL;
    return s;
}

double * stack_get_front (const stack *s)
{
    return s->top == NULL ? NULL : &(s->top->data);
}

void stack_free (stack *s)
{
    node *t = s->top;
    while (t != NULL)
    {
        s->top = t->next;
        free(t);
        t = s->top;
    }
}
