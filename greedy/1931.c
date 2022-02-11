#include <stdio.h>
#include <stdlib.h>




typedef struct {
    int start;
    int end;
} meet;


int cmp(const void* x, const void * y)
{
    const meet* a, *b;
    a = (const meet*)x;
    b = (const meet*)y;

    if(a->end != b->end)
    {
        if(a->end < b->end) return -1;
        else return 1;
    }
    else
    {
        if(a->start < b->start) return -1;
        else if (a->start == b->start) return 0;
        else return 1;
    }

}

int main()
{
    int N = 0;
    scanf("%d",&N);
    meet* meeting;
    meeting = (meet*)calloc(N,sizeof(meet));
    if(meeting == NULL) return -1;

    for(int i=0;i<N;i++) scanf("%d %d", &meeting[i].start, &meeting[i].end);

    qsort(meeting, N, sizeof(meet), cmp);


    //for(int i=0;i<N;i++) printf("%d %d\n", meeting[i].start,meeting[i].end);

    int tmp = 0;int cnt =0;
    for(int i=0;i<N;i++)
    {
        if(tmp <= meeting[i].start)
        {
            tmp = meeting[i].end;
            cnt++;
        }
    }

    printf("%d\n",cnt);



    return 0;
}