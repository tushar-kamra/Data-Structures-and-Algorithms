#include<iostream>
#include<algorithm>
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

void storeInorder(Node* root, int a[], int &i){
    if(root == NULL){
        return ;
    }
    storeInorder(root->left,a,i) ;
    a[i++] = root->data ;
    storeInorder(root->right,a,i) ;
}

void convert(Node* root, int a[], int &i){
    if(root == NULL){
        return ;
    }
    convert(root->left,a,i) ;
    root->data = a[i++] ;
    convert(root->right,a,i) ;
}

void bt2bst(Node* root){
    int inorder[15] ;
    int idx = 0 ;
    storeInorder(root,inorder,idx) ;
    sort(inorder,inorder+idx);
    idx = 0 ;
    convert(root,inorder,idx);
}

int main(){
    Node* root = NULL ;
    root = createNode(10) ;
    root->left = createNode(2) ;
    root->right = createNode(7) ;
    root->left->left = createNode(8) ;
    root->left->right = createNode(4) ;
    cout << "Inorder before : " ;
    inorder(root) ;
    cout << endl ;
    bt2bst(root) ;
    cout << "Inorder after : " ;
    inorder(root) ;
    cout << endl ;
}