#ifndef QUEUE_H
#define QUEUE_H

typedef struct CS101_queue {
	int *arr;
	int head;
	int tail;
	int size;
} CS101_queue;

CS101_queue *queue_new(int size);
int queue_empty(CS101_queue *queue);
int queue_full(CS101_queue *queue);
void queue_enqueue(CS101_queue *queue, int data);
int queue_dequeue(CS101_queue *queue);
void queue_free(CS101_queue *queue);
void queue_print(CS101_queue *queue);

#endif // !QUEUE_H
