#include <stdlib.h>
#include <CS101/stack.h>
#include <CS101/util.h>

CS101_stack *stack_new(int size)
{
	CS101_stack *stack = malloc(sizeof(CS101_stack));
	if (stack && size > 0) {
		stack->arr = malloc(size * sizeof(int));
		stack->top = stack->arr - 1;
		stack->size = size;
		return stack;
	}
	free(stack);
	return 0;
}

int stack_empty(CS101_stack *stack)
{
	return stack->top == stack-> arr - 1;
}

int stack_full(CS101_stack *stack)
{
	return stack->top == stack->arr + stack->size - 1;
}

void stack_push(CS101_stack *stack, int data)
{
	stack->top++;
	*stack->top = data;
}

int stack_pop(CS101_stack *stack)
{
	stack->top--;
	return *(stack->top + 1);
}

void stack_free(CS101_stack *stack)
{
	free(stack->arr);
	free(stack);
}

void stack_print(CS101_stack *stack)
{
	print_array(stack->arr, stack->top + 1);
}
