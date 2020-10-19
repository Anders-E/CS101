#include <gtest/gtest.h>
extern "C" {
	#include <CS101/stack.h>
}

TEST(Stack, NewSucess)
{
	struct CS101_stack *CS101_stack = stack_new(10);
	ASSERT_NE(CS101_stack, nullptr);
	stack_free(CS101_stack);
}

TEST(Stack, NewFailure)
{
	struct CS101_stack *CS101_stack = stack_new(0);
	ASSERT_FALSE(CS101_stack);
}

TEST(Stack, Empty)
{
	struct CS101_stack *CS101_stack = stack_new(2);
	ASSERT_TRUE(stack_empty(CS101_stack));
	stack_push(CS101_stack, 1);
	ASSERT_FALSE(stack_empty(CS101_stack));
	stack_push(CS101_stack, 2);
	ASSERT_FALSE(stack_empty(CS101_stack));
	stack_pop(CS101_stack);
	stack_pop(CS101_stack);
	ASSERT_TRUE(stack_empty(CS101_stack));
	stack_free(CS101_stack);
}

TEST(Stack, Full)
{
	struct CS101_stack *CS101_stack = stack_new(2);
	ASSERT_EQ(stack_full(CS101_stack), false);
	stack_push(CS101_stack, 1);
	ASSERT_EQ(stack_full(CS101_stack), false);
	stack_push(CS101_stack, 2);
	ASSERT_EQ(stack_full(CS101_stack), true);
	stack_pop(CS101_stack);
	ASSERT_EQ(stack_full(CS101_stack), false);
	stack_free(CS101_stack);
}

TEST(Stack, Push)
{
	struct CS101_stack *CS101_stack = stack_new(3);
	stack_push(CS101_stack, 1);
	stack_push(CS101_stack, 2);
	stack_push(CS101_stack, 3);
	EXPECT_EQ(CS101_stack->arr[0], 1);
	EXPECT_EQ(CS101_stack->arr[1], 2);
	EXPECT_EQ(CS101_stack->arr[2], 3);
	stack_free(CS101_stack);
}

TEST(Stack, Pop)
{
	struct CS101_stack *CS101_stack = stack_new(3);
	stack_push(CS101_stack, 1);
	stack_push(CS101_stack, 2);
	stack_push(CS101_stack, 3);
	EXPECT_EQ(stack_pop(CS101_stack), 3);
	EXPECT_EQ(stack_pop(CS101_stack), 2);
	EXPECT_EQ(stack_pop(CS101_stack), 1);
	stack_free(CS101_stack);
}
