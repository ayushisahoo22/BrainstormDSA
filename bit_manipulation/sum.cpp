#include <bits/stdc++.h> 
using namespace std;

//add a and b without suing + and ++

int getSum(int a, int b)
{
	while(b!=0){
        int carry=a&b;
        a=a^b;
        b=carry<<1;
    }	
    return a;
}
int main(){
    int a,b;
    cout<<"Enter a and b: ";
    cin>>a>>b;
    int ans=getSum(a,b);
    cout<<ans;
}