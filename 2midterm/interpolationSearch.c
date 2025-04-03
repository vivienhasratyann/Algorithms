// Interpolation Search Algorithm

#include <stdio.h>

int interpolationSearch(int arr[], int l, int h, int x){
    int pos;
    if(l <= h && x>=arr[l] && x<=arr[h]){
        pos = l + (((x-arr[l])*(h-l))/(arr[h]-arr[l]));

        if(arr[pos] == x)
            return pos;
        
        if(arr[pos] < x)
            return interpolationSearch(arr, pos+1, h, x);
        
        if(arr[pos] > x)
            return interpolationSearch(arr, l, pos-1, x);
    }
    return -1;
}

int main(){
    int arr[] = {2, 4, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 22;
    int index = interpolationSearch(arr, 0, n-1, x);

    if(index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found");

    return 0;
}