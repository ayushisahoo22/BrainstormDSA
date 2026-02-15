#include <bits/stdc++.h> 
using namespace std;

// given a vector 'ARR' consisting of ‘N’ integers. You are also given a positive integer ‘K’.
// a vector 'CONCAT' of size 'N * K' formed by concatenating 'ARR' ‘K’ times. 
// e.g->if 'ARR' = [0, -1, 2] and 'K' = 3, then 'CONCAT' is given by [0,-1,2,0,-1,2,0,-1,2].
// Your task is to find the maximum possible sum

long long kadane(vector<int>arr,int n){
	long long maxi=INT_MIN;
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum>maxi){
			maxi=sum;
		}
		if(sum<0) sum=0;
	}
	return maxi;
}
long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
	if(k==1) return kadane(arr,n);
	long long totalSum=accumulate(arr.begin(),arr.end(),0);
	vector<int>twice;
	twice.insert(twice.end(),arr.begin(),arr.end());
	twice.insert(twice.end(),arr.begin(),arr.end());
	long long maxTwo=kadane(twice,2*n);
	if(totalSum<=0){
		return maxTwo;
	}else{
		return maxTwo+(long long) (k-2)*totalSum;
	}
	return maxTwo;
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
    long long ans=maxSubSumKConcat(arr,n,k);
    cout<<ans;
}