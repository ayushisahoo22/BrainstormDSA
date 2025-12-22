#include <bits/stdc++.h>
using namespace std;

//remove duplicate after atmost 2 occurence of the element
//eg-> [1,2,2,2,3,3]--->[1,2,2,3,3](len=5)

int removeAfter2(vector<int> &arr){
    int i=0;
    int cnt=0;
    for(int j=0;j<arr.size();j++){
        if(j==0 || arr[j]!=arr[j-1]){
            cnt=1;
        }else{
            cnt++;
        }
        if(cnt<=2){
            arr[i]=arr[j];
            i++;
        }
    }
    return i;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int> arr;
    //enter array in sorted manner
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    int len=removeAfter2(arr);
    cout<<len;
}