#include<bits/stdc++.h>
using namespace std;

vector<int>productExcept(vector<int>arr,int n){
    int left=1,right=1;
    vector<int>res(n,1);
    for(int i=0;i<n;i++){
        res[i]*=left;  
        left*=arr[i];  //prefix

        res[n-1-i]*=right;
        right*=arr[n-i-1];  //suffix
    }
    return res;
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
    vector<int>res=productExcept(arr,n);
    for(auto it:res){
        cout<<it<<" ";
    }
}