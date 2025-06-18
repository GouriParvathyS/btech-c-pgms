/*#include <stdio.h>
#include <stdlib.h>
typedef struct Process{
    int id, at, bt, pr, ct, tat, wt;
}Process;
void sortA(Process p[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].pr>p[j+1].pr)
            {
                Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void completion(Process p[],int n)
{
    p[0].ct=p[0].bt;
    for(int i=1;i<n;i++)
    {
        p[i].ct=p[i-1].ct+p[i].bt;
    }
}
void tat(Process p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
    }
}
void wt(Process p[],int n)
{
    for(int i=0;i<n;i++)
    {
        p[i].wt=p[i].tat-p[i].bt;
    }
}
void avg(Process p[],int n)
{
    int atat=0;
    int twt=0;
    completion(p,n);
    tat(p,n);
    wt(p,n);
    printf("id\tat\tbt\tpr\tct\ttat\twt\n");
    for (int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
    }
    for (int i=0;i<n;i++)
    {
        atat+=p[i].tat;
        twt+=p[i].wt;
    }
    printf("atat=%d\n",atat);
    printf("twt=%d\n",twt);
}
void main(){
    Process proc[]={{1, 0, 4, 3}, {2, 1, 3, 2}, {3, 3, 2, 1}, {4, 5, 1, 4}, {5, 6, 4, 2}};
    Process p[30];
    int n=sizeof(proc)/sizeof(proc[0]);
    sortA(proc,n);
    int tbt=0;
    for(int i=0;i<n;i++)
    {
        tbt+=proc[i].bt;
    }
    int currentTime=0;
    int j=0;
    while(currentTime<tbt)
    {
        for (int i = 0; i < n; i++)
        {
            if(currentTime>=proc[i].at && proc[i].at>-1)
            {
                p[j]=proc[i];
                j++;
                proc[i].at=-1;
                break;
            }
        }
        currentTime+=p[j-1].bt;
    }
    avg(p,n);
}*/
/*-----------------------------------------------------------------------------------------------------------------------*/
/*#include <stdio.h>
#include <stdlib.h>
typedef struct Process{
    int id, bt, tat, wt;
}Process;
void rr(Process p[],int n,int tq)
{
    int completed=0;
    int remainingtime[n];
    int currentTime=0;
    for(int i=0;i<n;i++)
    {
        remainingtime[i]=p[i].bt;
    }
    while(completed<n)
    {
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(remainingtime[i]>0)
            {
                flag=1;
                if(remainingtime[i]<=tq)
                {
                    currentTime+=remainingtime[i];
                    remainingtime[i]=0;
                    printf("Process %d completed at time %d\n",p[i].id,currentTime);
                    p[i].tat=currentTime;
                    p[i].wt=p[i].tat-p[i].bt;
                    completed++;
                }
                else{
                    currentTime+=tq;
                    remainingtime[i]-=tq;
                                        
                }
            }
        }
        if(!flag)
        {
            break;
        }
    }
    float awt=0;
    float atat=0;
    for(int i=0;i<n;i++)
    {
        awt=awt+p[i].wt;
        atat=atat+p[i].tat;
    }
    printf("Average WT=%f Average TAT=%f",awt/n,atat/n);
    
}
int main() {
    int n = 3; // Number of processes
    struct Process processes[] = {{1, 4}, {2, 3}, {3, 5}};
    int time_quantum = 2;

    printf("Round Robin Scheduling:\n");
    rr(processes, n, time_quantum);
    return 0;
}*/
/*-----------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
int main()
{
    int n, m, i, j, k, y, alloc[20][20], max[20][20], avail[50], ind = 0;
    printf("Enter the no of Proceses:");
    scanf("%d", &n);
    printf("Enter the no of Resources:");
    scanf("%d", &m);
    printf("Enter the Allocation Matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("Enter the Max Matrix:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    printf("Enter the Available Matrix");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);
    int finish[n], safesequence[n], work[m], need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("NEED matrix is");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < m; j++)
            printf(" %d ", need[i][j]);
    }
    for (i = 0; i < m; i++)
    {
        work[i]=avail[i];
    }
    for (i = 0; i < n; i++)
    {
        finish[i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if (finish[i]==0)
            {
                int flag=0;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                     safesequence[ind++] = i;
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    finish[i] = 1

                }
            }
        }
    }