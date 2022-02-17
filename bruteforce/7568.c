#include <stdio.h>

typedef struct{
    int x;
    int y;
}Body;

int main()
{
    Body body[50]; 
    int N = 0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d %d", &body[i].x, &body[i].y);
    
    int cnt;
    for(int i=0;i<N;i++)
    {
        cnt = 0;
        for(int j=0;j<N;j++)
        {
            if(body[i].x<body[j].x && body[i].y<body[j].y) cnt++;
        }
        printf("%d ",cnt+1);

    }


    return 0;
}