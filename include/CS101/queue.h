#ifndef QUEUE_H
#define QUEUE_H

struct queue {
	int *arr;
	int head;
	int tail;
	int size;
};

struct queue *queue_new(int size);
int queue_empty(struct queue *queue);
int queue_full(struct queue *queue);
void queue_enqueue(struct queue *queue, int data);
int queue_dequeue(struct queue *queue);
void queue_free(struct queue *queue);
void queue_print(struct queue *queue);

#endif // !QUEUE_H
