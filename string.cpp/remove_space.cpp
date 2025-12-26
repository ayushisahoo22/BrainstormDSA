#include<bits/stdc++.h>
using namespace std;

//reverse the original string word by word
//there can be leading space, white space like -> "   m rs  tyu "
string reverseString(string s){
	int n=s.size();
	reverse(s.begin(),s.end());
	int i=0;
	int j=0;
	while(i<n){
		while(i<n && s[i]==' ') i++;
		if(i>=n) break;
		int start=j;
		while(i<n && s[i]!=' '){
			s[j++]=s[i++];
		}
		reverse(s.begin()+start,s.begin()+j);
		s[j++]=' ';
	}
	if(j>0) j--;
	return s.substr(0,j);
}

int main(){
    string s;
    getline(cin,s);
    string result=reverseString(s);
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
}