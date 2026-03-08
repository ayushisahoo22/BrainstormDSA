#include<bits/stdc++.h>
using namespace std;

//index i is balanced if the sum of elements strictly to the left of i equals the product of elements strictly to the right of i.
// If there are no elements to the left, the sum is considered as 0. 
// Similarly, if there are no elements to the right, the product is considered as 1. else return -1

int smallestBalancedIndex(vector<int>& nums) {
    int n=nums.size();
    int ans=-1;
    vector<long long>sum(n); //calculating prefix sum
    //and not doing for product bcz it will lead to overflow
    sum[0]=nums[0];
    for(int i=1;i<n;i++){
        sum[i]=nums[i]+sum[i-1];
    }
    unsigned long long prod=1;
    for(int i=n-1;i>=1;i--){
        if(sum[i-1]==prod){
            ans=i;
        }
        //when it exceeds the prefix sum it can't be equal to the further prefix sum
        //so break is used for managing overflow ontime
        if(prod>sum[i-1]){
            break;
        }
        prod*=nums[i];
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans=smallestBalancedIndex(nums);
    cout<<ans;
}