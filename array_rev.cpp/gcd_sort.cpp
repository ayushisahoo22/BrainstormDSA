#include <bits/stdc++.h>
using namespace std;

//There are N players, numbered from 1 to N.
// The score of the i-th player is defined as:
// score(i)=gcd(i,N)
// where gcd(i, N) is the greatest common divisor of i and N.

// arrange all players in an order such that:
// Players with higher scores appear before players with lower scores.
// If two players have the same score, the one with a smaller player number appears earlier.


//return true false for comparison, to keep a before b or b before a while sorting
bool compare(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second>b.second;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
        //to store pairs of player and score
	    vector<pair<int,int>> result;
	    for(int i=1;i<=n;i++){   //manual gcd func
	        vector<int>maximum;
	        for(int j=1;j<=n;j++){
	            if(i%j==0 && n%j==0){
	                maximum.push_back(j);
	            }
	        }
	        int maxi=INT_MIN;
	        for(auto it:maximum){
	            if(it>maxi){
	                maxi=it;
	            }
	        }
	        result.push_back({i,maxi});

            //gcd built in func
            /*for (int i = 1; i <= n; i++) {
                int g = __gcd(i, n);
                result.push_back({i, g});
            }*/

	    }
	    sort(result.begin(),result.end(),compare);
	    
	    vector<int> ans;
	    for(auto it:result){
	        ans.push_back(it.first);
	    }
	    for(auto it:ans){
	        cout<<it<<" ";
	    }
	    cout<<endl;
	}
}