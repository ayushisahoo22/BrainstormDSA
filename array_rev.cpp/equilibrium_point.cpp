#include<bits/stdc++.h>
using namespace std;

//TC---> O(N^2)

int findEquilibrium(vector<int> &arr) {
    // int indx=-1;
    for(int i=0;i<arr.size();i++){
        int sum1=0,sum2=0;
        for(int j=i-1;j>=0;j--){
            sum1+=arr[j];
        }
        for(int k=i+1;k<arr.size();k++){
            sum2+=arr[k];
        }
        if(sum1==sum2){
            // indx=i; this will change if it found another pair later

            return i;
        }
    }
    return -1;  //if no i exists then return -1
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=findEquilibrium(arr);
    cout<<ans;
}