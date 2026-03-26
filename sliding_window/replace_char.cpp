#include<bits/stdc++.h>
using namespace std; 

int characterReplacement(string s, int k) {
    int i=0;
    int cnt=0;
    int maxi=0;
    vector<int>v(26,0);
    for(int j=0;j<s.size();j++){
        v[s[j]-'A']++;
        cnt=max(cnt,v[s[j]-'A']);
        while((j-i+1)-cnt>k){
            v[s[i]-'A']--;
            i++;
        }
        maxi=max(maxi,j-i+1);
    }
    return maxi;
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int k;
    cout<<"Enter k: ";
    cin>>k;
    int ans=characterReplacement(s,k);
    cout<<ans;
}