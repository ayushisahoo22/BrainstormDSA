#include<bits/stdc++.h>
using namespace std;

//given a positive number n.
// Return the smallest number x greater than or equal to n
// such that the binary representation of x contains only set bits
// eg--> 5(101) to 7(111)  or 10(1010) to 15(1111)

//TC-->O(logN);
//as the seq continues 1,3,7,10.. prev number of every number say x, x=x*2+1 gives the next number
int smallestNumber(int n) {
    int x=1;
    while(x<n){
        x=x*2+1;
    }
    return x;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans=smallestNumber(n);
    cout<<ans;
}