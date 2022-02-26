//count the occurance of a substring
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s1 = "My name is puja karmakar";
	string s2 = "ajup";
	int i=1, c=0;
	size_t found = s1.find(s2); //returns the index of the first occurance of str2 in str1 
    	while(1){
    	    if(found != string::npos){ //check if the position is -1 (highest possible value of size_t) (basically end of string)
        	    found = s1.find(s2, found+i); //chech for the next occurance just by adding 2nd argument as found+1, found+2, ...
        	    i++;
        	    c++;
    	    }
    	    else break;
    }
    cout<<"string occured "<<c<<" times";
	return 0;
}
