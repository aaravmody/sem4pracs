#include <stdio.h>
#include <stdlib.h>

void main()
{
    int noFrames,noPages, frames[10], pages[20], timestamp[10], fault=0, hit=0;
    printf("Enter number of frames : ");
    scanf("%d", &noFrames);
    for (int i=0; i<noFrames; i++)
    {
        frames[i] = -1;
    }
    for (int i=0; i<noFrames; i++)
    {
        timestamp[i] = -1;
    }
    printf("Enter total number of pages : ");
    scanf("%d", &noPages);
    printf("Enter sequence : \n");
    for (int i=0; i<noPages; i++)
    {
        scanf("%d", &pages[i]);
    }
    
    for (int i=0; i<noPages; i++)
    {
        int count = 0;
        for (int j=0; j<noFrames; j++)
        {
            if (frames[j] != pages[i])
            {
                count++;
            }
            else
            {
                hit++;
                timestamp[j] = i;
                break;
            }
        }
        if(i<noFrames && count == noFrames)
        {
            frames[fault] = pages[i];
            timestamp[fault] = i;
            fault++;
        }
        else if(count == noFrames)
        {
            fault++;
            int min=99, minElement;
            for (int j=0; j<noFrames; j++)
            {
                if(timestamp[j]<min)
                {
                    min = timestamp[j];
                    minElement = j;
                }
            }
            frames[minElement] = pages[i];
            timestamp[minElement] = i;
        }
        printf("Page : %d\tFrames : ", pages[i]);
        for (int j=0; j<noFrames; j++)
        {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("\nPage Faults : %d", fault);
    printf("\nNumber of Hits : %d",hit);
    printf("\nNumber of Miss : %d",noPages - hit);
} 