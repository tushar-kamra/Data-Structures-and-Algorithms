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

Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left ;
    }
    return root ;
}

Node* deletion(Node* root, int x){
    if(root == NULL){
        return root ;
    }
    else if(root->data > x){
        root->left = deletion(root->left,x) ;
    }
    else if(root->data < x) {
        root->right = deletion(root->right,x) ;
    }
    else {
        if(root->left == NULL && root->right == NULL){
            Node* temp = root ;
            root = NULL ;
            delete temp ;
        }
        else if(root->left == NULL){
            Node* temp = root ;
            root = root->right ;
            delete temp ;
        }
        else if(root->right == NULL){
            Node* temp = root ;
            root = root->left ;
            delete temp ;
        }
        else {
            Node* temp = findMin(root->right) ;
            root->data = temp->data ;
            root->right = deletion(root->right,temp->data) ;
        }
    }
    return root ;
}

void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root->data <<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left) ;
    cout << root->data <<" " ;
    inorder(root->right) ;
}

void postorder(Node* root){
    if(root == NULL){
        return ;
    }
    postorder(root->left) ;
    postorder(root->right) ;
    cout << root->data <<" " ;
}

int main(){
    Node* root = NULL ;
    insertion(root,2) ;
    insertion(root,4) ;
    insertion(root,1) ;
    insertion(root,3) ;
    insertion(root,6) ;
    insertion(root,7) ;
    deletion(root,1) ;
    cout << "Preorder : " ;
    preorder(root) ;
    cout << endl ;
    cout << "Inorder : " ;
    inorder(root) ;
    cout << endl ;
    cout << "Postorder : " ;
    postorder(root) ;
    cout << endl ;
}