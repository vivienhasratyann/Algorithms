#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int data;
    int priority;
} Element;

Element heap[MAX];
int size = 0;

void swap (int i, int j){
    Element temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insert(int data, int priority){
    int i = size++;
    heap[i].data = data;
    heap[i].priority = priority;
    while (i != 0 && heap[(i-1)/2].priority > heap[i].priority){
        swap(i, (i-1)/2);
        i = (i-1)/2; // (i-1)/2 arajin angam vor tenc bajanum enq uremn inchy vor stanum enq mer verjin cnoxna 
    }
}

int deleteHighestPriority(){
    if (size == 0) return -1;
    int data =  heap[0].data;
    heap[0] = heap[--size];
    int i = 0;
    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;
        if(left<size && heap[left].priority < heap[smallest].priority){
            smallest = left;
        }
        if(right < size && heap[right].priority < heap[smallest].priority){
            smallest = right;
        }
        if(smallest == i) break;
        swap(i, smallest);
        i = smallest;
    }
    return data;
}

int main(){
    insert(10, 10);
    insert(9,9);
    insert(1, 1);
    insert(2, 2);
    printf("%d \n", deleteHighestPriority());
    return 0;
}