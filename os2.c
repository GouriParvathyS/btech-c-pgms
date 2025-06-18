#include <stdio.h>
#include <string.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation)); 
   for (int i = 0; i < n; i++) {
    int bestIdx = -1;
    for (int j = 0; j < m; j++) {
      if (blockSize[j] >= processSize[i])
        { 
        if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) 
          bestIdx = j;
        }
    }
    if (bestIdx != -1) {
      allocation[i] = bestIdx;
      blockSize[bestIdx] -= processSize[i];
    }
  }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("Free Blocks\n");
   for (int i = 0; i < m - 1; i++) 
    printf("%d->", blockSize[i]);

    printf("%d\n", blockSize[m - 1]); 

}
int main() {
    int blockSize[] = {40, 50, 30, 120, 35};
    int processSize[] = {40, 10, 30, 60};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    printf("\t Block sizes \n");
    for(int i=0;i<m;i++)
    {
        printf("%d. %d\n",i+1,blockSize[i]);
    }

     printf("\t Process sizes \n");
    for(int i=0;i<m;i++)
    {
        printf("%d. %d\n",i+1,processSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}