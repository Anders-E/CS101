#ifndef STACK_H
#define STACK_H

typedef struct CS101_stack {
	int *arr;
	int *top;
	int size;
} CS101_stack;

CS101_stack *stack_new(int size);
int stack_empty(CS101_stack *stack);
int stack_full(CS101_stack *stack);
void stack_push(CS101_stack *stack, int data);
int stack_pop(CS101_stack *stack);
void stack_free(CS101_stack *stack);
void stack_print(CS101_stack *stack);

#endif // !STACK_H
