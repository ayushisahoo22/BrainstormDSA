#include<bits/stdc++.h>
using namespace std;

// You are given an integer array nums with the following properties:
// nums.length == 2 * n.
// nums contains n + 1 unique elements.
// Exactly one element of nums is repeated n times.

//PIGEONHOLE PRINCIPLE

int repeatedNTimes(vector<int>& nums) {
    //checking on subarray of 3 length
    for(int i=0;i<nums.size()-2;i++){
        //if two elements are equal in a window
        if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
            return nums[i];  //return it
        }
    }
    return nums.back(); //for edge case [3,1,2,3]
    //as window can't check for two adjacent 3 and as it is guaranteed there an element
    //the .back() will be that element only
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }
    int ans=repeatedNTimes(arr);
    cout<<ans;
}