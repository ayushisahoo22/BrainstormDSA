#include <bits/stdc++.h> 
using namespace std;

// given an array of integers "ARR" of length 'N' and an integer 'K'.
// task is to find whether or not you can divide the array "ARR" into 'K' subsets with equal sum.

bool solve(int idx, vector<int> &arr, vector<int> &bucket, int target) {
    // all elements are used
    if(idx == arr.size())
        return true;

    int val = arr[idx];
    // try placing current element in every subset
    for(int i = 0; i < bucket.size(); i++) {

        // cannot exceed target sum
        if(bucket[i] + val > target)
            continue;

        bucket[i] += val;
        if(solve(idx + 1, arr, bucket, target))
            return true;

        // backtrack
        bucket[i] -= val;

        // optimization
        if(bucket[i] == 0)
            break;
    }
    return false;
}

bool splitArray(vector<int> &arr, int K) {
    int sum = 0;
    for(int x : arr)
        sum += x;

    // total sum must be divisible by K
    if(sum % K != 0)
        return false;

    int target = sum / K;

    // sort descending for pruning
    sort(arr.rbegin(), arr.rend());

    // largest element itself greater than target
    if(arr[0] > target)
        return false;

    vector<int> bucket(K, 0);
    return solve(0, arr, bucket, target);
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
    bool ans=splitArray(arr,k);
    cout<<ans;
}