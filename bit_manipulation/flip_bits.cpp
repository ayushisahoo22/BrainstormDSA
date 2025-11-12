#include <bits/stdc++.h> 
using namespace std;

// given an integer 'NUM' (32 bits) and an array of size 'N'.
// Your task is to flip all the bits of 'NUM' at position 'ARR[i]' where 0<= i <= N-1.

// e.g - num = 21  →  binary: 1 0 1 0 1
//       positions of bits:   5 4 3 2 1
//       after flip :         1 1 1 1 0 (num=30)

// if pos = 4, then
// (1 << (pos - 1)) = (1 << 3) = 1000₂ = 8₁₀. [interested in 4rth bit]
// That’s a mask — a number where only the bit you want to flip is 1.
//The “mask bits” are the 1s inside that stencil — they mark which bits we’re interested in to flip.

//num^mask using xor operator, compares each bit
// If the mask bit is 1 → that position flips
// If the mask bit is 0 → that position stays the same

int flipSomeBits(int num, vector<int> &arr, int n)
{
	for(int i=0;i<n;i++){
		int pos=arr[i];
		num^=(1<<(pos-1));
	}
	return num;
}

int main(){
    int num,n;
    cout<<"Enter the n and num: ";
    cin>>n>>num;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=flipSomeBits(num,arr,n);
    cout<<ans<<endl;
}