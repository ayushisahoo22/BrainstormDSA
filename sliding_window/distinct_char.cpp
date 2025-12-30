#include<bits/stdc++.h>
using namespace std;

// You are given a string s and an integer k.
// Return the length of the longest substring that contains at most k distinct characters.

int longestSubstr(string s,int k){
    int n=s.size();
    int i=0;
    int maxi=0;
    unordered_map<char,int>mpp;
    for(int j=0;j<n;j++){
        mpp[s[j]]++;
        while(mpp.size()>k){
            mpp[s[i]]--;
            if(mpp[s[i]]==0){
                mpp.erase(s[i]);
            }
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
    int k;
    cout<<"enter k: ";
    cin>>k;
    int ans=longestSubstr(s,k);
    cout<<ans;
}