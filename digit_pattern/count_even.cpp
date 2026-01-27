#include<bits/stdc++.h>
using namespace std;

//TC->O(1)
//count(A → B) = count(1 → B) − count(1 → A−1)
//for handling large a and b as they will throw tle
//we will observe pattern and perform the task without looping from a to b

long long int countEven(int a,int b){

    //even no from [1,n]= n/2
    int c=b/2;
    c-=(a-1)/2;
    return c;
}

int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    int ans=countEven(a,b);
    cout<<ans;
}