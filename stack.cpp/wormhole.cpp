#include<bits/stdc++.h>
using namespace std;

//LC->1190

string reverseParentheses(string s) {
    int n=s.size();
    vector<int>pairs(n),st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push_back(i);
        }else if(s[i]==')'){
            pairs[i]=st.back();
            pairs[pairs[i]]=i;
            st.pop_back();
        }
    }
    string res;
    int dir=1;
    for(int i=0;i<n;i+=dir){
        if(s[i]>='a'){
            res+=s[i];
        }else{
            i=pairs[i];
            dir=-dir;
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    string res=reverseParentheses(s);
    cout<<res;
}