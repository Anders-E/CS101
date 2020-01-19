#include <stdio.h>
#include <stdlib.h>

#include <CS101/sorting.h>
#include <CS101/linked_list.h>
#include <CS101/heap.h>
#include <CS101/util.h>
#include <CS101/stack.h>

int main()
{
	struct stack *stack = stack_new(100);
	stack_push(stack, 1);
	stack_print(stack);
	stack_push(stack, 2);
	stack_print(stack);
	stack_push(stack, 3);
	stack_print(stack);
	printf("%d\n", stack_pop(stack));
	stack_print(stack);
	printf("%d\n", stack_pop(stack));
	stack_print(stack);
	printf("%d\n", stack_pop(stack));
	stack_print(stack);
}
