#include <bits/stdc++.h> 
using namespace std;

// Given an array/list 'ARR' of integers and an integer 'LIMIT'.
// return the length of the longest subarray for which the absolute difference
// between the maximum and minimum element is less than or equal to the 'LIMIT'.

int getLongestSubarrayLength(vector<int> &arr, int limit)
{
	int n=arr.size();
	int l=0;int ans=0;
	for(int r=0;r<n;r++){
		int maxi=arr[r];
		int mini=arr[r];
		for(int i=l;i<=r;i++){
			maxi=max(maxi,arr[i]);
			mini=min(mini,arr[i]);
		}
		while(abs(maxi-mini)>limit && l<=r){
			l++;
			maxi=arr[l];
			mini=arr[l];
			for(int i=l;i<=r;i++){
				maxi=max(maxi,arr[i]);
				mini=min(mini,arr[i]);
			}
		}
		ans=max(r-l+1,ans);
	}
	return ans;
}

int main(){
    int n,lmit;
    cout<<"Enter n and lmit: ";
    cin>>n>>lmit;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=getLongestSubarrayLength(arr, lmit);
    cout<<ans<<" ";
}

