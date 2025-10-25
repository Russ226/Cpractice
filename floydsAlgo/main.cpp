#include <iostream>
#include <climits>

#define NO_PATH 999
#define SIZE 7

void printMatrix(int m[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                std::cout << m[i][j]  << " ";
            }
            std::cout << std::endl;
        }
}

void printPath(int P[SIZE][SIZE], int i, int j){
    if(P[i][j] != 0){
        int t = P[i][j];
        printPath(P, i, P[i][j]);
        std::cout << "V: " << P[i][j] << " " << std::endl;
        printPath(P, P[i][j], j);
    }
}

int main(){
    int adjMax[SIZE][SIZE] ={
        {0, 4, NO_PATH, NO_PATH, NO_PATH, 10, NO_PATH}, //v1
        {3, 0, NO_PATH, 18, NO_PATH, NO_PATH, NO_PATH}, //v2
        {NO_PATH, 6, 0, NO_PATH, NO_PATH, NO_PATH, NO_PATH},//v3
        {NO_PATH, 5, 15, 0, 2, 19, 5},//v4
        {NO_PATH, NO_PATH, 12, 1, 0, NO_PATH, NO_PATH},//v5
        {NO_PATH, NO_PATH, NO_PATH, NO_PATH, NO_PATH, 0, 10},//v6
        {NO_PATH, NO_PATH, NO_PATH, 8, NO_PATH, NO_PATH, 0}//v7
    };
    

    int D[SIZE][SIZE][SIZE] = {};
    int P[SIZE][SIZE] = {};
   for(int j = 0; j < SIZE; j++){
            for(int l = 0; l < SIZE; l++){
                D[0][j][l] = adjMax[j][l];
                P[j][l] = 0;
            }
        }
    
    for(int k = 1; k < SIZE; k++){
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if(D[k - 1][i][j] > D[k - 1][i][k] + D[k - 1][k][j]){
                    D[k][i][j] = D[k - 1][i][k] + D[k - 1][k][j];
                    P[i][j] = k - 1;
                }else{
                    D[k][i][j] = D[k - 1][i][j];
                }
            }
        }
    }
    std::cout << "D Matrix: " << std::endl;
    for(int i = 0; i < SIZE; i++){
        
        printMatrix(D[i]);
        std::cout << std::endl;
    }

    std::cout << "P Matrix: " << std::endl;
    printMatrix(P);
    
    //printPath(P, 0, 2);
    return 0;
}