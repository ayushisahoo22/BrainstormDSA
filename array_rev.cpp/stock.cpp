#include<bits/stdc++.h>
using namespace std;

// It will wait till the end for the minimum value to assign it for buy
// in example [2,4,1]
// if we will wait for the min and after that there will be no max for sell
// so the stock will be 0

/*int maxProfit(vector<int>prices){
    int buy=INT_MAX;
    int indx=-1;
    for(int i=0;i<prices.size();i++){
        if(prices[i]<buy){
            buy=prices[i];
            indx=i;
        }
    }
    int sell=INT_MIN;
    for(int j=indx+1;j<prices.size();j++){
        if(prices[j]>sell){
            sell=prices[j];
        }
    }
    int stock=sell-buy;
    if(stock>0){return stock;}
    else{ return 0;}
}*/

//but optimally for [2,4,1] the stock should be 2
int maxProfit(vector<int> prices){
    int buy=INT_MAX;
    int stock=0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]<buy){
            buy=prices[i];
        }else if(prices[i]-buy>stock){
            stock=prices[i]-buy;
        }
    }
    return stock;
}
int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int ans=maxProfit(prices);
    cout<<ans;
}