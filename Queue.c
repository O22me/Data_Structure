#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct {
	element* data;
	int front;
	int rear;
	int size;
}Queue;

void InitQueue(Queue* q, int size) {
	q->data = (element*)malloc(sizeof(element) * size);
	if (q->data == NULL) return;
	q->front = 0;
	q->rear = 0;
	q->size = size;
}
bool is_full(Queue* q) {
	if ((q->rear + 1) % q->size == q->front) return true; //(rear + 1) % size == front
	else return false;
}
bool is_empty(Queue* q) {
	if (q->front == q->rear) return true;
	else return false;
}
void printQueue(Queue* q) {
	for (int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size) {
		printf("%d ", *(q->data + i));
	}
	printf("\n");
}
void enqueue(Queue* q, element data) {
	if (is_full(q)) {
		printf("Queue is full.\n");
		return;
	}
	else {
		q->rear = (q->rear + 1) % q->size;
		*(q->data + q->rear) = data;
	}
}
element dequeue(Queue* q) {
	if (is_empty(q)) {
		printf("Queue is empty.\n");
		return -1;
	}
	else {
		q->front = q->front + 1 % q->size;
		return *(q->data + q->front);
	}
}
int main(void) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL) return -1;

	InitQueue(q, 8);

	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);

	printQueue(q);

	dequeue(q);
	dequeue(q);

	printQueue(q);

	dequeue(q);
	dequeue(q);

	printQueue(q);

	free(q->data);
	free(q);

	return 0;
}