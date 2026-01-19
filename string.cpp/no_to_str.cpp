#include <bits/stdc++.h> 
using namespace std;

//convert number to string(indian system)
//1<=n<=999999999

string ones[]={
    "zero","one","two","three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"
};
string tens[]{
    "","","twenty","thirty","forty","fifty","sixty","seventy",
    "eighty","ninety"
};
string twoDig(int n){
    if(n<20){
        return ones[n];
    }
    return tens[n/10]+((n%10)?" "+ones[n%10]:"");
}
string handleAll(int n)
{
    string res="";
    if(n>=10000000){
        res+=twoDig(n/10000000)+" crore";
        n%=10000000;
        if(n>0) res+=" ";
    }
    if(n>=100000){
        res+=twoDig(n/100000)+" lakh";
        n%=100000;
        if(n>0) res+=" ";
    }
    if(n>=1000){
        res+=twoDig(n/1000)+" thousand";
        n%=1000;
        if(n>0) res+=" ";
    }
    if(n>=100){
        res+=twoDig(n/100)+" hundred";
        n%=100;
        if(n>0) res+=" ";
    }
    if(n>0 && n<100 && !res.empty() && res.back()!='d'){
        res+="and ";
    }
    if(n>0){
        res+=twoDig(n);
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    string result=handleAll(n);
    cout<<result;
}