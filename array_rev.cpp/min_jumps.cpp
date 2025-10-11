#include <bits/stdc++.h>
using namespace std;


//Jumping only to the fixed index
//Test case failed at --> 2 3 1 1 4
//output should be 2 mor min jumps and it is giving 3 which is index jump
/*int indxJump(vector<int>& arr) {
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
}*/

//TC-->O(N^2)---Not always applicable([3, 4, 3, 2, 5, 4, 3])
/*int minJumps(vector<int>& arr) {
        int cnt=0;
        int indx=0;
        if (arr[0] == 0) return -1;
        while(indx<arr.size()-1){
            int j=indx;
            indx+=arr[indx];
            int maxi=arr[j+1];
            int best=j+1;
            for(int i=j+1;i<=indx && i<arr.size();i++){
                if(maxi<arr[i]){
                    maxi=arr[i];
                    best=i;
                }
            }
            indx = best;
            if(arr[indx]==0) return -1;
            cnt++;
        }
        return cnt;
    }*/


int minJumps(vector<int> arr){
    int jump=0;
    int end=0;
    int farthest=0;
    for(int i=0;i<arr.size()-1;i++){
        farthest=max(farthest,i+arr[i]);
        if(i==end){
            jump++;
            end=farthest;
        }
    }
    return jump;
}


int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int ans= indxJump(arr);
    // cout<<ans;

    int ans= minJumps(arr);
    cout<<ans;
}