#include <stdio.h>

int tmp[1000] ={0,};

void Merge(int arr[],int start, int end, int middle)
{
    int i=0,j=0,k=0;
    i = start;
    j = middle+1;
    k = start;


    while(i<=middle && j<= end)
    { 
        if(arr[i]<=arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }
    if(i>middle)
    {
        for(int l=j;l<=end;l++)
        {
            tmp[k++] = arr[l];
        }
    }

    else
    {
        for(int l=i;l<=middle;l++)
        {
            tmp[k++] = arr[l];
        }
    }

    for(int l=start;l <= end;l++)
    {
        arr[l] = tmp[l];
    }
}


void MergeSort(int arr[], int start, int end)
{
    int middle = 0;
    if (start < end) {
        middle = (start + end) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);
        Merge(arr, start, end, middle);

    }
    
}
int main()
{
    int a = 0;
    int time[1000] = {0,};
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&time[i]);
    }

    MergeSort(time,0,a-1);


    
#if 1
    int ans = 0;
    int buf = 0;
    for(int i=0;i<a;i++)
    {
        buf += time[i];
        ans += buf;
    }
    printf("%d",ans);
#endif







    return 0;
}

