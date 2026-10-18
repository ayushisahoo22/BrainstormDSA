#include<bits/stdc++.h>
using namespace std;

//LC-3551

int digitSum(int n){
    int sum=0;
    while(n>0){
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
int swaps(vector<int>arr){
    int n=arr.size();
    vector<int>sorted=arr;
    sort(sorted.begin(),sorted.end(),[](int a,int b){
        int sa=digitSum(a);
        int sb=digitSum(b);
        if(sa==sb) return a<b;
        return sa<sb;
    });
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[sorted[i]]=i;
    }
    int swap=0;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i] || mpp[arr[i]]==i) continue;
        int j=i;
        int cycle=0;
        while(!visited[j]){
            visited[j]=true;
            cycle++;
            j=mpp[arr[j]];
        }
        swap+=(cycle-1);
    }
    return swap;
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
    int ans=swaps(arr);
    cout<<ans;
}