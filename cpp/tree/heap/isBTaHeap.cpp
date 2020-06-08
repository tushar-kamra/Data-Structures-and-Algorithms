#include<iostream>
using namespace std ;

struct Node
{
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

int countNodes(Node* root){
    if(root == NULL){
        return 0 ;
    }
    return (1 + countNodes(root->left) + countNodes(root->right)) ;
}

bool isCompleteUtil(Node* root, int idx, int size){
    if(root == NULL){
        return true ;
    }
    if(idx >= size){
        return false ;
    }
    return isCompleteUtil(root->left, 2*idx+1, size) && isCompleteUtil(root->right, 2*idx+2, size) ;
}

bool isHeapUtil(Node* root){
    if(root->left == NULL && root->right == NULL){
        return true ;
    }
    if(root->right == NULL){
        return (root->data >= root->left->data) ;
    }
    else {
        if(root->data >= root->left->data && root->data >= root->right->data){
            return (isHeapUtil(root->left) && isHeapUtil(root->right)) ;
        }
    }
    return false ;
}

bool isHeap(Node* root){
    int n = countNodes(root) ;
    if(isCompleteUtil(root,0,n) && isHeapUtil(root)){
        return true ;
    }
    return false ;
}

int main(){
    Node* root = NULL ;
    root = createNode(114) ;
    root->left = createNode(7) ;
    root->right = createNode(9) ;
    root->left->left = createNode(5) ;
    root->left->right = createNode(0) ;
    if(isHeap(root)){
        cout << "True" ;
    }
    else {
        cout << "False" ;
    }
}
