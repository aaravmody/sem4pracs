//GPT kiya bohat easy ho gya samaj jayega pura

#include <stdio.h>
#define MAX_PROCESSES 5

// Process structure
struct Process {
    int id; // Process ID
    int arrival_time; // Arrival time
    int burst_time; // Burst time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time; // Waiting time
};

int main() {
    struct Process processes[MAX_PROCESSES];
    int n = MAX_PROCESSES; // Number of processes

    // Process data
    int arrival_times[MAX_PROCESSES] = {2, 5, 1, 0, 4};
    int burst_times[MAX_PROCESSES] = {6, 2, 8, 3, 4};

    int time = 0;
    int complete = 0;

    // Initialize processes
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrival_time = arrival_times[i];
        processes[i].burst_time = burst_times[i];
        processes[i].completion_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    // Sort processes by arrival time (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Simulate scheduling
    while (complete < n) {
        int min_burst = 1000;
        int min_index = -1;

        // Find process with minimum burst time among arrived processes
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].burst_time < min_burst && processes[i].completion_time == 0) {
                min_burst = processes[i].burst_time;
                min_index = i;
            }
        }

        // If a process is found
        if (min_index != -1) {
            printf("P%d\t%d\n", processes[min_index].id, time);
            time++;
            processes[min_index].burst_time--;

            // If burst time becomes 0, update completion time and other metrics
            if (processes[min_index].burst_time == 0) {
                processes[min_index].completion_time = time;
                processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
                processes[min_index].waiting_time = processes[min_index].turnaround_time - burst_times[min_index];
                complete++;
            }
        } else {
            // If no process is available, move time forward
            time++;
        }
    }

    // Print process details
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival_time, burst_times[i], processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}
