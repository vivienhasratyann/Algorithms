#include <stdio.h>

int josephus(int n, int k){
    if (n == 1){
        return 0;
    }
    else{
        return (josephus(n-1,k)+k)%n;
    }
}

int main(){
    int n = 7;
    int k = 3;

    int index = josephus(n,k);
    printf("Last element's index is %d \n", index);

    return 0;
}