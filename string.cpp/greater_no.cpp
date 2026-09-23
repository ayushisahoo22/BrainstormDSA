#include<bits/stdc++.h>
using namespace std;

string nextGreater(string S) {
	int n=S.size();
	int i=n-2;
	while(i>=0 && S[i]>=S[i+1]){
		i--;
	}
	if(i<0) return "-1";
	int j=n-1;
	while(S[j]<=S[i]){
		j--;
	}
	swap(S[i],S[j]);
	reverse(S.begin()+i+1,S.end());
	return S;
}

int main(){
    string s;
    cout<<"Enter s: ";
    cin>>s;
    string ans=nextGreater(s);
    cout<<ans;
}