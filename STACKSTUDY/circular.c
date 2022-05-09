#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{
    int data;
    struct ListNode* link;
}listNode;

typedef struct {
    listNode* head;
}linkedList_h;

linkedList_h* create(){
    linkedList_h* CL;
    CL = (linkedList_h*)calloc(1,sizeof(linkedList_h));
    CL->head = NULL;
    return CL;
}

void printList(linkedList_h* CL){
    listNode* p;
    printf(" CL = (");
    p = CL->head;
    if(p!= NULL)
    {
    do{
        printf("%d",p->data);
        p = p->link;
        if(p != CL->head){
            printf(", ");
        }
    }while(p != CL->head);
    printf(") \n");
    }
    else{printf("CL isempty\n");}
}

void insertF(linkedList_h* CL,int x)
{
    listNode* newNode,*cur;
    newNode = (listNode*)calloc(1,sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;

    if(CL->head == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else{
        cur = CL->head;
        while(cur->link != CL->head)
        {
            cur = cur->link;
        }
        newNode->link = cur->link;
        cur->link = newNode;
        CL->head = newNode;
    }
}

void insertM(linkedList_h*CL,listNode* pre, int x)
{
     listNode* newNode,*cur;
    newNode = (listNode*)calloc(1,sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;

    if(CL->head == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
    }
    else if (pre == NULL)
    {
        newNode->link = CL->head;
        CL->head = newNode;
    }
    else{
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void deletenode(linkedList_h* CL, listNode* old)
{
    listNode* pre = NULL;
    listNode* cur = NULL;
    listNode* find = NULL;
    if(CL->head==NULL||old==NULL)
    {
        return;
    }
    pre = cur= CL->head;

    if(pre == old)
    {
        while(cur->link != CL->head)
        {
            cur=cur->link;
        }
        CL->head = pre->link;
        cur->link = CL->head;
        free(pre);
        return;
    }
    cur = pre->link;
    while(cur!= CL->head)
    {
        if(cur==old)
        {
            find = cur;
            return;
        }
        pre = cur;
        cur= cur->link;
    }
    if(find!=NULL)
    {
        pre->link = find->link;
        free(find);
    }

}

listNode* search(linkedList_h* CL, int x)
{
    int cnt_i=0;
    listNode* temp = CL->head;
    if(temp == NULL)
    {
        return NULL;
    }
    do{
        printf("Search try:  %d\n",cnt_i++);
    }while(temp != CL->head);
    return NULL;
}
listNode* search2(listNode* from, int x)
{
    int cnt_i= 0;
    listNode* temp = from;
    if(temp == NULL)
    {
        return NULL;
    }
    do{
        printf("Search try:  %d\n",cnt_i++);
    }while(temp != from);
    return NULL;
}

void orderInsert(linkedList_h* CL, int x)
{
    listNode* pre = NULL;
    listNode* cur = NULL;
    listNode* newNode = NULL;

    newNode = (listNode*)calloc(1,sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;

    pre = cur = CL->head;
    if(cur == NULL)
    {
        CL->head = newNode;
        newNode->link = newNode;
        return;
    }
    else if (cur!=NULL)
    {
        if(cur->data >x)
        {
            cur = cur->link;
        }
        newNode->link = cur->link;
        cur->link = newNode;
        CL->head = newNode;
        return;
    }
    cur = cur->link;
    while(cur!= CL->head)
    {
        if(cur->data > x)
        {
            break;
        }
        pre = cur;
        cur = cur = cur->link;
    }
    newNode->link = pre->link;
    pre->link = newNode;
}

void test_circular_list()
{
    int cnt_i;
    int data;

    linkedList_h* CL = NULL;
    listNode* p =NULL;
    srand((unsigned int)time(NULL));

    CL= create();
    for(cnt_i = 0;cnt_i<10;cnt_i++)
    {
        orderInsert(CL,rand()%10);
        printList(CL);
    }
}
int main(){
    test_circular_list();
    getchar();
    return 0;
}