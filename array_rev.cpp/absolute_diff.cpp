#include <bits/stdc++.h>
using namespace std;

int main(){   
    int n;
    cout<<"Enter the val of n: ";
    cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }


    //APPROACH IS NOT WORKING FOR all Test cases as it is a greedy approach
    //This greedy strategy optimizes locally for each arr1[i], but not globally for all pairs.

    /*vector<pair<int,int>> ans;
    vector<bool> used(n, false);   //track use of all elements

    for(int i = 0; i < n; i++) {
        int minDiff = INT_MAX;
        int first = arr1[i], second = -1, idx = -1;

        for(int j = 0; j < n; j++) {
            if(!used[j]) {  // to check not used
                if(abs(arr1[i] - arr2[j]) < minDiff) {
                    minDiff = abs(arr1[i] - arr2[j]);
                    second = arr2[j];
                    idx = j;   // to remember which j we used
                }
            }
        }

        if(second != -1) {
            ans.push_back({first, second});   // push only once
            used[idx] = true;                 // mark it used
        }
    }

    int cnt = 0;
    for(auto &p : ans){
        cnt += abs(p.first - p.second);
    }
    return cnt;*/


    //Complexity: O(n log n)
    //This works because of the Rearrangement Inequality in math:
            //If both sequences are sorted in the same order, the sum of absolute differences is minimized.
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=abs(arr1[i]-arr2[i]);
    }
    cout<<cnt;
}