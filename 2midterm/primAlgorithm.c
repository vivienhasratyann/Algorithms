#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 4

int minRoad(int road[], bool mst[]){
    int min = INT_MAX;
    int min_index = -1;
    for(int i=0; i<N; ++i ){
        if(road[i] < min && ! mst[i]){
            min = road[i];
            min_index = i;
        }
    }
    return min_index;
}

void prim(int g[][N]){
    int parent[N];
    bool mst[N] = {false};
    int road[N];
    for(int i=0; i<N; i++){
        road[i] = INT_MAX;
    }
    road[0]=0;
    parent[0]=1;
    for (int i = 0; i < N-1; i++){
        int index = minRoad(road, mst);
        mst[index]=true;
        for (int j = 0; j < N; j++){
            if(g[index][j] && !mst[j] && g[index][j]< road[j]){
                parent[j] = index;
                road[j] = g[index][j];
            }
        }
        for (int i = 0; i< N; i++){
            printf("Node %c connected with %c cost = %d\n",'A'+parent[i], 'A'+i,g[i][parent[i]]);
        }
    }
    
}

int main(){
    int g[][N]={
        {0,4,5,0},
        {4,0,7,6},
        {5,7,0,5},
        {0,6,5,0},
    };
    prim(g);
}