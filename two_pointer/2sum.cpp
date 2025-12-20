#include<bits/stdc++.h>
using namespace std;

// You are given a sorted array of integers and a target value sum.
// here sorted plays an imp role to move the pointers
// find two values from array which sum up to target
// dont use hashmap

int main(){
    vector<int>arr={1,2,3,4,6,8,9};
    int sum;
    cout<<"Enter sum: ";
    cin>>sum;
    int i=0,j=6;
    while(i<j){
        if(arr[i]+arr[j]==sum){
            cout<<arr[i]<<" "<<arr[j];
            break;
        }else if(arr[i]+arr[j]>sum){
            j--;
        }else{
            i++;
        }
    }
}