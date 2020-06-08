#include<iostream>
#include<queue>
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

Node* insertNode(Node* root, int x){
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        if(!temp->left){
            temp->left = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->left) ;
        }
        if(!temp->right){
            temp->right = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->right) ;
        }
    }
    return root ;
}

void printleftbdr(Node* root){
    if(root){
        if(root->left){
            cout << root->data <<" ";
            printleftbdr(root->left) ;
        }
        else if(root->right){
            cout << root->data <<" " ;
            printleftbdr(root->right) ;
        }
    }
}

void printleaf(Node* root){
    if(root){
        if(root->left == NULL && root->right == NULL){
            cout << root->data <<" " ;
        }
        printleaf(root->left) ;
        printleaf(root->right) ;
    }
}

void printrightbdr(Node* root){
    if(root){
        if(root->right){
            printrightbdr(root->right); 
            cout << root->data <<" " ;
        }
        else if(root->left){
            printrightbdr(root->left) ;
            cout << root->data <<" " ;
        }
    }
}

void boundary(Node* root){
    if(root == NULL) return ;
    cout << root->data << " " ;

    printleftbdr(root->left) ;
    printleaf(root->left) ;
    printleaf(root->right) ;
    printrightbdr(root->right) ;
}

int main(){
    Node* root = NULL ;
    root = insertNode(root,2);
    root = insertNode(root,4);
    root = insertNode(root,1);
    root = insertNode(root,8);
    root = insertNode(root,6);
    root = insertNode(root,5);
    root = insertNode(root,7);
    root = insertNode(root,9);
    root = insertNode(root,11);
    root = insertNode(root,16);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);
    boundary(root) ;
}