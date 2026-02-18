#include<bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n) {
    int cur = n % 2;
    n /= 2;
    while (n > 0) {
        if (cur == n % 2) return false;
        cur = n % 2;
        n /= 2;
    }
    return true;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    bool ans=hasAlternatingBits(n);
    cout<<ans;
}