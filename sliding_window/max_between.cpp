#include<bits/stdc++.h>
using namespace std;

int countSubarrays(int n, vector<int>& arr, int k) {
    int cnt = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (arr[j] > k) {
            i = j + 1;
        }
        cnt += j - i + 1;
    }
    return cnt;
}

int maxInbw(int n, vector<int>& arr, int x, int y) {
    return countSubarrays(n, arr, y)- countSubarrays(n, arr, x - 1);
}

int main(){
    int n,x,y;
    cout<<"Enter n,x and y: ";
    cin>>n>>x>>y;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int result=maxInbw(n,arr,x,y);
    cout<<result;
}