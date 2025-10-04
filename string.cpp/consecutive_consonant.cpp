#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            maxi=max(maxi,cnt);
            cnt=0;
        }else{
            cnt++;
        }
    }

    //if there is no vowel in the string
    // s= "bcdf"
    //if condition will not hit and maxi will not be evaluated
    //so keep it outside
    maxi=max(maxi,cnt);   
    
    if(maxi>=4){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}