/*#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a process
struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
};

// Function to find the process with the shortest remaining burst time
int findShortestJob(struct Process processes[], int n, int current_time,int rt[]) {
    int shortest_job = -1;
    int min_burst_time = INT_MAX;

    for (int i = 0; i <n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].burst_time <= min_burst_time && rt[i]!=0) {
            min_burst_time = processes[i].burst_time;
            shortest_job = i;
        }
    }

    return shortest_job;
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n, int wt[], int tat[]) {
    int remaining_time[n];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int completed = 0;
    int current_time = 0;
  int shortest_jobs[50];
  int i=0;
    while (completed < n) {
        int shortest_job = findShortestJob(processes, n, current_time,remaining_time);
        printf("Executing P%d\n",shortest_job); 
        shortest_jobs[i++]=shortest_job;
        if (shortest_job == -1) {
            current_time++;
            continue;
        }

        //if (remaining_time[shortest_job] == processes[shortest_job].burst_time)
        //    {wt[shortest_job] = current_time - processes[shortest_job].arrival_time;}

        remaining_time[shortest_job]--;
        current_time++;

        if (remaining_time[shortest_job] == 0) {
            tat[shortest_job] = current_time - processes[shortest_job].arrival_time;
            wt[shortest_job]=tat[shortest_job]-processes[shortest_job].burst_time;
            completed++;
        }
      
    }
}

// Function to calculate average waiting time and turnaround time
void calculateAvgTimes(struct Process processes[], int n) {
    int wt[n], tat[n];
    calculateTimes(processes, n, wt, tat);
    printf("WT \t TAT\n");
   for(int i=0;i<n;i++)
     printf("%d\t %d\n",wt[i],tat[i]);
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Average waiting time = %.2f\n", avg_wt / n);
    printf("Average turnaround time = %.2f\n", avg_tat / n);
}

int main() {
    int n = 5; // Number of processes
    struct Process processes[] = {
        {1, 0, 8},
        {2, 1, 1},
        {3, 2, 3},
        {4, 3, 2},
        {5, 4, 6}
    };

    // Calculate average waiting time and turnaround time
    calculateAvgTimes(processes, n);

    return 0;
}*/
#include <stdio.h>

typedef struct
{
    int id, at, bt, rt, ct, tat, wt;
} Process;

void sortProcesses(Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
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
    sortProcesses(proc, n);

    int j = 0, totalBt = 0, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalBt += proc[i].bt;
        proc[i].rt = proc[i].bt;
    }
    Process p[] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    while (currentTime <= totalBt)
    {
        for (int i = 0; i < n; i++)
        {
            if (proc[i].at <= currentTime && proc[i].at > -1)
            {
                proc[i].rt=proc[i].rt-1;
                if (proc[i].rt == 0)
                {
                    p[j] = proc[i];
                    p[j].ct=currentTime+1;
                    j++;
                    proc[i].at = -1;
                }
                break;
            }
        }
        currentTime++;
    }

    findAverageTime(p, n);
}