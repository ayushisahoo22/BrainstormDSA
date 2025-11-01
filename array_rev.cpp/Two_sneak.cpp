#include<bits/stdc++.h>
using namespace std;

// there was a list of numbers called nums containing integers from 0 to n - 1. 
// Each number was supposed to appear exactly once in the list, however,
// two mischievous numbers sneaked in an additional time, making the list longer than usual.


vector<int> getSneakyNumbers(vector<int>& nums) {
    int ans=0;
    int n=nums.size()-2;
    for(int num:nums){
        ans^=num;   //xor of nums
    }
    for(int i=0;i<n;i++){
        ans^=i;      //xor of index
    }

    //to provide the rightmost set bit
    //isolates the lowest bit where x and y differ
    //eg--> for 3
    // n = 0011
    // -n = 1101
    // n & -n = 0001
    int diff=ans & -ans;
    int a=0;      //One group where that bit is 0
    int b=0;     //One group where that bit is 1
    for(int num:nums){
        if((num & diff)==0) a^=num;    //for nums
        else b^=num;
    }
    for(int i=0;i<n;i++){
        if((i & diff)==0) a^=i;   //for index
        else b^=i;
    }
    return {a,b};
}


int main(){
    int n;
    cout<<"Enter n ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result= getSneakyNumbers(arr);
    for(auto it:result){
        cout<<it<<" ";
    }
}