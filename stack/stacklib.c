#include "stacklib.h"



void InitStack(Stack* stack)

{

    stack->top = -1; //���� �ʱ�ȭ������ top�� -1�� ����

}

int IsFull(Stack* stack)

{

    return (stack->top + 1) == STACK_SIZE;//top+1 �� ���� ũ��� ������ �� �� ����

}

int IsEmpty(Stack* stack)

{

    return stack->top == -1;    //top�� -1�̸� �� ����    

}

void Push(Stack* stack, int data)

{

    if (IsFull(stack))

    {

        printf("������ �� á��\n");

        return;

    }

    stack->top++; //top�� 1 ����

    stack->buf[stack->top] = data;   //������ ����

}

int Pop(Stack* stack)

{

    int re = 0;

    if (IsEmpty(stack))

    {

        printf("������ �����\n");

        return re;

    }

    re = stack->buf[stack->top];//top �ε����� ������ ���� re�� ����

    stack->top--;//top�� 1 ����

    return re;

}





