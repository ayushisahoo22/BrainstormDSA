#include<bits/stdc++.h>
using namespace std;

// Given an array arr of size n and an integer k,
// for every contiguous subarray (window) of size k,
// print the first negative number in that window.
// If there is no negative number, print 0.

//here queue is needed to track index bcz we can't easily undo the effect as of sum/count

vector<int> firstNeg(vector<int> arr,int k){
    vector<int>ans;
    queue<int> q;
    int i=0;
    for(int j=0;j<arr.size();j++){
        if(arr[j]<0) q.push(j);
        if(j-i+1>k){
            if(!q.empty() && q.front()==i){
                q.pop();
            }
            i++;
        }
        if(j-i+1==k){
            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(arr[q.front()]);
            }
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    vector<int> result=firstNeg(arr,k);
    for(auto it:result){
        cout<<it<<" ";
    }
}