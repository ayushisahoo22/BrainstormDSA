#include<bits/stdc++.h>
using namespace std;

//can be solved using set and unordered map..but space complexity will be O(N)
//here space complexity is O(1)
int removeDuplicates(vector<int>& nums) {
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
}