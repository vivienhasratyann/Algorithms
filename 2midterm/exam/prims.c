#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define N 4 // NxN matrix qani ket uni mer graphy

int minRoad(int road[], bool mst[]){
    int min = INT_MAX;  // пока считаем, что минимальная цена — бесконечность
    int min_index = -1; // индекс лучшего города пока неизвестен
    for(int i=0; i<N; ++i){
        if(road[i] < min && !mst[i]){ // меньше, чем текущая минимальная цена и ещё не подключён
            min = road[i];
            min_index = i;
        }
    } return min_index; // вернули лучший город
}

void prim(int g[][N]){
    int parent[N];  // кто чей родитель (откуда пришли)
    bool mst[N] = {false};  // какие города уже в сети (MST)
    int road[N];  // минимальная цена дороги до каждого города
    for(int i=0; i<N; i++){
        road[i] = INT_MAX; // заполняем road бесконечностями
    }
    road[0] = 0;  // первый город сам по себе, цена 0
    parent[0] = -1;  // у него нет родителя
    for (int i = 0; i < N; i++){
        int index = minRoad(road, mst); // нашли город с самой дешёвой дорогой
        mst[index] = true; // добавили его в дерево
        for (int j = 0; j < N; j++){ // проверяем соседей
            if (g[index][j] && !mst[j] && g[index][j] < road[j]){
                parent[j] = index; // обновили родителя
                road[j] = g[index][j]; // обновили мин  цену
            }  
        }
    } 
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < N; i++){ // начинаем с 1 потому что у 0 нет родителя
        printf("Note %c connected with %c cost = %d\n", 'A' + parent[i], 'A' + i,g[i][parent[i]]);
    } 
}

int main(){
    int g[][N]={
        {0, 4, 5, 0},
        {4, 0, 7, 6},
        {5, 7, 0, 5},
        {0, 6, 5, 0},
    }; prim(g);
}