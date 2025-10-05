#include <bits/stdc++.h> 
using namespace std;
int stringMania(int n, int m, string str1, string str2) {


    /*for(int i=0;i<min(m,n);i++){
        if(str1[i]>str2[i]){
            return 1;
        }else if(str1[i]<str2[i]){
            return -1;
        }
    }*/

    //String already support lexicographical comparison using operators <, >, ==, etc.
    //so instead of manually looping and checking ASCII values,we could directly compare
    if(str1>str2){return 1;}
    if(str2>str1){return -1;}
    if(n>m){
        return 1;
    }else if(m>n){
        return -1;
    }else{
        return 0;
    }
}

int main(){
    string s1,s2;
    int n,m;
    cout<<"Enter the length of s1 & s2 :";
    cin>>n>>m;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter strign 2: ";
    cin>>s2;
    int ans=stringMania(n,m,s1,s2);
    cout<<ans;
}