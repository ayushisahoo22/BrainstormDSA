#include<bits/stdc++.h>
using namespace std;

//RIGHT rotate
void rightRotate(int arr[],int n,int k){
    k=k%n;
    int temp[k];
    for(int i=n-k;i<n;i++){
        temp[i-n+k]=arr[i];
    }
    for(int i=n-1;i>=0;i--){
        arr[i]=arr[i-k];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
}

//APPROACH 2-->Reversal
//1. Reversing last two element (1 2 3 4 5 7 6)
// 2.Reversing the other max_element (5 4 3 2 1 7 6)
// 3.Reversing the whole array (6 7 1 2 3 4 5)

//LEFT rotate
void leftRotate(int arr[],int n,int k){

    //If someone inputs k > n (say k = 10 for an array of size 7)
    //It will not raise error and rotate by 3 places as till 7 it will be in correct prev order(1 2 3 4 5 6 7)
    k=k%n;   //this ensure for number gretater than n
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-n+k];
    }
}

//APPROACH 2-->Reversal
//1. Reversing first two element (2 1 3 4 5 6 7)
// 2.Reversing the other max_element (2 1 7 6 5 4 3)
// 3.Reversing the whole array (3 4 5 6 7 1 2)

int main(){
    int arr[]={1,2,3,4,5,6,7};
    /*cout<<"After rotating k elements to the right: ";
    rightRotate(arr,7,2);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }*/
    cout<<"After rotating k elements to the left: ";
    leftRotate(arr,7,10);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }

}