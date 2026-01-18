#include<bits/stdc++.h>
using namespace std;

// find the position of the only set bit in the binary representation of the input integer ‘N’.
// The position of the set bit must be counted from the LSB
// If the count of set bits in the Binary number is not equal to 1, 
// then your function should return '-1'

int findSetBit(int N) {   
    if((N==0) || (N&(N-1))!=0){
        return -1;
    }
    int pos=1;
    while((N&1)==0){
        N>>=1;
        pos++;
    }
    return pos;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=findSetBit(n);
    cout<<ans;
}