#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*struct Process{
    int id;
    int burst_Time;
};
void RR(int timequantum,struct Process proc[] ,int n)
{
    int remaining[n];
    int wt[n], tat[n];
    for (int i=0;i<n;++i)
    {
        remaining[i]=proc[i].burst_Time;
    }
    int currentTime=0;
    int completed=0;
    while(completed<n){
        int flag=0;
        for(int i=0;i<n;i++){
            if(remaining[i]>0){
                flag=1;
                if(remaining[i]<=timequantum){
                    currentTime+=remaining[i];
                    remaining[i]=0;
                    printf("%d finished execution at time %d\n",i+1,currentTime);
                    tat[i]=currentTime;
                    wt[i]=tat[i]-proc[i].burst_Time;
                    printf("%d %d\n",wt[i],tat[i]);
                    completed++;
                }
                else{
                    currentTime+=timequantum;
                    remaining[i]-=timequantum;
                }
            }
        }
        if(!flag){
            break;
        }
    }
    int t=0,w=0;
    for(int i=0;i<n;i++)
    {
        t+=tat[i];
        w+=wt[i];
    }
    printf("%.2f is the Turnaround time average\n",t/n);
    printf("%f is the waiting time average\n",w/n);
}
int main()
{
   struct Process processs[]={{1,4} ,{2,3},{3,5} };
   int ti=2;
   RR(ti,processs,3);
   return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100

struct File {
    char filename[20];
    int start_block;
    int num_blocks;
};

void allocateContiguous(struct File* file, int startBlock, int numBlocks) {
    strcpy(file->filename, "my_file.txt");
    file->start_block = startBlock;
    file->num_blocks = numBlocks;
}

int main() {
    struct File myFile;

      allocateContiguous(&myFile, 10, 5);


    printf("File Name: %s\n", myFile.filename);
    printf("Start Block: %d\n", myFile.start_block);
    printf("Number of Blocks: %d\n", myFile.num_blocks);

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

// Structure to represent an index block
struct IndexBlock
{
    int data_blocks[MAX_BLOCKS];
};

// Function to initialize an index block
void initializeIndexBlock(struct IndexBlock *indexBlock)
{
    for (int i = 0; i < MAX_BLOCKS; ++i)
    {
        indexBlock->data_blocks[i] = -1; // Initialize with -1 (invalid block)
    }
}

// Function to allocate a data block for a file
int allocateDataBlock(struct IndexBlock *indexBlock, int blockNumber)
{
    for (int i = 0; i < MAX_BLOCKS; ++i)
    {
        if (indexBlock->data_blocks[i] == -1)
        {
            indexBlock->data_blocks[i] = blockNumber;
            return 1; // Successfully allocated
        }
    }
    return 0;
}
void readData(struct IndexBlock *indexBlock, int fileBlockNumber)
{
    int flag = 0;
    for (int i = 0; i < MAX_BLOCKS; i++)
    {
        if (indexBlock->data_blocks[i] != -1 && fileBlockNumber == indexBlock->data_blocks[i])
        {
            printf("Reading data from block %d\n", indexBlock->data_blocks[i]);
            flag = 1;
        }
    }

    if (flag == 0)
        printf("Block %d is not allocated.\n", fileBlockNumber);
}

int main()
{
    struct IndexBlock indexBlock;
    initializeIndexBlock(&indexBlock);

    // Allocate data blocks for a file (example)
    allocateDataBlock(&indexBlock, 5);
    allocateDataBlock(&indexBlock, 8);
    allocateDataBlock(&indexBlock, 12);
}