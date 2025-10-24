#include<bits/stdc++.h>
using namespace std;

// given a string STR and a non-empty string PTR. 
// Your task is to find all the starting indices of PTR’s anagram in STR.

// 1. Both STR and PTR consist of English uppercase letters.
// 2. Length of string 'STR' will always be greater than or equal to the length of string ‘PTR’.
// 3. In case, there is no anagram substring, then return an empty sequence.
// 4. In case of more than one anagrams, return the indices in increasing order.

vector<int> findAnagramsIndices(string str, string ptr, int n, int m){
    string sortedPTR=ptr;
    //sorting later bcs sort() don't return anything
    sort(sortedPTR.begin(),sortedPTR.end());
    vector<int>ans;
    int i=0,j=0;
    string temp="";
    while(j<n){
        temp+=str[j];
        if(temp.size()>m){
            temp.erase(temp.begin());
            i++;   //shrinking i only when the condition breaks
        }
        if(temp.size()==m){
            string sortedTemp=temp;
            sort(sortedTemp.begin(),sortedTemp.end());
            if(sortedTemp==sortedPTR){
                ans.push_back(i);
            }
        }
        j++;     //else expanding the j
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter the size: n,m ";
    cin>>n>>m;
    string str,ptr;
    cin>>str>>ptr;
    vector<int> result=findAnagramsIndices(str,ptr,n,m);
    for(auto it:result){
        cout<<it<<" ";
    }
}