#include<bits/stdc++.h>
using namespace std;

int findNumber(int n)
{
    n--;
    int ans=0;
    int place=1;
    while(n>0){
        int d=n%6;
        ans+=(d*place);
        place*=10;
        n/=6;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans=findNumber(n);
    cout<<ans;
}