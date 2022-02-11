#include <stdio.h>


int main()
{
	int cnt = 0;
	int arr[11] = { 0, };
	int N = 0; int K = 0;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	int NUM = K;
	int iterator = N - 1;

	while (NUM != 0)
	{
		if (NUM > arr[iterator])
		{
			cnt += NUM / arr[iterator];
			NUM %= arr[iterator];
		}
		else
		{
			iterator--;
		}
	}

	printf("%d\n", cnt);






	return 0;
}