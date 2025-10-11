#include<bits/stdc++.h>
using namespace std;


//Approach like kadane's algo
//Won't work for diff test cases because we don't want maximum sum
//In kadane's algo we want maximum sum there -ve effects the sum 
//so we reset the sum whenever we find a negative number--> if(sum<0) sum=0

/*int maxLength(vector<int>& arr) {
    int sum=arr[0];
    int ansStart=-1;
    int ansEnd=-1;
    int start=-1;
    for(int i=1;i<arr.size();i++){
        if(sum>0){
            sum-=arr[i-1];
            start=i;
        }
        sum+=arr[i];
        if(sum==0){
            ansStart=start;
            ansEnd=i;
        }
    }
    if(ansStart=-1 || ansEnd==-1){
        return 0;
    }
    else{
        return (ansEnd-ansStart+1);
    }   
 }*/


//Prefix sum approach
//Here sum is fixed(which is 0)
//we won't reset the sum because of any +ve,-ve or 0
//we will track the history to check if we had seen the sum earlier
//and keep it in map with index to find the maximum length

int maxLength(vector<int>& arr) {
    map<int,int>mpp;
    int sum=0;
    int maxLen=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==0){
            maxLen=i+1;
        }
        if(mpp.find(sum)!=mpp.end()){
            int len=i-mpp[sum];
            maxLen=max(len,maxLen);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }
    return maxLen;
}
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=maxLength(arr);
    cout<<ans;
}