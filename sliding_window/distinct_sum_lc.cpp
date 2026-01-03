#include<bits/stdc++.h>
using namespace std;

// given an integer array nums and an integer k.
// Return the minimum length of a subarray whose sum of the distinct values 
//present in that subarray(each value counted once) is at least k.
// If no such subarray exists, return -1.


//core of the prblm
// Window may have duplicates
// distinctSum = sum of values with freq >= 1

int distinctSumLen(vector<int>arr,int k){
    unordered_map<int,int>mpp;
    int sum=0;
    int mini=INT_MAX;
    int i=0;
    for(int j=0;j<arr.size();j++){
        if(mpp.find(arr[j])==mpp.end()){
            sum+=arr[j];
        }
        mpp[arr[j]]++;
        while(sum>=k){
            mini=min(mini,j-i+1);
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0){
                mpp.erase(arr[i]);
                sum-=arr[i];
            }
            i++;
        }
    }
    return (mini==INT_MAX)?-1:mini;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int len=distinctSumLen(arr,k);
    cout<<len;
}