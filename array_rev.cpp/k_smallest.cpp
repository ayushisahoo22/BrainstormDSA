#include<bits/stdc++.h>
using namespace std;

/*int kthSmallest(vector<int>& v, int n, int k) {
int k_small;   // to update with the next smallest element
while(k--){
    int smallest=INT_MAX;
    int indx=-1;    //keeping track for index of smallest element
    for(int i=0;i<n;i++){
        if(v[i]<smallest && v[i]!=smallest){
            smallest=v[i];
            indx=i;
        }
    }
    v[indx]=INT_MAX;   //the smallest element is updated so it should not be considered next time
    k_small=smallest;  //giving the value of smallest as each iteration initiate as smallest=INT_MAX
    }
    return k_small;
}*/

//using priority que:
//Default priority_queue is a max-heap
//Top element is always the maximum
//Elements are popped in decreasing order

int kthSmallest(vector<int>& arr, int n, int k) {
    // Using greater<int> makes the priority_queue a min-heap,
    // so the smallest element comes out first.
    
	priority_queue<int,vector<int>,greater<int>>pq;
	for(int x:arr){
		pq.push(x);
	}
    //will pop from the top till k-1
	for(int i=1;i<k;i++) pq.pop();
    //at k returning the value
	return pq.top();
}
int main(){
    int n,k;
    cout<<"Enter the n and k: ";
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=kthSmallest(arr,n,k);
    cout<<ans;
}