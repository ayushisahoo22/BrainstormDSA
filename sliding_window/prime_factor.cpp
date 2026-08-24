#include<bits/stdc++.h>
using namespace std;

vector<int>getPrimes(int n){
    vector<bool>isPrime(n+1,true);
    vector<int>primes;
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            if(1ll*i*i<=n){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    return primes;
}

vector<int>fact(int n,vector<int>&primes){
    vector<int>factors;
    for(int p:primes){
        if(1ll*p*p>n) break;
        if(n%p==0){
            factors.push_back(p);
            while(n%p==0){
                n/=p;
            }
        }
    }
    if(n>1){
        factors.push_back(n);
    }
    return factors;
}

int longestSubarray(vector<int>& nums, int k) {
    int n=nums.size();
    int maxi=*max_element(nums.begin(),nums.end());
    vector<int>primes=getPrimes(maxi);
    vector<vector<int>>factors(n);
    for(int i=0;i<n;i++){
        factors[i]=fact(nums[i],primes);
    }
    vector<int>freq(maxi+1,0);
    int dist=0;
    int i=0;
    int len=0;
    for(int j=0;j<n;j++){
        for(int p:factors[j]){
            if(freq[p]==0) dist++;
            freq[p]++;
        }
        while(dist>k){
            for(int p:factors[i]){
                freq[p]--;
                if(freq[p]==0) dist--;
            }
            i++;
        }
        len=max(len,j-i+1);
    }
    return len;
}

int main(){
    int n,k;
    cout<<"Enter n and k: ";
    cin>>n>>k;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans=longestSubarray(arr,k);
    cout<<ans;
    return 0;
}