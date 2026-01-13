#include<bits/stdc++.h>
using namespace std;


// Given N shops where each shop has a certain number of working bulbs and total bulbs, 
// along with EXTRA guaranteed working bulbs, distribute the extra bulbs among the shops to maximize the average working ratio.
// Each added bulb increases both the working and total count of a shop by one. 
// The working ratio of a shop is WORKS / TOTAL, and the goal is to maximize the average of these ratios across all shops.

double maxAverageWorkingRatio(vector<vector<int>>& bulbs, int n, int extra) {
    priority_queue<pair<double,pair<int,int>>> pq;
    for(auto b:bulbs){
        int w=b[0],t=b[1];
        double gain=(double)(w+1)/(t+1)-(double)w/t;     //marginal gain formula
        pq.push({gain,{w,t}});
    }
    while(extra--){
        pair<double,pair<int,int>> top=pq.top();
        pq.pop();
        int w=top.second.first;
        int t=top.second.second;
        w++;
        t++;
        double newGain=(double)(w+1)/(t+1)-(double)w/t;
        pq.push({newGain,{w,t}});
    }
    double sum=0.0;
    while(!pq.empty()){
        pair<double,pair<int,int>> top=pq.top();
        sum+=(double) top.second.first/top.second.second;
        pq.pop();
    }
    return sum/bulbs.size();
}

int main(){
    int n,extra;
    cout<<"Enter n and extra: ";
    cin>>n>>extra;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    double ans=maxAverageWorkingRatio(arr,n,extra);
    cout<<ans;
}