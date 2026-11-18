#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<int> numbersAndDigits(int n) 
{
    vector<int>ans;
    int d=to_string(n).size();
    int start=max(1,n-9*d);
    for(int i=start;i<=n;i++){
        int sum=0;
        int temp=i;
        while(temp>0){
            sum+=(temp%10);
            temp/=10;
        }
        if(sum+i==n){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int>res=numbersAndDigits(n);
    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}