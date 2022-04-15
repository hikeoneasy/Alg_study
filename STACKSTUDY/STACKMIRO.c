#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE	100
#define MAX_SIZE	6

typedef struct StackObject {

	short r;
	short c;
}StackObject;


StackObject stack[STACK_SIZE];
int top = -1;
StackObject here = { 1,0 };

char maze[MAX_SIZE][MAX_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};


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
    if (top == STACK_SIZE - 1) return 1;
    else return 0;
}

void push(StackObject item) {
    if (isFull()) { printf("error\n"); return; }
    else {
        stack[++top] = item;
    }
}

StackObject pop() {
    if (isEmpty()) printf("empty\n");
    else return stack[top--];
}

void printStack()
{
    for (int i = MAX_SIZE - 1; i > 0; i--)
    {
        printf("|     |\n");
    }
    for (int i = top; i >= 0; i--)
    {
        printf("|(%01d,%01d)|\n",stack[i].r,stack[i].c);
    }
    printf("------\n");
}

void pushLOC(short r, short c)
{
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.')
    {
        StackObject temp;
        temp.r = r;
        temp.c = c;
        push(temp);
    }
}
void PrintMaze(char m[MAX_SIZE][MAX_SIZE])
{
    int r, c;
    printf("\n\n");
    for (r = 0; r < MAX_SIZE; r++)
    {
        for (c = 0; c < MAX_SIZE; c++)
        {
            if (c == here.c && r == here.r)
            {
                printf("m ");
            }
            else {
                if (m[r][c] == 0) {
                    printf("0 ");
                }
                else {
                    printf("%c ", m[r][c]);
                }
            }
        }
        printf("\n");
    }
    printf("\n\n");
}
void findroot()
{
    short r, c;

    PrintMaze(maze);
    printStack();
    while (maze[here.r][here.c] != 'x')
    {
        PrintMaze(maze);

        r = here.r;
        c = here.c;

        maze[r][c] = '.';
        pushLOC(r - 1, c);
        pushLOC(r + 1, c);
        pushLOC(r, c - 1);
        pushLOC(r, c + 1);
        printStack();
        if (isEmpty()) {
            printf("FAIL!\n");
            return;
        }
        else {
            here = pop();
        }
        PrintMaze(maze);
        printStack();
    }printf("SUCCESS\n");
}

int main()
{
    findroot();


    return 0;
}