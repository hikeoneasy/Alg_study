#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>


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
		printf("%c: %d\n", i + 97, frequency[i]);

	}
	printf("\nBye!");
	free(INPUT);
}




#define MAXSTRLEN 32
typedef struct _LIST_NODE_ {
	char data[MAXSTRLEN];
	struct _LIST_NODE_* link;
}LIST_NODE;


typedef struct _LINKEDLIST_H_ {
	LIST_NODE* head;
	//int numOfNodes;
}LINKEDLIST_H;


LINKEDLIST_H* create(void)
{
	LINKEDLIST_H* L = NULL;
	L = (LINKEDLIST_H*)calloc(1, sizeof(LINKEDLIST_H));
	if(L == NULL) return 0;
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
	if(newNode == NULL) return;
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
	if(newNode == NULL) return;

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
	if(newNode == NULL) return;

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
	if(newNode == NULL) return;
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
		printf("%s", p->data);
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
	if(newNode == NULL) return;
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



#define TRUE 1
#define FALSE 0


typedef int element;

typedef struct _STACKNODE_ {
	element data;
	struct _STACKNODE_* link;
}stackNode;

stackNode* top;


void init()
{
	top = NULL;
}


int isEmpty()
{
	if (top == NULL) return TRUE;
	else return FALSE;
}


void push(element item)
{
	stackNode* temp = (stackNode*)calloc(1, sizeof(stackNode));
	if (temp == NULL) return;
	temp->data = item;
	temp->link = top;
	top = temp;
}
element peek()
{

	if (top == NULL)
	{
		printf("Stack is empty");
		return 0;
	}
	else
	{
		return (top->data);
	}
}
element pop()
{
	element item;
	stackNode* temp = top;

	if (top == NULL)
	{
		printf("\n\n Stack is empty ! \n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}


void printStack()
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p)
	{
		printf("%c ", p->data);
		p = p->link;
	}
	printf("] ");
}


void freestack()
{
	stackNode* pre = NULL;
	stackNode* cur = NULL;

	pre = cur = top;
	while (cur != NULL)
	{
		pre = cur;
		cur = cur->link;
		free(pre);
		pre = NULL;
	}
	top = NULL;
}

int testPair(char* exp)
{
	char symbol, open_pair;

	int i; int length = (int)strlen(exp);

	top = NULL;

	for (i = 0; i < length; i++)
	{
		//printStack();

		symbol = exp[i];
		switch (symbol) {

		case '(':
		case '[':
		case '{':
			push(symbol); break;

		case ')':
		case ']':
		case '}':
			if (top == NULL) return FALSE;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') || (open_pair == '[' && symbol != ']') || (open_pair == '{' && symbol != '}'))
					return FALSE;
				else break;
			}


		}

	}
	if (top == NULL) return TRUE;
	else return FALSE;
}

int precedence(char op)
{
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	}
	return -1;
}


void infix_to_postfix(char* infix, char* postfix)
{
	int cnt_i = 0;
	int cnt_j = 0;


	char c, op;

	while (infix[cnt_i] != '\0')
	{
		c = infix[cnt_i++];
		if (c >= '0' && c <= '9')
		{
			postfix[cnt_j++] = c;
			while (infix[cnt_i] >= '0' && infix[cnt_i] <= '9')
			{
				postfix[cnt_j++] = infix[cnt_i++];
			}
			postfix[cnt_j++] = ' ';
		}
		else if (c == '(')  push(c);
		else if (c == ')')
		{
			while (!isEmpty())
			{
				op = pop();
				if (op == '(') break;
				else
				{
					postfix[cnt_j++] = op;
					postfix[cnt_j++] = ' ';
				}
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		{
			while (!isEmpty())
			{
				op = peek();
				if (precedence(c) <= precedence(op))
				{
					op = pop();
					postfix[cnt_j++] = op;
					postfix[cnt_j++] = ' ';
				}
				else break;
			}
			push(c);
		}
	}
	while (!isEmpty()) {
		postfix[cnt_j++] = pop();
		postfix[cnt_j++] = ' ';
	}
	postfix[cnt_j] = '\0';
}



int evalPostfix(char* exp)
{
	int ope1, ope2, value, i;
	int len = (int)strlen(exp);

	char symbol;

	top = NULL;

	for (i = 0; i < len; i++)
	{
		symbol = exp[i];

		if (symbol >= '0' && symbol <= '9')
		{
			value = symbol - '0';
			i += 1;
			while (exp[i] >= '0' && exp[i] <= '9')
			{
				value *= 10;
				value += (exp[i] - '0');
				i += 1;
			}
			push(value);
		}
		else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%')
		{
			ope2 = pop();
			ope1 = pop();

			switch (symbol)
			{
			case '+': push(ope1 + ope2); break;
			case '-': push(ope1 - ope2); break;
			case '*': push(ope1 * ope2); break;
			case '/': push(ope1 / ope2); break;
			case '%': push(ope1 % ope2); break;
			}
		}
	}
	return pop();
}



void test3()
{
	int result;
	char infix_expr[13][80] = { "3*5-6/2", "((4+2)/4)-(3+70/(7*5))", "((((5*6)+7)-8)*9)", "((((5*6)+7)-8)*9)+(9+8)*7", "((((5*6)+7)-8)*9)+(((9+8)*7)%4)", "(((((((((1*2)*3)*4)*5)*6)*7)*8)*9)*10)", "1*2+3*4+6/2+8%3+9-8", "70+80*9-10+(60+70+80*2-10)", "(9-(4/2+1))*(5*2-2)", "((80*87)/4)*2-705", "100*((90-80+20*5)-(30*20-10/5))", "(9-(4/2+1+(10*5)+7*6))*(50*20-10%2)", "123+456*(789+(90-80+20*5)-(30*20-10/5))", };
	char postfix_expr[320] = { 0x00, };

	for (int i = 0; i < 13; i++)
	{
		printf("[%02d]-th 수식평가\n", i);
		if (testPair(infix_expr[i]) == 1)
			printf("괄호 개수가 일치함\n");
		else
			printf("괄호 개수가 불일치함\n");

		memset(postfix_expr, 0, sizeof(postfix_expr));

		init();
		infix_to_postfix(infix_expr[i], postfix_expr);

		printf("\n\ninfix: %s -> postfix: %s\n", infix_expr[i], postfix_expr);

		printf("후위 표기식 : %s", postfix_expr);

		result = evalPostfix(postfix_expr);
		printf("\n\n연산결과 => %d\n\n", result);
		freestack();
	}
}









int main()
{
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();

	return 0;
}