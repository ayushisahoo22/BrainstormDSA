#include <bits/stdc++.h>
using namespace std;

//The array contain elements-1,2 &3
//make the array good by removing any element if it makes 4 by adding with another element
//give the minimum deletion of elements required
int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) cnt1++;
        else if(arr[i]==2) cnt2++;
        else{
            cnt3++;
        }
    }
    int del=0;
    del+=min(cnt1,cnt3);
    if(cnt2>=2){
        del+=max(0,cnt2-1);
    }
    cout<<del<<endl;

}