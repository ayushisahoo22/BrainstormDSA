#include <bits/stdc++.h> 
using namespace std;

// given an array ARR of size N, where ARR[i] represents the wallet balance of the i-th friend.
// In one transaction, a friend can transfer exactly K rupees to another friend, provided they have at least K rupees.
// Find the minimum number of transactions required to make all wallet balances equal.
// If it is not possible, return -1.

int minTransactions(int k, vector < int > & arr) {
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);
    if(sum%n!=0) return -1;
    int ans=sum/n;
    int cnt=0;
    for(auto it:arr){
        if((it-ans)%k != 0) return -1;
        if(it>ans){
            cnt+=(it-ans)/k;
        }
    }
    return cnt;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=minTransactions(k,arr);
    cout<<ans;
}