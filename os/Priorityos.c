#include <stdio.h>

typedef struct
{
    int id, at, bt, pr, ct, tat, wt;
} Process;

void sortProcesses(Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].pr > p[j + 1].pr)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void findCompletionTime(Process p[], int n)
{
    p[0].ct = p[0].bt;
    for (int i = 1; i < n; i++)
    {
        p[i].ct = p[i].bt + p[i - 1].ct;
    }
} 

void findTurnAroundTime(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
    }
}

void findWaitingTime(Process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void findAverageTime(Process p[], int n)
{
    int totalTat = 0, totalWt = 0;
    findCompletionTime(p, n);
    findTurnAroundTime(p, n);
    findWaitingTime(p, n);

    printf("Process\tArrival Time\t Burst Time\t Priority\t Completion Time\t Turnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
        totalTat += p[i].tat;
        totalWt += p[i].wt;
    }
    printf("Average turnaround time = %.2f\n", (float)totalTat / n);
    printf("Average waiting time = %.2f\n", (float)totalWt / n);
}

void main()
{
    Process proc[] = {{1, 0, 4, 3}, {2, 1, 3, 2}, {3, 3, 2, 1}, {4, 5, 1, 4}, {5, 6, 4, 2}};
    int n = sizeof(proc) / sizeof(proc[0]);
    sortProcesses(proc, n);

    int j = 0, totalBt = 0, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalBt += proc[i].bt;
    }
    Process p[30];
    while (currentTime < totalBt)
    {
        for (int i = 0; i < n; i++)
        {
            if (proc[i].at <= currentTime && proc[i].at > -1)
            {
                p[j] = proc[i];
                j++;
                proc[i].at=-1;
                break;
            }
        }
        currentTime += p[j - 1].bt;
    }

    findAverageTime(p, n);
}