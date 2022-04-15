
#include "linkedlist.h"


LINKEDLIST_H* create(void)
{
	LINKEDLIST_H* L = NULL;
	L = (LINKEDLIST_H*)calloc(1, sizeof(LINKEDLIST_H));
	assert(L != NULL);
	L->head = NULL;

	return L;
}

void freelist(LINKEDLIST_H* L)
{
	LIST_NODE* p;

	if (L != NULL)
	{
		while (L->head != NULL)
		{
			p = L->head;
			L->head = L->head->link;
			free(p);
			p = NULL;
		}
		L->head = NULL;
	}
	else
	{
		fprintf(stderr, "error: Null lsit\n");
		return;
	}
}

void insertF(LINKEDLIST_H* L, char* x)
{
	LIST_NODE* newNode = NULL;
	newNode = (LIST_NODE*)calloc(1, sizeof(LIST_NODE));
	assert(newNode != NULL);
	newNode->link = NULL;

	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertL(LINKEDLIST_H* L, char* x)
{
	LIST_NODE* newNode = NULL;
	LIST_NODE* temp = NULL;

	newNode = (LIST_NODE*)calloc(1, sizeof(LIST_NODE));
	assert(newNode != NULL);

	strncpy(newNode->data, x, MAXSTRLEN);
	newNode->link = NULL;

	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}
	temp = L->head;

	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = newNode;
		
}

LIST_NODE* searchNode(LINKEDLIST_H* L, char* x)
{
	LIST_NODE* temp = NULL;
	temp = L->head;

	while (temp != NULL)
	{
		if (strncmp(temp->data, x, MAXSTRLEN) == 0) return temp;
		else
		{
			temp = temp->link;
		}
	}

	return temp;
}

void insertM(LINKEDLIST_H* L, LIST_NODE* pre, char* x)
{
	LIST_NODE* newNode = NULL;
	LIST_NODE* temp = NULL;

	newNode = (LIST_NODE*)calloc(1, sizeof(LIST_NODE));
	assert(newNode != NULL);

	strncpy(newNode->data, x, MAXSTRLEN);
	newNode->link = NULL;

	if (L->head == NULL)
	{
		L->head = newNode;
	}
	else if (pre == NULL)
	{
		newNode->link = L->head;
		L->head = newNode;
	}
	else
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void delete(LINKEDLIST_H* L, LIST_NODE* p)
{
	LIST_NODE* pre = NULL;
	LIST_NODE* cur = NULL;
	LIST_NODE* find = NULL;

	if (L->head == NULL || p == NULL)
	{
		return;
	}

	pre = cur = L->head;

	if (pre == p)
	{
		cur = pre->link;
		free(pre);
		L->head = cur;
		return;
	}
	
	cur = cur->link;
	while (cur != NULL)
	{
		if (cur == p)
		{
			find = cur;
			break;
		}
		pre = cur;
		cur = cur->link;
	}
	if (find != NULL)
	{
		pre->link = find->link;
		free(find);
	}
}
void orederInsertBIG(LINKEDLIST_H* L, char* x)
{
	LIST_NODE* pre = NULL;
	LIST_NODE* cur = NULL;
	LIST_NODE* newNode = NULL;

	newNode = (LIST_NODE*)calloc(1, sizeof(LIST_NODE));
	assert(newNode != NULL);
	strncpy(newNode->data, x, MAXSTRLEN);
	newNode->link = NULL;


	pre = cur = L->head;
	
	if (cur == NULL)
	{
		L->head = newNode;
		return;
	}
	else if (cur != NULL)
	{
		if (strncmp(cur->data, x, MAXSTRLEN) > 0)
		{
			newNode->link = cur;
			L->head = newNode;
			return;
		}
	}

	cur = cur->link;
	while (cur != NULL)
	{
		if (strncmp(cur->data, x, MAXSTRLEN) > 0)
		{
			break;
		}
		pre = cur;
		cur = cur->link;
	}
	newNode->link = cur;
	pre->link = newNode;
}

void printlist(LINKEDLIST_H* L)
{
	LIST_NODE* p = NULL;
	p = L->head;
	printf("L = (");
	while (p != NULL)
	{
		printf("%s", p -> data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(")\n");

}

void orederInsertSMALL(LINKEDLIST_H* L, char* x)
{
	LIST_NODE* pre = NULL;
	LIST_NODE* cur = NULL;
	LIST_NODE* newNode = NULL;

	newNode = (LIST_NODE*)calloc(1, sizeof(LIST_NODE));
	assert(newNode != NULL);
	strncpy(newNode->data, x, MAXSTRLEN);
	newNode->link = NULL;


	pre = cur = L->head;

	if (cur == NULL)
	{
		L->head = newNode;
		return;
	}
	else if (cur != NULL)
	{
		if (strncmp(cur->data, x, MAXSTRLEN) < 0)
		{
			newNode->link = cur;
			L->head = newNode;
			return;
		}
	}

	cur = cur->link;
	while (cur != NULL)
	{
		if (strncmp(cur->data, x, MAXSTRLEN) < 0)
		{
			break;
		}
		pre = cur;
		cur = cur->link;
	}
	newNode->link = cur;
	pre->link = newNode;
}
