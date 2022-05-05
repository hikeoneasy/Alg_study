#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

typedef int element;

typedef struct _DQNODE_{
    element data;
    struct _DQNODE_ * llink;
    struct _DQNODE_ * rlink;
}DQNODE;


//front랑 rear를 관리해주기
typedef struct _DQUEUE_TYPE_{
    DQNODE* front, *rear;
}_DQUEUE_TYPE;

_DQUEUE_TYPE* create()
{
    _DQUEUE_TYPE* DQ = NULL;
    DQ = (_DQUEUE_TYPE*)calloc(1,sizeof(_DQUEUE_TYPE));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

element Isempty(_DQUEUE_TYPE* DQ)
{
    if(DQ->front == NULL) return TRUE;
    else return FALSE;
}

void insertF(_DQUEUE_TYPE* DQ, element items)
{
    DQNODE* newnode = NULL;
    newnode = (DQNODE*)calloc(q,sizeof(DQNODE));
    newnode->data = items;

    if(DQ->front == NULL)
    {
            // is empty
            DQ->front = newnode;
            DQ->rear = newnode;
            newnode->llink = NULL;
            newnode->rlink = NULL;
    }
    else{
            // is not empty
            DQ->front->llink=newnode;
            newnode->rlink = DQ->front;
            newnode->llink = NULL;
            DQ->front = newnode;
    }
}

void insertR(_DQUEUE_TYPE*DQ,element items)
{
    DQNODE* newnode = NULL;
    newnode = (DQNODE*)calloc(1,sizeof(DQNODE));
    newnode->data = items;

    if(DQ->rear == NULL)
    {
        DQ->front = newnode;
        DQ->rear = newnode;
        newnode->llink = NULL;
        newnode->rlink = NULL;
    }
    else
    {
        DQ->rear->rlink = newnode;
        newnode ->llink = DQ->rear;
        newnode->rlink = NULL;
        DQ->rear = newnode;
    }
}

element deleteF(_DQUEUE_TYPE*DQ)
{
    DQNODE* old = NULL;
    element items=0;

    if(Isempty(DQ)) return FALSE;
    else{
        old = DQ->front;
        items = old->data;

        if(DQ->front->rlink == NULL)
        {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else{
        DQ->front = DQ->front->rlink;
        DQ->front->llink = NULL;
        }
        free(old);
        return items;
    }
}

element deleteR(_DQUEUE_TYPE*DQ)
{
    DQNODE* old = NULL;
    element items=0;

    if(Isempty(DQ)) return FALSE;
    else{
        old = DQ->rear;
        items = old->data;

        if(DQ->rear->llink == NULL)
        {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else{
        DQ->rear = DQ->rear->llink;
        DQ->rear->rlink = NULL;
        }
        free(old);
        return items;
    }
}

//peek 구현해보기


void printDQ(_DQUEUE_TYPE* DQ)
{
    DQNODE* temp = DQ->front;
    //구현해보기
}

