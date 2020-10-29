#include <gtest/gtest.h>
extern "C" {
	#include <CS101/queue.h>
}

TEST(Queue, NewSuccess)
{
	CS101_queue *queue = queue_new(10);
	ASSERT_NE(queue, nullptr);
	queue_free(queue);
}

TEST(Queue, NewFailure)
{
	CS101_queue *queue = queue_new(0);
	ASSERT_FALSE(queue);
}

TEST(Queue, EnqueueDequeue)
{
	CS101_queue *queue = queue_new(2);
	queue_enqueue(queue, 1);
	queue_enqueue(queue, 2);
	queue_enqueue(queue, 3);
	EXPECT_EQ(queue_dequeue(queue), 2);
	EXPECT_EQ(queue_dequeue(queue), 3);
}

TEST(Queue, Empty)
{
	CS101_queue *queue = queue_new(10);
	EXPECT_TRUE(queue_empty(queue));
	queue_enqueue(queue, 1);
	EXPECT_FALSE(queue_empty(queue));
	queue_dequeue(queue);
	EXPECT_TRUE(queue_empty(queue));
	queue_free(queue);
}

TEST(Queue, Full)
{
	CS101_queue *queue = queue_new(1);
	EXPECT_FALSE(queue_full(queue));
	queue_enqueue(queue, 1);
	EXPECT_TRUE(queue_full(queue));
	queue_enqueue(queue, 2);
	EXPECT_TRUE(queue_full(queue));
	queue_dequeue(queue);
	EXPECT_FALSE(queue_full(queue));
	queue_free(queue);
}
