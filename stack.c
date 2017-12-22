#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int top;
    int size;
}stackS;

void init(stackS *stack, int size)
{
    stack->top = -1;
    stack->size = size;
    stack->array = (int*) malloc(sizeof(int) * size);

    if( stack->array == NULL)
    {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}

int pop(stackS *stack)      /*delite  the top element*/
{
    if(stack->top < 0)
        printf("stack is empty\n");
    int num =  stack->array[stack->top];
    stack->top--;
    return num;
}

void push(stackS *stack, int element)   /*push element in the top of stack*/
{
    if(stack->top >= stack->size - 1)
        printf("stack is full\n");
    stack->top++;
    stack->array[stack->top] = element;
}

int main()
{
    stackS *stack = (stackS*) malloc(sizeof(stackS));
    init(stack, 5);

    push(stack,3);
    push(stack,7);
    push(stack,8);
    push(stack,9);

    while(stack->top >= 0 )         /*output values in stack*/
        printf("%d\n",pop(stack));

    free(stack->array);
    stack->array = NULL;
    free(stack);

    return 0;
}
