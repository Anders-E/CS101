#include <stdlib.h>
#include <stdio.h>
#include <CS101/queue.h>

CS101_queue *queue_new(int size)
{
	CS101_queue *queue = malloc(sizeof(CS101_queue));
	if (queue && size > 0) {
		queue->arr = malloc((size + 1) * sizeof(int));
		queue->head = 0;
		queue->tail = 0;
		queue->size = size;
		return queue;
	}
	free(queue);
	return 0;
}

int queue_empty(CS101_queue *queue)
{
	return queue->head == queue->tail;
}

int queue_full(CS101_queue *queue)
{
	return (queue->head == (queue->tail + 1) % (queue->size + 1));
}

void queue_enqueue(CS101_queue *queue, int data)
{
	queue->arr[queue->tail] = data;
	queue->tail = (queue->tail + 1) % (queue->size + 1);
	if (queue->tail == queue->head) // overwrite if full
		queue->head++;
}

int queue_dequeue(CS101_queue *queue)
{
	int data = queue->arr[queue->head];
	queue->head = (queue->head + 1) % (queue->size + 1);
	return data;
}

void queue_free(CS101_queue *queue)
{
	free(queue->arr);
	free(queue);
}

void queue_print(CS101_queue *queue)
{
	int i = queue->head;
	printf("[");
	if (!queue_empty(queue)) {
		printf("%d", queue->arr[i]);
		for (i++; i != queue->tail; i = (i + 1) % (queue->size + 1))
			printf(", %d", queue->arr[i]);
	}
	printf("]\n");
}
