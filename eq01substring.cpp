//count the number of substring which has equal number of 1s and 0s, if not print -1
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string arr = "0000000000";
	int currc=0, c=0, flag=0;
	int i, n = arr.length();
	for(i=0;i<n;i++){
	    if(arr[i]=='0') currc++;
	    if(arr[i]=='1') currc--;
	    if(currc==0){
	        c++;
	        flag=1;
	    }
	}
	if(flag==0){
	    cout<<-1;
	    return 0;
	}
	cout<<c;
	return 0;
}
