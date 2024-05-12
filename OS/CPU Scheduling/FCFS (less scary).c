#include <stdio.h>

struct process{
    int pid,at,bt,ct,tat,wt;
}pq[10];

void main()
{
    int n;
    float awt=0,atat=0,gantt[5],totaltat=0,totalwt=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &pq[i].at, &pq[i].bt);
        pq[i].pid=i+1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pq[j].at > pq[j + 1].at) {
                struct process temp = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = temp;
            }
        }
    }

    int current=0;

    for(int i=0;i<n;i++)
    {
        if(current<pq[i].at)
        {
            current=pq[i].at;
        }


        pq[i].ct = current + pq[i].bt;
        printf("%d-%d",pq[i].pid,pq[i].ct);
        pq[i].tat = pq[i].ct - pq[i].at;
        pq[i].wt = pq[i].tat - pq[i].bt;

        current=pq[i].ct;
        totaltat+=pq[i].tat;
        totalwt+=pq[i].wt;
    }

    printf("ID\t AT\t BT\t CT\t TAT\t WT\n");
    for(int i=0;i<n;i++)
    {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,pq[i].at,pq[i].bt,pq[i].ct,pq[i].tat,pq[i].wt);
}

printf("Avg TAT %0.2f\n AVG WT %0.2f",totaltat/n,totalwt/n);
}