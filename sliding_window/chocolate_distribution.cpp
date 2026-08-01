#include<bits/stdc++.h>
using namespace std;

int chocolateD(vector<int>arr,int n,int m){
    if(m>n) return -1;
    sort(arr.begin(),arr.end());
    int i=0,j=m-1;
    int mini=INT_MAX;
    while(j<n){
        mini=min(mini,arr[j]-arr[i]);
        i++;
        j++;
    }
    return mini;
}

int main(){
    int n,m;
    cout<<"Enter n and no of students(m): ";
    cin>>n>>m;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int diff=chocolateD(arr,n,m);
    cout<<diff;
    return 0;
}