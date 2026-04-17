#include<bits/stdc++.h>
using namespace std;

//LC-1423

int maxScore(vector<int>arr,int n,int k){
    int leftS=0;
    for(int i=0;i<k;i++){
        leftS+=arr[i];
    }
    int rightS=0;
    int rightInd=n-1;
    int sum=0;
    for(int i=k-1;i>=0;i--){
        leftS-=arr[i];
        rightS+=arr[rightInd];
        rightInd--;
        sum=max(sum,leftS+rightS);
    }
    return sum;
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
    int ans=maxScore(arr,n,k);
    cout<<ans;
}