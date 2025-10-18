#include <bits/stdc++.h> 
using namespace std;

//You are given an array of N tuples, where each tuple contains L integers.
//Your task is to sort all the tuples in non-decreasing order according to their last element.
//If two tuples have the same last element, 
//the tuple that appeared earlier in the input should appear earlier in the output as well (i.e., maintain their relative order).

void sortTuples(vector<vector<int>>&arr){
    int n=arr.size();
    int l=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][l-1]>arr[j+1][l-1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    int n = 3, l = 2;
    vector<vector<int>> arr = {{1, 1}, {5, 3}, {8, 2}};
    
    sortTuples(arr);

    for (auto& row : arr) {
        cout << "(";
        for (int i = 0; i < row.size(); i++) {
            cout << row[i];
            if (i < row.size() - 1) cout << ", ";
        }
        cout << ") ";
    }
    cout << endl;
}