#include<iostream>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
};

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    return temp ;
}

Node* insertion(Node*& root, int x){
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    else if(x <= root->data){
        root->left = insertion(root->left,x) ;
    }
    else{
        root->right = insertion(root->right,x) ;
    }
    return root ;
}

Node* removeLeaves(Node* root){
    if(root != NULL){
        if(root->left == NULL && root->right == NULL){
            delete root ;
            return NULL ;
        }
        else {
            root->left = removeLeaves(root->left) ;
            root->right = removeLeaves(root->right) ;
        }
    }
    return root ;
}

void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left) ;
    cout << root->data <<" " ;
    inorder(root->right) ;
}

int main(){
    Node* root = NULL ;
    insertion(root,6) ;
    insertion(root,4) ;
    insertion(root,1) ;
    insertion(root,3) ;
    insertion(root,2) ;
    insertion(root,7) ;
    insertion(root,5) ;
    insertion(root,11) ;
    insertion(root,13) ;
    insertion(root,9) ;
    cout << "Inorder : " ;
    inorder(root) ;
    cout << endl ;
    removeLeaves(root) ;
    cout << "Inorder : " ;
    inorder(root) ;
    cout << endl ;
}