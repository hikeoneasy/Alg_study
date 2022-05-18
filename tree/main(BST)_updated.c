
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define TRUE	1
#define FALSE	0

typedef char element;
typedef int NodeData;

typedef struct _TREENODE_ {
	element key;
	struct _TREENODE_* left;
	struct _TREENODE_* right;
}TREENODE;

typedef struct _NODEMAP_ {
	int flag;
	NodeData data;
}NODEMAP;

TREENODE* searchNode(TREENODE* root, char x);			// 반복적 방법
TREENODE* searchNode_recur(TREENODE* root, char x);		// 재귀적 방법

void insertNode(TREENODE** p, char x);					// 반복적 방법
TREENODE* insertNode_recur(TREENODE* p, char x);		// 순환적(재귀적) 방법

void deleteNode(TREENODE** root, element key);			// 반복적방법
TREENODE* deleteNode_recur(TREENODE* root, int key);			// 재귀적

TREENODE* min_value_node(TREENODE* node)
{
	TREENODE* current = node;
	while (current->left != NULL) current = current->left;
	return current;
}



TREENODE* searchNode(TREENODE* root, char x) {
	TREENODE* p;
	p = root;
	while (p != NULL)
	{
		if (p->key == x) return p;
		else if (x < p->key) p = p->left;
		else p = p->right;
	}
	return NULL;
}

TREENODE* searchNode_recur(TREENODE* root, char x) {
	TREENODE* p;
	p = root;
	if (p == NULL) return NULL;
	else if (x == p->key) return p;
	else if (x < p->key) return searchNode_recur(p->left, x);
	else return searchNode_recur(p->right, x);
}

void insertNode(TREENODE** p, char x)
{
	TREENODE* newNode = NULL;
	TREENODE* cur = *p;
	TREENODE* q = NULL;


	while (cur != NULL)
	{
		if (cur->key == x) return;

		q = cur;
		if (x < cur->key) cur = cur->left;
		else cur = cur->right;
	}

	newNode = (TREENODE*)calloc(1, sizeof(TREENODE));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	if (q != NULL)
	{
		if (x < q->key) q->left = newNode;
		else q->right = newNode;
	}
	else *p = newNode;
}

TREENODE* insertNode_recur(TREENODE* p, char x) {
	TREENODE* new_node = NULL;
	
	if (p == NULL) {
		new_node = (TREENODE*)calloc(1, sizeof(TREENODE));
		new_node->key = x;
		new_node->left = NULL;
		new_node->right = NULL;
		return new_node;
	}
	else if (x < p->key) p->left = insertNode_recur(p->left, x);
	else if (x > p->key) p->right = insertNode_recur(p->right, x);
	return p;
}


void deleteNode(TREENODE** root, element key)
{
	
}

TREENODE* deleteNode_recur(TREENODE* root, int key)
{
	
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(TREENODE * root) {
	if (root) {
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}

int getHeight(TREENODE* node) {
	int hLeft, hRight;
	if (node == NULL) return 0;
	hLeft = getHeight(node->left);
	hRight = getHeight(node->right);
	return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
}

void printGivenLevel(TREENODE* root, int level, NODEMAP* map, int pos)
{
	if (root == NULL)
	{
		return;
	}
	if (level == 1) {
		map[pos].data = root->key;
		map[pos].flag = TRUE;
	}
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1, map, pos * 2);
		printGivenLevel(root->right, level - 1, map, pos * 2 + 1);
	}
}

