#include <bits/stdc++.h> 
using namespace std;

// Given a positive integer N, you can do the following operation at most once
// a) Swap two digits of the integer N.
// determine the largest integer you can get by performing the above operation at most once.
//WE WILL SWAP THE RIGHMOST MAX INDX WITH THE FIRST INDX AT ONCE ONLY

//here we are storing the corresponding rightmost index of the larger elements

//     (0,1,2,3)
//eg-->(4,5,8,9)
//     (3,3,3,3)    rightmax vector 
//from very position we are getting 9 is the largest at indx 3   
int maximumSwap(int n) {
	string s=to_string(n);
	int len=s.size();
	vector<int> rightMax(len);   //used to store the right max index from the current index
	int maxIndx=len-1;
	rightMax[len-1]=len-1;
	for(int i=len-2;i>=0;i--){
		if(s[i]>s[maxIndx]){
			maxIndx=i;
		}
		rightMax[i]=maxIndx;    
	}
	for(int i=0;i<len;i++){
		if(s[i]<s[rightMax[i]]){
			swap(s[i],s[rightMax[i]]);
			break;     //if we dont put break it will swap more than once
		}
	}
	return stoi(s);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int ans= maximumSwap(n);
    cout<<ans;
}