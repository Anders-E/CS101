#include <gtest/gtest.h>
extern "C" {
	#include <CS101/stack.h>
}

TEST(Stack, CreateNewSuccess)
{
    struct stack *stack = stack_new(10);
    ASSERT_NE(stack, nullptr);
}

TEST(Stack, CreateNewFailure)
{
    struct stack *stack = stack_new(0);
    ASSERT_EQ(stack, nullptr);
}

TEST(Stack, Empty)
{
    struct stack *stack = stack_new(2);
    ASSERT_EQ(stack_empty(stack), true);
    stack_push(stack, 1);
    ASSERT_EQ(stack_empty(stack), false);
    stack_push(stack, 2);
    ASSERT_EQ(stack_empty(stack), false);
    stack_pop(stack);
    stack_pop(stack);
    ASSERT_EQ(stack_empty(stack), true);
}

TEST(Stack, Full)
{
    struct stack *stack = stack_new(2);
    ASSERT_EQ(stack_full(stack), false);
    stack_push(stack, 1);
    ASSERT_EQ(stack_full(stack), false);
    stack_push(stack, 2);
    ASSERT_EQ(stack_full(stack), true);
    stack_pop(stack);
    ASSERT_EQ(stack_full(stack), false);
}

TEST(Stack, Push)
{
    struct stack *stack = stack_new(3);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    EXPECT_EQ(stack->arr[0], 1);
    EXPECT_EQ(stack->arr[1], 2);
    EXPECT_EQ(stack->arr[2], 3);
}

TEST(Stack, Pop)
{
    struct stack *stack = stack_new(3);
    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);
    EXPECT_EQ(stack_pop(stack), 3);
    EXPECT_EQ(stack_pop(stack), 2);
    EXPECT_EQ(stack_pop(stack), 1);
}
