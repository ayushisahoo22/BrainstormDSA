#include<bits/stdc++.h>
using namespace std;

//Invert a binary tree;

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

Node* invertTree(Node* root) {
    if(root==NULL) return NULL;
    if(root->left!=NULL || root->right!=NULL){
        Node * temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    Node* l=invertTree(root->left);
    Node* r=invertTree(root->right);
    return root;
}
//inorder traversal
void inorder(Node *root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
int main(){
    Node *t1=new Node(5);
    t1->left=new Node(6);
    t1->right=new Node(7);
    t1->left->left=new Node(9);
    t1->left->right=new Node(2);
    t1->right->left=new Node(1);
    t1->right->right=new Node(8);
    cout<<"Before invert: "<<endl;
    inorder(t1);
    cout<<endl;

    Node* ans=invertTree(t1);
    cout<<"After invert: "<<endl;
    inorder(ans);
}