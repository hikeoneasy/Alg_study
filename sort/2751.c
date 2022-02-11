
#include <stdio.h>
#include <stdlib.h>


# define MAX_SIZE 1000001
int tmp[MAX_SIZE];



void Merge(int arr[], int start, int end, int middle)
{
    int i = 0, j = 0, k = 0;

    i = start;
    j = middle + 1;
    k = start;

    


    while (i <= middle && j <= end)
    {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];

        else tmp[k++] = arr[j++];
    }

    if (i > middle)
    {
        for (int l = j; l <= end; l++)
        {
            tmp[k++] = arr[l];
        }
    }

    else
    {
        for (int l = i; l <= middle; l++)
        {
            tmp[k++] = arr[l];
        }
    }

    for (int l = start; l <= end; l++)
    {
        arr[l] = tmp[l];
    }
}
void MergeSort(int arr[], int start, int end)
{
    int middle = 0;
    if (start < end)
    {
        middle = (start + end) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);
        Merge(arr, start, end, middle);
    }
}

int main()
{
    int SIZE = 0;
    scanf("%d", &SIZE);
    int* arr = NULL;
    arr = (int*)malloc(sizeof(int) * SIZE);
    if (arr == NULL) return 0;

    for (int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);

    MergeSort(arr, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
