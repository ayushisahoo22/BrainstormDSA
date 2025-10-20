#include <bits/stdc++.h>
using namespace std;

//You are given an integer X.
//Your task is to find the first X terms of the series defined by the formula:
//𝑇=3N+2
//where N starts from 1, excluding the terms that are multiples of 4.
//Return or print the resulting list of numbers.

//TC-->O(NlogN)
/*vector < int > termsOfAP(int x) { 
    vector<int>ans; 
    set<int>visited; //to store the visited i to skip in next iteration
    for(int i=1;i<=x;i++){ 
        if(visited.find(i)==visited.end()){ 
            int digit=3*i+2;
            if(digit%4==0){
                 digit=3*(i+1)+2;
                 x++; //dynamically increasing x if the digit is divisible by 4
                 ans.push_back(digit); 
                 visited.insert(i+1); 
            }else{
                 ans.push_back(digit); 
                 visited.insert(i); 
            } 
        }
    } 
    return ans; 
}*/

//TC-->O(N)
vector < int > termsOfAP(int x) {
    vector<int>ans;
    int n=1;
    while(ans.size()<x){
        int digit=3*n+2;
        if(digit%4!=0){
            ans.push_back(digit);
        }
        n++;
    }
    return ans;
}

int main(){
    int x;
    cout<<"Enter the x: ";
    cin>>x;
    vector<int>result=termsOfAP(x);
    for(auto it:result){
        cout<<it<<" ";
    }
}