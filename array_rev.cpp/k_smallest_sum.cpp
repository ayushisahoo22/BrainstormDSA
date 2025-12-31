#include <bits/stdc++.h> 
using namespace std;

// given an N x M matrix ‘MAT’ and an integer ‘K’.
// All rows in the matrix have values in sorted order.
// choose 1 integer from each row and make an array of length ‘N’.
// task is to find the smallest k-th smallest array sum out of all the possibilities.

vector<int> merge(vector<int>&a,vector<int>&b,int k){
	priority_queue<
		pair<int,pair<int,int>>,
		vector<pair<int,pair<int,int>>>,
		greater<pair<int,pair<int,int>>>	
	> pq;

	vector<int>res;
	for(int i=0;i<a.size();i++){
		pq.push({a[i]+b[0],{i,0}});
	}
	while(k-- && !pq.empty()){
		pair<int,pair<int,int>>top=pq.top();
		pq.pop();
		int sum= top.first;
		res.push_back(sum);
		int i=top.second.first;
		int j=top.second.second;
		if(j+1<b.size()){
			pq.push({a[i]+b[j+1],{i,j+1}});
		}
	}
	return res;
}

int kSmallest(int n,int m, int k, vector< vector<int>> &mat) 
{
	vector<int>sums=mat[0];
	for(int i=1;i<n;i++){
		sums=merge(sums,mat[i],k);
	}
	return sums[k-1];
}

int main(){
    int n,m,k;
    cout<<"Enter rows, cols and k: ";
    cin>>n>>m>>k;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int ans= kSmallest(n,m,k,arr);
    cout<<ans;
}