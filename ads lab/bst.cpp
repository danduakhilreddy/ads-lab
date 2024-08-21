#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left=right=NULL;
        }
        Node(){
            left=right=NULL;
        }
};
Node* insert(int val,Node* root){
    if(root==NULL) return new Node(val);
    Node* temp=new Node(val);
    Node* curr=root;
    Node* prev=root;
    while(curr!=NULL){
        if(curr->data<val){
            prev=curr;
            curr=curr->right;
        }else{
            prev=curr;
            curr=curr->left;
        }
    }
    if(prev->data<val){
     prev->right=temp;   
    }else{
        prev->left=temp;
    }
    return root;
}
bool search(Node* root,int key){
    Node* temp=root;
    while(temp){
        if(temp->data==key) return true;
        else if(temp->data<key){
            temp=temp->right;
        }else{
            temp=temp->left;
        }
    }
    return false;
}
Node* helper(Node* root){
    if(root==NULL) return NULL;
    if(root->left==NULL) return root->right;
    if(root->right==NULL) return root->left;
    Node* temp=root->left;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    temp->right=root->right;
    root->right=NULL;
    return root->left;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* deleteNode(Node* root,int key){
    if(root==NULL) return NULL;
    Node* temp=root;
    if(temp->data==key) return helper(temp);
    while(temp){
        if(temp->data>key){
            if(temp->left!=NULL&&temp->left->data==key){
                temp->left=helper(temp->left);
                break;
            }else{
                temp=temp->left;
            }
            
        }else{
            if(temp->right!=NULL&&temp->right->data==key){
                temp->right=helper(temp->right);
                break;
            }else{
                temp=temp->right;
            }
            
        }
    }
    return root;
}
int main(){
    Node* root=NULL;
    root=insert(1,root);
    root=insert(2,root);
    root=insert(3,root);
    root=insert(4,root);
    root=insert(5,root);
    inorder(root);
    cout<<endl;
    root=deleteNode(root,4);
    inorder(root);
    return 0;
}
