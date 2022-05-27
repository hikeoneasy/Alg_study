#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "AVL.h"

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
void displayInorder(TREENODE * root);
void delete_BST_Node(TREENODE** root, element key);
void delete_AVL_Node(TREENODE** root, element key);

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void delete_BST_Node(TREENODE** root, element key)
{
	TREENODE *parent = NULL, *p = NULL, *succ = NULL, *succ_parent = NULL;
	TREENODE *child = NULL;

	p = *root;

	// 삭제할 노드의 위치 탐색
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

	// 삭제할 노드가 없는 경우
	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다.!");
		return;
	}

	// p가 삭제할 노드임
	// 삭제할 노드가 단말 노드인 경우(차수 = 0)
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			// 삭제되는 노드가 부모의 왼쪽이라면
			// 부모의 왼쪽 자식이 NULL
			if (parent->left == p) {
				parent->left = NULL;
			}
			// 삭제되는 노드가 부모의 오른쪽이라면
			// 부모의 오른쪽 자식이 NULL
			else {
				parent->right = NULL;
			}
		}
		else // 만약 부모노드가 NULL이면 삭제되는 노드는 루트
		{
			*root = NULL;
		}
	}
	// 삭제할 노드가 자식 노드를 한 개 가진 경우(차수 = 1)
	else if ((p->left == NULL) || (p->right == NULL))
	{
		// p의 왼쪽 자식노드가 있는 경우
		if (p->left != NULL) {
			child = p->left;
		}
		// p의 오른쪽 자식노드가 있는 경우
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
		else {// 단 두개의 노드만 존재할 때, parent가 삭제되는 경우
			*root = child;
		}
	}
	// 삭제할 노드가 자식 노드를 두 개 가진 경우(차수 = 2)
	else {
		succ_parent = p;	// p는 삭제될 노드

							// 왼쪽 서브 트리에서 후계자 찾기
							// 왼쪽 서브 트리로 이동
		succ = p->left;
		// 왼쪽 서브트리의 가장 오른쪽 노드를 얻어옴
		while (succ->right != NULL)
		{
			succ_parent = succ;
			succ = succ->right;
		}
		// 후계자의 부모와 후계자의 자식을 연결
		if (succ_parent->left == succ) {	// 특수한 경우(처음부터 오른쪽 자식이 없는 경우)
			succ_parent->left = succ->left;
		}
		else {
			// 후계자의 왼쪽 서브트리를 부모의 오른쪽에 붙임
			// succ의 오른쪽 자식은 당연히 없음
			// 오른쪽 자식이 있으면 더 타고 들어갔을 것임
			succ_parent->right = succ->left;
		}
		p->key = succ->key;	// 후계자 키를 대체되는 노드에 복사(삭제할 노드를 삭제한 것과 동일한 효과)
		p = succ;			// 후계자 삭제
	}

	free(p);
}

TREENODE* insert_BST_Node(TREENODE** p, char x) {
	TREENODE* newNode = NULL;
	TREENODE* cur = *p;
	TREENODE* q = NULL;

	// 탐색 수행
	while (cur != NULL) {
		if (cur->key == x) {
			printf("이미 같은 키가 있습니다.\n");
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

	// key가 트리안에 없으므로 삽입가능
	newNode = (TREENODE*)calloc(1, sizeof(TREENODE));
	newNode->key = x;
	newNode->left = NULL;
	newNode->right = NULL;

	// 부모 노드와 링크 연결
	if (q != NULL) {
		if (x < q->key) {
			q->left = newNode;
		}
		else {
			q->right = newNode;
		}
	}
	else {  // 노드가 하나도 없는 경우에
		*p = newNode;
	}
	return *p;
}

/*
 * 서브트리의 높이 계산
 */
int getHeight(TREENODE* p) {
	int height = 0;
	if (p != NULL) {
		height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	}
	return height;
}

/*
 * 이진탐색트리, AVL 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
 */
TREENODE* searchNode(TREENODE* root, char x) {
	TREENODE* p = NULL;
	int count = 0;

	p = root;
	while (p != NULL) {
		
		count++;		// 검색횟수 파악

		if (x < p->key) {
			p = p->left;
		}
		else if (x == p->key)
		{
			printf("%3d번째에 탐색 성공", count);
			return p;
		}
		else
		{
			p = p->right;
		}
	}
	count++;

	printf("\n %3d번째에 탐색 실패, 찾는 키가 없습니다.!\n", count);
	return p;
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(TREENODE * root) {
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
	parent->right = child -> left;
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
	
}

int main()
{

	testAVLTest_ClassVersion();

	getchar();

	return 0;
}
