#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

bool isSameTree(Node* p, Node* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;

    if (p->data != q->data) return false;
    bool l=isSameTree(p->left, q->left);
    bool r=isSameTree(p->right, q->right);

    return  l && r;
}

int main(){
    Node *t1=new Node(5);
    t1->left=new Node(6);
    t1->right=new Node(7);

    Node *t2=new Node(5);
    t2->left=new Node(6);
    t2->right=new Node(7);

    bool ans=isSameTree(t1,t2);
    cout<<ans;
}
