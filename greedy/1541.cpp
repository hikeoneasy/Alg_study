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

			if (Input[i] == '-') flag = 1; //음수가 나온뒤 부터는 계속 뺴주면 된다.
		}

		else 
		{
			num[j] = Input[i];  //숫자 문자들을 num에 저장해준다.
			j++;
		}

		i++;

	}

	//맨 마지막 숫자 문자에 대한 연산을 처리해준다.

	if (flag) result -= atoi(num);

	else result += atoi(num);

	printf("%d", result);
	return 0;
}