#include<bits/stdc++.h>
using namespace std;

//Longest Subarray with At Most K Zeros
// You are given a binary array arr (containing only 0 and 1) and an integer k.
// You can flip at most k zeros to ones.
// Return the length of the longest contiguous subarray that contains at most k zeros.

int oneAfterFlip(vector<int>arr,int k){
    int i=0;
    int cnt=0;
    int maxLen=0;
    for(int j=0;j<arr.size();j++){
        if(arr[j]==0) cnt++;
        while(cnt>k){
            if(arr[i]==0) cnt--;
            i++;
        }
        maxLen=max(maxLen,j-i+1);
    }
    return maxLen;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int ans=oneAfterFlip(arr,k);
    cout<<ans;
}