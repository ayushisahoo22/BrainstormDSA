#include <bits/stdc++.h> 
using namespace std;

int maximumSwap(int n) {
	string s=to_string(n);
	vector<int>last(10,-1);
	for(int i=0;i<s.size();i++){
		last[s[i]-'0']=i;
	}
	for(int i=0;i<s.size();i++){
		for(int d=9;d>s[i]-'0';d--){
			if(last[d]>i){
				swap(s[i],s[last[d]]);
				return stoi(s);
			}
		}
	}
	return n;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=maximumSwap(n);
    cout<<ans;
}