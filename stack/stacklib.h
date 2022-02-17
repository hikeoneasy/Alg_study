#ifndef __STACKLIB_
#define __STACKLIB_
#include <stdio.h>

#include <stdlib.h>



#define STACK_SIZE  10




typedef struct {

    int buf[STACK_SIZE];//저장소

    int top; //가장 최근에 보관한 인덱스

}Stack;


void InitStack(Stack* stack);//스택 초기화

int IsFull(Stack* stack); //스택이 꽉 찼는지 확인

int IsEmpty(Stack* stack); //스택이 비었는지 확인

void Push(Stack* stack, int data); //스택에 보관

int Pop(Stack* stack); //스택에서 꺼냄









#endif
