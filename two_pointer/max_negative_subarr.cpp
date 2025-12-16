#include <bits/stdc++.h>
using namespace std;

//find maximum length of subarray containing negative integers
//eg->{-3,-9,0,-4,-5,-6,7} ans will be 3 as max length is of
// -4,-5,-6 

//One pointer approach
/*int maxNegative(vector<int> arr,int n){
    int len=0;
    int curr=0;
    for(int j=0;j<n;j++){
        if(arr[j]<0){
            curr++;
            len=max(len,curr);
        }else{
            curr=0;
        }
    }
    return len;
}*/

//Two pointer approach
int maxNegative(vector<int> arr,int n){
    int len=0;
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[j]>0){
           i=j+1; 
        }
        len=max(len,j-i+1);
    }
    return len;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=maxNegative(arr,n);
    cout<<ans;
}