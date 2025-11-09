#include <bits/stdc++.h>
using namespace std;

//linear probing
//h(x)=x mod n
vector<int> linearProbing(vector<int> keys)
{
    int n=keys.size();
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        int indx=keys[i]%n;
        while(ans[indx]!=-1 ){
            indx=(indx+1)%n;
        }
        ans[indx]=keys[i];
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result=linearProbing(arr);
    for(auto it: result){
        cout<<it<<" ";
    }
}