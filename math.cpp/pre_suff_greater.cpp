#include<bits/stdc++.h>
using namespace std;

//LC-> 3912

vector<int> findValidElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxLeft(n), maxRight(n);

    // maxLeft[i] = max from 0 to i-1
    maxLeft[0] = INT_MIN;
    for(int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i-1], nums[i-1]);
    }

    // maxRight[i] = max from i+1 to n-1
    maxRight[n-1] = INT_MIN;
    for(int i = n-2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i+1], nums[i+1]);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(nums[i] > maxLeft[i] || nums[i] > maxRight[i]) {
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=findValidElements(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
}