#include<bits/stdc++.h>
using namespace std;

// given an integer array arr and an integer k.
// Return an array containing the maximum element in every contiguous subarray of size k.

//using pq---TC=O(NlogN)
// vector<int> maxInWindow(vector<int>arr,int k){
//     priority_queue<pair<int,int>> pq;
//     vector<int>ans;
//     int i=0;
//     for(int j=0;j<arr.size();j++){
//         pq.push({arr[j],j});
//         if(j-i+1>k){
//             i++;
//         }
//         if(j-i+1==k){
//             while(!pq.empty() && pq.top().second<i){
//                 pq.pop();
//             }
//             ans.push_back(pq.top().first);
//         }
//     }
//     return ans;
// } 

//using deque---TC=O(N)
vector<int> maxInWindow(vector<int>arr,int k){
    deque<int> dq;
    vector<int>ans;
    int i=0;
    for(int j=0;j<arr.size();j++){
        //Remove smaller elements (maintain decreasing order)
        while(!dq.empty() && arr[dq.back()]<arr[j]){
            dq.pop_back();
        }

        //pushing element
        dq.push_back(j);

        //after window slides if max is not in the curr window
        while(!dq.empty() && dq.front()<i){
            dq.pop_front();
        }
        if(j-i+1==k){
            ans.push_back(arr[dq.front()]);
            i++;
        }
    }
    return ans;
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
    vector<int> result=maxInWindow(arr,k);
    for(auto it:result){
        cout<<it<<" ";
    }
}