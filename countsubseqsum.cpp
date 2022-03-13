#include<iostream>
using namespace std;
int c=0;
int Csubseq(int arr[], int k, int i, int n, int sum){
        if(i>=n){
            if(sum == k){
                c++;
            }
            return c;
        }
        sum += arr[i];
        Csubseq(arr, k, i+1, n, sum);
        sum -= arr[i];
        Csubseq(arr, k, i+1, n, sum);
}

int main(){
    int arr[] = {1, 2, 1};
    int k = 2, i=0, sum=0, c=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Csubseq(arr, k, i, n, sum);
    return 0;
}
