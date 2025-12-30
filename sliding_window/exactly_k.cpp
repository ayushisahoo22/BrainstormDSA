#include<bits/stdc++.h>
using namespace std;

// You are given a string s and an integer k.
// Return the number of substrings of s that contain exactly k distinct characters.
//core--->Exactly K distinct = AtMost(K) − AtMost(K−1)

int atmostK(string s,int k){
    int l = 0;
    int count = 0;
    unordered_map<char, int> freq;
    for (int r = 0; r < s.size(); r++) {
        freq[s[r]]++;
        while (freq.size() > k) {
            freq[s[l]]--;
            if (freq[s[l]] == 0)
                freq.erase(s[l]);
            l++;
        }

        // all substrings ending at r are valid
        count += (r - l + 1);
    }

    return count;
}

int exactlyK(string s,int k){
    if(k==0) return 0;
    return atmostK(s,k)-atmostK(s,k-1);
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int k;
    cout<<"enter k: ";
    cin>>k;
    int ans=exactlyK(s,k);
    cout<<ans;
}