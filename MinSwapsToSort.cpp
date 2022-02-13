#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int i, n=nums.size();
	    // Code here
	    vector<pair<int, int>> p(n);
	    for(i=0;i<n;i++) p[i] = {nums[i], i}; //store the numbers with their index as pairs in the vector
	    sort(p.begin(), p.end()); // sort the pairs according to the values
	    int c=0;
	    for(i=0;i<n;i++){
	        if(p[i].second == i) continue; //compare the pair indexes to the actual index in the pair
	        else{
	            swap(p[i], p[p[i].second]); //if the indexes are different then the velue is not in the right place, swap it
	            c++;
	            i--; //cross-check if the value after swaping is in the right palce
	        }
	    }
	    return c;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
} 