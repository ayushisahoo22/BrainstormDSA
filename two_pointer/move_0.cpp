#include <bits/stdc++.h>
using namespace std;

//Move all the zeroes to the end maintaining the order of other elements

//points to be observed:
//if we keep a pointer j at n-1 and make it swap with i only where arr[i]==0
//(then the order will not be maintained)

//this is a pure two pointer problem cant be solved by sliding window bcz we are fixate with the no of elements
// in the array as cant shrink or expand the window out of requirement
/*vector<int> moveZero(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            int j=i+1;
            while(j<n && arr[j]==0) j++;
            if(j>=n) break;
            swap(arr[i],arr[j]);
        }
    }
    return arr;
}*/

//same can be solved using while loop
//(approach for both is same to keep i at 0 and j at non-0)
vector<int> moveZero(vector<int> &arr,int n){
    int i=0,j=0;
    while(i<n && j<n){
        while(i<n && arr[i]!=0) i++;
        if(arr[i]==0){
            j=i+1;
            while(j<n && arr[j]==0) j++;
            if(j>=n) break;
            swap(arr[i],arr[j]);
        }
        i++;
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
    vector<int>result =moveZero(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
}