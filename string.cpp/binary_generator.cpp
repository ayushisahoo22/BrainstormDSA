#include <bits/stdc++.h>
using namespace std;


//constraint
//Given an integer N, output a binary string of length N such that:
//The count of 01 subsequences in the string is equal to the count of 10 subsequences;
//The string has at least one occurrence of 0 as well as 1

int main() {
	int t;    //for various test cases
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s="";
        //if n is odd, the pattern of num can be 1010 or 0101..
	    if(n%2!=0){   
	        for(int i=0;i<n;i++){
	            if(i%2==0){
	                s.push_back('1');
	            }else{
	                s.push_back('0');
	            }
	        }
	    }
        //if n is even, the pattern of num can be 110011,1001,..
	    else{
	        string left(n/2,'1');  //no need of for loop to generate the string till n/2 of char '1'
	        left[n/2-1]='0';     // last char will become '0'
	        s+=left;  //can't use push_back(left) bcz push_back can only push character

            //reverse do not return anything;
            //can't do like string right=reverse(left.begin(),left.end());
	        reverse(left.begin(),left.end());   
	        string right=left;
	        s+=right;
	    }
	    cout<<s<<endl;
	}

}
