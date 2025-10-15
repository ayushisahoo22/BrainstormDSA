#include<bits/stdc++.h>
using namespace std;

//select any index i such that 0 < i < words.length and words[i - 1] 
//and words[i] are anagrams, and delete words[i] from words

//func to check if two strings are anagrams
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
        if(!isAnagram(words[i],words[i-1])){    //if the words[i] is not anagram
            ans.push_back(words[i]);            //push it to ans
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