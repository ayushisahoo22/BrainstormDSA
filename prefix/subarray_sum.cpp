#include<bits/stdc++.h>
using namespace std;

//LC-209

int subarraySum(vector<int>arr,int n,int target){
    vector<int>prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr[i-1];
    }
    int ans=INT_MAX;
    for(int j=1;j<=n;j++){
        int need=prefix[j]-target;
        int pos=upper_bound(prefix.begin(),prefix.begin()+j,need)-prefix.begin();
        if(pos>0){
            int i=pos-1;
            ans=min(ans,j-i);
        }
    }
    return ans;
}

int main(){
    int n,target;
    cout<<"Enter n and target: ";
    cin>>n>>target;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=subarraySum(arr,n,target);
    cout<<ans;
    return 0;
}