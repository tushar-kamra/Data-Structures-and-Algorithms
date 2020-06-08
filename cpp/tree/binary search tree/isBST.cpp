#include<iostream>
#include<climits>
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

bool isBST(Node* root, int min, int max){
    if(root == NULL){
        return true ;
    }
    if(root->data > min && root->data < max){
        if(isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
            return true ;
        }
    }
    return false ;
}

void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root->data <<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

int main(){
    Node* root = NULL ;
    // insertion(root,2) ;
    // insertion(root,4) ;
    // insertion(root,1) ;
    // insertion(root,3) ;
    // insertion(root,6) ;
    // insertion(root,7) ;
    root = createNode(5) ;
    root->left = createNode(3) ;
    root->right = createNode(8) ;
    root->left->left = createNode(2) ;
    root->right->left = createNode(6) ;
    root->right->right = createNode(9) ;
    preorder(root) ;
    cout << endl ;
    (isBST(root,INT_MIN,INT_MAX))?cout <<"True" : cout <<"False" ;
}