#include <bits/stdc++.h>
using namespace std;

// Given an array of integers arr and an integer k
// find the maximum sum of any contiguous subarray of size k.

int maxLen(vector<int>arr,int k){
    int maxi=0;
    int i=0;
    int sum=0;
    for(int j=0;j<arr.size();j++){
        sum+=arr[j];
        if(j-i+1>k){
            sum-=arr[i];
            i++;
        }
        if(j-i+1==k){
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

int main() {
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
    int ans=maxLen(arr,k);
    cout<<ans;
}