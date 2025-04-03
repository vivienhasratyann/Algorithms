#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

typedef struct{
    int data;
    int priority;
} Element;

Element queue[MAX];
int size = 0;

void insertion(int data, int priority){
    if(size == MAX){
        printf("Queue is full");
        return;
    }
    queue[size].data = data;
    queue[size].priority = priority;
    size++;
}

int getHighestPriorityIndex(){
    int min = INT_MAX;
    int index = 1;
    for(int i = 0; i < size; i++){
        if(queue[i].priority<min){
            min = queue[i].priority;
            index= i;
        }
    }
    return index;
}

int deleteHighestPriority(){
    if(size == 0) return -1;
    int index = getHighestPriorityIndex();
    int data = queue[index].data;
    for(int i = index; i< size-1;i++){
        queue[i] = queue[i+1];
    }
    return data;
}

// ete priority-n krknvum a inqy durs a berum arajin handipacin

int main(){
    insert(12,5);
    insert(34,3);
    insert(8,7);
    int n = deleteHighestPriority();
    printf("\n%d ", n);
    n = deleteHighestPriority;
    printf("\n%d ", n);
    return 0;
}