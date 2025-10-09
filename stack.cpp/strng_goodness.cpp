#include <bits/stdc++.h> 
using namespace std;

int goodnessOfString(string &s)
{
    int sum = 0;
    map<int,int> mpp;
    stack<char> st;
    int cnt = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '['){
            st.push(s[i]);
            cnt++;
        } 
        else if(s[i] == ']'){
            if(!st.empty()){
                st.pop();
                cnt--;
            }
        }

        if(isdigit(s[i])){
            int num = 0;
            while(i < s.size() && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++; //as here we increment
                //if the next is not a digit and the pointer incremented so we will decrement it
            }
            i--;   //to get back to the index i for  FOR LOOP
            mpp[num] += cnt;  // to maintain the occurrence of repeated we use += in place of =
            // like for [1, [1, 2]]
        }
    }

    for(auto it : mpp){
        sum += it.first * it.second;
    }
    return sum;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int ans=goodnessOfString(s);
    cout<<ans;
}