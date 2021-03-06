#include "stacklib.h"



void InitStack(Stack* stack)

{

    stack->top = -1; //스택 초기화에서는 top을 -1로 설정

}

int IsFull(Stack* stack)

{

    return (stack->top + 1) == STACK_SIZE;//top+1 이 스택 크기와 같으면 꽉 찬 상태

}

int IsEmpty(Stack* stack)

{

    return stack->top == -1;    //top이 -1이면 빈 상태    

}

void Push(Stack* stack, int data)

{

    if (IsFull(stack))

    {

        printf("스택이 꽉 찼음\n");

        return;

    }

    stack->top++; //top을 1 증가

    stack->buf[stack->top] = data;   //데이터 보관

}

int Pop(Stack* stack)

{

    int re = 0;

    if (IsEmpty(stack))

    {

        printf("스택이 비었음\n");

        return re;

    }

    re = stack->buf[stack->top];//top 인덱스에 보관한 값을 re에 설정

    stack->top--;//top을 1 감소

    return re;

}





