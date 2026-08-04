#include<bits/stdc++.h>
using namespace std;

int rotationCnt(vector<int>&arr,int n){
    int s=0;
    int e=n-1;
    int ans=INT_MAX;
    int i=-1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[s]<=arr[mid]){
            if(arr[s]<ans){
                ans=arr[s];
                i=s;
            }
            s=mid+1;
        }else{
            if(arr[mid]<ans){
                ans=arr[mid];
                i=mid;
            }
            e=mid-1;
        }
    }
    return i;
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
    int ans=rotationCnt(arr,n);
    cout<<ans-0;
    return 0;
}