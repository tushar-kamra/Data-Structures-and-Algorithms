#include<iostream>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
    int height ;
};

Node* createNode(int x){
    Node* temp = new Node();
    temp->data = x ;
    temp->height = 0 ;
    temp->left = NULL ;
    temp->right = NULL ;
    return temp ;
}

int height(Node* root){
    if(root == NULL){
        return -1 ;
    }
    return root->height ;
}

int getBalance(Node* root){
    if(root == NULL){
        return 0 ;
    }
    return height(root->left)-height(root->right) ;
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

Node* insertNode(Node* root, int x){
    if(root == NULL){
        return createNode(x) ;
    }
    if(x < root->data){
        root->left = insertNode(root->left,x) ;
    }
    else if(x > root->data){
        root->right = insertNode(root->right,x) ;
    }
    else {
        return root ;
    }
    root->height = 1 + max(height(root->left),height(root->right)) ;
    int balance = getBalance(root) ;

    if(balance > 1 && root->left->data > x){
        return rrRotation(root) ;
    }
    if(balance < -1 && root->right->data < x){
        return llRotation(root) ;
    }
    if(balance > 1 && root->left->data < x){
        root->left = llRotation(root->left) ;
        return rrRotation(root) ;
    }
    if(balance < -1 && root->right->data > x){
        root->right = rrRotation(root->right);
        return llRotation(root) ;
    }
    return root ;
}

Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left ;
    }
    return root ;
}

Node* deleteNode(Node* root, int x){
    if(root == NULL){
        return root ;
    }
    if(x < root->data){
        root->left = deleteNode(root->left,x) ;
    }
    else if(x > root->data){
        root->right = deleteNode(root->right,x) ;
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
            root->right = deleteNode(root->right,temp->data) ;
        }
    }
    if(root == NULL){
        return root ;
    }
    root->height = 1 + max(height(root->left),height(root->right)) ;
    int balance = getBalance(root) ;

    if(balance > 1 && getBalance(root->left)>=0){
        return rrRotation(root) ;
    }
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = llRotation(root->left);
        return rrRotation(root) ;
    }
    if(balance < -1 && getBalance(root->right)>=0){
        return llRotation(root) ;
    }
    if(balance < -1 && getBalance(root->right) < 0){
        root->right = rrRotation(root->right) ;
        return llRotation(root) ;
    }
    return root ;
}

void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root->data << " " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

int main(){
    Node* root = NULL ;
    root = insertNode(root, 9);  
    root = insertNode(root, 5);  
    root = insertNode(root, 10);  
    root = insertNode(root, 0);  
    root = insertNode(root, 6);  
    root = insertNode(root, 11);  
    root = insertNode(root, -1);  
    root = insertNode(root, 1);  
    root = insertNode(root, 2);  
    preorder(root) ;
    cout << endl ;
    root = deleteNode(root,10) ;
    preorder(root) ;
}