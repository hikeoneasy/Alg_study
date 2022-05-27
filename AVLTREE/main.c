#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "AVL.h"

#include <assert.h>
#define MAX(a,b) ((a>b)?a:b)

TREENODE* LL_rotate(TREENODE* parent);
TREENODE* RR_rotate(TREENODE* parent);
TREENODE* LR_rotate(TREENODE* parent);
TREENODE* RL_rotate(TREENODE* parent);
int getHeight(TREENODE* p);
int getBF(TREENODE* p);
TREENODE* rebalance(TREENODE** p);
TREENODE* insert_BST_Node(TREENODE** p, char x);
TREENODE* insert_AVL_Node(TREENODE** root, element x);
TREENODE* searchNode(TREENODE* root, char x);
void displayInorder(TREENODE* root);
void delete_BST_Node(TREENODE** root, element key);
void delete_AVL_Node(TREENODE** root, element key);

// ��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void delete_BST_Node(TREENODE** root, element key)
{
	TREENODE* parent = NULL, * p = NULL, * succ = NULL, * succ_parent = NULL;
	TREENODE* child = NULL;

	p = *root;

	// ������ ����� ��ġ Ž��
	while ((p != NULL) && (p->key != key))
	{
		parent = p;
		if (key < p->key) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}

	// ������ ��尡 ���� ���
	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�.!");
		return;
	}

	// p�� ������ �����
	// ������ ��尡 �ܸ� ����� ���(���� = 0)
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			// �����Ǵ� ��尡 �θ��� �����̶��
			// �θ��� ���� �ڽ��� NULL
			if (parent->left == p) {
				parent->left = NULL;
			}
			// �����Ǵ� ��尡 �θ��� �������̶��
			// �θ��� ������ �ڽ��� NULL
			else {
				parent->right = NULL;
			}
		}
		else // ���� �θ��尡 NULL�̸� �����Ǵ� ���� ��Ʈ
		{
			*root = NULL;
		}
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���(���� = 1)
	else if ((p->left == NULL) || (p->right == NULL))
	{
		// p�� ���� �ڽĳ�尡 �ִ� ���
		if (p->left != NULL) {
			child = p->left;
		}
		// p�� ������ �ڽĳ�尡 �ִ� ���
		else {
			child = p->right;
		}

		if (parent != NULL)
		{
			if (parent->left == p) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else {// �� �ΰ��� ��常 ������ ��, parent�� �����Ǵ� ���
			*root = child;
		}
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���(���� = 2)
	else {
		succ_parent = p;	// p�� ������ ���

							// ���� ���� Ʈ������ �İ��� ã��
							// ���� ���� Ʈ���� �̵�
		succ = p->left;
		// ���� ����Ʈ���� ���� ������ ��带 ����
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		// �İ����� �θ�� �İ����� �ڽ��� ����
		if (succ_parent->left == succ) {	// Ư���� ���(ó������ ������ �ڽ��� ���� ���)
			succ_parent->left = succ->left;
		}
		else {
			// �İ����� ���� ����Ʈ���� �θ��� �����ʿ� ����
			// succ�� ������ �ڽ��� �翬�� ����
			// ������ �ڽ��� ������ �� Ÿ�� ���� ����
			succ_parent->right = succ->left;
		}
		p->key = succ->key;	// �İ��� Ű�� ��ü�Ǵ� ��忡 ����(������ ��带 ������ �Ͱ� ������ ȿ��)
		p = succ;			// �İ��� ����
	}

	free(p);
}

TREENODE* insert_BST_Node(TREENODE** p, char x) {
	TREENODE* newNode = NULL;
	TREENODE* cur = *p;
	TREENODE* q = NULL;

	// Ž�� ����
	while (cur != NULL) {
		if (cur->key == x) {
			printf("�̹� ���� Ű�� �ֽ��ϴ�.\n");
			return NULL;
		}
		q = cur;
		if (x < cur->key) {
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}

	// key�� Ʈ���ȿ� �����Ƿ� ���԰���
	newNode = (TREENODE*)calloc(1, sizeof(TREENODE));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	// �θ� ���� ��ũ ����
	if (q != NULL) {
		if (x < q->key) {
			q->left = newNode;
		}
		else {
			q->right = newNode;
		}
	}
	else {  // ��尡 �ϳ��� ���� ��쿡
		*p = newNode;
	}
	return *p;
}

/*
 * ����Ʈ���� ���� ���
 */
int getHeight(TREENODE* p) {
	int height = 0;
	if (p != NULL) {
		height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	}
	return height;
}

/*
 * ����Ž��Ʈ��, AVL Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
 */
TREENODE* searchNode(TREENODE* root, char x) {
	TREENODE* p = NULL;
	int count = 0;

	p = root;
	while (p != NULL) {

		count++;		// �˻�Ƚ�� �ľ�

		if (x < p->key) {
			p = p->left;
		}
		else if (x == p->key)
		{
			printf("%3d��°�� Ž�� ����", count);
			return p;
		}
		else
		{
			p = p->right;
		}
	}
	count++;

	printf("\n %3d��°�� Ž�� ����, ã�� Ű�� �����ϴ�.!\n", count);
	return p;
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
void displayInorder(TREENODE* root) {
	if (root) {
		displayInorder(root->left);
		printf("_%d", root->key);
		displayInorder(root->right);
	}
}

TREENODE* LL_rotate(TREENODE* parent) {
	TREENODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}


TREENODE* RR_rotate(TREENODE* parent) {
	TREENODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;

}


TREENODE* LR_rotate(TREENODE* parent)
{
	TREENODE* child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}


TREENODE* RL_rotate(TREENODE* parent)
{
	TREENODE* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

int getBF(TREENODE* p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}


TREENODE* rebalance(TREENODE** p)
{
	int BF = getBF(*p);

	if (BF > 1)
	{
		if (getBF((*p)->left) >= 0) *p = LL_rotate(*p);
		else *p = LR_rotate(*p);
	}
	else if (BF < -1)
	{
		if (getBF((*p)->left) <= 0) *p = RR_rotate(*p);
		else *p = LR_rotate(*p);
	}
	return *p;
}

void delete_AVL_Node(TREENODE** root, element key) {
	delete_BST_Node(root, key);
	*root = rebalance(root);
}



TREENODE* insert_AVL_Node(TREENODE** root, element x) {
	if (*root == NULL)
	{
		*root = (TREENODE*)calloc(1, sizeof(TREENODE));
		(*root)->key = x;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (x < (*root)->key)
	{
		(*root)->left = insert_AVL_Node(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x > (*root)->key)
	{
		(*root)->right = insert_AVL_Node(&((*root)->right), x);
		*root = rebalance(root);
	}
	else return NULL;
	return *root;
}

void testAVLTest_ClassVersion()
{
	int cnt_i;
	int data;
	TREENODE* root_AVL = NULL;
	TREENODE* root_BST = NULL;

	srand(time(NULL));
	printf("\n ========================= AVLƮ�� ���� =====================");
	for (cnt_i = 0; cnt_i < 8; cnt_i++)
	{
		insert_AVL_Node(&root_AVL, cnt_i);
		printf("\nInsert %d\n", cnt_i);
		showTree(root_AVL);
		getchar();
	}
	printf("\n ========================= AVLƮ�� ��� =====================");
	displayInorder(root_AVL);

	printf("\n ========================= AVLƮ�� ���� =====================");
	for (cnt_i = 0; cnt_i < 8; cnt_i++)
	{
		delete_AVL_Node(&root_AVL, cnt_i);
		showTree(root_AVL);
	}
	getchar();
	printf("\n ========================= BSTƮ�� ���� =====================");

	for (cnt_i = 0; cnt_i < 8; cnt_i++)
	{
		insert_BST_Node(&root_BST, cnt_i);
		showTree(root_BST);
	}

	printf("\n ========================= BSTƮ�� ��� =====================");
	displayInorder(root_BST);

	printf("\n ========================= BSTƮ�� ���� =====================");
	for (cnt_i = 0; cnt_i < 8; cnt_i++)
	{
		delete_BST_Node(&root_BST, cnt_i);
		showTree(root_BST);
	}





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

	// level order ������ treeArray�� ����� ������ ����
	pos = 1;
	for (cnt_i = 1; cnt_i <= height; cnt_i++) {
		printGivenLevel(node, cnt_i, treeArray, pos);
	}

	// ��ĭ�� �������� �̵�
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
int main()
{

	testAVLTest_ClassVersion();

	getchar();

	return 0;
}
