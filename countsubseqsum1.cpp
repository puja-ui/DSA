#include<iostream>
using namespace std;
int Csubseq(int arr[], int k, int i, int n, int sum){
    if(i>=n){
        if(sum == k) return 1;
        return 0;
    }
    int l, r;
    sum += arr[i];
    l = Csubseq(arr, k, i+1, n, sum);
    sum -= arr[i];
    r = Csubseq(arr, k, i+1, n, sum);
    return l+r;
}

int main(){
    int arr[] = {2, 2, 2};
    int k = 2, i=0, sum=0, c=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<Csubseq(arr, k, i, n, sum);
    return 0;
}
