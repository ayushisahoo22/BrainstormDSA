#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int>mpp;
    int i=0;
    int len=0;
    for(int j=0;j<fruits.size();j++){
        mpp[fruits[j]]++;
        while(mpp.size()>2){
            mpp[fruits[i]]--;
            if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
            i++;
        }
        len=max(len,j-i+1);
    }
    return len;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans =totalFruit(arr);
    cout<<ans;
}