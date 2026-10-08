#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left,*right;
    TreeNode(int d){
        data=d;
        left=right=NULL;
    }
};

vector<vector<int>> diagonal(TreeNode* root){
    vector<vector<int>>ans;
    if(!root) return ans;
    map<int,vector<int>>mpp;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        TreeNode*node=it.first;
        int indx=it.second;
        while(node){
            mpp[indx].push_back(node->data);
            if(node->left){
                q.push({node->left,indx+1});
            }
            node=node->right;
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    TreeNode*root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(4);
    vector<vector<int>>res=diagonal(root);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}