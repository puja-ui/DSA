//Find longest palindromic substring in a string, DP approach
#include<bits/stdc++.h>
using namespace std;
    string longestPalin (string S) {
        // code here
        int n = S.length();
        bool dp[n][n];
        int i, j; //i = straing point and j = ending point of the main string
        
        for(i=n-1;i>=0;i--){ //bottom-up
            for(j=n-1;j>=i;j--){
                if(i==j) dp[i][j]=true; //substrings with lengh 1 are always palindrome
                else if(i+1 == j){  //checking for substrings of lengh 2
                    if(S[i]==S[j]) dp[i][j]=true;
                    else dp[i][j]=false;
                }
                else{
                    dp[i][j] = (S[i] == S[j])*(dp[i+1][j-1]); //for other substrings it will be palindrome if starting and ending character is equal 
                }                                             //and the inner string is palindrom
            }
        }
        int maxdis=0, low;
        for(i=n-1;i>=0;i--){ //again bottom up because in case of same lengh palindromic substrings we have to choose the first occured one
            for(j=n-1;j>=i;j--){
                if(dp[i][j]==1 && (j-i) >= maxdis){ // >= because low is storing the starting index and index can be 0
                        low=i;
                        maxdis = max(j-i, maxdis); //maximizing the length
                }
            }
        }
        
        string t="";
        for(i=low;i<=low+maxdis;i++){
            t = t+ S[i]; //concatenating at string t
        }
        return t;
    }
    
    int main(){
        string s="rfkqyuqfjkxy";
        cout<<endl<<longestPalin(s);
        return 0;
    }
