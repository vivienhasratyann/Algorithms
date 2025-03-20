#include <stdio.h>
int search(int arr[], int n, int x){
    for (int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;  
}

int main(){
    int arr[] = {7, 28, 36, 42, 50, 63};
    int x = 42;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, n, x);
    if(result == -1){
        printf("Element is not present in the array!");
    }
    else{
        printf("Element index is %d \n", result);
    }
    return 0;
}