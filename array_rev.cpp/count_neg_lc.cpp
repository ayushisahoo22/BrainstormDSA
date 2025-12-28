// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise,
// return the number of negative numbers in grid.

// TC-> O(N+M)   (MAIN)

#include<bits/stdc++.h>
using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int i=n-1;
    int j=0;
    int cnt=0;
    while(i>=0 && j<m){
        if(grid[i][j]<0){
            cnt+=(m-j);
            i--;
        }else{
            j++;
        }       
    }
    return cnt;
}

int main(){
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int ans=countNegatives(grid);
    cout<<ans;
}