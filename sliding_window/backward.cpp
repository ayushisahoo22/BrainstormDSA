#include<bits/stdc++.h>
using namespace std;

string minWindow(string S, string T)
{
    int n = S.size();
    int m = T.size();
    int indx = -1;
    int len = INT_MAX;
    int i = 0;
    for(int j = 0; j < n; j++)
    {
        if(S[j] == T[i])
        {
            i++;
        }
        if(i == m)
        {
            int end = j;
            i = m - 1;
            int k = j;
            while(i >= 0)
            {
                if(S[k] == T[i])
                {
                    i--;
                }
                k--;
            }
            int currStart = k + 1;
            if(end - currStart + 1 < len)
            {
                len = end - currStart + 1;
                indx = currStart;
            }
            j = currStart;
            i = 0;
        }
    }
    if(indx == -1)
        return "";
    return S.substr(indx, len);
}

int main(){
    string s,t;
    cout<<"enter s and t ";
    cin>>s>>t;
    string res=minWindow(s,t);
    cout<<res;
}