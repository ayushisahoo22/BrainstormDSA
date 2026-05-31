#include<bits/stdc++.h>
using namespace std;

//LC->124
struct Node{
    int val;
    Node *left,*right;
    Node(int d){
        val=d;
        left=right=NULL;
    }
};
int dfs(Node* node, int& res) {
    if (!node) {
        return 0;
    }
    int leftSum = max(0, dfs(node->left, res));
    int rightSum = max(0, dfs(node->right, res));
    res = max(res, leftSum + rightSum + node->val);
    return max(leftSum, rightSum) + node->val;
}

int maxPathSum(Node* root) {
    int res = root->val;
    dfs(root, res);
    return res;
}

int main(){
    Node *t1=new Node(-10);
    t1->left=new Node(6);
    t1->right=new Node(7);
    t1->left->left=new Node(-3);
    t1->left->right=new Node(2);
    t1->right->left=new Node(1);
    t1->right->right=new Node(8);
    int ans=maxPathSum(t1);
    cout<<ans;
}