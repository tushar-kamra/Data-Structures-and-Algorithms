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

Node* levelOrder(Node* root, int key){
    if(root == NULL){
        root = createNode(key) ;
        return root ;
    }
    if(root->data > key){
        root->left = levelOrder(root->left,key) ;
    }
    else {
        root->right = levelOrder(root->right,key) ;
    }
    return root ;
}

Node* constructBST(Node* root, int a[], int n){
    for(int i=0; i<n; i++){
        root = levelOrder(root,a[i]) ;
    }
    return root ;
}

void inorder(Node* root){
    if(root == NULL) return ;
    cout << root->data <<" " ;
    inorder(root->left);
    inorder(root->right) ;
}

int main(){
    int n ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    Node* root = NULL ;
    root = constructBST(root,a,n) ;
    inorder(root) ;
}