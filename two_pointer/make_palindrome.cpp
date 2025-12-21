#include <bits/stdc++.h> 
using namespace std; 

// Given an array of positive integers, determine the minimum number of merge
// operations required to make the array palindromic. In one operation, two
// adjacent elements can be merged by adding their values.
//eg->[1,2,3,4,1]----[1,5,4,1]----[1,9,1] (2 operation reqd)

int palindrome(vector<int> &arr)
{
	int ans=0;
	int i=0;
	int j=arr.size()-1;
	while(i<j){
		if(arr[i]==arr[j]){
			i++;
			j--;
		}
		else if(arr[i]<arr[j]){
			arr[i+1]+=arr[i];
			i++;
			ans++;
		}
		else{
			arr[j-1]+=arr[j];
			j--;
			ans++;
		}
	}
	return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=palindrome(arr);
    cout<<ans;
}