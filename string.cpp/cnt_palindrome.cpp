#include <bits/stdc++.h>
using namespace std;


//given a string S of words. task is to find the number of palindrome words in the given string S. 
//A word is called palindrome,if it reads the same backwards as forwards.

bool palindrome(string s){
	int n=s.size();
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]){
			return false;
		}
	}
	return true;
} 
int countNumberOfPalindromeWords(string s)
{
	transform(s.begin(),s.end(),s.begin(),::tolower); //to convert every element into lower
	int cnt=0;
	string strg="";
	for(int i=0;i<s.size();i++){
		if(s[i]!=' '){
			strg+=s[i];
		}else{
			if(strg.size()>0 && palindrome(strg)){
				cnt++;
			}
			strg.clear();
		}
	}
	if(strg.size()>0 && palindrome(strg)){
		cnt++;
	}
	return cnt;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);   //to take the whole string with whitespaces
    int ans=countNumberOfPalindromeWords(s);
    cout<<ans;
}