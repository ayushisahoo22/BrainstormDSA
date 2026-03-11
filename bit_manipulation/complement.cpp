#include<bits/stdc++.h>
using namespace std;

//complement no n

int bitwiseComplement(int n) {
    if(n==0) return 1;

    //__builtin_clz is used to count leading zeroes
    //32-__buitin_clz is done to count the significant bits
    //mask is generated of 1,11,111.. as per the bitlenth

    int mask=(1<<(32-__builtin_clz(n)))-1;
    return n^mask;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=bitwiseComplement(n);
    cout<<ans;
}