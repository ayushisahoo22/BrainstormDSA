#include <bits/stdc++.h>
using namespace std;


//Jumping only to the fixed index
//Test case failed at --> 2 3 1 1 4
//output should be 2 mor min jumps and it is giving 3 which is index jump
int indxJump(vector<int>& arr) {
        int cnt=0;
        int indx=0;
        while(indx<arr.size()-1){
            indx+=arr[indx];
            if(arr[indx]==0){
                return -1;
            }
            cnt++;
        }
        return cnt;
}



int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans= indxJump(arr);
    cout<<ans;
}