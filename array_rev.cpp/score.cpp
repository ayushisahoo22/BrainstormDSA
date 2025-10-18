#include <bits/stdc++.h>
using namespace std;

//in a contest which has 11problems (numbered 1 through 11). 
//The first eight problems (i.e. problems 1,2,..,8) are scorable,
// while the last three problems (9,10 & 11 are non-scorable)

//For each scorable problem, you look at the scores of all submissions 
//you made on that problem and take the maximum of these scores (or 0 if you didn't make any submissions on that problem)
//the total score is the sum of the maximum scores you took.


int main(){
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<int,int>> submission(n);   //to store pairs in vector
	    for(int i=0;i<n;i++){
	        cin>>submission[i].first>>submission[i].second;   //input for the values of pair
	    }
	    map<int,int>mpp;   //to track max scores of the que<9
	    for(auto it:submission){
	        if(it.first<9){
	            mpp[it.first]=max(mpp[it.first],it.second);  //store only the max value of que<9
	        }
	    }
	    int total=0;
	    for(auto it:mpp){
	        total+=it.second;
	    }
	    cout<<total<<endl;
	}
}