#include<bits/stdc++.h>
using namespace std;

//Check If Array Can Be Made Strictly Increasing by Removing One Element

//by one pointer

int main(){
    vector<int> arr={1,2,3,5,4,2};
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            cnt++;
        }
    }
    if(cnt>1) cout<<"NO";
    else cout<<"YES";
}