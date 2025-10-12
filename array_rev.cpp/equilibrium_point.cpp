#include<bits/stdc++.h>
using namespace std;

//TC---> O(N^2)

/*int findEquilibrium(vector<int> &arr) {
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
}*/


//Optimal approach
//Two pointer approch for positives only

//It wont work for the array containing negative number bcz Negative numbers can reduce a sum.
//So sum1 < sum2 at one step doesn’t guarantee that adding another number from the left moves us closer to equality
//it might move us further away.
//When all numbers are positive → sums always increase, so balance can only happen once.
//When negatives exist → sums can oscillate, so you can skip over the equilibrium index completely.
/*int findEquilibrium(vector<int> &arr) {
    int n=arr.size();
    int i=0;int j=n-1;
    int sum1=0,sum2=0;
    while(i<j){
        if(sum1<sum2){
            sum1+=arr[i];
            i++;
        }else{
            sum2+=arr[j];
            j--;
        }
    }
    if(sum1==sum2){
        return i;
    }
    return -1;
}*/


//Optimal approach-Prefix

//At each index i:
// Subtract arr[i] from totalSum → that becomes the right side sum.
// Compare leftSum and totalSum (after subtraction).
// If they’re equal, we’ve found the equilibrium index.
// Then add arr[i] to leftSum and move on.

int findEquilibrium(vector<int> &arr) {
    int n=arr.size();
    int totalSum=0;
    for(auto it:arr){
        totalSum+=it; //add up the elements at once
    }
    int leftSum=0;
    for(int i=0;i<n;i++){
        totalSum-=arr[i];  //will now work as right sum
        if(leftSum==totalSum){
            return i;
        }
        leftSum+=arr[i];
    }
    return -1;
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