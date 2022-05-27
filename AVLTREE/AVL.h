#pragma once

#define TRUE	1
#define FALSE	0

typedef int element;
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

void showTree(TREENODE* node);

// EOF

