#include<bits/stdc++.h>
using namespace std;

//can be solved using set and unordered map..but space complexity will be O(N)
//here space complexity is O(1)
/*int removeDuplicates(vector<int>& nums) {
    // If array is empty, return 0 directly
    if (nums.empty()) return 0;

    // Pointer for the position of last unique element
    int i = 0;

    // Traverse the array starting from the second element
    for (int j = 1; j < nums.size(); j++) {
        // If current element is different from last unique element
        if (nums[j] != nums[i]) {
            // Move pointer for unique element forward
            i++;
            // Place the new unique element at the next position
            nums[i] = nums[j];
        }
    }

    // i is index of last unique element, count = i + 1
    return i + 1;
}


int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans=removeDuplicates(nums);
    cout << "Array after removing duplicates: ";
    for (int x = 0; x < ans; x++) {
        cout << nums[x] << " ";
    }
    cout << endl;
}*/

//returning the unique elements in a vector
vector<int> func(vector<int>arr,int n){
    int i=0;
    vector<int> ans;
    ans.push_back(arr[i]); //first element is always unique
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            swap(arr[i],arr[j]);
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> k=func(arr,n);
    for(int i=0;i<k.size();i++){
        cout<<k[i]<<" ";
    }
}