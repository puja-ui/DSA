#include <iostream>
#define n 9
using namespace std;

bool issafe(int c, int grid[n][n], int i, int j){
    int k, I, J;
    for(k=0;k<n;k++){
        if(grid[k][j] == c) return false;
        if(grid[i][k] == c) return false;
        I = (3*(i/3))+i/3;
        J = (3*(j/3))+j%3;
        if(grid[I][J] == c) return false;
    }
    return true;
}

bool suduku(int grid[n][n]){
    int i, j, c;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(grid[i][j] == 0){
                for(c=1;c<=9;c++){
                    if(issafe(c, grid, i, j)){
                        grid[i][j]=c;
                        if(suduku(grid)) return true;
                        else grid[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
	// your code goes here
	int grid[n][n] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                       {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                       {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                       {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                       {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                       {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                       {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                       {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                       {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    suduku(grid);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
