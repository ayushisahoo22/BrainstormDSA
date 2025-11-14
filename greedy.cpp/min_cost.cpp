#include <bits/stdc++.h> 
using namespace std;

//given a board of length 'L' and width 'W'.task is to break this board into 'L' * 'W' smaller squares,
//such that the total cost involved in breaking is the minimum possible.
//eg-> square or l=3 and w=3
//row->(1,2) and col->(2,1)
//the cost to cut first piece horizontally(row)=1 and then will take 2

int minimumCost(vector<int> row, vector<int> column, int l, int w)
{
    //here sorting helps in minimum cost because the more pieces of board will get multiply with more cost
    //..later if it is not sorted which will increase the cost
	sort(row.begin(),row.end(),greater<int>());
	sort(column.begin(),column.end(),greater<int>());
	int horizontal=1,vertical=1;
	int cost=0;
	int i=0,j=0;
	while(i<row.size() && j<column.size()){
		if(row[i]>column[j]){
			cost+=vertical*row[i];
			horizontal++;
			i++;
		}else{
			cost+=column[j]*horizontal;
			vertical++;
			j++;
		}
	}
    //to calculate cost if last ele of row remains
	while(i<row.size()){
		cost+=vertical*row[i];
		horizontal++;
		i++;
	}
    //to calculate cost if last ele of col remains
	while(j<column.size()){
		cost+=column[j]*horizontal;
		vertical++;
		j++;
	}
	return cost;
}

int main(){
    int l,w;
    cout<<"Enter l and w: ";
    cin>>l>>w;
    vector<int> row(w-1);
    vector<int> col(l-1);
    //enter the values of row
    for(int i=0;i<w-1; i++){
        cin>>row[i];
    }
    //enter the value of col
    for(int i=0;i<l-1; i++){
        cin>>col[i];
    }
    int cost=minimumCost(row,col,l,w);
    cout<<cost;
}