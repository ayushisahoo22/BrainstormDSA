#include<bits/stdc++.h>
using namespace std;

//Longest Substring Without Repeating Characters
//Given a string s, find the length of the longest substring without repeating characters.

int longestSubstr(string s){
    int n=s.size();
    int i=0;
    int maxi=0;
    unordered_map<char,int>mpp;
    for(int j=0;j<n;j++){
        mpp[s[j]]++;
        while(mpp[s[j]]>1){
            mpp[s[i]]--;
            i++;
        }
        maxi=max(maxi,j-i+1);
    }
    return maxi; 
}
int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    // int k;
    // cout<<"enter k: ";
    // cin>>k;
    int ans=longestSubstr(s);
    cout<<ans;
}
