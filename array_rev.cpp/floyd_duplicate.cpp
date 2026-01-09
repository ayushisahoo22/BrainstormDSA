#include <bits/stdc++.h>
using namespace std;

// given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once.
// There is a single integer value that is present in the array twice.
// Your task is to find the duplicate integer value present in the array.

int findDuplicate(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: detect cycle
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Phase 2: find entry of cycle
    fast = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =findDuplicate(arr);
    cout<<ans;
}