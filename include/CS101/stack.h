#ifndef STACK_H
#define STACK_H

struct stack {
	int *arr;
	int top;
	int size;
};

struct stack *stack_new(int size);
int stack_empty(struct stack *stack);
int stack_full(struct stack *stack);
void stack_push(struct stack *stack, int data);
int stack_pop(struct stack *stack);
void stack_free(struct stack *stack);
void stack_print(struct stack *stack);

#endif // !STACK_H
