#include<bits/stdc++.h>
using namespace std;

int square(int n) {
    int ans = 0;
    int num = abs(n);

    for (int i = 0; i < num; i++) {
        ans += num;
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int ans= square(n);
    cout<< ans;
}