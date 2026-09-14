#include <bits/stdc++.h> 
using namespace std;

// a list of ‘N’ numbers and a number ‘K’
// rearrange the elements of the list such that
// all elements less than or equal to ‘K’ become adjacent to each other

int minimumSwaps(vector<int> &arr, int n, int k)
{
	int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k) cnt++;
    }
    int i=0;
    int good_cnt=0;
    int ans=INT_MAX;
    for(int j=0;j<n;j++){
        if(arr[j]<=k) good_cnt++;
        while(j-i+1>cnt){
            if(arr[i]<=k) good_cnt--;
            i++;
        }
        if(j-i+1==cnt){
            ans=min(ans,cnt-good_cnt);
        }
    }
    return ans;
}

int main(){
    int k=2;
    vector<int>arr={1,1,5,1,2};
    int n=arr.size();
    int ans=minimumSwaps(arr,n,k);
    cout<<ans;
}