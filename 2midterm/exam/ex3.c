#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 4

int minRoad(int road[], bool mst[]){
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < N; i++){
        if (road[i] < min && !mst[i]){
            min = road[i];
            min_index = i;
        }
    } 
    return min_index;
}


int prims(int g[][N]){
    int parent[N];
    bool mst[N] = {false};
    int road[N];
    for (int i = 0; i < N; i++){
        road[i] = INT_MAX;
    }
    road[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < N; i++){
        
    }
    

    
    

}

int main(){
    int g[][N] = {
        {0, 3, 4, 8},
        {3, 0, 2, 3},
        {4, 2, 0, 0},
        {8, 3, 0, 0},
    }; 
    prims(g);
}