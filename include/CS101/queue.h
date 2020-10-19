#ifndef QUEUE_H
#define QUEUE_H

struct CS101_queue {
	int *arr;
	int head;
	int tail;
	int size;
};

struct CS101_queue *queue_new(int size);
int queue_empty(struct CS101_queue *queue);
int queue_full(struct CS101_queue *queue);
void queue_enqueue(struct CS101_queue *queue, int data);
int queue_dequeue(struct CS101_queue *queue);
void queue_free(struct CS101_queue *queue);
void queue_print(struct CS101_queue *queue);

#endif // !QUEUE_H
