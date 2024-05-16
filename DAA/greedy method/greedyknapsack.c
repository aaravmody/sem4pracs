#include <stdio.h>

#define max 15

struct items{
    int profit,weight;
    float profitbyweight,includes;
}item[10];

void main()
{
    int n,w,m;
    float maxprofit=0;
    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter max wt: ");
    scanf("%d",&m);
    w=m;
    for(int i=0;i<n;i++)
    {
        printf("Enter profit and weight of item: ");
        scanf("%d %d",&item[i].profit,&item[i].weight);
        item[i].profitbyweight=item[i].profit/(float)item[i].weight;
        item[i].includes=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(item[j].profitbyweight<item[j+1].profitbyweight)
            {
                struct items temp = item[j];
                item[j]=item[j+1];
                item[j+1]=temp;
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        if(item[i].weight<=w)
        {
            w-=item[i].weight;
            item[i].includes=1;
            maxprofit+=item[i].profit;
        }
        else{
            float ratio=(float)w/item[i].weight;
            item[i].includes=ratio;
            w-=(int)item[i].weight*ratio;
            maxprofit+=(float)item[i].profit*ratio;
        }
    }

    printf("\nProfit\t\tWeight\t\tP/W\t\tIncludes\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%d\t\t%.2f\t\t%.2f\n", item[i].profit, item[i].weight, item[i].profitbyweight, item[i].includes);
    }
}

