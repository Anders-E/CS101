#include <gtest/gtest.h>
extern "C" {
	#include <CS101/queue.h>
}

TEST(Queue, NewSuccess)
{
	struct CS101_queue *CS101_queue = queue_new(10);
	queue_free(CS101_queue);
}

TEST(Queue, NewFailure)
{
	struct CS101_queue *CS101_queue = queue_new(0);
	ASSERT_FALSE(CS101_queue);
}

TEST(Queue, EnqueueDequeue)
{
	struct CS101_queue *CS101_queue = queue_new(2);
	queue_enqueue(CS101_queue, 1);
	queue_enqueue(CS101_queue, 2);
	queue_enqueue(CS101_queue, 3);
	EXPECT_EQ(queue_dequeue(CS101_queue), 2);
	EXPECT_EQ(queue_dequeue(CS101_queue), 3);
}

TEST(Queue, Empty)
{
	struct CS101_queue *CS101_queue = queue_new(10);
	EXPECT_TRUE(queue_empty(CS101_queue));
	queue_enqueue(CS101_queue, 1);
	EXPECT_FALSE(queue_empty(CS101_queue));
	queue_dequeue(CS101_queue);
	EXPECT_TRUE(queue_empty(CS101_queue));
	queue_free(CS101_queue);
}

TEST(Queue, Full)
{
	struct CS101_queue *CS101_queue = queue_new(1);
	EXPECT_FALSE(queue_full(CS101_queue));
	queue_enqueue(CS101_queue, 1);
	EXPECT_TRUE(queue_full(CS101_queue));
	queue_enqueue(CS101_queue, 2);
	EXPECT_TRUE(queue_full(CS101_queue));
	queue_dequeue(CS101_queue);
	EXPECT_FALSE(queue_full(CS101_queue));
	queue_free(CS101_queue);
}
