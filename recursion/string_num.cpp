#include <bits/stdc++.h> 
using namespace std;
void solve(int i,string s,string r,vector<string>&ans){
    if(i==s.size()){
        ans.push_back(r);
        return;
    }
    if(s[i]!='0'){
        int num=s[i]-'0';
        char ch='a'+num-1;
        solve(i+1,s,r+ch,ans);
    }
    if(i+1<s.size()){
        int num=(s[i]-'0')*10+(s[i+1]-'0');
        if(num>=10 && num<=26){
            char ch='a'+num-1;
            solve(i+2,s,r+ch,ans);
        }
    }
}
vector<string> getAllStrings(string& s) {
    // Write your code here
    vector<string>ans;
    solve(0,s,"",ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s;
    cout<<"Enter s: ";
    cin>>s;
    vector<string>res=getAllStrings(s);
    for(auto it:res){
        cout<<it<<" ";
    }
}