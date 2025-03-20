#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>


void print_arr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        int min_ind = i;
        for(int j=min_ind+1; j<size; j++){
            if(arr[min_ind]>arr[j]){
                min_ind = j;
            }
        }
        swap(&arr[min_ind], &arr[i]);
    }
}

int main(){
    int arr[]={5,4,3,6,7,8};
    int size = sizeof(arr)/sizeof(int);
    selection_sort(arr,size);
    print_arr(arr, size);
    
}