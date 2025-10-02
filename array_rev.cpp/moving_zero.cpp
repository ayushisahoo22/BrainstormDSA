#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    //TC--->O(N)
    //SC--->O(N)
    /*vector<int> temp;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt++;
        }else{
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<cnt;i++){
        temp.push_back(0);
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }*/

    //TC--->O(N)
    //SC--->O(1)
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}