#include <bits/stdc++.h>
#define n 4
using namespace std;
bool issafe(int arr[n][n], int i, int j){
    int p, q;
    for(p=0;p<j;p++){ //left
        if(arr[i][p]==1) return false;
    }
    for(p=i,q=j ; p>=0&&q>=0 ; p--,q--){ //upper left
        if(arr[p][q]==1) return false;
    }
    for(p=i,q=j ; p<n&&q>=0 ; p++, q--){ //lower left
        if(arr[p][q]==1) return false;
    }
    return true;
}
void printB(int arr[n][n]){
    int a, b;
        for(a=0;a<n;a++){
            for(b=0;b<n;b++){
                cout<<arr[a][b]<<" ";
            }
            cout<<endl;
        }
}
bool nqueen(int arr[n][n], int j){
    if(j==n){                           //returns when reaches the last coulumn
        return true;
    }
    for(int row=0;row<n;row++){
        if(issafe(arr, row, j)){
            arr[row][j]=1;
            if(nqueen(arr, j+1)) return true;
            arr[row][j]=0;
        }
    }
    return false;
}

int main() {
	// your code goes here
	int i, j;
	int arr[n][n];
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        arr[i][j]=0;
	    }
	}
	if(!nqueen(arr, 0)){
	    cout<<"no solution";
	    return 0;
	}
	printB(arr);
	return 0;
}
