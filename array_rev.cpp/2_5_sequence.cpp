#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    
    //BRUTE FORCE APPROACH
    //TC--->O(N^2)
    vector<long long>ans;
    for(long long i=2;i<=n;i++){
        string s1=to_string(i);
        string s2="";
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='2' || s1[j]=='5'){
                s2+=s1[j];
            }
        }
        if(!s2.empty() && s2.size()==s1.size()){
            ans.push_back(stoll(s2));
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}