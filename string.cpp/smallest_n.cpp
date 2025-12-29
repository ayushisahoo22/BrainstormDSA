#include<bits/stdc++.h>
using namespace std;

// given two positive integers ‘N’ and ‘K’.find the smallest ‘N’ digit number whose sum of digits equals ‘K’.
// If no such number exists then you need to print -1.

//eg-> 2,8 = 17
string smallestNumber(int n,int k){
    if(k==0 || k>n*9) return "-1";
    if(n==1){
        if(k>=0 && k<=9) return to_string(k);
        else return "-1";
    }
    vector<int> digits(n,0);
    digits[0]=1;
    k-=1;
    for(int i=n-1;i>=0 && k>0;i--){
        int add=min(9,k);
        digits[i]+=add;
        k-=add;
    }
    string s="";
    for(auto it:digits){
        s.push_back('0'+it);
    }
    return s;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    string ans=smallestNumber(n,k);
    cout<<ans;
}