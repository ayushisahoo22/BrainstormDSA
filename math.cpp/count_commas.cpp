#include<bits/stdc++.h>
using namespace std;

// Return the total number of commas used when writing all integers from [1, n] (inclusive).
// A comma is inserted after every three digits from the right.

long long countCommas(long long n) {
    if(n<1000) return 0;
    long long ans=0;
    long long p=1000;
    while(p<=n){
        ans+=(n-p+1);
        p*=1000;
    }
    return ans;
}

int main(){
    long long n;
    cout<<"Enter n: ";
    cin>>n;
    long long ans=countCommas(n);
    cout<<ans;
}