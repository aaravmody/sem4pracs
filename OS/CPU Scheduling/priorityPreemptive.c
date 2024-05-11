#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival, burst, completion, turnaround, waiting, completed, r_burst, start, priority;
};
struct process pq[10];

int getHighPriorityProcess(int clock, int total){
    int highPriorityProcess;
    for (int i=0; i<total; i++){
        if (pq[i].arrival <= clock && pq[i].completed != 1){
            highPriorityProcess = i;
            break;
        }
    }
    for(int i=highPriorityProcess; i<total; i++){
        if (pq[i].arrival <= clock && pq[i].completed != 1 && pq[i].priority > pq[highPriorityProcess].priority){
            highPriorityProcess = i;
        }
    }
    return highPriorityProcess;
}

void main(){
    int total, clock=0, completedProcess=0;
    float avgTAT=0, avgWT=0;
    printf("This is Preemtive Priority process sheduling\n");
    printf("Enter number of processes : ");
    scanf("%d",&total);
    
    for (int i=0; i<total; i++){
        printf("Enter process arrival time, burst time, priority : ");
        scanf("%d%d%d",&pq[i].arrival,&pq[i].burst,&pq[i].priority);
        pq[i].completed = 0;
        pq[i].r_burst = pq[i].burst;
        pq[i].start = -1;
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
        if(pq[process].start == -1){
            pq[process].start = clock;
        }
        pq[process].r_burst--;
        clock++;
        if(pq[process].r_burst == 0){
            pq[process].completion = clock;
            pq[process].turnaround = pq[process].completion - pq[process].arrival;
            pq[process].waiting = pq[process].turnaround - pq[process].burst;
            completedProcess += 1;
            pq[process].completed = 1;
        }
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