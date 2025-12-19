#include<bits/stdc++.h>
using namespace std;

// Out of all possible pairs of lines,
// find the two that create the largest rectangular area of water.

int maxWater(vector<int>arr,int n){
    int i=0;
    int j=n-1;
    int maxi=0;
    while(i<j){
        int width=j-i;
        int height=min(arr[i],arr[j]);
        maxi=max(maxi,height*width);
        if(arr[i]<arr[j]){
            i++;
        }else{
            j--;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr={5,2,8,6,4};
    int ans=maxWater(arr,5);    
    cout<<ans;
}