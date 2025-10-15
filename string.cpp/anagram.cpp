#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string s,string t){
    if(s.size()!=t.size()){
        return false;
    }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}
vector<string> removeAnagrams(vector<string>& words) {
    vector<string> ans;
    ans.push_back(words[0]);
    for(int i=1;i<words.size();i++){
        if(!isAnagram(words[i],words[i-1])){
            ans.push_back(words[i]);
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    vector <string>result= removeAnagrams(words);
    for(auto it:result){
        cout<<it<<" ";
    }
}