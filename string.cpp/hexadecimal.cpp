#include<bits/stdc++.h>
using namespace std;
string toHex(int num) {
	unsigned int n=(unsigned int)num;     //to handle negative numbers
	string hexa="0123456789ABCDEF";
	string result="";
	if(n==0) return 0;
	while(n>0){
		int digit=n%16;
		result+=hexa[digit];
		n/=16;
	}
	reverse(result.begin(),result.end());
	return result;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    string ans=toHex(n);
    cout<<ans;
}