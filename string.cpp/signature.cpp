#include<bits/stdc++.h>
using namespace std;

//Find the lexicographically smallest string that appears in every contiguous subarray of size k.

string find_persistent(int n, int k, vector<string> signatures) {

    // EDGE CASE: no window of size k exists
    if (k > n) return "None";
    unordered_map<string, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[signatures[i]].push_back(i);
    }
    string answer = "";
    bool found = false;
    for (auto &it : pos) {
        const string &sig = it.first;
        const vector<int> &v = it.second;
        int prev = -1;
        int maxGap = 0;
        for (int idx : v) {
            maxGap = max(maxGap, idx - prev);
            prev = idx;
        }
        maxGap = max(maxGap, n - prev);
        if (maxGap <= k) {
            if (!found || sig < answer) {
                answer = sig;
                found = true;
            }
        }
    }

    return found ? answer : "None";
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string ans=find_persistent(n,k,arr);
    cout<<ans;
}
