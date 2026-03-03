#include<bits/stdc++.h>
using namespace std;

// Given two positive integers n and k, the binary string Sn is formed as follows:
// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// find kth bit of nth binary string

//recursion approach : bcz Si depends on Si-1
//TC->O(N)   SC->O(N)
// char findKthBit(int n,int k){
//     if(n==1) return '0';
//     int len=(1<<n);  //2^n  bcz of 1 based indexing
//     if(k<len/2) return findKthBit(n-1,k);
//     else if(k==len/2) return '1';
//     else{
//         char c=findKthBit(n-1,len-k);  //len-k is for mirror position
//         return (c=='0')?'1':'0';
//     }
// }

//divide and conquer method
//TC->O(N)  SC->O(1)
char findKthBit(int n,int k){
    int invertCount=0;
    int len=(1<<n)-1;
    while(k>1){
        if(k==len/2+1){
            return (invertCount%2==0)?'1':'0';
        }
        if(k>len/2){
            k=len+1-k;
            invertCount++;
        }
        len/=2;
    }
    return (invertCount%2==0)?'0':'1';
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    char ans=findKthBit(n,k);
    cout<<ans;
}