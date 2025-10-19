#include<bits/stdc++.h>
using namespace std;

//You are given a numeric string s (even length) and two integers a and b.
// You can repeatedly:
// Add a to all digits at odd indices (mod 10).
// Rotate the string to the right by b positions.
// Find the lexicographically smallest string possible after any number of such operations.

string AddOperation(string s,int a){
    for(int i=1;i<s.size();i+=2){
        int digit=s[i]-'0';
        digit=(digit+a)%10;
        s[i]=digit+'0';
    }
    return s;
}
string RotateOperation(string s,int b){
    int n=s.size();
    b=b%n;   //if b>9 ..to overlap it to the range of 0-9
    string rotated=s; //used rotated so we won't overlap the values of s to s
    for(int i=0;i<n;i++){
        rotated[(i-b+n)%n]=s[i];  //right rotation
    }
    return rotated;
}
string findLexSmallestString(string s, int a, int b) {
    set<string> seen;  //to keep track of different string
    queue<string> q;  //to pick from the q for operations with a and b
    
    q.push(s);
    seen.insert(s);
    string best=s;   //to access smallest string at the end
    while(!q.empty()){
        string curr=q.front();
        q.pop();  //the strings will get pop from the front which are get used as curr for operations
        if(curr<best){
            best=curr;   //wherever we achieve the best value
        }
        string s1=AddOperation(curr,a);
        if(seen.find(s1)==seen.end()){
            q.push(s1);   // new string will be added to q
            seen.insert(s1);   //to push in set
        }
        string s2=RotateOperation(curr,b);
        if(seen.find(s2)==seen.end()){
            q.push(s2);   // new string will be added to q
            seen.insert(s2);   //to push in set
        }
    }
    return best;
}
int main(){
    string s;
    cout<<"Enter string of digits 0-9: ";
    cin>>s;
    int a,b;
    cout<<"Enter the value of a, b: ";
    cin>>a>>b;
    string smallest=findLexSmallestString(s,a,b);
    cout<<smallest;
}