void showTree(TREENODE* node)
{
	int height = 0;
	int numOfNodes = 0;
	NODEMAP* treeArray = NULL;
	char** square = NULL;
	static int pos = 0;
	int cnt_i;
	int cnt_j;
	int position;
	int start, term, index;

	height = getHeight(node);
	if (height != 0) {
		numOfNodes = (1 << height);
	}

	treeArray = (NODEMAP*)calloc(numOfNodes, sizeof(NODEMAP));
	assert(treeArray != NULL);

	square = (char**)calloc(height, sizeof(char*));
	for (cnt_i = 0; cnt_i < height; cnt_i++)
	{
		square[cnt_i] = (char*)calloc(numOfNodes, sizeof(char));
		memset(square[cnt_i], '.', numOfNodes);
	}

	// level order 순으로 treeArray에 노드의 데이터 삽입
	pos = 1;
	for (cnt_i = 1; cnt_i <= height; cnt_i++) {
		printGivenLevel(node, cnt_i, treeArray, pos);
	}

	// 한칸씩 왼쪽으로 이동
	for (cnt_i = 1; cnt_i <= numOfNodes; cnt_i++)
	{
		treeArray[cnt_i - 1] = treeArray[cnt_i];
	}

	pos = 0;
	start = (1 << (height - 1)) - 1;
	term = (1 << (height));
	index = (1 << (height - 2));
	for (cnt_i = 0; cnt_i < height; cnt_i++)
	{
		for (cnt_j = start; cnt_j < numOfNodes; cnt_j += term)
		{
			if (treeArray[pos].flag == TRUE) {
				if (treeArray[pos].data >= 0 && treeArray[pos].data <= 9) {
					square[cnt_i][cnt_j] = (treeArray[pos].data + '0');
				}
				else {
					square[cnt_i][cnt_j] = (treeArray[pos].data);
				}
			}
			else {
				square[cnt_i][cnt_j] = '.';
			}
			pos += 1;
		}
		term >>= 1;
		start -= index;
		index >>= 1;
	}

	printf("\n");
	for (cnt_i = 0; cnt_i < height; cnt_i++)
	{
		for (cnt_j = 0; cnt_j < numOfNodes; cnt_j++)
		{
			printf("%c", square[cnt_i][cnt_j]);
		}
		printf("\n");
	}

	if (treeArray != NULL) {
		free(treeArray);
	}
	if (square != NULL)
	{
		for (cnt_i = 0; cnt_i < height; cnt_i++)
		{
			if (square[cnt_i] != NULL)
			{
				free(square[cnt_i]);
			}
		}
		free(square);
	}
}

void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : 트리 출력");
	printf("\n\t2 : 문자 삽입");
	printf("\n\t3 : 문자 삭제");
	printf("\n\t4 : 문자 검색");
	printf("\n\t5 : 종료");
	printf("\n*---------------------------*");
	printf("\n메뉴입력 >> ");
}

int main() {
	
	TREENODE* root = NULL;
	TREENODE* foundedNode = NULL;
	char choice, key;
	insertNode(&root, 'h');
	insertNode(&root, 'a');
	insertNode(&root, 'k');
	insertNode(&root, 'c');
	insertNode(&root, 'z');
	insertNode(&root, 'e');
	insertNode(&root, 'o');
	insertNode(&root, 'u');
	//insertNode(&root, 'c');
	//insertNode(&root, 'k');
	//insertNode(&root, 'u');
	//insertNode(&root, 't');






	
	while (1) {
		menu();
		scanf("%c", &choice);
		if (choice - '0' < 1) { printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n"); break; }
		switch (choice - '0') {
		case 1:	printf("\t[이진 트리 출력]  ");
			displayInorder(root);  printf("\n");
			showTree(root);
			break;

		case 2:	printf("삽입할 문자를 입력하세요 : ");
			scanf(" %c", &key);
			insertNode(&root, key);
			displayInorder(root);  printf("\n");
			showTree(root);
			break;

		case 3:	printf("삭제할 문자를 입력하세요 : ");
			scanf(" %c", &key);

			break;

		case 4: printf("찾을 문자를 입력하세요 : ");
			scanf(" %c", &key);
			//searchNode_recur(root, key);
			//이걸 어떻게 받아와서 보여줄지 생각하기 
			break;

		case 5: 	return 0;

		default: printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}
	}
	return 0;
}

// EOF
