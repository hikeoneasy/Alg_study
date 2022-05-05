
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack 사용과 관련된 함수 및 코드 정의

#define STACK_SIZE 1000000
typedef int element;
typedef struct _STACK_ {
    element stackarr[STACK_SIZE];
    int topIndex;
    int stackSize;
}stack;

void init(stack* stack1, int size) {
    stack1->stackSize = size;
    stack1->topIndex = -1;
}


int isEmpty(stack* stack1)
{
    if (stack1->topIndex == -1) return 1;
    else return 0;

}



void push(stack* stack1, element item) {

    stack1->stackarr[++(stack1->topIndex)] = item;

}

element pop(stack* stack1) {
    if (isEmpty(stack1)) return -1;
    else {

        return stack1->stackarr[(stack1->topIndex)--];
    }
}

element peek(stack* stack1) {
    if (isEmpty(stack1)) return -1;
    return stack1->stackarr[(stack1->topIndex)];
}

void sizeprint(stack* stack1)
{

    printf("%d\n", stack1->topIndex + 1);
}




void test_10828()
{
    int pop_recv = 0;
    stack stack1;
    init(&stack1, 10002);

    int num = 0;
    char buff[6];
    int X = 0;
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
            push(&stack1, X);
        }
        else if (!strcmp(buff, "pop"))
        {

            pop_recv = pop(&stack1);
            printf("%d\n", pop_recv);
        }
        else if (!strcmp(buff, "size"))
        {
            sizeprint(&stack1);
        }
        else if (!strcmp(buff, "empty"))

        {
            pop_recv = isEmpty(&stack1);
            printf("%d\n", pop_recv);
        }
        else
        {
            pop_recv = peek(&stack1);
            printf("%d\n", pop_recv);
        }
    }

}


void test_1874()
{
    int num = 0;
    scanf("%d", &num);

    int* output = (int*)malloc(sizeof(int) * num);
    if (output == NULL) return;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &output[i]);
    }


    stack stack1;
    char ans[300000] = { 0, };
    if (ans == NULL) return;


    int cnt = 1; int tmp = 0;
    init(&stack1, 100000);

    for (int i = 0; i < num; i++)
    {
        while (cnt <= output[i])
        {
            push(&stack1, cnt++);
            strcat(ans, "+");

        }

        if (peek(&stack1) == output[i])
        {
            pop(&stack1);
            strcat(ans, "-");
        }
        else
        {
            printf("NO\n");
            return;
        }
    }

    strcat(ans, "9");

    int k = 0;
    while (ans[k] != '9')
    {
        printf("%c\n", ans[k++]);

    }
}

void test_17298()
{
    int num = 0;
    scanf("%d", &num);
    int A[10000001] = { 0, };
    int ans[10000001] = { 0, };
    if (A == NULL || ans == NULL) return;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &A[i]);
    }

    stack stack1;
    init(&stack1, num);



    for (int i = num - 1; i >= 0; i--)
    {
        while (!isEmpty(&stack1) && (peek(&stack1) <= A[i]))
        {
            pop(&stack1);
        }

        if (!isEmpty(&stack1)) ans[i] = peek(&stack1);
        else ans[i] = -1;
        push(&stack1, A[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("%d ", ans[i]);
    }
}

int main()
{
	//test_10828();
	//test_1874();
	//test_17298();

	return 0;
}

// EOF

