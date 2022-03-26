//Recursive Approach (top-down) (ending at base case)
#include<bits/stdc++.h>
using namespace std;

bool subsetsum(int n, int arr[], int sum){
    if(sum==0) return true; //when the sum becomes zero the condition is met
    if(n==0){
        return false; //if traversing the array is over or there is empty array then there is no chance of meeting the condition
    }
    if(arr[n] > sum) return subsetsum(n-1, arr, sum); //when array element of that index is bigger than sum then skip the element
                                                      //which means go to the next element without reducing the sum
    return subsetsum(n-1, arr, sum-arr[n]) || subsetsum(n-1, arr, sum); //pick result OR not-pick result
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2}, sum = 30;
    int n = sizeof(arr)/sizeof(arr[0]);
    n++; //n+1 to get access the nth poition
    if(subsetsum(n, arr, sum)) cout<<"true";
    else cout<<"false";
    return 0;
}

/*-------------------------------------------------------------*/
//recursion to dp conversion, top-down to bottom-up

//DP approach (bottom-up)(starting from base case)
#include<bits/stdc++.h>
using namespace std;

bool subsetsum(int n, int arr[], int sum){
    int j, i, dp[n+1][sum+1]; //at recusive call n and sum is changing so rows=(n+1) and coloums=(sum+1)
    for(i=0;i<=n;i++) dp[i][0] = true; //1st base case, if sum==0 all true
    for(i=0;i<=sum;i++) dp[0][i] = false; //2nd base case, if n==0 all false
    
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){ //decresing n of recursion becomes increasing i 
            if(j<arr[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; //chnge recursion parameters to dp indexes
        }
    }
    return dp[n][sum]; //return UP-est value
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2}, sum = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(subsetsum(n, arr, sum)) cout<<"true";
    else cout<<"false";
    return 0;
}
