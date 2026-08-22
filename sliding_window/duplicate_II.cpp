#include<bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int>st;
    int i=0;
    for(int j=0;j<nums.size();j++){
        if(st.count(nums[j])) return true;
        st.insert(nums[j]);
        while(j-i>=k){
            st.erase(nums[i]);
            i++;
        }
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=containsNearbyDuplicate(arr,k);
    cout<<ans;
}