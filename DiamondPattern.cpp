//diamond pattern using recursion and backtracking
/*
      * 
    * * * 
  * * * * * 
* * * * * * * 
  * * * * * 
    * * * 
      * 
*/
#include <iostream>
using namespace std;

void ds(int i, int n){
    if(n<=0) return; //base case
        
    int g = (n-1)*2; //space limit
    while(g--) cout<<" ";
    
    int c=i;//star limit
    while(c--) cout<<"* ";
    
    cout<<endl;
    
    ds(i+2, n-1);//recursion
    
    if(n==1) return; //skipping the double call of longest line
    //backtracking
    c=i;
    g = (n-1)*2;
    while(g--) cout<<" ";
	    
    while(c--) cout<<"* ";
    cout<<endl;
}

int main() {
	// your code goes here
	int n=4; //no. of line till longest line
	ds(1, n);
	return 0;
}
