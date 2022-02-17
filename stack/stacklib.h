#ifndef __STACKLIB_
#define __STACKLIB_
#include <stdio.h>

#include <stdlib.h>



#define STACK_SIZE  10




typedef struct {

    int buf[STACK_SIZE];//�����

    int top; //���� �ֱٿ� ������ �ε���

}Stack;


void InitStack(Stack* stack);//���� �ʱ�ȭ

int IsFull(Stack* stack); //������ �� á���� Ȯ��

int IsEmpty(Stack* stack); //������ ������� Ȯ��

void Push(Stack* stack, int data); //���ÿ� ����

int Pop(Stack* stack); //���ÿ��� ����









#endif
