#include<bits/stdc++.h>
using namespace std;

//Move all the ones to the end
//no need to maintain order here as of moving 0 bcz it is a binary arr

vector<int> moveOne(vector<int>arr,int n){
    int j=n-1;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            while(j>=i && arr[j]==1) j--;
            if(j<i) break;
            swap(arr[i],arr[j]);
        }
    }
    return arr;
}

int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>result =moveOne(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
}