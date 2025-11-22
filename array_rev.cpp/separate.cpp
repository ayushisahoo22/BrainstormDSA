#include <bits/stdc++.h>
using namespace std;

//given an array and an integer x
//Ai<x and Ai+1>x or Ai>x and Ai+1<x
//we have to check if in any arrangements it is possible that x not separate the array
//then print yes else no
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        int l=0,g=0,e=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>x) g++;
            else if(arr[i]<x) l++;
            else{
                e++;
            }
        }
        if(l==0 || g==0 ||e>=1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

}