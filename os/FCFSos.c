/*#include <stdio.h>

typedef struct {
    int pid, bt, at;
} Process;

void findWaitingTime(Process processes[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = processes[i-1].bt + wt[i-1] - processes[i].at + processes[i-1].at;
}

void findTurnAroundTime(Process processes[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + processes[i].bt;
}

void findAvgTime(Process processes[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, wt);
    findTurnAroundTime(processes, n, wt, tat);

    printf("Processes\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].at, processes[i].bt, wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    Process processes[] = {{1, 8, 8}, {2, 1, 6}, {3, 3, 2}};
    int n = sizeof(processes) / sizeof(processes[0]);
    int tbt = 0;
    int current = 0;
    int processed[n];
    Process proc[n];
    for (int i = 0; i < n; i++)
    {
        tbt += processes[i].bt;
        proc[i] = (Process){0, 0, 0};
        processed[i]=1;
    }
    int j = 0;
    
    while(current <= tbt) {
        for(int i = 0; i < n; i++) {
            if(processes[i].at <= current && processed[i] != 0) {
                proc[j] = processes[i];
                j++;
                processed[i]=0;
                break;
            }    
        }
        if(j > 0)
            current += proc[j-1].bt;
        else
            current++;
    }

    findAvgTime(proc, n);
    return 0;
}
*/
#include <stdio.h>

int main() {
    int n, i;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    // Input: number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n], completion_time[n];
    
    // Input: arrival time and burst time for each process
    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    
    // Initial calculations
    waiting_time[0] = 0;
    completion_time[0] = arrival_time[0] + burst_time[0];
    turnaround_time[0] = burst_time[0];
    
    // Calculating waiting time, turnaround time, and completion time for each process
    for (i = 1; i < n; i++) {
        // Completion time for current process
        completion_time[i] = completion_time[i - 1] + burst_time[i];
        
        // Waiting time for current process
        waiting_time[i] = completion_time[i - 1] - arrival_time[i];
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0; // If process arrives after completion of previous, it waits zero time.
            completion_time[i] = arrival_time[i] + burst_time[i];
        }

        // Turnaround time
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }
    
    // Displaying results and calculating averages
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    
    return 0;
}
