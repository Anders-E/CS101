#include <stdlib.h>
#include <CS101/stack.h>
#include <CS101/util.h>

struct stack *stack_new(int size)
{
	struct stack *stack = malloc(sizeof(struct stack));
	if (stack && size > 0) {
		stack->arr = malloc(size * sizeof(int));
		stack->top = -1;
		stack->size = size;
		return stack;
	}
	return 0;
}

int stack_empty(struct stack *stack)
{
	return stack->top == -1;
}

int stack_full(struct stack *stack)
{
	return stack->top == stack->size - 1;
}

void stack_push(struct stack *stack, int data)
{
	stack->top++;
	stack->arr[stack->top] = data;
}

int stack_pop(struct stack *stack)
{
	stack->top--;
	return stack->arr[stack->top + 1];
}

void stack_free(struct stack *stack)
{
	free(stack->arr);
	free(stack);
}

void stack_print(struct stack *stack)
{
	array_print(stack->arr, stack->top + 1);
}
