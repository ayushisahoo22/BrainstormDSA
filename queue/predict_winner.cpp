#include <bits/stdc++.h>
using namespace std;
int predictTheWinner(int n, int k) {
    list<int> v;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    auto it = v.begin();
    while(v.size() > 1) {
        for(int i = 1; i < k; i++) {
            it++;
            if(it == v.end())
                it = v.begin();
        }
        // Remove current person
        it = v.erase(it);
        // If we reached end, go back to beginning
        if(it == v.end())
            it = v.begin();
    }

    return *it;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    int ans=predictTheWinner(n,k);
    cout<<ans;
}