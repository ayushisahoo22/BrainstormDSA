#include<bits/stdc++.h>
using namespace std;

    //using stack approach--LIFO
    //pushing whenever we find a opening bracket
    //popping the upper one in stack whose closing bracket is seen first
    // for {()}
    //      |        |
    //      |    (   |      //popping ( as next is )
    //      |____{___|      //popping { as next is }
    //if stack is empty then the pair of all brackets are balanced 
bool isBalanced(string& s){
    stack<char> st;
    for(auto it:s){
        if(it=='(' || it=='{' || it=='['){
            st.push(it);
        }else{
            if(st.empty()) return false;  //if there is no element pushed
            char top=st.top();
            if((it==')' && top!='(')||
                (it=='}' && top!='{')||
                (it==']' && top!='[')
            ) return false;
            st.pop();
        }
    }
    return st.empty();      //can be used in place of if(st.empty()) then else
}

int main(){
    string s;
    cout<<"Enter brackets: ";
    cin>>s;
    bool ans=isBalanced(s);
    if(ans){
        cout<<"Balanced";
    }else{
        cout<<"Unbalanced";
    }
}