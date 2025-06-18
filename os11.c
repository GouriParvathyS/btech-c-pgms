#include <stdio.h>
#include <stdlib.h>
void bestfit(int blocksize[],int m,int processsize[],int n)
{
    int bestid;
    int allocation[n];
    for (int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for (int i=0;i<n;i++){
        bestid=-1;
        for (int j = 0; j < m; j++)
        {
            if(blocksize[j]>=processsize[i])
            {
                if (bestid=-1)
                {
                    bestid=j;
                }
                else if(blocksize[bestid]>blocksize[j])
                {
                    bestid=j;
                }
            }
        }
        if (bestid!=-1){
            allocation[i]=bestid;
            blocksize[bestid]=blocksize[bestid]-processsize[i];
        }
        
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processsize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("Free Blocks\n");
    for (int i = 0; i < m; i++) printf("%d->",blocksize[i]);
}
int main() {
    int blocksize[] = {100, 500, 200, 300, 600};
    int processsize[] = {212, 417, 112, 426};
    int m = sizeof(blocksize) / sizeof(blocksize[0]);
    int n = sizeof(processsize) / sizeof(processsize[0]);
    bestfit(blocksize, m, processsize, n);
    return 0;
}