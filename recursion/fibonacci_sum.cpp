#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
pair<long long,long long> fibonacci(long long n){
    if(n==0) return {0,1};
    pair<long long,long long> p = fibonacci(n/2);
    long long a = p.first;
    long long b = p.second;
    long long c = (a * ((2*b-a+MOD)%MOD)) % MOD;
    long long d = (a*a%MOD + b*b%MOD) % MOD;
    if(n%2==0)
        return {c,d};
    return {d,(c+d)%MOD};
}
int fiboSum(int n , int m)
{
    long long x = fibonacci(m+2).first;
    long long y = fibonacci(n+1).first;

    return (x-y+MOD)%MOD;
}

int main(){
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    int ans = fiboSum(n,m);
    cout<<ans;
}