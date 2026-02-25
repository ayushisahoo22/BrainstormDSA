#include <bits/stdc++.h> 
using namespace std;

//replace spaces with "@40"
//TC->O(N)   SC->O(1)
string replaceSpaces(string &str){
	string r="@40";
	string target=" ";
	size_t pos=0;
	while((pos=str.find(target))!=string::npos){
		str.replace(pos,target.length(),r);
		pos+=r.size();
	}
	return str;
}
int main(){
    string s;
    cout<<"Enter string s: ";
    getline(cin,s);
    string res=replaceSpaces(s);
    cout<<res;
}