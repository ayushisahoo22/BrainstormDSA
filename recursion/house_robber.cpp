#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int>&nums,int &ans,int curr){
    if(i>=nums.size()){
        ans=max(ans,curr);
        return;
    }
    solve(i+2,nums,ans,curr+nums[i]);
    solve(i+1,nums,ans,curr);
}

int rob(vector<int>& nums) {
    int ans=0;
    solve(0,nums,ans,0);
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=rob(arr);
    cout<<ans;
}