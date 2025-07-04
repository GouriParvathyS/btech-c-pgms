/*#include <stdio.h>
#include <stdlib.h>
// Structure to represent a process
struct Process {
    int id;
    int burst_time;
};
// Function to simulate Round Robin scheduling
void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_time[n];
    int wt[n],tat[n];
    for (int i = 0; i < n; ++i){
        remaining_time[i] = processes[i].burst_time;
        }
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (remaining_time[i] > 0) {
                flag = 1;
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    printf("Process P%d completed at time %d\n", processes[i].id, current_time);
                    tat[i]=current_time;
                    wt[i]=tat[i]-processes[i].burst_time;
                    printf("Process P%d WT=%d TAT=%d\n",processes[i].id,wt[i],tat[i]);
                    completed++;
                } else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
        if (!flag)
            break;
    }
    float awt=0;
    float atat=0;
    for(int i=0;i<n;i++)
    {
        awt=awt+wt[i];
        atat=atat+tat[i];
    }
    printf("Average WT=%f Average TAT=%f",awt/n,atat/n);
    
}
int main() {
    int n = 3; // Number of processes
    struct Process processes[] = {{1, 4}, {2, 3}, {3, 5}};
    int time_quantum = 2;

    printf("Round Robin Scheduling:\n");
    roundRobin(processes, n, time_quantum);
    return 0;
}
*/
#include <stdio.h>

typedef struct
{
    int id, at, bt, rt, ct, tat, wt;
} Process;

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
    findTurnAroundTime(p, n);
    findWaitingTime(p, n);

    printf("Process\tArrival Time\t Burst Time\tCompletion Time\t Turnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totalTat += p[i].tat;
        totalWt += p[i].wt;
    }
    printf("Average turnaround time = %.2f\n", (float)totalTat / n);
    printf("Average waiting time = %.2f\n", (float)totalWt / n);
}

void main()
{
    Process proc[] = {{1, 0, 8}, {2, 1, 4}, {3, 2, 9}, {4, 3, 5}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int quantum = 2;

    int j = 0, totalBt = 0, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalBt += proc[i].bt;
        proc[i].rt = proc[i].bt;
    }
    Process p[20];
    Process q[100];
    int i = 0, k = 0, m = 0;
    while (currentTime < totalBt)
    {
        while (m < n && proc[m].at <= currentTime)
        {
            q[k] = proc[m];
            k++;
            m++;
        }
        if (i != 0 && q[i - 1].rt != 0)
        {
            q[k] = q[i - 1];
            k++;
        }
        if (q[i].rt <= quantum)
        {
            p[j] = q[i];
            currentTime += q[i].rt;
            p[j].ct = currentTime;
            j++;
            q[i].rt = 0;
        }
        else
        {
            q[i].rt -= quantum;
            currentTime += quantum;
        }
        i++;
    }
    findAverageTime(p, n);
}
