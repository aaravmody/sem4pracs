#include<stdio.h>
#include<limits.h>
void main()
{
    int ct[100],tat[100],wt[100],n=7,i,j,temp,temp1,temp2,ttat=0,twt=0,ind=0,cgant[7];
    int gant[7];
    float attat,awt;
    int at[7]={0,1,2,3,4,5,6};
    int bt[7]={4,2,3,5,1,4,6};
    int pr[7]={2,4,6,10,8,12,9};
    int v[7]={0,0,0,0,0,0,0};
    int pro[7]={1,2,3,4,5,6,7};
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(pr[j]>pr[j+1])
            {
                temp=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=temp;                
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp1=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp1;
                temp2=pro[j];
                pro[j]=pro[j+1];
                pro[j+1]=temp2;
            }
        }
    }
    i=0;
    int flag=0;
    while(flag!=7)
    {
        int f=0;
        for(j=0;j<n;j++)
        {
            if(at[j]<=i && v[j]==0)
            {
                ct[j]=i+bt[j];
                v[j]=1;
                i=ct[j];
                flag++;
                f++;
                gant[ind]=pro[j];
                cgant[ind]=ct[j];
                ind++;
                break;
            }
        }
        if(f==0)
        i++;
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("Process\tprio\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        ttat+=tat[i];
        twt+=wt[i];
    }
    awt=(float)twt/n;
    attat=(float)ttat/n;
    for(i=0;i<n;i++)
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],pr[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAvg TAT=%f\nAvg WT=%f",attat,awt);
    printf("\nGant Chart \n");
    for(i=0;i<ind;i++)
    printf("%d\t",gant[i]);
    printf("\n");
    for(i=0;i<ind;i++)
    printf("%d\t",cgant[i]);
}


