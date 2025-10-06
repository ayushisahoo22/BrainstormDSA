#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    
    //s     t    tot_1 tot_2 player    diff
    //140	82    140	82	Player 1	58
    //89	134   229	216	Player 1	13
    // 90	110   319	326	Player 2	7
    //112	106   431	432	Player 2	1
    // 88	90    519	522	Player 2	3

    //mistake is that we have to store absolute diff of cumulative scores
	/*int s[n],t[n];  //assuming the array for score of s and t
	vector<int>diff;     //to push every difference
	for(int i=0;i<n;i++){
	    cin>>s[i]>>t[i];
	    int d=abs(s[i]-t[i]);   //not storing the diff of total but storing the diff of current score
	    diff.push_back(d);
	}
	int maxi=diff[0];   //no need to loop over it
	int idx=-1;
	for(int i=0;i<diff.size();i++){  //because diff.size()=n can be managed in above loop
	    if(diff[i]>maxi){
	        maxi=diff[i];
	        idx=i;
	    }
	}
    if(s[idx]>t[idx] && diff[idx]==maxi){
        cout<<1<<" "<<maxi;
    }else if(s[idx]<t[idx] && diff[idx]==maxi){
        cout<<2<<" "<<maxi;
    }
    return 0;*/

    int s,t;
	int total1=0,total2=0;
	int maxi=0;
	int winner=0;
	for(int i=0;i<n;i++){
	    cin>>s>>t;
	    total1+=s;
	    total2+=t;
	    int d=abs(total1-total2);
	    if(d>maxi){
	        maxi=d;
	        winner=(total1>total2)?1:2;
	    }
	}
    cout<<winner<<" "<<maxi;
    return 0;
}