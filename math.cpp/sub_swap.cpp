// given two positive integers X and Y.
// Repeat the following operation until X is not 0:
// If X>Y, swap X and Y;
// Otherwise, set X=(Y−X) and Y=X.
// Output the final value of Y after all operations.

#include <bits/stdc++.h>
using namespace std;

/*int main() {
	int t;
	cin>>t;
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    int temp;
	    while(x!=0){   //continuous subtraction raising tle
	        if(x>y){
	            temp=x;
	            x=y;
	            y=temp;
	        }else{
	            temp=x;
	            x=y-x;
	            y=temp;
	        }
	    }
	    cout<<y<<endl;
	}

}*/

int main() {
	int t;
	cin>>t;
	while(t--){
	    int x,y;
	    cin>>x>>y;
	    int temp;
	    while(x!=0){
	        int temp=x;
	        x=y%x;
	        y=temp;
	    }
	    cout<<y<<endl;
	}

}