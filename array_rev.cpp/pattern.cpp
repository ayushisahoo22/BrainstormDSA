#include <bits/stdc++.h> 
using namespace std;

vector < vector < int > > numberPattern(int n) {

  int m=1<<n;
  int num=1;
  vector<vector<int>>v;
  for(int i=0;i<n;i++){
    int val=1<<i;
    vector<int>row;
    for(int j=0;j<val;j++){
      row.push_back(num);
      if(num==9){
        num=1;
      }else{
        num++;
      }
    }
    v.push_back(row);
  }
  return v;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<vector<int>>res=numberPattern(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}