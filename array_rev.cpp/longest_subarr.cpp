#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter the n: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //FOR positive num containing array
    map<long long,int>preSum;
    int maxLen=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];  //summing the element
        if(sum==k){  //if sum is k then give its maxLen
            maxLen=max(maxLen,i+1);
        }
        int rem=sum-k;    //rem is the prefix sum part sum-k
        if(preSum.find(rem) != preSum.end()){   //if we find rem in map
            int len=i-preSum[rem];              //check for its length
            maxLen=max(maxLen,len);            //compare for maximum of lengths
        }
        preSum[sum]=i;  //always store the sum with its index
    }
    cout<<maxLen;
}