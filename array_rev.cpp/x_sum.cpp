#include<bits/stdc++.h>
using namespace std;


// For every subarray (or window) of size k, we need to find its x-sum, which is determined by:

// The x most frequent elements.
// If there’s a tie in frequency, prefer the larger element.
// Essentially, each subarray acts as a small snapshot, we count what appears most often, 
// pick the top x, and sum only those numbers’ occurrences.


//INTUITION
// 1.Slide a window of size k across nums.

// 2.For each starting index i, take the subarray nums[i : i + k].
// Count frequencies using a hash map (Counter).

// 3.Sort the elements by:

// 4.Frequency (descending)
// Value (descending, for tie-breaking)
// Select the top x elements and store them in a set.

// 5.Sum all elements in the subarray that are part of the top x set.

// 6.Append this sum to the result list.

vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n=nums.size();
    vector<int>ans;    //to store the product sum
    for(int i=0;i<=n-k;i++){
        unordered_map<int,int> cnt;   //to track the count of elements
        for(int j=i;j<i+k;j++){
            cnt[nums[j]]++;
        }
        vector<pair<int,int>> freq(cnt.begin(),cnt.end());  //to store pairs of map cnt - ele:cnt
        sort(freq.begin(),freq.end(),[](auto &a, auto &b){  //sort the freq
            if(a.second==b.second) return a.first>b.first;
            return a.second>b.second;
        });
        int xsum=0;   //sum of pair's product
        for(int j=0;j<x && j<freq.size();j++){
            xsum+=freq[j].first*freq[j].second;
        }
        ans.push_back(xsum);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k,x;
    cout<<"Enter k and x: ";
    cin>>k>>x;
    vector<int> result=findXSum(arr,k,x);
    for(auto it:result){
        cout<<it<<" ";
    }
}