#include <stdio.h>
#include <stdlib.h>

#define	TRUE	1
#define FALSE	0

#define	QSIZE	10

typedef int element;
typedef struct {
	element queue[QSIZE];
	int front, rear;
} QueueType;

//Å¥»ý¼º
QueueType* createQueue()
{
	QueueType* Q;
	Q = (QueueType*)calloc(1, sizeof(QueueType));
	if (Q == NULL) return -1;
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

//²ËÃ¡³ª?
int isFull(QueueType* Q)
{
	if (Q->rear == QSIZE - 1)
	{
		printf("Queue is full!\n");
		return TRUE;
	}
	else return FALSE;
}

//ºñ¾îÀÖ³ª?
int isEmpty(QueueType* Q)
{
	if (Q->front == Q->rear)
	{
		printf("Queue is empty!\n");
		return TRUE;
	}
	else return FALSE;
}

//»ðÀÔ
void enQueue(QueueType* Q, element item)
{
	if (isFull(Q)) return;
	else
	{
		Q->rear+=1;
		Q->queue[Q->rear] = item;
	}
}

//²¨³»±â
element deQueue(QueueType* Q)
{
	if ((isEmpty(Q))) return -1;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

element peek(QueueType* Q)
{
	if (isEmpty(Q)) return -1;
	else {
		return Q->queue[Q->front + 1];
	}
}


void printQ(QueueType* Q) {
	int i;
	printf("Queue: (front: %d, (rear: %d)[", Q->front, Q->rear);
	for (i = Q->front + 1; i <= Q->rear; i++)
	{
		printf("%d, ", Q->queue[i]);
	}
	printf("]\n");
}

int main()
{
	QueueType* Q1 = createQueue();
	QueueType* Q2 = createQueue();
	element data;

	printf("[Å¥»ðÀÔ]\n");

	for (int i = 0; i < 11; i++) {
		printf("%d »ðÀÔ\n", i);
		enQueue(Q1, i);
		printQ(Q1);
	}
	data = peek(Q1);
	printf("\nFirst item in Queue: %d\n", data);

	printf("\n[Å¥ »èÁ¦]\n");
	for (int i = 0; i < 11; i++)
	{
		data = deQueue(Q1);
		printf("%d »èÁ¦\n", data);
		printQ(Q1);
	}

	printf("\n[°ÅÁþÆ÷È­]\n");
	for (int i = 0; i < 11; i++) {
		printf("enQueue: ");
		enQueue(Q2, i);
		printQ(Q2);

		printf("deQueue: ");
		deQueue(Q2);
		printQ(Q2);
	}
}