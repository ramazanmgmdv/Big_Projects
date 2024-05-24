#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct node
{
    double data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

stack * stack_alloc ();

double * stack_get_front (const stack *s);

int stack_push (stack *s, double e);

int stack_pop  (stack *s, double *e);

void stack_free (stack *s);

#endif // STACK_H_INCLUDED
