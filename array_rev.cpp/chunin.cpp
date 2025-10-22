#include <bits/stdc++.h>
using namespace std;


//Each element in the matrix represents the skill level of a Ninja sitting in the class.
// Formally, ARR[i][j] represents the skill level of the Ninja sitting in the j-th column of the i-th row.

// A Ninja is called a Chunin if:
// He has the minimum skill level in his row, and
// He has the maximum skill level in his column.

// eg--> 3 4 5                      
//       2 7 6                      
//       1 2 4  ans will be 3      

//Finds minimum value and its first column index, then directly checks only that column.
/*vector<int> chuninNinja(int n, int m, vector<vector<int>> arr) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int mini = INT_MAX;
        int colIndex = -1;

        // Find minimum in the i-th row
        for(int j = 0; j < m; j++) {
            if (arr[i][j] < mini) {
                mini = arr[i][j];
                colIndex = j;
            }
        }

        // Find maximum in that column
        int maxi = INT_MIN;
        for(int k = 0; k < n; k++) {
            maxi = max(maxi, arr[k][colIndex]);
        }

        // Check if that element is both row-min and column-max
        if(mini == maxi) {
            ans.push_back(mini);
        }
    }
    return ans;
}*/


//Finds minimum value in the row, then checks every occurrence of that value to see if it’s also column-max.
//eg --> 3 3 3
//       3 3 3    ans will be 3 3 3 3 3 3 3 3 3
//       3 3 3
//but for the above code it will be 3 only

vector<int> chuninNinja(int n, int m, vector<vector<int>> arr){
    vector<int> ans; for (int i = 0; i < n; i++){
        //min_element() (from <algorithm>) finds the smallest element in that row.
        //It returns an iterator, so we use * to get the actual value.
        int mini = *min_element(arr[i].begin(), arr[i].end());  //Find the Minimum in the Current Row
        for(int j = 0; j < m; j++) {

            //Only process columns j where the current element equals the row’s minimum (mini).
            //This allows us to handle multiple minimum values in the same row.
            if (arr[i][j] == mini) {
                bool isMax = true;
                for (int k = 0; k < n; k++){ // check column
                    
                    //if other ele is max than the mini, break the loop
                    if (arr[k][j] > arr[i][j]){
                        isMax = false; 
                        break;
                    } 
                }if (isMax){
                    ans.push_back(arr[i][j]); 
                } 
            } 
        } 
    }
    return ans; 
}


int main(){
    int n,m;
    cout<<"Enter the row and col: ";
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));  //for 2d vector
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> result=chuninNinja(n,m,arr);
    for(auto it: result){
        cout<<it<<" ";
    }
}