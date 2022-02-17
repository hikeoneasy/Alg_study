#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>



int main() {

	
	int N=0,M=0;
	int arr[100] = { 0, };
	int tmp = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);


	int tmp2 = 0; int ans = 0;

	for (int i = N - 1; i >= 2; i--) {

		for (int j = i-1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				tmp2 = arr[i] + arr[j] + arr[k];
				if (tmp2 <= M && tmp2 > ans)
				{
					ans = tmp2;
				}

			}
			
		}

	}

	printf("%d", ans);











	return 0;
}








