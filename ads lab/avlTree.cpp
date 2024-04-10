#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data,height;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            height=1;
            left=right=NULL;
        }
};

int getHeight(Node* root){//used to update height when needed
    if(root==NULL) return 0;
    return root->height;
}

//fucntion to find balance factor
int findBalance(Node* root){
    return getHeight(root->left)-getHeight(root->right);
}

//lets do right rotation
Node* rightrotation(Node* root){
    Node* child=root->left;
    Node* rightsChild=child->right;
    child->right=root;
    root->left=rightsChild;
    root->height=1+max(getHeight(root->right),getHeight(root->left));
    child->height=1+max(getHeight(child->right),getHeight(child->left))
    return child;
}

//lets do leftrotation
Node* leftrotation(Node* root){
    Node* child=root->right;
    Node* leftsChild=child->left;
    child->left=root;
    root->right=leftsChild;
    root->height=1+max(getHeight(root->right),getHeight(root->left));
    child->height=1+max(getHeight(child->right),getHeight(child->left))
    return child;
}

Node* insert(Node* root,int key){//key to be inserted
    //if tree is empty till now return node
    if(root==NULL) return new Node(key);
    if(root->data<key){
        root->right=insert(root->right,key);
    }else if(root->data>key){
        root->left=insert(root->left,key);
    }else{
        return root;
    }
    //updating height as new element added to tree

    root->height=1+max(getHeight(root->left),getHeight(root->right));

    //now we should balance tree
    int balance=findBalance(root);

    //ll rotation
    if(balance>1&&key<root->left->data){
        //we just do rotation for root rightrotation
        return rightrotation(root);
    }

    //rr rotation
    else if(balance<-1&&key>root->right->data){
        return leftrotation(root);
    }

    //lr rotation
    else if(balance>1&&key>root->left->data){
        root->left=leftrotation(root->left);
        return rightrotation(root);

    }

    //rl rotation
    else if(balance<-1&&key<root->right->data){
        root->right=rightrotation(root->right);
        return leftrotation(root);

    }else{
        return root;
    }
}
//delete node in avl tree
Node* deleteNode(Node* root,int key){
    if(root==NULL) return NULL;
    if(key>root->data){
        root->right=deleteNode(root->right,key);
    }else if(key<root->data){
        root->left=deleteNode(root->left,key);
    }else{
        //if root is leaf node
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //if root has only one child
        else if(root->left==NULL&&root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }else if(root->left!=NULL&&root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }else{
            Node* curr=root->left;
            while(curr->right!=NULL){
                curr=curr->right;
            }
            root->data=curr->data;
            root->left= deleteNode(root->left,root->data);
        }
    }
    //now we update height
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    //now we check balancing
    int balance=findBalance(root);
     //we deleted element from right side so leftheight -rightheight is positive
    if(balance>1){

        if(findBalance(root->left)>=0){//then ll rotation
            return rightrotation(root);
        }else{//lr rotation
            root->left=leftrotation(root->left);
            return rightrotation(root);
        }

    }else if(balance<-1){//element deleted from left side
        if(findBalance(root->right)<=0){//then rr rotation
            return leftrotation(root);
        }else{//rl rotation
            root->right=rightrotation(root->right);
            return leftrotation(root);
        }
    }
    return NULL;
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
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,0);
    inorder(root);
    deleteNode(root,1);
    cout<<endl;
    inorder(root);
    

    return 0;
}