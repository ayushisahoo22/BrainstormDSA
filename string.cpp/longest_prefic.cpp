#include <bits/stdc++.h>
using namespace std;

//failing for ["a","ab","abc"]
// first temp=a
// second temp=ab   --- final will be ab while it should be a

/*string longestCommonPrefix(vector<string>& strs) {
    //no handling of edge cases
    string temp="";  
    for(int i=0;i<strs.size()-1;i++){  //taking i=0
        string curr="";
        int j=i+1;  //j=1
        for(int k=0;k<min(strs[i].size(),strs[j].size());k++){
            if(strs[i][k] == strs[j][k]){   //comparing with the adjacent strings
                curr+=strs[j][k];
            }else{
                break;
            }
        }
        temp=curr;  //overwriting the value of temp 
    }
    return temp;
}*/

//so we will be storing the value of temp and comparing the next string with that simultaneously
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    if(strs.size()==1) return strs[0];  //handling edge cases
    string temp=strs[0];  //temp storing first val
    for(int i=1;i<strs.size();i++){
        string curr="";
        for(int k=0;k<min(temp.size(),strs[i].size());k++){
            if(temp[k] == strs[i][k]){   //comparing with the prefix found so far
                curr+=temp[k];
            }else{
                break;
            }
        }
        temp=curr;
        if(temp.empty()) return "";  //handling edge case
    }
    return temp;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<string> strs(n);
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    string ans=longestCommonPrefix(strs);
    cout<<ans
;}