//332224451 -> 2 threes, 3 tows, 2 fours, 1 five, 1 one -> 2332241511
#include<bits/stdc++.h>
using namespace std;

    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11"; //base cases
        string t, s = "11";
        int j, i, c;
        for(i=3;i<=n;i++){ //loop for the n
            t="";
            s = s+"$"; //extra char
            c=1;
            for(j=1;j<s.length();j++){
                if(s[j] != s[j-1]){ //if not repeating
                    t=t+to_string(c); //conert the count and add
                    t= t + s[j-1]; // add the number
                    c=1; //reset the count
                }
                else c++;
            }
            s=t; //update the main string for next iteration
        }
        return s;
    }
    
    int main(){
      int n;
      cin>>n;
      cout<<countAndSay(n);
      return 0;
    }
