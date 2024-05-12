#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival, burst, completion, turnaround, waiting, completed, priority;
};
struct process pq[10];

int getHighPriorityProcess(int clock, int total) {
    int highPriorityProcess = -1; // Initialize with an invalid index
    int maxPriority = INT_MIN;    // Initialize maxPriority with the minimum possible integer value

    for (int i = 0; i < total; i++) {
        if (pq[i].arrival <= clock && pq[i].completed != 1) {
            if (pq[i].priority > maxPriority) {
                highPriorityProcess = i;
                maxPriority = pq[i].priority;
            }
        }
    }

    return highPriorityProcess;
}


void main(){
    int total, clock=0, completedProcess=0;
    float avgTAT=0, avgWT=0;
    printf("This is Non Preemtive Priority process sheduling\n");
    printf("Enter number of processes : ");
    scanf("%d",&total);
    
    for (int i=0; i<total; i++){
        printf("Enter process arrival time, burst time, priority : ");
        scanf("%d%d%d",&pq[i].arrival,&pq[i].burst,&pq[i].priority);
        pq[i].completed = 0;
    }
    for(int i=1; i<total; i++){
        int j = i-1;
        struct process key = pq[i];
        while(j >= 0 && key.arrival < pq[j].arrival){
            struct process temp = pq[j];
            pq[j+1] = pq[j];
            pq[j] = temp;
            j--;
        }
        pq[j+1] = key;
    }

    clock = pq[0].arrival;
    while(completedProcess < total){
        int process = getHighPriorityProcess(clock, total);
        pq[process].completion = clock + pq[process].burst;
        pq[process].turnaround = pq[process].completion - pq[process].arrival;
        pq[process].waiting = pq[process].turnaround - pq[process].burst;
        clock += pq[process].burst;
        completedProcess += 1;
        pq[process].completed = 1;
    }
    
    
    printf("Id\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<total; i++){
        avgTAT += pq[i].turnaround;
        avgWT += pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, pq[i].arrival, pq[i].burst, pq[i].completion, pq[i].turnaround, pq[i].waiting);
    }
    avgTAT /= total; 
    avgWT /= total; 
    printf("Avg TAT : %.2f, Avg WT : %.2f", avgTAT, avgWT);
}