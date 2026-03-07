#include<bits/stdc++.h>
using namespace std;

//Given a string s, partition s such that every substring of the partition is a palindrome. 
//Return all possible palindrome partitioning of s.

//In que like partitioning, divide string we wont use st+s[i] bcz it will add the char (a,aa...)

bool isPalindrome(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int ind,string st,vector<string>&curr,vector<vector<string>>&res,string s){
    if(ind==s.size()){
        res.push_back(curr);
        return;
    }
    for(int e=ind;e<s.size();e++){
        string part=s.substr(ind,e-ind+1);
        if(isPalindrome(part)){
            curr.push_back(part);
            solve(e+1,st,curr,res,s);
            curr.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    string st="";
    vector<string>curr;
    vector<vector<string>>res;
    solve(0,st,curr,res,s);
    return res;
}

int main(){
    string s;
    cout<<"Enter string s: ";
    cin>>s;
    vector<vector<string>>res=partition(s);
    for(auto it:res){
        for(auto p:it){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}