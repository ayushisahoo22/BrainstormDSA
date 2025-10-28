#include<bits/stdc++.h>
using namespace std;

// Start by selecting a starting position curr such that nums[curr] == 0,
// and choose a movement direction of either left or right.

// After that, you repeat the following process:

// If curr is out of the range [0, n - 1], this process ends.
// If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
// Else if nums[curr] > 0:
// Decrement nums[curr] by 1.
// Reverse your movement direction (left becomes right and vice versa).
// Take a step in your new direction.
// A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.

// Return the number of possible valid selections.


//TC--> O(N^2)
//SC--> O(1)
//bcz of manuallly adding for left and right sum
/*int countValidSelections(vector<int>& nums) {
    int cnt=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int count_left=0,count_right=0;
        if(nums[i]==0){
            int left=i-1,right=i+1;
            while(left>=0){
                count_left+=nums[left];
                left--;
            }
            while(right<=n-1){
                count_right+=nums[right];
                right++;
            }
            if(count_left==count_right){
                cnt+=2;
            }else if(count_left==count_right+1 || count_right==count_left+1){
                cnt++;
            }
        }
    }
    return cnt;
}*/


//TC-->O(N)
//SC-->O(1)
int countValidSelections(vector<int>& nums) {
    //accumulate is used for summing from nums begin to end
    //0LL is used for long long for safer side
    int total=accumulate(nums.begin(),nums.end(), 0LL);
    int cnt=0,left=0;
    for(auto it:nums){
        int right=total-left-it;   //current right sum after removing left sum
        if(it==0){
            if(left==right){
                cnt+=2;
            }else if(left==right+1 || right==left+1){
                cnt+=1;
            }   
        }
        left+=it;   //prefix sum
    }
    return cnt;
}


int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=countValidSelections(arr);
    cout<<ans;
}