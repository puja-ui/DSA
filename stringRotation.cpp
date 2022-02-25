//check if the 2nd string is the rotated virsion of the first one
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string str1, str2;
	cin>>str1>>str2;
	if(str1.length() != str2.length()){ // if length is diffrent then definitely if is not rotation
	    cout<<"NA"<<endl;
	    return 0;
	}
	str1 = str1+str1; //concatenationg str1 twice in str1
	int search = str1.find(str2); //returns the index of the first occurance of str2 in str1
	if(search != string::npos) cout<<"rotation"; //check if the position is -1 (highest possible value of size_t) (basically end of string)
	else cout<<"no rotation";
	return 0;
}
