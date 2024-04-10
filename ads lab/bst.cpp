#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

Node* insert(Node* root,int key){
    
    if(root==NULL) return new Node(key);
    if(key>root->data){
        root->right=insert(root->right,key);
    }else if(root->data>key){
        root->left=insert(root->left,key);
    }else{
        return root;
    }
    return root;
}
bool find(Node* root,int key){
    if(root==NULL) return false;
    if(root->data==key) return true;
    else if(root->data>key){
        return find(root->left,key);
    }else{
        return find(root->right,key);
    }
    return false;
}
Node* helper(Node* root){//takes node to be deleted then it go left max element and delete node

    if(root->left==NULL) return root->right;
    Node* curr=root->left;
    while(curr->right!=NULL){
        curr=curr->right;
    }
    curr->right=root->right;
    Node* newRoot=root->left;
    root->left=NULL;
    root->right=NULL;
    delete root;
    return newRoot;
}
Node* deleteNode(Node* root,int key){
    
    if(root->data==key) return helper(root);
    if(root->data>key){
        if(root->left!=NULL&&root->left->data==key){
            root->left=helper(root->left);
        }else{
            root->left=deleteNode(root->left,key);
        }
    }else{//root->data <key
        if(root->right!=NULL&&root->right->data==key){
            root->right=helper(root->right);
        }else{
            root->right=deleteNode(root->right,key);
        }
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,9);
    root=insert(root,5);
    inorder(root);
    cout<<endl<<"element found "<<find(root,5);
    root=deleteNode(root,1);
    inorder(root);
    return 0;
}