#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
typedef int element;
typedef struct _STACK_{
    element stackarr[STACK_SIZE];
    int topIndex;
    int stackSize;
}stack;

void init(stack* stack1, int size){
    stack1->stackSize = size;
    stack1->topIndex;
}


int isEmpty(stack* stack1)
{
    if (stack1->topIndex == -1) return 1;
    else return 0;

}

int isFull(stack* stack1)
{
    if(stack1->topIndex == STACK_SIZE-1) return 1;
    else return 0;
}

void push(stack* stack1 , element item){
    if(isFull(stack1)) {printf("error\n"); return;}
    else{
        stack1->stackarr[++(stack1->topIndex)] = item;
    }
}

element pop(stack* stack1){
    if(isEmpty(stack1)) return 0;
    else return stack1-> stackarr[(stack1->topIndex)--];
}

element peek(stack* stack1){
    if(isEmpty(stack1)) return 0;
    else return stack1-> stackarr[(stack1->topIndex)];
}


void printStack(stack* stack1)
{
    for(int i = stack1->topIndex;i>0;i--)
    {
        printf("%d ",stack1->stackarr[i]);
    }
    printf("\n");
}


void sttack_test2()
{
    stack stack1;
    for(int i =10;i>=0;i--)
    {
        printStack(&stack1);
        push(&stack1, i);
    }
    for(int i =10;i>=0;i--)
    {
        printStack(&stack1);
        pop(&stack1);
    }
}

int main()
{
    sttack_test2();
    return 0;
}