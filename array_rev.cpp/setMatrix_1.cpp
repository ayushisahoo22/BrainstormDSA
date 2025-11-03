#include<bits/stdc++.h>
using namespace std;

//THE problem:Set matrix [i][j] to 1 for all row and col to which i and j belongs
//for matrix like {1, 1, 1},
//                {1, 0, 0},
//                {1, 0, 0}
// the data will be overwritten every time


/*void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MAT[i][j]==1){
                int row=i,col=j;
                for(int r=0;r<n;r++){
                    MAT[r][col]=1;
                }
                for(int c=0;c<m;c++){
                    MAT[row][c]=1;
                }
            }
        }
    }
}*/

//OPTIMAL

//maintain the row and col vector for checkpoints of i j to keep 1 there
void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    vector<int> row(n,0),col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(MAT[i][j]==1){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                MAT[i][j]=1;
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter n and m: ";
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m)); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    setMatrixOnes(arr,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}