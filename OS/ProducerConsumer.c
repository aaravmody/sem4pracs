#include <stdio.h>
#include <stdlib.h>

int buffer[8], buffer_size=5, full=0, empty=5, semaphore=1, in=-1, out=0;

int up(int n){
    return ++n;
}
int down(int n){
    return --n;
}

int produce_item(){
    int item = rand()%10;
    printf("Producer produced item :  %d\n", item);
    return item;
}

void producer(){
    int item = produce_item();
    empty = down(empty);
    semaphore = down(semaphore);
    in = (in+1)%buffer_size;
    buffer[in] = item;
    full = up(full);
    semaphore= up(semaphore);
}

void consumer(){
    full = down(full);
    semaphore = down(semaphore);
    int item = buffer[out];
    out = (out+1)%buffer_size;
    empty = up(empty);
    semaphore= up(semaphore);
    printf("Consumer consumes item : %d\n", item);
}

void main(){
    int choice,arr[20]={1,2};
    while(1){
        printf("Choice : ");
        choice=arr[(rand()%2)];
        switch(choice){
            case 1:
            if(semaphore == 1 && full!=0){
                consumer();
            }
            else{
                printf("Buffer Empty Consumer Preemteed\n");
            }
            break;
            case 2:
            if(semaphore == 1 && empty!=0){
                producer();
            }
            else{
                printf("Buffer Full Producer Preemteed\n");
            }
            break;
            case 3:
            exit(0);
            break;
        }
        sleep(2);
    }
}