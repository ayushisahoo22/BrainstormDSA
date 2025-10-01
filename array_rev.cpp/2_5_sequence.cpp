#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    
    //BRUTE FORCE APPROACH
    //TC--->O(NlogN)
    /*vector<long long>ans;
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
    }*/

    //BRUTE FORCE 2
    /*vector<long long>ans;
    ans.push_back(2);  //pushing 2 in the ans
    ans.push_back(5);  //pushing 5 in the ans
    for(auto it:ans){
        string s1=to_string(it);    //converting them to string
        for(auto it:ans){
            string s2=to_string(it);   //iterating again and converting them to string
            int l=stoll(s1+s2);        //concating s1 and s2 (2,5,22,25,52,55)
            if(l<=n){
                ans.push_back(l);
            }
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }*/


    //OPTIMAL Approach
    vector<long long>ans;
    ans.push_back(2);  //pushing 2 in the ans
    ans.push_back(5);  //pushing 5 in the ans
    for(int i=0;i<ans.size();i++){   //size (2-->4(due to addition of a & b of 2)-->6(due to addition of a & b of 5))
        long long x=ans[i];
        long long a=x*10+2;
        long long b=x*10+5;
        if(a<=n && b<=n){
            //dynamically increasing size while pushing a,b
            ans.push_back(a);  
            ans.push_back(b);
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}