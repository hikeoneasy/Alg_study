#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char Input[51];
	char num[6] = { 0, };
	int i = 0, j = 0, result = 0, flag = 0;

	scanf("%s", Input);

	while (Input[i] != NULL) {
		if (Input[i] == '+' || Input[i] == '-')
		{
			if (flag) result -= atoi(num);
			
			else result += atoi(num);

			memset(num, NULL, 6);
			j = 0;

			if (Input[i] == '-') flag = 1; //������ ���µ� ���ʹ� ��� ���ָ� �ȴ�.
		}

		else 
		{
			num[j] = Input[i];  //���� ���ڵ��� num�� �������ش�.
			j++;
		}

		i++;

	}

	//�� ������ ���� ���ڿ� ���� ������ ó�����ش�.

	if (flag) result -= atoi(num);

	else result += atoi(num);

	printf("%d", result);
	return 0;
}