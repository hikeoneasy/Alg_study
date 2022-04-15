#define _CRT_SECURE_NO_WARNINGS

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cassert>
#define MAXSTRLEN 32
typedef struct _LIST_NODE_ {
	char data[MAXSTRLEN];
	struct _LIST_NODE_* link;
}LIST_NODE;


typedef struct _LINKEDLIST_H_ {
	LIST_NODE* head;
	//int numOfNodes;
}LINKEDLIST_H;



LINKEDLIST_H* create(void);  // new linked list
void freelist(LINKEDLIST_H* L);  //free linked list
void insertF(LINKEDLIST_H* L, char* x); //insert first Node
void insertL(LINKEDLIST_H* L, char* x); //insert last Node
void insertM(LINKEDLIST_H* L, LIST_NODE* pre, char* x);

LIST_NODE* searchNode(LINKEDLIST_H* L, char* x);

void delete(LINKEDLIST_H* L, LIST_NODE* p);

void orederInsertBIG(LINKEDLIST_H* L, char* x); 
void orederInsertSMALL(LINKEDLIST_H* L, char* x);
void printlist(LINKEDLIST_H* L);
#endif 