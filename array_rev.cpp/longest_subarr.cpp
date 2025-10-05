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

    //Better for positive and zeroes elements
    //Optimal for negative nums

    /*map<long long,int>preSum;
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

        //not to reupdate sum's index bcz we want to be at as left as possible for longest subarr of k
        //eg---> 2,0,0,3
        //if we update 2 for index 2 then the target 3 will have subarr [3] of len 1
        //so in map 2 with index 0 and target 3 will have subarr[0,0,3] of len 3

        if(preSum.find(sum)==preSum.end()){         
            preSum[sum]=i;  //always store the sum with its index
        }
        
    }
    cout<<maxLen;*/

    // Two pointer approach for positives and zeroes(OPTIMAL)
    int right=0,left=0;
    int sum=arr[right];
    int maxLen=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    cout<<maxLen;
}