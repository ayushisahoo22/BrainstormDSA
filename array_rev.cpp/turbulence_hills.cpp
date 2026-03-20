#include <bits/stdc++.h> 
using namespace std;

// given an array/list HEIGHT denoting the heights of ‘N’ adjacent hills. The hills are said to be dangerous if their heights are turbulent.
// A range of hills is turbulent if the comparison sign for their heights flips between each adjacent pair of hills

int longestDangerousRange(vector<int>& arr, int n)
{   
    if(n==1) return 1;
    int curr=1,ans=1;
    for(int i=1;i<n;i++){
        if(i==1){
            if(arr[i]==arr[i-1])curr=1;
            else curr=2;
        }else{
            if((arr[i-2]<arr[i-1] && arr[i-1]>arr[i])||
                (arr[i-2]>arr[i-1] && arr[i-1]<arr[i])){
                    curr++;
                }
            else if(arr[i]==arr[i-1]) curr=1;
            else curr=2;
        }
        ans=max(ans,curr);
    }
    return ans;
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
    int ans=longestDangerousRange(arr,n);
    cout<<ans;
}