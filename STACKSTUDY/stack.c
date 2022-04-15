#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
typedef int element;

element stack[STACK_SIZE];
int top = -1;

void init()
{
    top = -1;
}

int isEmpty()
{
    if (top == -1) return 1;
    else return 0;

}

int isFull()
{
    if(top == STACK_SIZE-1) return 1;
    else return 0;
}

void push(element item){
    if(isFull()) {printf("error\n"); return;}
    else{
        stack[++top] = item;
    }
}

element pop(){
    if(isEmpty()) return 0;
    else return stack[top--];
}

element peek(){
    if(isEmpty()) return 0;
    else return stack[top];
}


void printStack()
{
    for(int i = top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

void stackarr()
{
    element item;
    printf("stack test\n");
    printStack();
    for(int i = 0;i<3;i++) {push(i); printStack();}
}
int main()
{
stackarr();
    return 0;
}