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
string solve(TreeNode *root,vector<TreeNode*>&ans,map<string,int>&mpp){
    if(!root) return "#";
    string left=solve(root->left,ans,mpp);
    string right=solve(root->right,ans,mpp);
    string curr=left+to_string(root->data)+right;
    mpp[curr]++;
    if(mpp[curr]==2){
        ans.push_back(root);
    }
    return curr;
}
vector<TreeNode*> duplicate_subtree(TreeNode *root){
    vector<TreeNode*>ans;
    map<string,int>mpp;
    solve(root,ans,mpp);
    return ans;
}

void printTree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
    TreeNode*root=new TreeNode(2);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<TreeNode*>res=duplicate_subtree(root);
    for(auto it:res){
        printTree(it);
        cout<<endl;
    }
}