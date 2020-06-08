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

bool search(Node* root, int x){
    if(root == NULL){
        return false ;
    }
    if(root->data == x) {
        return true ;
    }
    else if(root->data >= x){
        return search(root->left,x) ;
    }
    return search(root->right,x) ;
}

int main(){
    Node* root = NULL ;
    insertion(root,2) ;
    insertion(root,4) ;
    insertion(root,1) ;
    insertion(root,3) ;
    insertion(root,6) ;
    insertion(root,7) ;
    (search(root,3))?cout<<"Present":cout<<"Not present" ;
    (search(root,8))?cout<<"Present":cout<<"Not present" ;
}