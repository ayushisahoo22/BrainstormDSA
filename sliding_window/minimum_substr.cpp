#include<bits/stdc++.h>
using namespace std;

//LC->76

string minWindow(string s, string t) {
    int mini=INT_MAX;
    int n=s.size(),m=t.size();
    unordered_map<char,int>chars;
    int st=-1;
    for(int i=0;i<m;i++){
        chars[t[i]]++;
    }
    int cnt=0;
    int l=0,r=0;
    while(r<n){
        if(chars[s[r]]>0){
            cnt++;
        }
        chars[s[r]]--;
        while(cnt==m){
            if(r-l+1<mini){
                mini=r-l+1;
                st=l;
            }
            chars[s[l]]++;
            if(chars[s[l]]>0) cnt=cnt-1;
            l++;
        }
        r=r+1;
    }
    return (mini==INT_MAX)?"":s.substr(st,mini);
}

int main(){
    string s,t;
    cout<<"Enter s:";
    cin>>s;
    cout<<"Enter t:";
    cin>>t;
    string res=minWindow(s,t);
    cout<<res;
}