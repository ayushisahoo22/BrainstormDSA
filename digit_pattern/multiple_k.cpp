#include<bits/stdc++.h>
using namespace std;

long long int multipleK(int a,int b,int k){
    int c=b/k;  //[1...b]
    c-=((a-1)/k);   //[1...a-1]
    return c;
}

int main(){
    int a,b,k;
    cout<<"Enter a,b and k: ";
    cin>>a>>b>>k;
    int ans=multipleK(a,b,k);
    cout<<ans;
}