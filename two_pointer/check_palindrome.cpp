#include <bits/stdc++.h>
using namespace std;

//check if the array is palindrome by allowing atmost removal of one elemnt

//here i used counter to check if cnt>1 then return false otherwise skip that element by comparing
//but as by skipping an ele, both the sides can be checked for palindrome

bool isPalin(vector<int>arr,int s,int e){
    while(s<=e){
        if(arr[s]!=arr[e]) return false;
        s++;
        e--;
    }
    return true;
}

bool checkPalindrome(vector<int> arr){
    int n=arr.size();
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            return (isPalin(arr,i+1,j) || isPalin(arr,i,j-1));
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    bool ans=checkPalindrome(arr);
    cout<<ans;
}