#include <stdio.h>


#if 1

int main()
{
	int N = 0; int n; int k; int tmp = 0;
	scanf("%d", &N);

	int ans = N;
	for (int i = 0; i < N; i++)
	{
		n = i;
		k = 0;
		tmp = n;
		while (n != 0)
		{
			k = n % 10;
			tmp += k;
			n /= 10;
		}

		
		if ((tmp == N) && (ans > i)) 
		{
			ans = i;
			
		}
	}
	if (ans == N) ans = 0;
	printf("%d", ans);

	return 0;
}
#endif
