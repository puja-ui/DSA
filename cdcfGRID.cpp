//Problem link - https://www.codechef.com/problems/GRID
#include<iostream>
using namespace std;
struct track{
  public:
  int ii, jj;  
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i, j;
        char arr[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        struct track dp[n+1][n+1];
        for(i=0;i<=n;i++){
            dp[i][n].ii = dp[i][n].jj = 1;
            dp[n][i].ii = dp[n][i].jj = 1;
        }
        int c=0;
        for(i=n-1;i>=0;i--){
            for(j=n-1;j>=0;j--){
                if(arr[i][j]=='#'){
                    dp[i][j].ii=0;
                    dp[i][j].jj=0;
                }
                else{
                    dp[i][j].ii = dp[i+1][j].ii;
                    dp[i][j].jj = dp[i][j+1].jj;
                }
                if(dp[i][j].ii==1 && dp[i][j].jj==1) c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
