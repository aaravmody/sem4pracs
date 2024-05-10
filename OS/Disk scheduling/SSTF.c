#include <stdio.h>
#include <stdlib.h>

int track[10],isvisited[10];

int shortest(int head,int request)
{
    int nearest;
    for(int i=0;i<request;i++)
    {
        if(isvisited[i]!=1)
        {
            nearest=i;
            break;
        }
    }

    for(int i=0;i<request;i++)
    {
        if(isvisited[i]!=1 && abs(head-track[nearest]) > abs(head-track[i]))
        {
            nearest=i;
        }
    }
    return nearest;
}

void main()
{
    int disk, request, head, totalTrackMovement=0, visited=0;
    printf("Enter number of disk tracks : ");
    scanf("%d", &disk);
    printf("Enter curent position of head : ");
    scanf("%d", &head);
    printf("Enter number of request in queue : ");
    scanf("%d", &request);
    for(int i=0; i<request; i++){
        isvisited[i]=0;
    }
    printf("Enter request queue : ");
    for(int i=0; i<request; i++){
        scanf("%d", &track[i]);
    }

    while(visited<request)
    {
        int nearest = shortest(head,request);
        printf("%d   ",track[nearest]);
        totalTrackMovement+=abs(track[nearest]-head);
        isvisited[nearest]=1;
        visited++;
        head=track[nearest];
    }

    printf("Total track movement: %d",totalTrackMovement);
}