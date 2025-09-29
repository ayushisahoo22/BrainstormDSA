#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of n: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int first=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=first;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}