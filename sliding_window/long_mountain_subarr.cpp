#include<bits/stdc++.h>
using namespace std;

//Find the longest contiguous subarray that strictly goes up, reaches exactly one peak, and then strictly goes down.

int longestMountain(vector<int>arr, int n)
{
    if(n<3) return 0;
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            int left=i,right=i;
            while(left>0 && arr[left]>arr[left-1]){
                left--;
            }
            while(right<n-1 && arr[right]>arr[right+1]){
                right++;
            }
            ans=max(ans,right-left+1);
            i=right;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=longestMountain(arr,n);
    cout<<ans;
}