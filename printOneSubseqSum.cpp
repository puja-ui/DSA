#include <iostream>
using namespace std;

bool subseq(int arr[], string v, int n, int i, int sum, int k){
    if(i>=n){
        if(sum == k){
            cout<<v<<endl;
            return true;
        }
        return false;
    }
    v = v + to_string(arr[i]);
    sum += arr[i];
    if(subseq(arr, v, n, i+1, sum, k) == true) return true;
    v.pop_back();
    sum -= arr[i];
    if(subseq(arr, v, n, i+1, sum, k) == true) return true;
    return false;
}

int main() {
	// your code goes here
	int arr[] = {1, 2, 1};
	int k = 2;
	int sum=0, i=0;
	int n = sizeof(arr)/sizeof(arr[0]);
	string v = "";
	subseq(arr, v, n, i, sum, k);
	return 0;
}
