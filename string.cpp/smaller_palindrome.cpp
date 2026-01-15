#include<bits/stdc++.h>
using namespace std;

//return the next smallest palindrome number of the number in string s

string nextSmallerPalindrome(string &s) {
	int n=s.size();
	if(n==1){
		if(s[0]=='0') return s;
		return string(1,s[0]-1);
	}
	bool spcl=true;
	if(s[0]=='1'){
		for(int i=1;i<n-1;i++){
			if(s[i]!='0'){
				spcl=false;
				break;
			}
		}
		if(spcl){
			return string(n-1,'9');
		}
	}
	int i;
	if(n%2==0){
		i=n/2-1;
	}else{
		i=n/2;
	}
	while(i>=0 && s[i]=='0'){
		s[i]='9';
		i--;
	}
	if(i<0) return string(n-1,'9');
	s[i]--;
	int l=0,r=n-1;
	while(l<r){
		s[r]=s[l];
		l++;
		r--;
	}
	if(s[0]=='0'){
		return string(n-1,'9');
	}
	return s;
}

int main(){
    string s;
    cout<<"Enter s: ";
    cin>>s;
    string ans= nextSmallerPalindrome(s);
    cout<<ans;
}