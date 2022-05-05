
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// queue 사용과 관련된 함수 및 코드 정의

#define TRUE 1
#define FALSE 0

#define Q_SIZE 20000000

typedef int element;

typedef struct QUEUETYPE {
    element queue[Q_SIZE];
    int front, rear;
}QueueType;

QueueType* create()
{
    QueueType* Q;
    Q = (QueueType*)calloc(1, sizeof(QueueType));
    if (Q == NULL) return -1;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int isFULL(QueueType* Q)
{
    if (Q->rear == Q_SIZE - 1) {
        //printf("Queue is full\n");
        return TRUE;
    }
    else return FALSE;
}

int isEmpty(QueueType* Q)
{
    if (Q->front == Q->rear) {
        //printf("Queue i sempty\n");
        return TRUE;
    }
    else return FALSE;
}

void enQueue(QueueType* Q, element item) {
    if (isFULL(Q)) return;
    else {
        Q->rear++;
        Q->queue[Q->rear] = item;
    }
}

element deQueue(QueueType* Q) {
    if (isEmpty(Q)) return -1;
    else {
        Q->front++;
        return Q->queue[Q->front];
    }
}

element peek(QueueType* Q)
{
    if (isEmpty(Q)) return -1;
    else return Q->queue[Q->front + 1];
}
void sizeprint(QueueType* Q)
{

    printf("%d\n", Q->rear - Q->front);
}
element back(QueueType* Q)
{
    if (isEmpty(Q)) return -1;
    return Q->queue[Q->rear];
}



void test_18258()
{
    QueueType* Q = create();
    int num = 0;
    char buff[6];
    int X = 0;
    int pop_recv;
    scanf("%d", &num);
    fgetc(stdin);
    for (int i = 0; i < num; i++)
    {
        scanf("%s", &buff);
        fgetc(stdin);
        if (!strcmp(buff, "push"))
        {
            scanf("%d", &X);
            fgetc(stdin);
            enQueue(Q, X);
        }
        else if (!strcmp(buff, "pop"))
        {

            pop_recv = deQueue(Q);
            printf("%d\n", pop_recv);
        }
        else if (!strcmp(buff, "size"))
        {
            sizeprint(Q);
        }
        else if (!strcmp(buff, "empty"))

        {
            pop_recv = isEmpty(Q);
            printf("%d\n", pop_recv);
        }
        else if (!strcmp(buff, "front"))
        {
            pop_recv = peek(Q);
            printf("%d\n", pop_recv);
        }
        else
        {
            pop_recv = back(Q);
            printf("%d\n", pop_recv);
        }
    }
}

void test_2164()
{
    int num = 0;
    scanf("%d", &num);
    QueueType* Q = create();
    for (int i = 1; i <= num; i++) enQueue(Q, i);

    int cnt = 0; int tmp = 0;
    for (int i = 0; i < num - 1; i++)
    {
        deQueue(Q);
        tmp = deQueue(Q);
        enQueue(Q, tmp);
    }

    printf("%d\n", peek(Q));
}

int main()
{
	//test_18258();
	//test_2164();

	return 0;
}

// EOF