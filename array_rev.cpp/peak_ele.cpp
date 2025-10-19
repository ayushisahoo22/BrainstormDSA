#include<bits/stdc++.h>
using namespace std;

//return the index of peak element in an array
//last and first element can be the peak element also
int peakElement(vector<int> &arr) {
    int n=arr.size();
    if(n==1) return 0;  //if there exists only one element
    if(arr[0]>arr[1]) return 0;  //if first element is peak(for n==2 like [-3,-5])
    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            return i;
        }
    }
    if(arr[n-1]>arr[n-2]) return n-1;  //if last element is peak  (for n==2 like [-5,-3])
    return -1;  //if no peak element exists
}
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=peakElement(arr);
    cout<<ans;
}