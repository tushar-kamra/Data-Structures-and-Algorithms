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


void inorder(Node* root){
    if(root == NULL) return ;
    inorder(root->left) ;
    cout << root->data <<" " ;
    inorder(root->right) ;
}

Node* lca(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL ;
    }
    if(root->data > n1 && root->data > n2){
        return lca(root->left,n1,n2) ;
    }
    if(root->data < n1 && root->data < n2){
        return lca(root->right,n1,n2) ;
    }
    return root ;
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
    int a,b ;
    cin >> a >> b ;
    cout << lca(root,a,b)->data ;
}