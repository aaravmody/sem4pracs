#include <stdio.h>
#include <stdlib.h>

void main(){
    int noFrames, noPages, frames[10], pages[20], fault=0, inFuture[10];
    printf("Enter number of frames : ");
    scanf("%d", &noFrames);
    for (int i=0; i<noFrames; i++){
        frames[i] = -1;
    }
    for (int i=0; i<noFrames; i++){
        inFuture[i] = 0;
    }
    printf("Enter total number of pages : ");
    scanf("%d", &noPages);
    printf("Enter sequence : ");
    for (int i=0; i<noPages; i++){
        scanf("%d", &pages[i]);
    }
    for (int i=0; i<noPages; i++){
        int count = 0;
        for (int j=0; j<noFrames; j++){
            if (frames[j] != pages[i]){
                count++;
            }else{
                break;
            }
        }
        if(i<noFrames){
            frames[fault] = pages[i];
            fault++;
        }
        else if(count == noFrames){
            fault++;
            int newCount=0;
            for (int k=i+1; k<noPages; k++){
                if(newCount < noFrames-1){
                    for (int j=0; j<noFrames; j++){
                        if(frames[j] == pages[k]){
                            newCount++;
                            inFuture[j] = 1;
                        }
                    }
                }else{
                    break;
                }
            }
            for (int j=0; j<noFrames; j++){
                if(inFuture[j] == 0){
                    frames[j] = pages[i];
                    break;
                }
            }
        }
        printf("Page : %d\tFrames : ", pages[i]);
        for (int j=0; j<noFrames; j++){
            printf("%d\t", frames[j]);
        }
        printf("\n");
        for (int i=0; i<noFrames; i++){
            inFuture[i] = 0;
        }
    }
    printf("Page Faults : %d", fault);
} 