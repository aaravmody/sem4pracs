#include <stdio.h>
#define MAX 100

int numItems, maxWeight, stateCount;
int profit[MAX], weight[MAX];

struct State {
    int profit, weight;
} states[MAX];

void knapsack() {
    int i, j;
    int tempCount;
    states[0].profit = 0;
    states[0].weight = 0;
    stateCount = 1;
    
    for (i = 0; i < numItems; i++) {
        struct State tempStates[MAX];
        tempCount = 0;
        
        for (j = 0; j < stateCount; j++) {
            tempStates[j].profit = states[j].profit + profit[i];
            tempStates[j].weight = states[j].weight + weight[i];
            tempCount++;
        }
        
        for (j = 0; j < tempCount; j++) {
            if (tempStates[j].weight <= maxWeight) {
                states[stateCount] = tempStates[j];
                stateCount++;
            }
        }
    }
    
    int maxProfit = 0;
    for (i = 0; i < stateCount; i++) {
        if (states[i].profit > maxProfit && states[i].weight <= maxWeight) {
            maxProfit = states[i].profit;
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
}

int main() {
    int i;
    printf("Enter number of items:\n");
    scanf("%d", &numItems);
    printf("Enter weight and profit for each item:\n");
    for (i = 0; i < numItems; i++) {
        scanf("%d %d", &weight[i], &profit[i]);
    }
    printf("Enter maximum weight capacity of knapsack:\n");
    scanf("%d", &maxWeight);
    knapsack();
    return 0;
}
