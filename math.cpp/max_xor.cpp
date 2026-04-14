#include <bits/stdc++.h> 
using namespace std;

// find the maximum possible value of ‘X’ such that the following two conditions hold.
// a ⊕ b = X, where ⊕ denotes bitwise xor operation.
// Both numbers ‘a’ and ‘b’ belong to the array ‘A’ of range L-R.

int maxXor(int L, int R)
{
    if(L==R) return 0;
    int n=L^R;
    int msb=0;
    while(n>1){
        n>>=1;
        msb++;
    }
    int res=(1<<(msb+1))-1;
    return res;
}

int main(){
    int l,r;
    cout<<"Enter l and r: ";
    cin>>l>>r;
    int ans=maxXor(l,r);
    cout<<ans;
}