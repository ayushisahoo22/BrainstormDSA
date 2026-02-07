#include<bits/stdc++.h>
using namespace std;

int calcAngle(int minute,int hour){
    hour=hour%12;
    double minCnt=minute*6;  //1minute=6 degree
    double hourCnt=hour*30;  //1 hour=30 degree
    hourCnt+=minute*0.5;
    double angle=abs(hourCnt-minCnt);
    return (int)min(angle,360-angle);
}

int main(){
    int minute,hour;
    cout<<"Enter hour and minute: ";
    cin>>hour>>minute;
    int ans=calcAngle(minute,hour);
    cout<<ans;
}