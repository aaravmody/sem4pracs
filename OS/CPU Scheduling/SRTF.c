#include<stdio.h>
int minBust(int b[],int a[],int t,int n)
{
    int i,ct=0,v[n],least=9999,minInd=-1;
    for(i=0;i<n;i++)
    v[i]=0;
    for(i=0;i<n;i++)
    {
        if(b[i]<least && a[i]<=t && b[i]>0)
        {
            least=b[i];
            minInd=i;
        }
    }
    return minInd;
}
void main()
{
    int n=6,i,j,count=0,minInd,temp,ind=0,ttat=0,twt=0;
    float awt,atat;
    int gant[100]={0},cgant[100];
    int pro[]={1,2,3,4,5,6};
    int at[]={0,1,2,3,4,5};
    int bt[]={7,5,3,1,2,1};
    int wt[n],tat[n],rt[n],ct[n],ogbt[n];
    for(i=0;i<n;i++)
    ogbt[i]=bt[i];
    i=0;
    while(count!=n)
    {
        minInd=minBust(bt,at,i,n);
        if(pro[minInd]!=gant[ind-1])
        {
            gant[ind]=pro[minInd];
            cgant[ind]=i;
            ind++;
        }
        else
        cgant[ind]=i;
        bt[minInd]--;
        i++;
        if(bt[minInd]==0)
        {
            count++;
            ct[minInd]=i;
            tat[minInd]=ct[minInd]-at[minInd];
            wt[minInd]=tat[minInd]-ogbt[minInd];
            ttat+=tat[minInd];
            twt+=wt[minInd];
        }
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    printf("\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],at[i],ogbt[i],ct[i],tat[i],wt[i]);
    awt=(float)twt/n;
    atat=(float)ttat/n;
    printf("Avg Wait Time %f\nAvg TAT %f\n",awt,atat);
    printf("\nGant Chart\n");
    for(i=0;i<ind;i++)
    printf("P%d ",gant[i]);
    printf("\n");
    for(i=0;i<ind;i++)
    printf("%d  ",cgant[i]);
    printf("%d ",ct[minInd]);
}