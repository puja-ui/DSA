//basically Longest common subsequence problem with same string, see /LCS.cpp for the comments
#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length(), i, j;
		    int dp[n+1][n+1];
		    for(i=0;i<=n;i++){
		        dp[i][n]=0;
		        dp[n][i]=0;
		    }
		    for(i=n-1;i>=0;i--){
		        for(j=n-1;j>=0;j--){
		            if(str[i] == str[j] && i!=j)
		                dp[i][j] = dp[i+1][j+1] +1;
		            else
		                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		        }
		    }
		    return dp[0][0];
		}

int main(){
    string str;
    cin>>str;
    cout<<LongestRepeatingSubsequence(str)
    retrun 0;
}
