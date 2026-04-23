#include<bits/stdc++.h>
using namespace std;

//LC-2615

vector<long long> distance(vector<long long>& nums) {
    int n=nums.size();
    unordered_map<long long ,vector<int>>groups;
    for(int i=0;i<n;i++){
        groups[nums[i]].push_back(i);
    }
    vector<long long> res(n);
    for (const auto& p : groups) {
        const auto& group = p.second;
        long long total = accumulate(group.begin(), group.end(), 0LL);
        long long prefixTotal = 0;
        for (int i = 0; i < group.size(); i++) {
            res[group[i]] =
                total - prefixTotal * 2 + group[i] * (2 * i - group.size());
            prefixTotal += group[i];
        }
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<long long>arr;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        arr.push_back(x);
    }
    vector<long long>res=distance(arr);
    for(auto it:res){
        cout<<it<<" ";
    }
}