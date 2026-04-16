#include <bits/stdc++.h> 
using namespace std;

// given two positive integers ‘N’ and ‘K’.
// task is to find the smallest ‘N’ digit number whose sum of digits equals ‘K’.
// If no such number exists then you need to print -1.

string smallestNumber(int n, int k)
{
	if(k>9*n) return "-1";
	if(k==0){
		if(n==1) return "0";
		return "-1";
	}
	vector<int>digits(n,0);
	digits[0]=1;
	k-=1;
	for(int i=n-1;i>=0;i--){
		if(k<=0) break;
		int add=min(9-digits[i],k);
		digits[i]+=add;
		k-=add;
	}
	if(k>0) return "-1";
	string an="";
	for(int i=0;i<n;i++){
		an+=(digits[i]+'0');
	}
	return an;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    string ans=smallestNumber(n,k);
    cout<<ans;
}