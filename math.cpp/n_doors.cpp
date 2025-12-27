#include<bits/stdc++.h>
using namespace std;

// There are ‘N’ doors and ‘N’ people in a house.
// Each person and door has a unique ID ranging from 1 to ‘N’.
// A person can change the status of the door.
// Initially, all the doors are closed and each person wants to change 
//the status of all doors whose ID is a multiple of the ID of the person.

//core concept-all the perfect sq numbered door will remain open

string doorStatus(int n) {
    string s;
    for(int i=1;i<=n;i++){
        int root=sqrt(i);
        if(root*root==i){
            s+='1';
        }else{
            s+='0';
        }
    }
    return s;
}

int main(){
    int n;
    cout<<"Enter no of doors or people: ";
    cin>>n;
    string result=doorStatus(n);
    cout<<result;
}