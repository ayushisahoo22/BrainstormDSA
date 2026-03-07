#include<bits/stdc++.h>
using namespace std;

//LC 17
//we'll use s+c[i] bcz we need combinations char by char

unordered_map<int,vector<char>>mpp={
    {'2',{'a','b','c'}},
    {'3',{'d','e','f'}},
    {'4',{'g','h','i'}},
    {'5',{'j','k','l'}},
    {'6',{'m','n','o'}},
    {'7',{'p','q','r','s'}},
    {'8',{'t','u','v'}},
    {'9',{'w','x','y','z'}}
};
void solve(int ind,string s,vector<string>&res,string digits){
    if(ind==digits.size()){
        res.push_back(s);
        return;
    }
    vector<char> c=mpp[digits[ind]];
    for(int i=0;i<c.size();i++){
        solve(ind+1,s+c[i],res,digits);
    }
}
vector<string> letterCombinations(string digits) {
    string s="";
    vector<string>res;
    solve(0,s,res,digits);
    return res;
}

int main(){
    string digits;
    cout<<"Enter string: ";
    cin>>digits;
    vector<string>res=letterCombinations(digits);
    for(auto it:res){
        cout<<it<<" ";
    }
}