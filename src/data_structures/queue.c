#include <stdlib.h>
#include <stdio.h>
#include <CS101/queue.h>

struct queue *queue_new(int size)
{
	struct queue *queue = malloc(sizeof(struct queue));
	size++;
	if (queue) {
		queue->arr = malloc(size * sizeof(int));
		queue->head = 0;
		queue->tail = 0;
		queue->size = size;
	}
	return queue;
}

int queue_empty(struct queue *queue)
{
	return queue->head == queue->tail;
}

int queue_full(struct queue *queue)
{
	return (queue->head == (queue->tail + 1) % queue->size);
}

void queue_enqueue(struct queue *queue, int data)
{
	queue->arr[queue->tail] = data;
	queue->tail = (queue->tail + 1) % queue->size;
	if (queue->tail == queue->head) // overwrite if full
		queue->head++;
}

int queue_dequeue(struct queue *queue)
{
	int data = queue->arr[queue->head];
	queue->head = (queue->head + 1) % queue->size;
	return data;
}

void queue_free(struct queue *queue)
{
	free(queue->arr);
	free(queue);
}

void queue_print(struct queue *queue)
{
	int i = queue->head;
	printf("[");
	if (!queue_empty(queue)) {
		printf("%d", queue->arr[i]);
		for (i++; i != queue->tail; i = (i + 1) % queue->size)
			printf(", %d", queue->arr[i]);
	}
	printf("]\n");
}
