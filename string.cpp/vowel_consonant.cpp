#include <bits/stdc++.h>
using namespace std;

//consonant will be swapped with consonant and vowel will be swapped with vowels only
bool isVowel(char c){  //will always return a val-true of false
    string s="AEIOU";
    if(s.find(c)!=string::npos){  //in string there is no s.end() we will use string::npos
        return true;
    }
    return false;   //can't skip this
}

int main() {
	int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        string target="CODETOWN";
        bool reach=true;
        if(s.size()!=target.size()){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<8;i++){
            bool sVowel=isVowel(s[i]);
            bool tVowel=isVowel(target[i]);
            if(sVowel!=tVowel){
                reach=false;
                break;
            }
        }
        if(reach){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}