#include <bits/stdc++.h>
using namespace std;

// You have 2 integers X and Y
// goal is to make them have a common divisor which is not 1 i.e. there should exist Z>1 such that 
// Z divides X and Z divides   y   .

// In one operation, you can do either of the following:
// set X=X+1, Y=Y+1
// Find the minimum number of operations needed to achieve your goal.


int main() {
	int t;
	cin>>t;
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    int cnt=0;
	    if(__gcd(x,y)>1){
	        cout<<0<<endl;
	    }else if(__gcd(x+1,y)>1 || __gcd(x,y+1)>1){
	        cout<<1<<endl;
	    }else{
	        cout<<2<<endl;
	    }
	}
}