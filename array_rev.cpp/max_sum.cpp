#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cout<<"Enter the chances k: ";
    cin>>k;
    cout<<"Enter the no of element of arr: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;
    while(k--){
        int maxi=INT_MIN;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                idx=i;    //idx is the index of current max value
            }
        }
        sum+=maxi;
        if(idx!=-1){   //if idx exists
            arr[idx]=INT_MIN;     //converting that ele to the minimum 
                                  //so that it will not be used as maxi in next iteration
        }
    }
    cout<<sum<<endl;
}