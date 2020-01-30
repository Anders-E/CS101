#include <stdio.h>
#include <stdlib.h>

#include <CS101/stack.h>

int main()
{
	struct stack *stack = stack_new(1);
	printf("%d\n", stack_empty(stack));
	stack_push(stack, 99);
	printf("%d\n", stack_full(stack));
}
