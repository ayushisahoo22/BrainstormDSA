#include<bits/stdc++.h>
using namespace std;

//add two binary strings a and b

string addBinary(string a, string b) {
    int i=a.size()-1;
    int j=b.size()-1;
    string res="";
    int carry=0;
    while(i>=0 || j>=0 || carry>0){
        int sum=carry;
        if(i>=0) sum+=(a[i--]-'0');
        if(j>=0) sum+=(b[j--]-'0');
        res+=to_string(sum%2);
        carry=sum/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    string ans=addBinary(a,b);
    cout<<ans;
}