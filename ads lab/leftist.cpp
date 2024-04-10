#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        int dist;
        Node(int data,int dist){
            this->data=data;
            this->dist=dist;
            left=NULL;
            right=NULL;
        }
        Node* merge(Node* root1,Node* root2){
            if(root1==NULL) return root2;
            if(root2==NULL) return root1;
            Node* returnedRoot=NULL;
            Node* finalRoot=NULL;
            if(root1->dist<root2->dist){
                returnedRoot=merge(root1->right,root2);
                finalRoot=root1;
            }else{
                returnedRoot=merge(root2->right,root1);
                finalRoot=root2;
            }
            //now lets merge returned roots
            //left s value should be greater than right or equal
            if(finalRoot->left!=NULL&&finalRoot->left->dist>returnedRoot->dist){
                finalRoot->right=returnedRoot;
            }else{
                Node* temp=finalRoot->left;
                finalRoot->left=returnedRoot;
                finalRoot->right=left;
            }
            return finalRoot;
        }
        Node* insert1(int val,Node* root){
            return merge(root,new Node(val,1));
        }
        Node* deleter(Node* root){
            return merge(root->left,root->right);
        }
        int getMin(Node* root){
            return root->data;
        }
        void inorder(Node* root){
            if(root==NULL) return;
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
};
int main(){
    Node* root=new Node(1,2);
    root->left=new Node(2,1);
    Node* returned=root->insert1(3,root);
    root->inorder(returned);
    return 0;
}