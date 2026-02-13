#include<bits/stdc++.h>
using namespace std;

// s is balanced if all distinct characters in the substring appear the same number of times.
// Return the length of the longest balanced substring of s.

//as the string is not monotonic bcz we will appear with char in future which cant be tracked prev
//so the naive soln O(N^2) is used
//its not sliding window as there's no use of shrinking and expanding in one go

int longestBalanced(string s) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        int distinct = 0;
        int maxFreq = 0;
        for(int j = i; j < n; j++) {
            if(freq[s[j] - 'a'] == 0)
                distinct++;
            freq[s[j] - 'a']++;
            maxFreq = max(maxFreq, freq[s[j] - 'a']);
            int length = j - i + 1;
            if(length == distinct * maxFreq) {
                ans = max(ans, length);
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int ans=longestBalanced(s);
    cout<<ans;
}