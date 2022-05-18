
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

TREENODE* searchNode(TREENODE* root, char x);			// �ݺ��� ���
TREENODE* searchNode_recur(TREENODE* root, char x);		// ����� ���

void insertNode(TREENODE** p, char x);					// �ݺ��� ���
TREENODE* insertNode_recur(TREENODE* p, char x);		// ��ȯ��(�����) ���

void deleteNode(TREENODE** root, element key);			// �ݺ������
TREENODE* deleteNode_recur(TREENODE* root, int key);			// �����

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

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
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

void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : Ʈ�� ���");
	printf("\n\t2 : ���� ����");
	printf("\n\t3 : ���� ����");
	printf("\n\t4 : ���� �˻�");
	printf("\n\t5 : ����");
	printf("\n*---------------------------*");
	printf("\n�޴��Է� >> ");
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
		if (choice - '0' < 1) { printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n"); break; }
		switch (choice - '0') {
		case 1:	printf("\t[���� Ʈ�� ���]  ");
			displayInorder(root);  printf("\n");
			showTree(root);
			break;

		case 2:	printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			insertNode(&root, key);
			displayInorder(root);  printf("\n");
			showTree(root);
			break;

		case 3:	printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);

			break;

		case 4: printf("ã�� ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			//searchNode_recur(root, key);
			//�̰� ��� �޾ƿͼ� �������� �����ϱ� 
			break;

		case 5: 	return 0;

		default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}
	}
	return 0;
}

// EOF
