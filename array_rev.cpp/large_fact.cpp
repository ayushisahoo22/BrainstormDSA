#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the num: ";
    cin>>n;
    vector<int>ans;
    ans.push_back(1);   //pushing 1 in ans
    while(n>1){
        int carry=0;    //initialising carry as 0
        for(int i=0;i<ans.size();i++){
            int res=ans[i]*n+carry;   
            carry=res/10;
            ans[i]=res%10;
        }

        //for large num carry can be greater(100,200,etc)
        while(carry){    //if carry remains then iterate to push back its last element
            ans.push_back(carry%10);
            carry/=10;
        }
        n--;
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        cout<<it<<" ";
    }
}