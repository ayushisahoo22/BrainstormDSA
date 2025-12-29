#include<bits/stdc++.h>
using namespace std;

// You are given an integer array arr and an integer k.
// Return the length of the longest contiguous subarray that contains at most k distinct integers.

int countDist(vector<int>arr,int k){
    int i=0;
    int maxLen=0;
    unordered_map<int,int>mpp;
    for(int j=0;j<arr.size();j++){
        mpp[arr[j]]++;
        while(mpp.size()>k){
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0){
                mpp.erase(arr[i]);
            }
            i++;
        }
        maxLen=max(maxLen,j-i+1);
    }
    return maxLen;
}

int main(){
    vector<int>arr;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int ans=countDist(arr,k);
    cout<<ans;
}