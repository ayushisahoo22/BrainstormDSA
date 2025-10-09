#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& v, int n, int k) {
int k_small;
while(k--){
    int smallest=INT_MAX;
    int indx=-1;
    for(int i=0;i<n;i++){
        if(v[i]<smallest && v[i]!=smallest){
            smallest=v[i];
            indx=i;
        }
    }
    v[indx]=INT_MAX;
    k_small=smallest;
    }
    return k_small;
}
int main(){
    int n,k;
    cout<<"Enter the n and k: ";
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=kthSmallest(arr,n,k);
    cout<<ans;
}