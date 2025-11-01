// Given an array ‘A’ having ‘N’ integers and an integer ‘m’. You need to rearrange the array elements 
//such that after re-arrangement difference of array elements with ‘m’ should be in a sorted fashion.

// If the difference between any two array elements and ‘m’ is the same, 
//then the element which comes first in the given array will be placed first in the re-arranged array.

// For Example
// If we have A =  [3, 5, 7, 9, 2, 6]  and m = 5.
// Difference of array elements with m : [2, 0, 2, 4, 3, 1].
// Array after rearrangement : [5, 6, 3, 7, 2, 9].
#include<bits/stdc++.h>
using namespace std;

//TC-->O(N^2)
/*vector<int> reArrange(vector<int> &arr , int m){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(arr[j]-m)<abs(arr[i]-m)){
                swap(arr[i],arr[j]);
            } 
        }
    }
    return arr;
}*/
 
//Using lambda function
vector<int> reArrange(vector<int> &arr,int m){
    sort(arr.begin(),arr.end(),[&](int x,int y){
        //returns bool val true or false
        // if x-m is less than y-m then will return true and in sorting x is placed before y
        //and vice versa for y(false)
        return abs(x-m)<abs(y-m);
    });
    return arr;
}

int main(){
    int n,m;
    cout<<"Enter n and m : ";
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result=reArrange(arr,m);
    for(auto it:result){
        cout<<it<<" ";
    }
}