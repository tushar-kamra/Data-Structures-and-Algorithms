#include<iostream>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
    int height ;
};

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp->height = 0 ;
    return temp ;
}

int height(Node* root){
    if(root == NULL) return -1 ;
    return root->height ;
}

int getBalanceFactor(Node* root){
    if(root == NULL) return 0 ;
    return height(root->left) - height(root->right) ;
}

Node* rrRotation(Node* p){
    Node* pl = p->left ;
    Node* plr = pl->right ;

    pl->right = p ;
    p->left = plr ;

    p->height = 1 + max(height(p->left),height(p->right)) ;
    pl->height = 1 + max(height(pl->left),height(pl->right)) ;

    return pl ;
}

Node* llRotation(Node* p){
    Node* pr = p->right ;
    Node* prl = pr->left ;

    p->right = prl ;
    pr->left = p ;

    p->height = 1 + max(height(p->left),height(p->right)) ;
    pr->height = 1 + max(height(pr->left),height(pr->right)) ;    

    return pr ;
}

Node* insert(Node* root, int key){
    if(root == NULL){
        return createNode(key) ;
    }
    if(key < root->data){
        root->left = insert(root->left,key) ;
    }
    else if(key > root->data){
        root->right = insert(root->right,key) ;
    }
    else {
        return root ;
    }
    root->height = 1+max(height(root->left),height(root->right)) ;
    int balance = getBalanceFactor(root) ;
    
    if(balance > 1 && root->left->data > key){
        return rrRotation(root) ;
    }
    if(balance < -1 && root->right->data < key){
        return llRotation(root) ;
    }
    if(balance > 1 && root->left->data < key){
        root->left = llRotation(root->left) ;
        return rrRotation(root) ;
    }
    if(balance < -1 && root->right->data > key){
        root->right = rrRotation(root->right);
        return llRotation(root) ;
    }
    return root ;
}

void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << "data : "<<root->data <<" height : "<<root->height<<endl ;
    preorder(root->left) ;
    preorder(root->right) ;
}

int main(){
    Node* root = NULL ;
    root = insert(root,10) ;
    root = insert(root,20) ;
    root = insert(root,30) ;
    root = insert(root,40) ;
    root = insert(root,50) ;
    root = insert(root,25) ;
    preorder(root) ;
}