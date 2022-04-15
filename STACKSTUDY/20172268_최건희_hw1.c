#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "linkedlist.h"


void test1()
{
	char buffer[1024] = { 0, };
	int frequency[26] = { 0, };
	char* INPUT = { 0x00 };
	int len = 0;

	printf("Input a string(max len 1024):\n");
	gets(buffer);
	len = (int)strlen(buffer);
	INPUT = (char*)calloc(len + 1, sizeof(char));
	if (INPUT == NULL) return;
	strcpy(INPUT, buffer);


	int iter = 0;
	for (int i = 0; i < len; i++)
	{
		if ('a' <= INPUT[i] && INPUT[i] <= 'z')
			INPUT[i] -= 32;

		iter = INPUT[i] - 65;
		if (iter < 26) frequency[iter] += 1;
		
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%c: %d\n", i+97, frequency[i]);
		
	}
	printf("\nBye!");
	free(INPUT);
}




void test2()
{
	LINKEDLIST_H* list1 = NULL;
	LINKEDLIST_H* list2 = NULL;
	LINKEDLIST_H* list3 = NULL;
	LINKEDLIST_H* list4 = NULL;
	LIST_NODE* temp = NULL;
	list1 = create(); 
	printf("(1) 리스트에 머리에 노드 삽입하기!\n");
	insertF(list1, "apple");
	insertF(list1, "banana");
	insertF(list1, "cat");
	printlist(list1);
	

	list2 = create();
	printf("\n(2) 리스트에 꼬리에 노드 삽입하기!\n");
	insertL(list2, "apple");
	insertL(list2, "banana");
	insertL(list2, "cat");
	printlist(list2);
	
	printf("\n(3) 리스트에서 노드 탐색하기!\n");
	temp = searchNode(list1, "banana");
	if (temp == NULL) printf("찾는 데이터가 없습니다. \n");
	else printf("[%s]를 찾았습니다.\n", temp->data);

	insertM(list1, temp, "test");
	temp = searchNode(list1, "test");
	if (temp == NULL) printf("찾는 데이터가 없습니다. \n");
	else printf("[%s]를 찾았습니다.\n", temp->data);

	printf("\n(4) 리스트에서 중간에 노드 삽입하기! \n");
	insertM(list1, temp, "zero");
	printlist(list1);

	freelist(list1);
	if (list1 != NULL) free(list1);
	freelist(list2);
	if (list2 != NULL) free(list2);


	printf("\n(5) 리스트에 정렬하여 노드 삽입하기! \n");
	list3 = create();
	orederInsertBIG(list3, "attain");
	orederInsertBIG(list3, "absolute");
	orederInsertBIG(list3, "affine");
	orederInsertBIG(list3, "blue");
	orederInsertBIG(list3, "test");
	orederInsertBIG(list3, "friday");
	printlist(list3);

	printf("\n(6) 리스트에서 노드 삭제하기! \n");
	temp = searchNode(list3, "absolute");
	delete(list3, temp);
	printlist(list3);
	freelist(list3);
	if (list3 != NULL) free(list3);

	printf("\n(7) 리스트에 정렬하여 노드 삽입하기! \n");
	list4 = create();
	orederInsertSMALL(list4, "attain");
	orederInsertSMALL(list4, "absolute");
	orederInsertSMALL(list4, "affine");
	orederInsertSMALL(list4, "blue");
	orederInsertSMALL(list4, "test");
	orederInsertSMALL(list4, "friday");
	printlist(list4);
	freelist(list4);
	if (list4 != NULL) free(list4);


}




int main()
{
	//test1();
	test2();


	return 0;
}