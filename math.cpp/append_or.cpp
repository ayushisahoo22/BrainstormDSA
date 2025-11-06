#include <bits/stdc++.h>
using namespace std;


// given an array A of length N,Y
// find the minimum non-negative integer X such that:(A1|A2|A3..AN|X)=Y
// Where | means bitwise OR operation.
// find minimum x to satisfy the condition
// If no such X exists, print -1.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,y;
	    cin>>n>>y;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int curr_or=0;
	    int ans;
	    for(auto it:arr){
	        curr_or|=it;  //for the or of all present elements
	    }

        // Some bit that is 1 in the array’s OR (curr_or)
        // is 0 in y → impossible to reach y.
        // Hence ans = -1.
	    if((~y & curr_or)!=0){
	        ans=-1;
	    }else{
	        ans=(y & ~curr_or);  //the bits that are 1 in y but still missing in array’s OR.
	    }
	    cout<<ans<<endl;
	}

}