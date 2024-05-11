#include <stdio.h>

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Gantt Chart:\n");
    
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime)
        {
            currentTime = processes[i].arrivalTime;
        }

        printf("%d-P%d-%d ", currentTime, processes[i].processID, currentTime + processes[i].burstTime);

        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        currentTime = processes[i].completionTime;
    }

    printf("\n\nProcessID\tArrival-Time\tBurst-Time\tCompletion-Time\tTurnaround-Time\tWaiting-Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\n", processes[i].processID, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].completionTime, processes[i].turnaroundTime,
               processes[i].waitingTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    calculateTimes(processes, n);

    return 0;
}
