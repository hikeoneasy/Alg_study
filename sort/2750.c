#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int left, int right)
{
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot >= arr[low]) low++;
		while (high >= (left+1) && pivot <= arr[high]) high--;

		if (low <= high) swap(arr, low, high);

	}
	swap(arr, left, high);
	return high;
}
void QuickSort(int arr[], int left, int right)
{
	
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot-1);
		QuickSort(arr, pivot+1, right);
	}




}

int main()
{
	int size = 0;
	scanf("%d", &size);
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL) return 0;
	for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

	QuickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) printf("%d\n", arr[i]);


	return 0;
}