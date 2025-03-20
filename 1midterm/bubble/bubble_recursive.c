// Sort following array = {5, 1, 4, 2, 8} using Bubble Sort recursive function

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap (int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n){
if (n==1) return;
for(int i = 0; i < n-1; i++){
    if(arr[i]>arr[i+1]){
        swap(arr, i, i+1);
    }
}
bubbleSort(arr, n-1); // mec tivy vor haytnvuma ira texum el iran chenq kpnum


}

int main(){
    int arr[] = {5,1,4,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
}