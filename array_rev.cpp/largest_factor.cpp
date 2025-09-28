#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    //for a list of prime factor
    vector<int> ans;

    while(n>1){   //1 is not a prime factor
        
        //temp is updated i
        int temp=-1;
        // dry run for 27
        for(int i=2;i*i<=n;i++){   //OPTIMAL bcz loop is running till (sqrt of n) rather than n
            if(n%i==0){
                ans.push_back(i);   // 27(ls adds 3)--> 9(ls adds 3)--->but will not add last 3
                temp=i;
                break;
            }
        }

        //if temp is not updated further or the sqr of temp is greter
        // diretly push n to keep the last prime factor
        if(temp==-1){   //3(ls adds 3 lastly)   after 9
            ans.push_back(n);
        }

        //updating n
        n=n/temp;
    }

    //max taken as non existing
    int max=-1;
    for(int i=0;i<ans.size();i++){
        if(ans[i]>max){
            max=ans[i];
        }
    }
    cout<<max;
}