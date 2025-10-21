#include <bits/stdc++.h> 
using namespace std;

//find the length of the longest substring without repeating characters
//i.e return a substring that does not have any repeating characters.
//eg--> abcabcbb, ans=3(abc is longest substr)

int uniqueSubstrings(string input)
{
    unordered_map<char,int>mpp;  //tracking the strings
    int maxLen=0;
    int i=0; //using two pointer
    for(int j=0;j<input.size();j++){
        char c=input[j];
        if(mpp.find(c)!=mpp.end() && mpp[c]>=i){
            i=mpp[c]+1;
        }
        mpp[c]=j;
        maxLen=max(maxLen,j-i+1);
    }
    return maxLen;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int ans=uniqueSubstrings(s);
    cout<<ans;
}