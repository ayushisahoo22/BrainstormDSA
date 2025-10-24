#include <bits/stdc++.h>
using namespace std;


//given two integers N and K Your task is to determine if there exists a binary string S of length N:
//S1+S2+S3+S4...=K and no two adjacent ele of string should be equal
// string can be like 0101010... or 101010...

//print yes if any string exist like this for n and k otherwise no

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,x;
	    cin>>n>>x;
	    if(n%2==0){
	        if(n/2==x){
	            cout<<"YES"<<endl;
	        }else{
	            cout<<"NO"<<endl;
	        }
	    }else{
            if((n/2==x) || (n/2+1==x)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
	    }
	}

}