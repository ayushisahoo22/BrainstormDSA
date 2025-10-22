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
vector<int> chuninNinja(int n, int m, vector<vector<int>> arr) {
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