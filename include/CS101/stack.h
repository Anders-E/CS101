#ifndef STACK_H
#define STACK_H

struct CS101_stack {
	int *arr;
	int *top;
	int size;
};

struct CS101_stack *stack_new(int size);
int stack_empty(struct CS101_stack *stack);
int stack_full(struct CS101_stack *stack);
void stack_push(struct CS101_stack *stack, int data);
int stack_pop(struct CS101_stack *stack);
void stack_free(struct CS101_stack *stack);
void stack_print(struct CS101_stack *stack);

#endif // !STACK_H
