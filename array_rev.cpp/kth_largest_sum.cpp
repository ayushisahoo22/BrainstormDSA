#include<bits/stdc++.h>
using namespace std; 

// find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, 
// the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

int getKthLargest(vector<int> &arr, int k)
{
	int n=arr.size();
	auto pq=priority_queue<int,vector<int>,greater<int>>();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			pq.push(sum);
			if(pq.size()>k) pq.pop();
		}
	}
	return pq.top();
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=getKthLargest(arr,k);
    cout<<ans;
}