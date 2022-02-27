//find the length of longest common subsequence, subsequence is the substring that can be retrived by deleting some or no characters from the main string
//one subsequence of "abcde" is "ace"
//"ace" is also a subsequence of "ace" itself
//so longest common subsequence is "ace"
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(), n2 = text2.length();
        int dp[n1+1][n2+1]; // +1 for the \0 character
        int i, j;
        for(i=n1;i>=0;i--){
            for(j=n2;j>=0;j--){
                if(i==n1 || j==n2) dp[i][j]=0; // at the null position common subsequent is not possible
            }
        }
        for(i=n1-1;i>=0;i--){
            for(j=n2-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i+1][j+1] +1; //if characters are matched then maximum length that has been accquired till now +1, both indexes changed
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]); //if doesn't match then max of the lengths, one index at a time changed
                }
            }
        }
        return dp[0][0];
    }

 int main(){
    string str1, str2;
    cin>>str1>>str2;
    cout<<longestCommonSubsequence(str1, str2)
    retrun 0;
}
