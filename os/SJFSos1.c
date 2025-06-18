/*#include <stdio.h>
#include <stdbool.h>

// Structure to represent a process
struct Process {
    int pid; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
};

// Function to sort processes based on burst time
void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                // Swap processes[j] and processes[j + 1]
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n, int wt[], int tat[]) {
    wt[0] = 0;
    tat[0]=wt[0]+processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + processes[i - 1].burst_time;
        tat[i] = wt[i] + processes[i].burst_time;
    }
}

// Function to calculate average waiting time and turnaround time
void calculateAvgTimes(struct Process processes[], int n) {
    int wt[n], tat[n];
    calculateTimes(processes, n, wt, tat);

    float avg_wt = 0, avg_tat = 0;
    printf("PID \tWT \tTAT\n");
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("%d\t %d\t %d\n",processes[i].pid,wt[i],tat[i]);
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

    // Sort processes based on burst time
    sortProcesses(processes, n);
        // Calculate average waiting time and turnaround time
    calculateAvgTimes(processes, n);

    return 0;
}
*/
#include <stdio.h>

typedef struct{
    int id,at,bt,ct,tat,wt;
} Process;

void sortProcesses(Process p[], int n){
    Process temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void findCompletionTime(Process p[], int n){
    p[0].ct=p[0].bt;
    for(int i=1;i<n;i++){
        p[i].ct=p[i].bt+p[i-1].ct;
    }
} 

void findTurnAroundTime(Process p[], int n){
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
    }
}

void findWaitingTime(Process p[], int n){
    for(int i=0;i<n;i++){
        p[i].wt=p[i].tat-p[i].bt;
    }
}

void findAverageTime(Process p[], int n){
    findCompletionTime(p,n);
    findTurnAroundTime(p,n);
    findWaitingTime(p,n);
    
    int ttat=0, twt=0;
    
    printf("ID AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){
        printf("%d %d %d %d %d %d\n",p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        ttat+=p[i].tat;
        twt+=p[i].wt;
    }
    printf("Averge TAT= %.2f", (float)ttat/n);
    printf("Averge WT= %.2f", (float)twt/n);
}

void main()
{
    Process proc[]={{1,0,4},{2,1,3},{3,3,2},{4,5,1},{5,6,4}};
    int n = sizeof(proc) / sizeof(proc[0]);
    sortProcesses(proc, n);

    int j = 0, totalBt = 0, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        totalBt += proc[i].bt;
    }
    Process p[] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    while(currentTime<=totalBt){
        for(int i=0;i<n;i++){
            if(proc[i].at<=currentTime && proc[i].at!=-1){
                p[j]=proc[i];
                j++;
                proc[i].at=-1;
                break;
            }
        }
        currentTime+=p[j-1].bt;
    }
    findAverageTime(p,n);
}